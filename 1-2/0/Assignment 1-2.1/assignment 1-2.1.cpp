#include<iostream>
#include<string.h>
using namespace std;

//함수선언

//79 897687543217
//897687543217 89
//897687543217 897687543217

int main()
{
	char str1[20], str2[20], str3[40];	//char형 배열 선언
	int str3_len;						//int형 배열 선언
	cout << "Input: ";
	cin >> str1 >> str2;				//두개의 문자열을 입력 받음
	
	strcpy_s(str3, str1);				//str3에 str1을 저장함
	strcat_s(str3, str2);				//str3에 str2를 이어붙임
	str3_len = strlen(str3);			//str3의 문자열 길이를 저장함
	cout << "Output: ";
	for (int i = 0; i < str3_len; i++)	//i가 0부터 str3_len-1까지
	{
		int num = 0, count = 0;			//int형 변수 선언, 0으로 초기화
		for (int k = 0; k < str3_len; k++)	//k가 0부터 str3_len-1까지
			if (str3[i] == str3[k])		//만약 같은수가 있다면
				num++;					//num = num + 1을 한다.

		if (i > 0)				//i가 0보다 클때
			for (int j = i - 1; j > -1; j--)	//j가 i-1부터 0까지
				if (str3[i] == str3[j])		//이미 출력한 수와 동일하다면
					count++;				//동일한 값의 수를 카운트함(count = count + 1)
		if (count > 0)						//이미 출력한 수가 있다면(count>0일때)
			continue;
		cout << str3[i] << num;				//숫자와 그 숫자의 개수를 출력한다.
	}
	return 0;
}