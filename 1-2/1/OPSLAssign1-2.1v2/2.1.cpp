#include <iostream>

using namespace std;

int main()
{
	const int LENGTH = 30;
	int num;
	int check_count = 0;

	char input[LENGTH] = { 0, };

	cin.getline(input, LENGTH);

	for (int i = 0; i < LENGTH; i++)			// �Է����� ���̸�ŭ �ݺ�
	{
		while (input[i] != 32 && input[i] != NULL)		// ���� �Ǵ� 0�϶��� ��� ������ �ǳʶڴ�.
		{
			num = input[i] - '0';						// ������ �ƴ� i��° ���� ���ڰ��� num�� �����Ѵ�.
			cout << num;								// num�� ����Ѵ�.

			for (int j = 0; j < LENGTH - 1; j++)	// �Է����� ���̸�ŭ �ݺ��Ѵ�.
			{
				if (input[j] - '0' == num)				// �̹� num�� ������ �ƴϱ⿡ ������ �ǳʶ� �ʿ䰡 ����.
				{										// ���� �ٽ� �Է��ٸ�ŭ �ݺ��ϸ� num�� ���� ���� ���� ���� ������ ����.
					check_count++;
					input[j] = 32;						// ���� ���� ���� ���� ��Ÿ������ ������ ���� ���� count ++, �ߺ��� ���ϱ� ���� �������� �ٲ������.
				}
			}
			cout << check_count;
		}
		check_count = 0;								// check_count�� num�� ���� �����̹Ƿ� for���� �ݺ��ɶ����� 0���� �ʱ�ȭ�Ѵ�.
	}

	return 0;
}