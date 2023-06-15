#include <iostream>
#include <cstring>

using namespace std;

struct s_node // array의 각 element를 담는 구조체
{
	char arr[21]; // 각 element 문자열을 담음
	struct s_node* next; // 옆 element
	struct s_node* down; // array 안에 array를 가리키는 포인터
};

s_node* make_one_node(const char* str, int &cnt) // 노드 하나를 만드는 함수
{
	int i = 0;
	s_node* new_node = new s_node;

	if (!new_node)
		return (0);
	if (str[0]) // 빈 문자열이 아니면 노드에 복사
	{
		while (str[cnt] && str[cnt] != ' '
			&& (str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ','
			&& str[cnt] != '[' && str[cnt] != ']') // 공백, 콤마, 대괄호가 아닐 때까지 복사
		{
			new_node->arr[i] = str[cnt];
			i++;
			cnt++;
		}
	}
	new_node->arr[i] = 0;
	new_node->down = 0;
	new_node->next = 0; // 포인터 초기화
	return (new_node);
}

s_node* make_array(const char *str, int& cnt) // linked list로 구현한 nested array를 만드는 함수
{
	s_node* head; // 각 line의 제일 앞 노드
	s_node* prev;
	s_node* now;

	head = 0;
	prev = 0;
	while (str[cnt]) // 문자열을 한 칸씩 읽어나감
	{
		while (str[cnt] && ((str[cnt] == ' ')
			|| (str[cnt] >= 9 && str[cnt] <= 13) || (str[cnt] == ',')))
			cnt++; // 콤마, 공백이 아닌 부분을 지나침
		if (str[cnt] == '[') // element가 array 이면
		{
			cnt++;
			now = make_one_node("", cnt); // element인 array를 가리키는 노드 생성
			// 해당 노드의 arr은 빈 문자열을 가지고 있다.
			if (head)
				prev->next = now;
			else
				head = now;
			prev = now;
			prev->down = make_array(str, cnt); // 재귀함수(array 생성 후 연결)
		}
		else if (str[cnt] == ']') // 전체 array 혹은 element인 array가 끝나면
		{
			cnt++;
			return (head);
		}
		else // element가 string
		{
			now = make_one_node(str, cnt);
			if (head)
				prev->next = now;
			else
				head = now;
			prev = now; // 노드 생성 후 연결
		}
	}
	return (head);
}

void print_array(s_node* head)
{
	cout << "["; // array의 시작
	while (head)
	{
		if (head->down) // down이 있다면 == nested array가 있다면
		{
			print_array(head->down); // 해당 array로 가 재귀 출력
			if (head->next)
				cout << ", ";
		}
		else
		{
			if (!(head->arr)[0] && !head->down) // 빈 문자열인데 down이 없다->빈 배열!
				cout << "[]";
			else
				cout << head->arr; // element 출력
			if (head->next)
				cout << ", ";
		}
		head = head->next;
	}
	cout << "]";
}

void execute_order(s_node* head)
{
	s_node* tmp = 0;
	char* input = 0;

	input = new char[100001]; // 명령들을 받을 문자열
	while (1)
	{
		cout << "order(break: exit): ";
		cin >> input;
		if (!strcmp(input, "exit"))
			break;
		else if (strlen(input) % 3 && strlen(input) < 3) // 입력의 포맷이 맞지 않으면 다시 입력
			continue;
		tmp = head;
		for (int i = 3; input[i]; i += 3) // 명령문에서 index만 추출 중(예: arr["3"]["1"][...)
		{
			if (tmp->down)
			{
				tmp = tmp->down;
				for (int j = 0; j < input[i + 1] - '0' && tmp->next; j++)
					tmp = tmp->next;
			} // 추출한 index 값에 따라 array의 출력 위치를 이동
		}
		if (tmp->down) // 출력해야 되는 element가 array라면
			print_array(tmp->down);
		else
		{
			if (!(tmp->arr)[0] && !tmp->down) // 출력해야 하는 element가 비어있다면 -> 빈 배열
				cout << "[]";
			else
				cout << tmp->arr;
		}
		cout << endl;
	}
	delete[]input;
}

void free_array(s_node* head) // nested array를 free하는 함수
{
	s_node* tmp;

	while (head)
	{
		if (head->down) // element가 array라면
			free_array(head->down); // 해당 array부터 free
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main()
{
	s_node* head = 0;
    char* input;
	int cnt = 0;

    cout << "nested array: ";
    input = new char[100001];
    cin.getline(input, 100001); // array 입력은 공백이 있을 수 있으므로 getline 함수 사용
	head = make_array(input, cnt); // array 생성
	if (!head)
	{
		delete[]input;
		input = 0;
		return (0);
	}
	delete[]input;
	input = 0;
	execute_order(head); // 명령어 입력 받고 실행
	free_array(head); // 메모리 해제
    return 0;
}