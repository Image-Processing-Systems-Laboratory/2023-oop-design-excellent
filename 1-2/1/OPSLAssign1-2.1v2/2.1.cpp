#include <iostream>

using namespace std;

int main()
{
	const int LENGTH = 30;
	int num;
	int check_count = 0;

	char input[LENGTH] = { 0, };

	cin.getline(input, LENGTH);

	for (int i = 0; i < LENGTH; i++)			// 입력줄의 길이만큼 반복
	{
		while (input[i] != 32 && input[i] != NULL)		// 공백 또는 0일때는 모든 실행을 건너뛴다.
		{
			num = input[i] - '0';						// 공백이 아닌 i번째 열의 숫자값을 num에 저장한다.
			cout << num;								// num을 출력한다.

			for (int j = 0; j < LENGTH - 1; j++)	// 입력줄의 길이만큼 반복한다.
			{
				if (input[j] - '0' == num)				// 이미 num은 공백이 아니기에 공백을 건너뛸 필요가 없다.
				{										// 또한 다시 입력줄만큼 반복하며 num과 같은 값을 가진 수의 개수를 센다.
					check_count++;
					input[j] = 32;						// 같은 값을 가진 수가 나타났을때 개수를 세기 위해 count ++, 중복을 피하기 위해 공백으로 바꿔버린다.
				}
			}
			cout << check_count;
		}
		check_count = 0;								// check_count는 num에 대한 개수이므로 for문이 반복될때마다 0으로 초기화한다.
	}

	return 0;
}