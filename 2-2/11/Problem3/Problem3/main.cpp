#include"CSVLoader.h"

int main() {

	//�ν��Ͻ� ���� ����
	CSVLoader csv("test.txt");
	//����� ������ ���
	csv.print();

	//����� �����Ϳ� ���ϱ� ���� �������� �ּ�, ��, ���� ũ�⸦ ����
	float** data = csv.getData();
	int col = csv.getCols();
	int row = csv.getRows();

	cout << endl;
	//���� ũ�⸸ŭ �ݺ�
	for (int i = 0; i < col; i++) {
		//���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < row; j++) {
			//ù��° �����Ͱ� �ƴ� ��
			if (j)
				//, ���
				cout << ", ";
			//�� ���
			cout << data[i][j];
		}
		//�� �ٲ�
		cout << endl;
	}

}