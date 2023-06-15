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

	if (res[2] == 0) //R_Load ���� 0�� ���
	{
		numerator = vol_s * res[1];
		denominator = res[0] + res[1];
	}
	else //R_Load ���� 0�� �ƴ� ���
	{
		numerator = vol_s * res[1] * res[2];
		denominator = res[0] * (res[1] + res[2]) + res[1] * res[2];
	}

	cout << numerator << "/" << denominator << " = ";;

	if (numerator % denominator == 0) //(numerator/denominator)�� ������ ���
	{
		cout << numerator / denominator;
	}
	else //���� ������ �ƴ� ���
	{
		int mok[30];
		int remain = numerator, multiply = 10;
		int i, j, k, start, end;
		bool find = false;

		//�������� ���� �� ������ �Ҽ��� ���� �ڸ����� �迭�� ����ش�
		for (i = 0; i < 30; i++)
		{
			mok[i] = remain / denominator;
			remain = remain % denominator;

			//����������� �Ҽ��� ���
			if (remain == 0)
			{
				start = i+1;
				end = 0;
				break;
			}

			//������ ������ �ϱ� ���� remain�� multiply�� �����ش�
			while (denominator > remain)
			{
				remain *= multiply;
			}

		}
		
		//��ȯ �Ҽ��� ���
		if (remain != 0)
		{
			start = 1;
			end = start;

			//���� �Ҽ��� �� ���ڵ��� ���Ͽ� ������ �ݺ��Ǵ��� Ȯ���Ѵ�
			for (i = start; i < 30 && !find; i++)
			{
				for (j = end+1; j < 30 && !find; j++)
				{
					//�տ��� ���Դ� ���ڰ� ������ ���
					if (mok[i] == mok[j])
					{
						start = i;
						end = j;
						find = true; //�ݺ��Ǵ� ���ڸ� ã�����Ƿ� find ���� true�� ����
					}
				}

				//��ȯ�� �Ǵ� �������� Ȯ��
				for (k = 0; k < end - start; k++)
				{
					//��ȯ ���� �ʴ� ���
					if (mok[start + k] != mok[end + k])
					{
						find = false; //�ݺ��Ǵ� ���ڰ� �ƴϹǷ� find ���� false�� ����
					}
				}
			}
		}

		//�ݺ����� �ʴ� ���� ���
		cout << mok[0] << ".";
		for (i = 1; i < start; i++)
		{
			cout << mok[i];
		}

		//�ݺ��Ǵ� ���� ���
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

	//load_power_ratio �� ��� �� ���
	if (res[2] != 0)
	{
		ratio = (((double)numerator / denominator) * res[1]) / (vol_s * (res[1] + res[2]));
		cout << fixed;
		cout.precision(2);
		cout << "Load power ratio: " << ratio*100 << "%" << endl;
	}

	return 0;
}