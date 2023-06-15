// 구현한 함수들을 테스트하는 메인 소스파일
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "oopstd.h" // oopstd 헤더파일을 include
using namespace std;

int main() // 확인을 위한 메인문은 임의로 만들었습니다
{
	char a[100] = "hello_cpp";
	char a1[100] = "hello_cpp";
	oopstd::memset(a, 'H', 3); // HHHlo_cpp가 됨
	memset(a1, 'H', 3); // 비교
	cout << a << endl << a1 << endl;

	char b1[100] = "cpp_hello";
	char b2[100] = "hi_cpp";
	char b3[100] = "cpp_hello";
	char b4[100] = "hi_cpp";
	oopstd::memcpy(b1, b2, 4); // hi_chello가 됨
	memcpy(b3, b4, 4); // 비교
	cout << b1 << endl << b3 << endl;

	char c[100] = "study!";
	char c1[100] = "study!";
	char c2[100] = "ddddy!";
	cout << oopstd::strcmp(c, c1) << " " << oopstd::strcmp(c, c2) << endl; // 0과 양수가 출력돼야 한다
	cout << strcmp(c, c1) << " " << strcmp(c, c2) << endl; // 비교
	// 이때 여기서 oopstd::strcmp는 15를 출력하는데, strcmp는 1을 출력한다. 왜냐면 oopstd::strcmp는 구현 당시에 두 문자열의 값 차이를 반환하도록 했지만, strcmp는 윈도우 컴파일러 기준 양수 반환 시 무조건 1을 반환하기 때문이다

	cout << oopstd::strncmp(c, c1, 3) << " " << oopstd::strncmp(c, c2, 3) << endl; // 역시 0과 양수가 출력돼야 한다
	cout << strncmp(c, c1, 3) << " " << strncmp(c, c2, 3) << endl; // 비교
	// 역시 strcmp와 똑같다. 근데 어차피 양수가 정상적으로 출력되기 때문에 아무 문제 없다

	char d[100] = "hello~";
	char d1[100] = "hihi~~";
	char d2[100] = "yes";
	char d3[100] = "hello~";
	char d4[100] = "hihi~~";
	char d5[100] = "yes";
	oopstd::strcpy(d, d1);
	strcpy(d3, d4); // 비교
	cout << d << endl << d3 << endl; // hihi~~가 출력돼야 한다

	oopstd::strncpy(d1, d2, 2);
	strncpy(d4, d5, 2); // 비교
	cout << d1 << endl << d4 << endl; // yehi~~가 출력돼야 한다

	char e[100] = "strlen_check";
	cout << oopstd::strlen(e) << endl << strlen(e) << endl; // 12가 출력돼야 한다

	char f[100] = "12345";
	int f1 = oopstd::atoi(f);
	int f2 = atoi(f); // 비교
	cout << f1 << endl << f2 << endl; // 12345가 (정수형태로)출력돼야 한다
	cout << f1 + 3 << endl << f2 + 3 << endl; // 정수형인지 체크(12348이 출력돼야 한다)

	char g[100] = "123.123";
	float g1 = oopstd::atof(g);
	float g2 = atof(g);// 비교
	cout << g1 << endl << g2 << endl; // 123.456이 (실수형태로)출력돼야 한다
	cout << g1 + 3.1 << endl << g2 + 3.1 << endl; // 실수형인지 체크(126.556이 출력돼야 한다)
	return 0;
}