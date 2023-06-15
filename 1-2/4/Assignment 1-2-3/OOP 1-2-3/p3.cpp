#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char data[100];
	char text_name[100];
	int compare_num = 0;
	char wildcard[10][100];
	//이름을 체크해줄 불리언값
	bool isIncluded = false;
	ifstream fin;

	fin.open("filename_list.txt");

	//파일이 없으면 에러 출력
	if (!fin) {
		cout << "Error : no such file in directory." << endl;
	}

	//필요한 정보 입력요구
	cout << "Input file name : ";
	cin >> text_name;
	cin >> compare_num;

	for (int i = 0; i < compare_num; i++) {
		cin >> wildcard[i];
	}

	//Check Wildcard Pattern

	while (!fin.eof()) {
		fin.getline(data, 100, '\n');
		
		
		for (int i = 0; i < compare_num; i++) {
			for (int j = 0; data[j] != '\0'; j++) {
				// 같은 글자면 통과
				if (data[j] == wildcard[i][j]) {
					isIncluded = true;
				}
				// *이면 임의의 문자열 전부 커버
				else if (wildcard[i][j] == '*') {
					isIncluded = true;
					break;
				}
				// ? 면 통과
				else if (wildcard[i][j] == '?') {
					isIncluded = true;
				}
				else {
					isIncluded = false;
					break;
				}
			}
			// true로 끝나면 패턴이 전부다 포함되는 경우이므로 출력
			if (isIncluded == true) {
				cout << data << endl;
				isIncluded == false;
			}
		}
	}
	fin.close();
	return 0;
}