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
		if (!strcmp(buf, "setData")) // myMusic a에 값 추가
		{
			cin.ignore(); // 입력 버퍼 비우기
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
			a.setTrackNo(atoi(ptr)); // 데이터가 ','를 기준으로 나뉘므로 strtok로 구분
		}
		else if (!strcmp(buf, "printData"))
		{
			cout << "Title: " << a.getTitle() << endl;
			cout << "Singer: " << a.getSinger() << endl;
			cout << "Album: " << a.getAlbum() << endl;
			cout << "Year: " << a.getYear() << endl;
			cout << "TrackNo: " << a.getTrackNo() << endl; // 전체 데이터 출력
		}
		else if (!strcmp(buf, "exit")) // exit이면 반복문 탈출
			break;
		else
			cout << "wrong input" << endl; // 입력이 setData, printData, exit중에 없음
	}
	return 0;
}