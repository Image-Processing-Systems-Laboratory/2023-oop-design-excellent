#include "class.h"

int main()
{
	string str;
	char name[10] = {};
	int age = 0;
	char class_name[30] = {};
	char s_class[30] = {};  //분반 검색용
	int n = 0; //객체 배열 사이즈 저장용

	School list; //클래스 객체 생성


	while (1) { //exit 입력 전까지 반복
		cin >> str;
		if (str == "new_student") { //학생 정보 추가
			cin >> name >> age >> class_name;
			list.new_student(name, age, class_name);
		}
		if (str == "print_all") { //모든 정보 출력
			list.print_all();
			cout << endl;
		}
		if (str == "print_class") { //해당 분반 정보 출력
			cin >> s_class; 
			cout << "=====print_class=====" << endl;
			n = list.showSize(); //객체 배열 사이즈 불러옴
			int no = 0, yes = 0; //이름 불일치, 일치 횟수 셀 변수
			for (int i = 0; i < n; i++) {
				if (list.Class_correct(s_class, i) == 1) { //일치할 시
					list.print_class(i);
					yes++;
				}
				else
					no++;
			}
			if (no == n) //해당 이름이 없는 경우
				cout << "검색 결과가 없습니다." << endl;
			cout << "Number of classmates : " << yes << endl;
			cout << endl;
		}
		if (str == "sort_by_name") { //이름 순 정렬
			list.sort_by_name();
		}
		if (str == "exit") { //종료
			break;
		}
	}
	return 0;
}