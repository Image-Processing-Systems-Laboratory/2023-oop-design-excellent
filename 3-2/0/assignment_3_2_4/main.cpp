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

	cin >> buf; // 다항식을 입력 받음
	for (int i = 0; i < buf.length(); i++)
	{
		if (buf.at(i) == '-' && i && buf.at(i - 1) != '^')
			buf.replace(i++, 1, "+-"); // 항의 구분을 +단위로 하기 위해 계수의 '-'를 "+-"로 변환
		// '^'다음에 나오는 -는 차수이므로 +-로 변환할 필요 X
	}
	ptr = buf.c_str();
	strcpy(pbuf, ptr); // string을 const char*로 변환 후 char pbuf[]에 입력
	pterm = strtok(pbuf, "+"); // + 단위로 끊음 -> 위에서 계수의 '-'를 "+-"로 바꿨으므로 항 단위 구분 
	while (pterm)
	{
		for (idx = 0; pterm[idx] != 'x' && pterm[idx]; idx++); // 'x'의 위치를 반환
		if (idx == 0) // x로 시작하면 -> 계수가 1
		{
			coeff = 1;
			expo = atoi(pterm + 2); // x^ 다음 숫자가 차수
		}
		else if (pterm[idx] == 0) // x가 없으면 -> 상수항 -> 차수가 0
		{
			coeff = atoi(pterm);
			expo = 0;
		}
		else
		{
			coeff = atoi(pterm);
			if (coeff == 0 && pterm[0] == '-' && pterm[1] == 'x')
				coeff = -1; // 계수 자리에 '-'만 있으면 -> 계수가 -1
			expo = atoi(pterm + idx + 2); // x^ 다음 수가 차수
		}
		if (coeff) // 계수가 0이 아니면
		{
			tmp = new Term;
			tmp->SetCoeff(coeff);
			tmp->SetExponent(expo); // 위에서 얻은 정보로 term 하나 생성
			pol.Insert(tmp); // polynomial에 삽입
		}
		pterm = strtok(0, "+"); // pbuf를 계속 +단위로 쪼갬
	}
}

int main()
{
	Polynomial a;
	Polynomial b; // 인스턴스 생성

	cout << "write a: ";
	parsing(a);
	cout << endl << "write b: ";
	parsing(b); // a와 b를 입력받아 파싱
	cout << endl <<  "Polynomial a: ";
	a.PrintList();
	cout << "Polynomial b: ";
	b.PrintList(); // a, b 다항식 출력
	a.Add(b); // a+b
	cout << "a + b: ";
	a.PrintList(); // 결과
	a.Sub(b); // a+b-b = a(a 복원)
	a.Sub(b); // a-b
	cout << "a - b: ";
	a.PrintList(); // 결과
	return 0;
}