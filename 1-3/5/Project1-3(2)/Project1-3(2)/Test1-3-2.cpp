#include <iostream>
#include <iomanip>   //�Ҽ��� �ڸ����� �����ϱ� ���� setpercision()�Լ��� ���Ե� ������� ����

using namespace std;

int main()
{
	float Vs, R1, R2, RL;    //������ �������� �Է¹ް� ������
	float Vout;
	float I, IRL;
	float LPR;

	int numer;  
	int denom;
	int arr[15] = { 0 };   //��ȯ�Ҽ� ���� �����ϴ� �迭
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

		while (numer % denom != 0)  //��ȯ�Ҽ��� ������ �������� �������� 0�� �ɶ����� �������� ����
		{
			numer = numer / denom;  
			arr[k] = numer;  //��ȯ�Ҽ��� ������
			k++;

			numer *= 10;  //�������� 0�� �Ǵ°� �����ϱ� ���ؼ� �ڸ����� �÷���

			if (arr[0] == arr[k])  //���� ó�� ���� ��� ������ ��� ��ȯ ���� ������
			{
				break;
			}
		}

		cout << "Vout:" << Vs * R2 << '/' << R1 + R2 << "= " << (int)Vout << ".(";

		for (int i = 0; i < k; i++)     //��ȯ�Ҽ� ���� ���
		{
			cout << arr[i];
		}

		cout << ')';

	}

	else
	{

		Vout = (Vs * R2 * RL) / (R1 * (R2 + RL) + R2 * RL);  //RL���� 0�� �ƴҶ� Vout�� ���ϴ� ��
		
		I = Vs / (R1 + R2 * RL / (R2 + RL));        
		
		IRL = I * R2 / (R2 + RL);
		
		LPR = Vout * IRL / (Vs * I) * 100;   //load power ratio���� 100���� %�� ǥ����
		
		cout << endl << "Vout: " << Vs * R2 * RL << '/' << R1 * (R2 + RL) + R2 * RL << '=' << Vout << endl;
		cout << "Load power ratio: ";
		cout << fixed << setprecision(2) << LPR << '%';  //�Ҽ����� 2�ڸ����� ����ϱ� ���� setprecision()�Լ��� ���

	}

	return 0;
}