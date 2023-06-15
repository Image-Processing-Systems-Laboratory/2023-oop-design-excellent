#include<iostream>
#include "StudentScoreList.h"

using namespace std;

int main()
{
	//변수 선언
	StudentScoreList ListA;
	char Input[20];
	double Math, English, Science;
	double Avg = 0;
	Score* add[100];
	int len = 0;

	while (1) {
		cin >> Input;
		//exit 동작
		if (strcmp(Input, "exit") == 0) {
			break;		//반복문 탈출
		}
		//add 동작
		else if (strcmp(Input, "add") == 0) {
			cout << "Score of Math, English, Science: ";
			cin >> Math >> English >> Science;		//입력 받기
			Avg = (Math + English + Science) / 3;	//평균값 저장
			add[len] = new Score;			//메모리 할당
			add[len]->SetAvg(Avg);		//add[len]에 값 저장
			ListA.Insert(add[len++]);			//add[len]에 저장된 값 저장
		}
		//print 동작
		else if (strcmp(Input, "print") == 0) {
			bool isAscendig;				//오름차순인지 아닌지 저장하는 변수
			cin >> isAscendig;			//입력 받기
			ListA.PrintList(isAscendig);	//1이면 오름차순, 0이면 내림차순 출력
		}
	}


	//할당한 메모리 해제
	for (int i = 0; i < len; i++)
		delete add[i];

	return 0;
}