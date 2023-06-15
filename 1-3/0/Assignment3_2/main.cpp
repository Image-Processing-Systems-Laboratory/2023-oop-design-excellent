#include<iostream>
#include<cmath>
using namespace std;

void get_rep(long long numer, long long denom);

int main(void)
{
	// 입력값으로 받을 변수들 선언
	long long Vs = 0;
	long long R1 = 0, R2 = 0, RL = 0;
	long long numer = 0,denom=0;

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
		numer = Vs * R2;
		denom = R1 + R2;

		cout << "Vout: " << numer << '/'<< denom << " = ";
		get_rep(numer, denom);
	}
	else
	{
		numer = Vs * R2 * RL;
		denom = R1 * (R2 + RL) + R2 * RL;
		cout << "Vout: " << numer << '/' << denom << " = ";
		get_rep(numer, denom);
		// 주어진 문제에서 ratio를 구하는 수식을 변형하면
		//아래와 같은 수식으로 출력이 가능하므로, round를 이용해 출력한다.
		
		double ratio_num = (double)Vs * Vs * (R2 + RL) / ((R1 * (R2 + RL) + (R2 * RL)));
		double ratio_denom = ((double)Vs * R2 * numer / denom) / (R1 * (R2 + RL) + RL * R2);
		double ratio = ratio_denom / ratio_num * 100;

		printf("\nLoad power ratio: %.2lf%%", ratio);
	}

	return 0;
}
void get_rep(long long numer, long long denom)
{
	cout << numer / denom;
	if (numer % (int)denom == 0)
		return;
	
	 cout << '.';
	numer = numer - denom * (numer / denom);

	//숫자가 등장했는지 확인하기 위한 배열, 행은 몫이고 열은 나머지를 대표함
	int** flag = new int* [10];
	for (int i = 0; i < 10; i++)
		flag[i] = new int[denom];
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < denom; j++)
			flag[i][j] = 0;

	int start_rep[2] = {0};	//순환이 시작되는 몫과 나머지를 저장하기 위한 배열 첫번째 원소에 몫, 두번째 원소에 나머지를 저장
	int tmp_share = 0, tmp_remain = numer; // 한자리씩 몫과 나머지를 저장하기 위한 배열

	// 나누어 떨어지거나 순환소수로 표현이 되지 않는 경우 모두 처리가 가능하므로
	// 아래와 같은 반복문을 사용
	for (int i = 1,j=0;; i++)
	{
		// 소수점 자리수에 있는 숫자를 보기위해 10의 제곱승을 곱하고 
		// 10을 나누어 몫과 나머지 확인
		// 나누어 떨어지는 경우에는 flag의 행과 열이 모두 0인곳에 마킹이 되므로 이상 없이 출력이 가능
		tmp_share = ((tmp_remain * 10) / denom);
		tmp_share %= 10;
		tmp_remain = tmp_remain * 10 % denom ;	//%연산은 int에서만 가능하므로 캐스팅

		// 순환되는 부분을 찾았을떄
		if (flag[tmp_share][tmp_remain] != 0)
		{
			start_rep[0] = tmp_share;
			start_rep[1] = tmp_remain;
			break;
		}
		else // 찾지 못했을때
			flag[tmp_share][tmp_remain]++;
	}

	// 순환하는 부분을 찾고, 결과를 출력
	tmp_remain = numer;
	for (int i=1,j=-1;;i++)
	{
		tmp_share = ((tmp_remain * 10) / denom);
		tmp_share %= 10;
		tmp_remain = tmp_remain * 10 % denom;

		if (tmp_remain == 0)
		{
			if (i != 1)
				return;
			cout << tmp_share;
			return;
		}
		// 문제에서 주어진 형식대로 순환마디를 표현하기 위한 부분
		if (start_rep[0] == tmp_share && start_rep[1] == tmp_remain)
		{
			if (j == -1)
			{
				cout << '(';
				j++;
			}
			else
			{
				cout << ')';
				break;
			}
		}
		cout << tmp_share;

	}

	return;
}