#include"CSVLoader.h"
using namespace std;

int main()
{
	char filename[20] = {};    // ����ڿ��� parse �� ������ �̸��� �Է� ����
	cin >> filename;
	CSVLoader load;               // Ŭ���� ����
	load.parse(filename);         // ����ڰ� ���ϴ� ������ �����м���
	load.print();                 // �����м� �� ������ �����
	cout << load.getRows() << ' ' << load.getCols() << endl;  // ���� �м��� ������ ��� �� ���
}