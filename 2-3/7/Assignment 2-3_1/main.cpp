#define _CRT_SECURE_NO_WARNINGS
#include "Empolyee.h"

int main()
{
	string str; //명령어

	char name[10]={};
	int age=0;
	char country[100]={};
	char job[100]={};

	char s_name[10] = {}; //검색할 이름
	char c_name[10] = {}; //수정할 이름

	Empolyee emp[10]; //클래스 객체 배열 생성


	int num = 0;
	while (1) { //exit 입력 전까지 반복
		cin >> str;
		if (str=="insert") { //정보 추가 삽입
			cin >> name >> age >> country >> job;
			emp[num++]=Empolyee(name, age, country, job);
			
		}
		if (str=="print") { //총 출력
			cout << "=====print=====" << endl;
			for (int i = 0; i < num; i++) {
				emp[i].print();
			}
			cout << endl;
		}
		if (str == "find") { //검색
			cin >> s_name;
			int no = 0; //이름 불일치 변수
			for (int i = 0; i < num; i++) {
				if (emp[i].isNameCorrect(s_name) == 1) { //이름 일치 검사
					cout << "=====find=====" << endl;
					emp[i].print(); //해당 정보 출력
				}
				else
					no++;
			}
			if (no == num) { //검색한 이름이 없을 경우
				cout << "검색 결과가 없습니다." << endl;
			}
			cout << endl;
		}
		if (str == "change") { //정보 수정
			cin >> c_name >> name >> age >> country >> job;
			for (int i = 0; i < num; i++) {
				if (emp[i].isNameCorrect(c_name) == 1) { //이름 일치 검사
					emp[i].change(name, age, country, job); //수정 정보 전달
				}
			}
		}
		if (str=="exit") { //종료
			break;
		}
	}
	return 0;
}