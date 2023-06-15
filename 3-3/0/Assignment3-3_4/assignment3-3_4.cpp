#include<iostream>
#include "StudentScoreList.h"

using namespace std;

int main()
{
	//���� ����
	StudentScoreList ListA;
	char Input[20];
	double Math, English, Science;
	double Avg = 0;
	Score* add[100];
	int len = 0;

	while (1) {
		cin >> Input;
		//exit ����
		if (strcmp(Input, "exit") == 0) {
			break;		//�ݺ��� Ż��
		}
		//add ����
		else if (strcmp(Input, "add") == 0) {
			cout << "Score of Math, English, Science: ";
			cin >> Math >> English >> Science;		//�Է� �ޱ�
			Avg = (Math + English + Science) / 3;	//��հ� ����
			add[len] = new Score;			//�޸� �Ҵ�
			add[len]->SetAvg(Avg);		//add[len]�� �� ����
			ListA.Insert(add[len++]);			//add[len]�� ����� �� ����
		}
		//print ����
		else if (strcmp(Input, "print") == 0) {
			bool isAscendig;				//������������ �ƴ��� �����ϴ� ����
			cin >> isAscendig;			//�Է� �ޱ�
			ListA.PrintList(isAscendig);	//1�̸� ��������, 0�̸� �������� ���
		}
	}


	//�Ҵ��� �޸� ����
	for (int i = 0; i < len; i++)
		delete add[i];

	return 0;
}