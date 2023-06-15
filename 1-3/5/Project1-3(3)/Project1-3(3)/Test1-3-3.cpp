#include <iostream>
#include <cmath>

using namespace std;

void convertBOH(int ber, int base)  //10진수를 2진수, 8진수, 16진수로 변환해주는 함수
{
	char hexa[17] = "0123456789ABCDEF";  //2진수, 8진수, 16진수로 변환시킬때 나머지를 쉽게 계산하여 저장하기 위한 16개의 숫자
	char out[20] = { 0 };          //결과를 저장할 배열

	int i;

	for (i = 0; ber != 0; i++)   //10진수를 2진수, 8진수, 16진수로 변환시키는 과정에 의해서 각 변환할 진수로 나누어 나머지를 배열에 저장함
	{
		out[i] = hexa[ber % base];  //나머지가 순서대로 저장됨
		ber /= base;
	}

	for (int a = i - 1; a >= 0; a--)  //나머지가 순서대로 저장되어있으므로 이를 역순으로 출력하여 표현함
	{
		cout << out[a];       
	}
}

int main()
{
	char arr[15];  //arr는 입력한 수

	int  b, c;   //a는 입력한 수, b는 입력한 수의 타입, c는 변환할 진수 형태이다.

	cin >> arr >> b >> c;

	int i = 0;
	int num = 0;

	switch (b)        //각각의 입력받은 수의 진수에 따라서 10진수로 변환해줌
	{
	case 2:
		while (arr[i] != '\0')   //배열의 크기를 계산함
		{
			i++;
		}

		for (int a = 0; a < i; a++)  //10진수를 2진수로 변환하는 과정
		{
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	case 8:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	case 10:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			
			num += ((int)arr[a] - '0') * pow(b, (i - a - 1));
		}
		break;

	case 16:
		while (arr[i] != '\0')
		{
			i++;
		}

		for (int a = 0; a < i; a++)
		{
			if(arr[a] >= 'A' && arr[a] <= 'F')    //16진수의 값이 들어왔을 경우 A부터 F의 아스키 코드값에서 55를 빼서 10진수로 변환
				num += ((int)arr[a] - '7') * pow(b, (i - a - 1));

			else
				num += ((int)arr[a] - '0') * pow(b, (i - a - 1));

		}
		break;

	default:
		cout << "error";
		break;
	}

	switch (c)    //입력받은 수를 원하는 진수로 변환해주는 switch문
	{
	case 2:
		convertBOH(num, c);
		break;

	case 8:
		convertBOH(num, c);
		break;

	case 10:
		cout << num;     //10진수를 10진수로 변환할떄는 그냥 num값을 출력함
		break;

	case 16:
		convertBOH(num, c);
		break;

	default:
		cout << "error";
		break;
	}

	return 0;
}