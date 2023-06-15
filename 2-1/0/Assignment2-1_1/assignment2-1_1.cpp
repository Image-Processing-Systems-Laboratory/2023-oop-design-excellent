#include<iostream>

using namespace std;


int main()
{
	int Output[128];	//수를 저장할 배열
	int top = 0;		//가장 위 숫자
	char Input[128];	//입력받을 문자열 저장
	while (1)
	{
		cout << "Input: ";
		//입력받기
		cin.getline(Input, sizeof(Input));

		//입력받은 수를 저장
		if (strncmp(Input, "push", 4) == 0)
		{
			Output[++top - 1] = atoi(Input + 5);	//++top 후 수를 저장 
		}

		//가장 위의 수를 출력하고 삭제
		else if (strcmp(Input, "pop") == 0 && top > 0)
		{
			cout << Output[top - 1] << endl;		//가장 위의 수를 출력
			Output[top-- - 1] = 0;					//가장 위의 수를 제거함
		}

		//가장 위의 수를 출력
		else if (strcmp(Input, "top") == 0 && top > 0)
			cout << Output[top - 1] << endl;		//가장 위의 수 출력

		//저장된 수들 출력
		else if (strcmp(Input, "print") == 0)
		{
			for (int i = 0; i <= top - 1; i++)		//top-1까지 저장되어 있는 모든 수 출력
				cout << Output[i] << " ";
			cout << endl;
		}

		//비어 있다면 1출력 비어있지 않다면 0출력
		else if (strcmp(Input, "empty") == 0)
		{
			if (top > 0)	//stack이 비어있지 않을때
				cout << 0 << endl;
			else			//stack이 비어있을때
				cout << 1 << endl;
		}
		
		//프로그램 종료
		else if (strcmp(Input, "exit") == 0)
			return 0;

	}

	return 0;
}


