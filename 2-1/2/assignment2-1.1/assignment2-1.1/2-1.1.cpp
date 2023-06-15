#include <iostream> //iostream 선언
#include <string.h> //strcmp 함수 사용을 위한 선언
using namespace std; //namespace std 선언

int stack[128]; //정수형 배열 stack선언, 최대 크기 128

int locate = 0; //스택의 위치를 제어하기 위한 locate 변수 선언

void push(int num) //push 함수: 스택에 요소를 넣는 기능
{
	if (locate == 128) //stack이 최대치로 차면 
	{
		cout << "You cannot push the elements anymore." << endl; //안내문 출력
	}
	else //그 외의 경우
	{
		stack[locate] = num; //stack의 locate인덱스에 num을 추가
		locate++; //locate 증가
	}

	return;
} //push함수 종료

void pop(void) //가장 위에 있는 요소를 출력하고 제거하는 함수
{

	if (locate == 0) //만약 스택에 아무것도 없으면
	{
		cout << "No elements exist." << endl; //안내문 출력
	}
	else //그 외에
	{
		cout << stack[locate-1] << endl; //스택 가장 위에 있는 요소를 출력한다. 이미 locate가 증가되어있는 상황이기 때문에 1을 감소시켜야 한다.
		stack[locate] = ' '; //pop시킨 인덱스는 공백을 채워준다.
		locate--; //인덱스 감소
	}

	return;
} //pop함수 종료

void top(void) //가장 위에 있는 요소를 보여주는 함수
{
	if (locate == 0) //만약 스택에 아무것도 없으면
	{
		cout << "No elements exist." << endl; //안내문 출력
	}
	else //그 외에
	{
		cout << stack[locate - 1] << endl; //가장 위에 있는 요소를 출력한다. pop과 마찬가지로 이미 증가되어 있는 상태이기에 1을 감소시켜야 한다.
		}
	

	return;
} //top함수 종료

void print(void) //stack에 있는 요소들을 출력해주는 함수
{
	if (locate == 0) //만약 아무것도 없으면
	{
		cout << "No elements exist." << endl; //안내문 출력
	}
	else //그 외에
	{
		for (int i = 0; i < locate; i++) //현재 쌓여있는 모든 스택의 요소들을 출력해준다.
			cout << stack[i] << " ";

		cout << endl;
	}

	return;
} //print함수 종료

int empty(void) //스택이 비었는지 아닌지 반환값으로 보여주는 함수
{
	if (locate == 0) //스택에 아무것도 없으면
		return 1; //1을 반환
	else //스택에 어떠한 요소라도 있으면
		return 0; //0을 반환
} //empty함수 종료


int main() //main함수 시작
{
	char control[300]={0}; //command를 입력받을 control 문자열 선언
	int element = 0; //push함수에 들어갈 요소를 위한 변수 선언

	
	while (1) //반복문 (exit에 의해 종료된다.)
	{
		cin >> control; //command를 입력받기
		if (!strcmp(control,"push")) //control이 push와 같으면 strcmp의 반환값이 0이다. 즉 push라는 단어가 control에 입력되면
		{
			cin >> element; //element를 입력받고
			push(element); //push함수로 전달
			
		}
		else if (!strcmp(control,"pop")) //control에 pop이 입력되면
		{
			pop(); //pop함수 실행
		}
		else if (!strcmp(control, "top")) //control에 top이 입력되면
		{
			top(); //top함수 실행
		}
		else if (!strcmp(control, "print")) //control에 print가 입력되면
		{
			print(); //print함수 실행
		}
		else if (!strcmp(control, "empty")) //control에 empty가 입력되면
		{
			cout << empty() << endl; //empty함수의 반환값을 출력
		}
		else if (!strcmp(control, "exit")) //control에 exit가 입력되면
		{
			break; //반복문 종료
		}
		else //control에 정해지지 않은 command가 입력되면
		{
			cout << "Wrong Command Entered. Please Try Again." << endl; //안내문 출력
		}
	}

	return 0; //0의 반환
} //main함수 종료