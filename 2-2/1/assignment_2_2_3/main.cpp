#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main()
{
    char path[100];

    cout << "path: ";
    cin >> path; // path를 입력받음
    CSVLoader a(path); // 입력받은 path로 인스턴스 a 생성

    a.print(); // 생성된 배열 출력
    cout << "rows: " << a.getRows() << endl; // 행 개수 출력
    cout << "cols: " << a.getCols() << endl; // 열 개수 출력
    return (0);
}