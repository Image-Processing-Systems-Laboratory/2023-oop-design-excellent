#include "School.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    School school;      // School 객체 생성
    string input;       // 사용자 입력을 저장할 string 변수

    while (true)
    {
        getline(cin, input);        // 사용자 입력을 input에 저장
        stringstream strin(input);      // input을 stringstream으로 변환
        string command;     // 명령어를 저장할 string 변수
        strin >> command;    // strin에서 command를 읽어옴

        // command에 따라 다른 함수 호출
        // new_student인 경우 이름, 나이, 반을 입력받아 학생을 추가
        if (command == "new_student")
        {
            char name[100], class_name[100];
            int age;
            strin >> name >> age >> class_name;
            school.new_student(name, age, class_name);
        }
        // sort_by_name인 경우 학생들을 이름순으로 정렬
        else if (command == "sort_by_name")
        {
            school.sort_by_name();
        }
        // print_all인 경우 학생들의 정보를 모두 출력
        else if (command == "print_all")
        {
            school.print_all();
        }
        // print_class인 경우 반을 입력받아 해당 반의 학생들의 정보를 출력
        else if (command == "print_class")
        {
            char class_name[100];
            strin >> class_name;
            school.print_class(class_name);
        }
        // exit인 경우 프로그램 종료
        else if (command == "exit")
        {
            break;
        }
        // 그 외의 경우 유효한 명령어를 입력하도록 출력
        else
        {
            cout << "Input vaild command" << endl;
        }
    }

    return 0;
}
