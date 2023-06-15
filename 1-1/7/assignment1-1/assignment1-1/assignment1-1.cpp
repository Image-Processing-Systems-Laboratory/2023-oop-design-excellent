#include<iostream>

char map[384][768];		//k=8 즉 k 값이 최대일 때 형성되는 삼각형의 높이는 384    밑변의 길이 767 + NULL값 들어갈 공간=768

void put_dollar(int high, int y, int x);

int main()
{
	int k;
	int high;
	int i, j;
	std::cout << "input:";
	std::cin >> k;		//입력받기

	for (i = 0; i < 384; i++)
		for (j = 0; j < 767; j++)
			map[i][j] = ' ';		//map을 전부 공백으로 채워놓음

	high = 3;				//k=1 일때 삼각형의 높이

	for (i = 1; i < k; i++)
		high *= 2;			//k>1 일때 삼각형의 높이

	put_dollar(high, 0, high - 1);		// 재귀 시작점은 y=0,x=high-1

	for (i = 0; i < high; i++)		//출력
	{
		for (j = 0; j < 2 * high; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
	return 0;
}

void put_dollar(int high, int y, int x)
{
	if (high == 3)		//재귀의 마지막 => 삼각형을 그림
	{
		map[y][x] = '$';
		map[y + 1][x - 1] = '$';
		map[y + 1][x + 1] = '$';
		for (int i = 0; i < 5; i++)
			map[y + 2][x - 2 + i] = '$';
		return;
	}
	high /= 2;
	put_dollar(high, y, x);		//3등분 되는 삼각형의 위쪽
	put_dollar(high, y + high, x - high);		//왼쪽
	put_dollar(high, y + high, x + high);		//오른쪽
}