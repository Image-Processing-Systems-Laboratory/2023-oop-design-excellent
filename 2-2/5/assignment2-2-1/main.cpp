#include <iostream>
#include <string>


using namespace std;

struct node {
	char arr[21] = {0};
	node* next = NULL;//다음연결 노드
	node* sub = NULL;//밑으로 파고 들어가는 포인터
	node* prev_depth = NULL;// 파고들어가기전의 노드의 주소값을 담는 포인터
};



void print_arr(node* head, char* command);
void print_sub(node* head);
void mem(node* current);




int main() {

	string total;//처음 입력받는 문자열을 담을 공간
	node* head = new node;//시작 노드를 가르키는 노드
	node* current = head;//현재노드를 가르키는 노드
	int count = 0;//문자열이 등장하였을때 인덱스를 표시해줌

	


	getline(cin,total);//입력값을 받음
	
	const char* loop = total.c_str();//string 값을 문자열 포인터에 저장

	while (*++loop != NULL) {
		if (*loop == ' ') {
			continue;//빈칸이 존재할 시 값을 입력받지 않음
		}

		if (*loop == '[') {//인덱스가 열리면 밑으로 파고 들어가는 노드 생성
			node* make = new node; 
			current->sub = make;// 배열을 가르키는 노드에 sub 노드의 존재 알림
			make->prev_depth = current;// 계층 표시
			current = make;
			count = 0;
			continue;
			
			
		}


		else if (*loop == ',') {//쉼표를 만나면 노드하나 생성

				node* make = new node;
				current->next = make;
				make->prev_depth = current->prev_depth;//현재 계층 계쏙해서 표시
				current = make;
				count = 0;
				continue;
				
	
		}

		else if (*loop ==	']') {
			current = current->prev_depth;//이전 계층값으로 되돌아옴 
			continue;
			
		}
	
		
		current->arr[count] = *loop;
		count++;
		
	
	}

	

	while (true) {

		char* command = new char[100000];//입력값을 저장할 공간
	
		cin >> command;

		if (!strcmp(command, "exit")) {
			break;
		}
	
				
		if (strncmp(command, "arr",3)) {// 입력값이 arr이 아닐경우 다시 입력을 받게 함
			cout << "invalid value" << endl;;
			continue;
		}

		print_arr(head, command);

		cout << endl;
	}// exit가 입력 될 때 까지 반복

	mem(head);// 메모리 할당해제
	
}


void print_sub(node* head) {

	node* current = head;

	cout << '[';
	
	while (current != NULL) {
		cout << current->arr; //현재 노드가 갖고 있는 문자열 출력



		if (current->next != NULL) {

			if (current->sub != NULL) {

			}
			else { cout << ", "; };// 다음 노드가 존재할 경우 쉼표 출력

		}


		if (current->sub != NULL) {
			print_sub(current->sub);//sub 노드가 존재할경우 재귀적으로 함수를 호출하여 인덱스 출력
			if (current->next != NULL) {
				cout << ", ";// 다음 노드가 존재할 경우 쉼표 출력
			}
		}

		current = current->next;// 다음 노드로 이동
	}
	cout << ']';


}



void print_arr(node* head, char* command) {


	int count = -1;
	int* index = new int[1000];

	while (*command != NULL) {

		if (*command == '[') {
			count++;
			index[count] = 0;// index[count]의 값 초기화
			while (isdigit(*(command+ 1))) {
				index[count] *= 10;
				index[count] += ( * (command + 1) - 48);//인덱스내의 숫자 가져오기 
				index[count + 1] = -1;//인덱스의 끝을 표현하기 위한 변수 설정
			
				command++;
			}
	
			continue;
			}
		command++;
	}

	node* current = head;
	char pass[] = "pass";// 재귀함수를 위한 임의 문자열


	
	if (count == -1) {
		print_sub(head);// 전체 노드 출력

	}


	if (count != -1) {// 인덱스가 존재할 경우 
		int new_index = 0;
		while (index[new_index] != -1) {// 인덱스의 값만큼 반복문 반복

			for (int i = index[new_index]; i > 0; i--) {
				current = current->next;// 옆의 노드로 이동
			
			}
			if (index[new_index + 1] != -1) {
				current = current->sub;//sub이 존재하는 노드의 위치 도착하였기에 sub node로 이동
			}
			new_index++;
			
		}


		if (current->sub!= NULL) {// 현재의 노드가 배열 노드일경우 
				print_sub(current->sub);
			
			}//배열 노드의 전체 출력
		
		
	
		else {
		
			cout << current->arr;// 배열노드가 아닐 경우 저장된 문자열 출력
		
		}


	
	}

	
	}

void mem(node* current) {

    if (current == NULL) {
        return;
    }
	if (current->sub != NULL) {
		mem(current->sub);// sub 노드가 존재할시 재귀적으로 함수를 호출하여 동적메모리 해제
	}

	else if(current->next!=NULL) {
		mem(current->next);//sub 노드가 존재하지 않을 경우 옆의 노드로 이동
		
	}
	delete current;// 마지막 노드 도착시 할당해제
}

	

