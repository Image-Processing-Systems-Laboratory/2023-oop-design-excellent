#include <iostream>
#include <cmath>      //sin, cos���� ����ϱ����� sin(),cos()�Լ��� �����ϴ� ������� ����

using namespace std;

int main()
{
	int degrees;   //������ �Է¹޾� ������ ����
	double x, y, z;   //�Է¹��� x, y, z��ǥ
	double arr[3];    //����� ������ �迭
	double pi = 3.14;
	double radian = pi / 180;

	cout << "Degrees: ";
	cin >> degrees;

	cout << "Coordinate: ";
	cin >> x >> y >> z;

	cout << endl;

	arr[0] = x * (-1) * cos(degrees * radian) + y * sin(degrees * radian);  //��Ľ� ���� ��� z�� ������ ������� z�� �׻� 0�� ����
	arr[1] = x * sin(degrees * radian) + y * cos(degrees * radian);
	arr[2] = 0;     //��� T�� 3�� ������ ��� 0�̹Ƿ� ��İ��� ����� 3�� 1�� ������ �׻� 0�� ����

	for (int i = 0; i < 3; i++)  //��°��� ����Ͽ� �����
	{
		cout << arr[i] << " ";
	}
}    