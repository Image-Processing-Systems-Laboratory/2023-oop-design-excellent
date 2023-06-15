#include<iostream>
#include<cmath>
using namespace std;

void get_rep(long long numer, long long denom);

int main(void)
{
	// �Է°����� ���� ������ ����
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
		// �־��� �������� ratio�� ���ϴ� ������ �����ϸ�
		//�Ʒ��� ���� �������� ����� �����ϹǷ�, round�� �̿��� ����Ѵ�.
		
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

	//���ڰ� �����ߴ��� Ȯ���ϱ� ���� �迭, ���� ���̰� ���� �������� ��ǥ��
	int** flag = new int* [10];
	for (int i = 0; i < 10; i++)
		flag[i] = new int[denom];
	
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < denom; j++)
			flag[i][j] = 0;

	int start_rep[2] = {0};	//��ȯ�� ���۵Ǵ� ��� �������� �����ϱ� ���� �迭 ù��° ���ҿ� ��, �ι�° ���ҿ� �������� ����
	int tmp_share = 0, tmp_remain = numer; // ���ڸ��� ��� �������� �����ϱ� ���� �迭

	// ������ �������ų� ��ȯ�Ҽ��� ǥ���� ���� �ʴ� ��� ��� ó���� �����ϹǷ�
	// �Ʒ��� ���� �ݺ����� ���
	for (int i = 1,j=0;; i++)
	{
		// �Ҽ��� �ڸ����� �ִ� ���ڸ� �������� 10�� �������� ���ϰ� 
		// 10�� ������ ��� ������ Ȯ��
		// ������ �������� ��쿡�� flag�� ��� ���� ��� 0�ΰ��� ��ŷ�� �ǹǷ� �̻� ���� ����� ����
		tmp_share = ((tmp_remain * 10) / denom);
		tmp_share %= 10;
		tmp_remain = tmp_remain * 10 % denom ;	//%������ int������ �����ϹǷ� ĳ����

		// ��ȯ�Ǵ� �κ��� ã������
		if (flag[tmp_share][tmp_remain] != 0)
		{
			start_rep[0] = tmp_share;
			start_rep[1] = tmp_remain;
			break;
		}
		else // ã�� ��������
			flag[tmp_share][tmp_remain]++;
	}

	// ��ȯ�ϴ� �κ��� ã��, ����� ���
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
		// �������� �־��� ���Ĵ�� ��ȯ���� ǥ���ϱ� ���� �κ�
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