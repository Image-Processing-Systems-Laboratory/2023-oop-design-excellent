#include "CSVLoader.h"
#include <iostream>

using namespace std;

int main()
{
    char path[100];

    cout << "path: ";
    cin >> path; // path�� �Է¹���
    CSVLoader a(path); // �Է¹��� path�� �ν��Ͻ� a ����

    a.print(); // ������ �迭 ���
    cout << "rows: " << a.getRows() << endl; // �� ���� ���
    cout << "cols: " << a.getCols() << endl; // �� ���� ���
    return (0);
}