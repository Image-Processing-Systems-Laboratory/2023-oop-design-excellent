// ������ �Լ����� �׽�Ʈ�ϴ� ���� �ҽ�����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "oopstd.h" // oopstd ��������� include
using namespace std;

int main() // Ȯ���� ���� ���ι��� ���Ƿ� ��������ϴ�
{
	char a[100] = "hello_cpp";
	char a1[100] = "hello_cpp";
	oopstd::memset(a, 'H', 3); // HHHlo_cpp�� ��
	memset(a1, 'H', 3); // ��
	cout << a << endl << a1 << endl;

	char b1[100] = "cpp_hello";
	char b2[100] = "hi_cpp";
	char b3[100] = "cpp_hello";
	char b4[100] = "hi_cpp";
	oopstd::memcpy(b1, b2, 4); // hi_chello�� ��
	memcpy(b3, b4, 4); // ��
	cout << b1 << endl << b3 << endl;

	char c[100] = "study!";
	char c1[100] = "study!";
	char c2[100] = "ddddy!";
	cout << oopstd::strcmp(c, c1) << " " << oopstd::strcmp(c, c2) << endl; // 0�� ����� ��µž� �Ѵ�
	cout << strcmp(c, c1) << " " << strcmp(c, c2) << endl; // ��
	// �̶� ���⼭ oopstd::strcmp�� 15�� ����ϴµ�, strcmp�� 1�� ����Ѵ�. �ֳĸ� oopstd::strcmp�� ���� ��ÿ� �� ���ڿ��� �� ���̸� ��ȯ�ϵ��� ������, strcmp�� ������ �����Ϸ� ���� ��� ��ȯ �� ������ 1�� ��ȯ�ϱ� �����̴�

	cout << oopstd::strncmp(c, c1, 3) << " " << oopstd::strncmp(c, c2, 3) << endl; // ���� 0�� ����� ��µž� �Ѵ�
	cout << strncmp(c, c1, 3) << " " << strncmp(c, c2, 3) << endl; // ��
	// ���� strcmp�� �Ȱ���. �ٵ� ������ ����� ���������� ��µǱ� ������ �ƹ� ���� ����

	char d[100] = "hello~";
	char d1[100] = "hihi~~";
	char d2[100] = "yes";
	char d3[100] = "hello~";
	char d4[100] = "hihi~~";
	char d5[100] = "yes";
	oopstd::strcpy(d, d1);
	strcpy(d3, d4); // ��
	cout << d << endl << d3 << endl; // hihi~~�� ��µž� �Ѵ�

	oopstd::strncpy(d1, d2, 2);
	strncpy(d4, d5, 2); // ��
	cout << d1 << endl << d4 << endl; // yehi~~�� ��µž� �Ѵ�

	char e[100] = "strlen_check";
	cout << oopstd::strlen(e) << endl << strlen(e) << endl; // 12�� ��µž� �Ѵ�

	char f[100] = "12345";
	int f1 = oopstd::atoi(f);
	int f2 = atoi(f); // ��
	cout << f1 << endl << f2 << endl; // 12345�� (�������·�)��µž� �Ѵ�
	cout << f1 + 3 << endl << f2 + 3 << endl; // ���������� üũ(12348�� ��µž� �Ѵ�)

	char g[100] = "123.123";
	float g1 = oopstd::atof(g);
	float g2 = atof(g);// ��
	cout << g1 << endl << g2 << endl; // 123.456�� (�Ǽ����·�)��µž� �Ѵ�
	cout << g1 + 3.1 << endl << g2 + 3.1 << endl; // �Ǽ������� üũ(126.556�� ��µž� �Ѵ�)
	return 0;
}