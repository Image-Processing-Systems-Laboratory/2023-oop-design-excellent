#include "mymusiclist.h"
#include <iostream>

using namespace std;

int main()
{
	MyMusicManagementList a; // 인스턴스 생성
	char arr[100]; // file name을 받는 버퍼
	char artist[1024]; // 검색할 artist의 이름

	cout << "file name: ";
	cin >> arr;
	cin.ignore(); // 입력 버퍼 비우기
	if (!(a.make_list(arr))) // 해당 파일이 없으면 프로그램 종료
		return 0;
	a.print_all(); // 리스트 출력
	cout << "search and print next artist: "; // artist 검색 후 그 다음 artist의 정보 출력
	cin.getline(artist, 1024); // artist 정보에 공백이 있으므로 getline으로 받음
	a.search_next_artist(artist);
	return 0;
}