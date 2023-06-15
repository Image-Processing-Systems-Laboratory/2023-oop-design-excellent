#include <iostream>
#include <cstring>
#include "mymusic.h"

using namespace std;

int main()
{
	myMusic a;
	char* ptr;
	char buf[100];
	char input[1000];

	while (1)
	{
		cout << "order: ";
		cin >> buf;
		if (!strcmp(buf, "setData")) // myMusic a�� �� �߰�
		{
			cin.ignore(); // �Է� ���� ����
			cout << "data: ";
			cin.getline(input, 1000);
			a.setTitle(strtok(input, ","));
			a.setSinger(strtok(0, ","));
			a.setAlbum(strtok(0, ","));
			ptr = strtok(0, ",");
			if (!ptr)
				continue;
			a.setYear(atoi(ptr));
			ptr = strtok(0, ",");
			if (!ptr)
				continue;
			a.setTrackNo(atoi(ptr)); // �����Ͱ� ','�� �������� �����Ƿ� strtok�� ����
		}
		else if (!strcmp(buf, "printData"))
		{
			cout << "Title: " << a.getTitle() << endl;
			cout << "Singer: " << a.getSinger() << endl;
			cout << "Album: " << a.getAlbum() << endl;
			cout << "Year: " << a.getYear() << endl;
			cout << "TrackNo: " << a.getTrackNo() << endl; // ��ü ������ ���
		}
		else if (!strcmp(buf, "exit")) // exit�̸� �ݺ��� Ż��
			break;
		else
			cout << "wrong input" << endl; // �Է��� setData, printData, exit�߿� ����
	}
	return 0;
}