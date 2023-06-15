#include <iostream>
#include <iomanip>   //소수점 자리수를 설정하기 위해 setpercision()함수가 포함된 헤더파일 선언

using namespace std;

int main()
{
	float Vs, R1, R2, RL;    //각각의 변수들을 입력받고 저장함
	float Vout;
	float I, IRL;
	float LPR;

	int numer;  
	int denom;
	int arr[15] = { 0 };   //순환소수 마디를 저장하는 배열
	int k = 0;
	int nd;

	cout << "Vs: ";
	cin >> Vs;

	cout << "R1: ";
	cin >> R1;

	cout << "R2: ";
	cin >> R2;

	cout << "R(Load): ";
	cin >> RL;

	if (RL == 0)  
	{
		Vout = Vs * R2 / (R1 + R2);

		nd = Vs * R2;
		denom = (R1 + R2);

		numer = nd % denom;
		numer *= 10;

		while (numer % denom != 0)  //순환소수를 나누는 과정에서 나머지가 0이 될때까지 나눗셈을 실행
		{
			numer = numer / denom;  
			arr[k] = numer;  //순환소수를 저장함
			k++;

			numer *= 10;  //나머지가 0이 되는걸 방지하기 위해서 자릿수를 올려줌

			if (arr[0] == arr[k])  //가장 처음 나눈 몫과 같아질 경우 순환 마디가 결정됨
			{
				break;
			}
		}

		cout << "Vout:" << Vs * R2 << '/' << R1 + R2 << "= " << (int)Vout << ".(";

		for (int i = 0; i < k; i++)     //순환소수 마디 출력
		{
			cout << arr[i];
		}

		cout << ')';

	}

	else
	{

		Vout = (Vs * R2 * RL) / (R1 * (R2 + RL) + R2 * RL);  //RL값이 0이 아닐때 Vout을 구하는 식
		
		I = Vs / (R1 + R2 * RL / (R2 + RL));        
		
		IRL = I * R2 / (R2 + RL);
		
		LPR = Vout * IRL / (Vs * I) * 100;   //load power ratio값을 100분율 %로 표현함
		
		cout << endl << "Vout: " << Vs * R2 * RL << '/' << R1 * (R2 + RL) + R2 * RL << '=' << Vout << endl;
		cout << "Load power ratio: ";
		cout << fixed << setprecision(2) << LPR << '%';  //소수점을 2자리까지 출력하기 위해 setprecision()함수를 사용

	}

	return 0;
}