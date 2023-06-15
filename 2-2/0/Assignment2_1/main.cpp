#pragma warning(disable:4996)

#include<iostream>
#include<cstring>

using namespace std;

class Ele
{
public:
	Ele* next;	// 다음 Ele 노드를 기리킬 포인터
	Ele* under;	// 아래로 향하는 노드를 가리킬 포인터
	char str[21];
	Ele()
	{
		next = NULL;
		under = NULL;
		str[0] = '\0'; // 비어있을경우 *사용
	}
	~Ele()	// 동적할당의 해제를 위해 소멸자 선언
	{
		if (under != NULL)
			under->~Ele();

		if (next != NULL)
			next->~Ele();
	}
};

class NestArry
{
public:
	Ele start;	// 최초의 노드

	void get_value(Ele* dest)	// 입력값에 따라 노드를 생성함
	{
		while (cin.peek() != ']')	// 괄호가 닫히면 반복문을 종료
		{
			if (cin.peek() == '[') // 괄호가 열리면 재귀적으로 함수를 호출한다
			{
				cin.get();	// '['를 버림
				dest->under = new Ele;
				get_value(dest->under); // 괄호가 열리면 아래로 향하는 노드를 생성하고 재귀적으로 호출
				if (cin.peek() == ']')
					break;
				dest->next = new Ele;// 아래로향하는 노드가 존재하는 노드에는 문자열 값이 들어가지 않음
				dest = dest->next;// 다음 노드 지목
			}
			else // 괄호가 열리지 않으면 노드의 str을 받고 입력 형식에 따라 행동함
			{
				get_str(dest);	// 문자열 을 dest에 저장함
				if (cin.peek() == ']')	// 괄호가 닫히면 반복문 탈출
					break;
				dest->next = new Ele; // 괄호가 닫히지 않으면 다음 노드를 생성 
				dest = dest->next;
			}
		}cin.get();// ']' 제거
		if (cin.peek() == ',') // 콤마와 공백을 버리기 위한 조건문
		{
			cin.get();	// 콤마를 버림
			while (cin.peek() == ' ') // 공백을 버림
			{
				cin.get();
			}
		}

		return;
	}
	
	void get_str(Ele* dest)	// 매개변수로 들어온 노드에 str값을 저장함
	{
		int idx = 0;
		while ((cin.peek() != ']')&&(cin.peek()!=',')) // 괄호가 닫히거나 ','로 구분되면 문자열 정보 읽기를 종료
		{
			(dest->str)[idx++] = cin.get();
		}

		(dest->str)[idx] = '\0'; // 마지막 널문자 추가

		if (cin.peek() == ',') // 콤마와 공백을 버리기 위한 조건문
		{
			cin.get();
			while (cin.peek()==' ')
			{
				cin.get();
			}
		}

		return;
	}

	int get_idx(void) // 입력값으로 인덱싱이 들어오면 정수값만 읽어오고 괄호는 버린다
	{
		int tmp = -1;
		while (cin.peek()!=']')
		{
			cin.get();
			tmp = (cin.get()) - '0';
		}
		cin.get();// ']'제거
		return tmp;
	}
	void print_nest(Ele* ptr) // 배열안에 배열이 포함된 경우의 출력문
	{
		cout << '['; //괄호를 출력
		while (ptr != NULL)// ptr이 널포인터라면 반복문 종료
		{
			if (ptr->under != NULL) // 해당 노드의 아래에 노드가 존재하면 재귀적 호출
				print_nest(ptr->under);

			else// 아래에 노드가 없다면 해당 노드의 str값을 출력한다
			{
				int idx = 0;
				while (1)
				{
					cout << ptr->str[idx];
					if (ptr->str[idx] == '\0')
						break;
					idx++;
				}
			}
			if (ptr->next == NULL) // 반복문이 종료될 예정이면 ]를 출력
				cout << ']';
			else
				cout << ", "; // 아니라면 , 출력
			ptr = ptr->next;

		}
		return;
	}
	void print(void)
	{
		Ele* ptr = &start;
		char flag_all = 1;	// 배열의 한 원소를 가리키는 건지 아닌지 확인할 플래그, 한 원소라면 0, 전체라면 1임
							
		while (cin.peek() != '\n')	// 모든 입력을 읽으면 반복문 종료
		{
			int tmp = get_idx();
			for (int i = 0; i < tmp; i++) // 인덱스를 하나 뽑아낼 때마다 노드들에 접근함
			{
				ptr = ptr->next;
				flag_all = 0;
			}
			if (ptr->under != NULL) // 아래에 노드가 존재하면 해당노드로 이동하고 flag 값을 변경함
			{
				ptr = ptr->under;
				flag_all = 1;
			}
			else
				flag_all = 0;
		}
		if (flag_all == 0) //flag 값에따라 원소하나를 출력할지 아닐지 판단함 
		{
			int idx = 0;
			while (1)
			{
				if (ptr->str[idx] == '\0'&&idx==0)
				{
					cout << "INVALID INDEX, VOID";
					break;
				}
				cout << ptr->str[idx];
				if (ptr->str[idx] == '\0')
					break;
				idx++;
			}
		}
		else
			print_nest(ptr);	// 한원소가 아닌 여러 원소들을 출력할때 호출할 함수

		cout << endl;

		return;
	}
	

};

char is_exit(void)	// command가 exit인지 확인하는 함수
{
	if (cin.peek() != 'e')
		return 0;

	char exit[] = "exit";
	for (int i = 0; i < 4; i++)
	{
		if (cin.get() != exit[i])
			return 0;
	}
	if (cin.peek() == '\n')
		return 1;
	
	return 0;
}
char is_arr(void)	// command가 arr인지 확인하는 함수
{
	if (cin.peek() != 'a')
		return 0;

	char arr[] = "arr";
	for (int i = 0; i < 3; i++)
	{
		if (cin.get() != arr[i])
			return 0;
	}
	return 1;
}

int main(void)
{
	cin.get();
	NestArry Na;
	Na.get_value(&(Na.start));	// 해당 객체의 값을 입력받음

	cin.ignore(5, '\n');
	while (!is_exit()) // 입력값이 exit이면 반복문 종료
	{
		if (!is_arr()) // 잘못된 입력값이면 프로그램을 종료한다.
		{
			cout << "INVALID INPUT, terminate program.\n";
			return 0;
		}
		Na.print(); // 출력하는 메서드 호출
		cin.ignore(5, '\n');
	}


	return 0;
}
