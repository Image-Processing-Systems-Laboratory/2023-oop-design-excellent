#include <iostream>
#pragma warning(disable:4996)
#include <string>
#include <cstring>
#include "poly.h"

using namespace std;

void parsing(Polynomial& pol)
{
	string buf;
	const char* ptr;
	char pbuf[1024];
	char* pterm;
	Term* tmp;
	int idx, coeff, expo;

	cin >> buf; // ���׽��� �Է� ����
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf.at(i) == '-' && i && buf.at(i - 1) != '^')
			buf.replace(i++, 1, "+-"); // ���� ������ +������ �ϱ� ���� ����� '-'�� "+-"�� ��ȯ
		// '^'������ ������ -�� �����̹Ƿ� +-�� ��ȯ�� �ʿ� X
	}
	ptr = buf.c_str();
	strcpy(pbuf, ptr); // string�� const char*�� ��ȯ �� char pbuf[]�� �Է�
	pterm = strtok(pbuf, "+"); // + ������ ���� -> ������ ����� '-'�� "+-"�� �ٲ����Ƿ� �� ���� ���� 
	while (pterm)
	{
		for (idx = 0; pterm[idx] != 'x' && pterm[idx]; idx++); // 'x'�� ��ġ�� ��ȯ
		if (idx == 0) // x�� �����ϸ� -> ����� 1
		{
			coeff = 1;
			expo = atoi(pterm + 2); // x^ ���� ���ڰ� ����
		}
		else if (pterm[idx] == 0) // x�� ������ -> ����� -> ������ 0
		{
			coeff = atoi(pterm);
			expo = 0;
		}
		else
		{
			coeff = atoi(pterm);
			if (coeff == 0 && pterm[0] == '-' && pterm[1] == 'x')
				coeff = -1; // ��� �ڸ��� '-'�� ������ -> ����� -1
			expo = atoi(pterm + idx + 2); // x^ ���� ���� ����
		}
		if (coeff) // ����� 0�� �ƴϸ�
		{
			tmp = new Term;
			tmp->SetCoeff(coeff);
			tmp->SetExponent(expo); // ������ ���� ������ term �ϳ� ����
			pol.Insert(tmp); // polynomial�� ����
		}
		pterm = strtok(0, "+"); // pbuf�� ��� +������ �ɰ�
	}
}

int main()
{
	Polynomial a;
	Polynomial b; // �ν��Ͻ� ����

	cout << "write a: ";
	parsing(a);
	cout << endl << "write b: ";
	parsing(b); // a�� b�� �Է¹޾� �Ľ�
	cout << endl <<  "Polynomial a: ";
	a.PrintList();
	cout << "Polynomial b: ";
	b.PrintList(); // a, b ���׽� ���
	a.Add(b); // a+b
	cout << "a + b: ";
	a.PrintList(); // ���
	a.Sub(b); // a+b-b = a(a ����)
	a.Sub(b); // a-b
	cout << "a - b: ";
	a.PrintList(); // ���
	return 0;
}