#include <iostream>
#include <cmath>

using namespace std;

void calculate(int num1, int num2); // �м��� ����ϴ� �Լ�

int main()
{
    double Vs, R1, R2, RL; // ���� �Է� �ޱ� ���� ������ ����
    cout << "Vs : ";
    cin >> Vs;
    cout << "R1 : ";
    cin >> R1;
    cout << "R2 : ";
    cin >> R2;
    cout << "R(Load) : ";
    cin >> RL;

    double R2RL = R2 * RL / (R2 + RL); // R2||RL�� �������� ��Ÿ�� ��
    double I, Vout, Pload, Ps, load_power_ratio; // ����� ������ �����ϱ� ���� ������ ����

    if (RL == 0) // RL�� 0�� ��� �Ʒ��� ���� �������� �Ͼ
    {
        I = Vs / (R1 + R2);
        Vout = I * R2;
        cout << "Vout : " << Vs * R2 << "/" << R1 + R2 << " = ";
        calculate(Vs * R2, R1 + R2); // �Լ� ȣ��
        cout << endl;

    }
    else // �� ���� ��� �Ʒ��� ���� �������� �Ͼ
    {
        I = Vs / (R1 + R2RL);
        Vout = I * R2RL;
        cout << "Vout : " << Vs * R2 * RL << "/" << (R1 * (R2 + RL)) + (R2 * RL) << " = ";
        calculate(Vs * R2 * RL, (R1 * (R2 + RL)) + (R2 * RL)); // �Լ� ȣ��
        cout << endl;

        // power �� ������
        Pload = Vout * Vout / RL;
        Ps = Vs * I;
        load_power_ratio = Pload / Ps;

        cout.precision(2); // �Ҽ��� ��°�ڸ����� ���
        cout << "Load power ratio : " << fixed << load_power_ratio * 100.0 << "%" << endl; // �Ҽ��� ��°�ڸ����� ���
    }
    return 0;
}

void calculate(int num1, int num2) // �м��� ����ϴ� �Լ�
{
    int cpynum1 = num1, cpynum2 = num2, cnt = 0, start, end; // ������ ����
    int num[10000] = { 0 }; // �迭 ����

    while (1) // ���ѷ���
    {
        cpynum1 = (cpynum1 % cpynum2 * 10); // ���ڸ� �и�� ���� �������� 10�� ����
        if (num[cpynum1] != 0)  // ���� num[cpynum1]�� 0�� �ƴ϶��
        {
            start = num[cpynum1]; // start�� ���� ����
            end = cnt; //end�� cnt�� ���� ��
            break; // ���� Ż��
        }
        num[cpynum1] = ++cnt; // num[cpynum1]�� cnt���� �����ϰ� cnt���� 1 ������Ŵ
    }

    cpynum1 = num1; // cpynum1�� num1���� ����
    cpynum2 = num2; // cpynum2�� num2���� ����
    cout << cpynum1 / cpynum2; // ���ڸ� �и�� ���� ���� ���
    if (cpynum1 % cpynum2 != 0) // �������� 0�� �ƴ϶��
    {
        cout << "."; // .�� ���
    }

    int temp = cpynum1 % cpynum2 * 10; // �������� 10 ���� ���� ����
    for (int i = 0; i < start - 1; i++)
    {
        cout << temp / cpynum2; // temp�� cpynum2�� ���� ���� ���
        temp = (temp % cpynum2 * 10); // temp�� cpynum2�� ���� �������� 10 ���� ���� ����
    }

    if (temp > 0) // temp�� 0���� ũ��
    {
        cout << "("; // (�� ���
        for (int j = start - 1; j < end; j++)
        {
            cout << temp / cpynum2; // temp�� cpynum2�� ���� ���� ���
            temp = temp % cpynum2 * 10; // temp�� cpynum2�� ���� �������� 10 ���� ���� ����
        }
        cout << ")\n"; // )�� ���
    }
}