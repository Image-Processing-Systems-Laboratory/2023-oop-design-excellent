#include <iostream> //iostream ����
using namespace std; //namespace std ����
void inputmatrix(void); //original Matrix �Է¹޴� �Լ� ����
void outputinverse(void); //inverse Matrix ��� �� ����ϴ� �Լ� ����
double finddev(void); //original matrix�� ��İ��� ���ϴ� �Լ� ����

double detmat = 0; //��İ��� �޴� ���� ����
int original[3][3];//original matrix�� ���� �迭 ����
double inverse[3][3];//inverse matrix�� ���� �迭 ����

int main(void) //main�Լ� ����
{
	inputmatrix(); //�Լ��� ���� original matrix �Է¹ޱ�
	detmat = finddev(); //�Է¹��� matrix�� ��İ��� finddev�Լ��� ��� �� ��ȯ���� detmat�� ����
	if (detmat == 0) //��İ��� 0�̸�
		cout << "The inverse matrix does not exist." << endl; //������� �������� �ʴ´ٴ� �ȳ��� ���
	else {
		outputinverse(); //�� ���� ��� ������� ��� �� ���
	}
	return 0; //0�� ��ȯ
} //main�Լ� ����

void inputmatrix(void) //Original Matrix�� �Է¹޴� �Լ� ����
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << i + 1 << "�� " << j + 1 << "�� �� �Է�: ";
			cin >> original[i][j];
		}
	} //��ø for���� �̿��Ͽ� ���ʴ�� ����� ���ڵ��� �Է¹ޱ�
	cout << endl << "Original Matrix: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << original[i][j] << " ";
		}cout << endl;
	} //�Է� Ȯ�� �� ����İ� �񱳸� ���� Original Matrix�� ��ø for���� �̿��Ͽ� ���

	return;
} //inputmatrix �Լ� ����

void outputinverse(void) //inverse matrix�� ����ϰ� ����ϴ� �Լ� ����
{
	inverse[0][0] = static_cast<double>(original[1][1] * original[2][2] - original[1][2] * original[2][1]);
	inverse[1][0] = static_cast<double>(-(original[1][0] * original[2][2] - original[1][2] * original[2][0]));
	inverse[2][0] = static_cast<double>(original[1][0] * original[2][1] - original[1][1] * original[2][0]);
	inverse[0][1] = static_cast<double>(-(original[0][1] * original[2][2] - original[0][2] * original[2][1]));
	inverse[1][1] = static_cast<double>(original[0][0] * original[2][2] - original[0][2] * original[2][0]);
	inverse[2][1] = static_cast<double>(-(original[0][0] * original[2][1] - original[0][1] * original[2][0]));
	inverse[0][2] = static_cast<double>(original[0][1] * original[1][2] - original[0][2] * original[1][1]);
	inverse[1][2] = static_cast<double>(-(original[0][0] * original[1][2] - original[0][2] * original[1][0]));
	inverse[2][2] = static_cast<double>(original[0][0] * original[1][1] - original[0][1] * original[1][0]);
	//cofactor matrix�� ���ϰ� transpose �� ����, �� �������� double�� ����ȯ

	cout << "Inverse Matrix: " << endl;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << inverse[i][j] / detmat << " ";
		}
		cout << endl;
	}
	//����� ���� ���� transpose�� cofactor matrix�� ��İ����� ������ ��ø for���� �̿��Ͽ� ���
	return;
} //outputinverse �Լ� ����

double finddev(void) //��İ��� ���ϴ� �Լ�
{
	double dev = static_cast<double>((original[0][0] * ((original[1][1] * original[2][2]) - (original[1][2] * original[2][1]))) - (original[0][1] * ((original[1][0] * original[2][2]) - (original[1][2] * original[2][0]))) + (original[0][2] * ((original[1][0] * original[2][1]) - (original[1][1] * original[2][0]))));
	//original matrix�� ������ �̿��Ͽ� ��İ��� ���ϰ�, double�� ����ȯ

	return dev; //��İ��� ��ȯ
} //finddev�Լ� ����
