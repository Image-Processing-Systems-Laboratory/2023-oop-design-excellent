#include "mymusiclist.h"
#include <iostream>

using namespace std;

int main()
{
	MyMusicManagementList a; // �ν��Ͻ� ����
	char arr[100]; // file name�� �޴� ����
	char artist[1024]; // �˻��� artist�� �̸�

	cout << "file name: ";
	cin >> arr;
	cin.ignore(); // �Է� ���� ����
	if (!(a.make_list(arr))) // �ش� ������ ������ ���α׷� ����
		return 0;
	a.print_all(); // ����Ʈ ���
	cout << "search and print next artist: "; // artist �˻� �� �� ���� artist�� ���� ���
	cin.getline(artist, 1024); // artist ������ ������ �����Ƿ� getline���� ����
	a.search_next_artist(artist);
	return 0;
}