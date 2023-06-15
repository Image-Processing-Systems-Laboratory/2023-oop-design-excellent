#include <iostream>
using namespace std;

int main(void)
{
	int vol_s, res[3], numerator, denominator;
	double ratio;

	cout << "Vs: ";
	cin >> vol_s;
	cout << "R1: ";
	cin >> res[0];
	cout << "R2: ";
	cin >> res[1];
	cout << "R(Load): ";
	cin >> res[2];

	cout << endl << "Vout: ";

	if (res[2] == 0) //R_Load 값이 0인 경우
	{
		numerator = vol_s * res[1];
		denominator = res[0] + res[1];
	}
	else //R_Load 값이 0이 아닌 경우
	{
		numerator = vol_s * res[1] * res[2];
		denominator = res[0] * (res[1] + res[2]) + res[1] * res[2];
	}

	cout << numerator << "/" << denominator << " = ";;

	if (numerator % denominator == 0) //(numerator/denominator)가 정수인 경우
	{
		cout << numerator / denominator;
	}
	else //값이 정수가 아닌 경우
	{
		int mok[30];
		int remain = numerator, multiply = 10;
		int i, j, k, start, end;
		bool find = false;

		//나눗셈을 했을 때 나오는 소수점 뒤의 자리들을 배열에 담아준다
		for (i = 0; i < 30; i++)
		{
			mok[i] = remain / denominator;
			remain = remain % denominator;

			//나누어떨어지는 소수인 경우
			if (remain == 0)
			{
				start = i+1;
				end = 0;
				break;
			}

			//나눗셈 연산을 하기 위해 remain에 multiply를 곱해준다
			while (denominator > remain)
			{
				remain *= multiply;
			}

		}
		
		//순환 소수인 경우
		if (remain != 0)
		{
			start = 1;
			end = start;

			//나온 소수점 뒤 숫자들을 비교하여 패턴이 반복되는지 확인한다
			for (i = start; i < 30 && !find; i++)
			{
				for (j = end+1; j < 30 && !find; j++)
				{
					//앞에서 나왔던 숫자가 나오는 경우
					if (mok[i] == mok[j])
					{
						start = i;
						end = j;
						find = true; //반복되는 숫자를 찾았으므로 find 값을 true로 변경
					}
				}

				//순환이 되는 숫자인지 확인
				for (k = 0; k < end - start; k++)
				{
					//순환 되지 않는 경우
					if (mok[start + k] != mok[end + k])
					{
						find = false; //반복되는 숫자가 아니므로 find 값을 false로 변경
					}
				}
			}
		}

		//반복되지 않는 숫자 출력
		cout << mok[0] << ".";
		for (i = 1; i < start; i++)
		{
			cout << mok[i];
		}

		//반복되는 숫자 출력
		if (end - start > 0)
		{
			cout << "(";
			for (i = start; i < end; i++)
			{
				cout << mok[i];
			}
			cout << ")";
		}
	}

	cout << endl;

	//load_power_ratio 값 계산 후 출력
	if (res[2] != 0)
	{
		ratio = (((double)numerator / denominator) * res[1]) / (vol_s * (res[1] + res[2]));
		cout << fixed;
		cout.precision(2);
		cout << "Load power ratio: " << ratio*100 << "%" << endl;
	}

	return 0;
}