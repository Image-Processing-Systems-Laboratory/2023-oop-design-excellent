#include <iostream>

using namespace std;

int main() {
	string inputF, inputS;
	int compare[100];
	int complete[100];
	int cnt = 0;
	int compareSize = 0, completeSize = 0;

	bool isDone = false;
	
	//1. �迭�� �Է¹ޱ�
	// compare : �� input�� ��ģ �迭 compareSize : �迭�� ����
	cout << "please give two integer : ";
	cin >> inputF >> inputS;

	for (int i = 0; i < inputF.size(); i++) {
		compare[i] = inputF[i] - '0';
		compareSize++;
	}

	int j = 0;
	for (int i = compareSize; j < inputS.size(); i++) {
		compare[i] = inputS[j] - '0';
		j++;
		compareSize++;
	}
	
	//2. Ž���ϴ� ���ڰ� �� ���� ���� ������ � �����ϴ��� ����



	for (int i = 0; i < compareSize; i++) {

		//2-1. �ռ� ���߾����� �˻�
		for (int k = 0; k < completeSize; k++) {
			if (complete[k] == compare[i]) isDone = true;
		}

		//2-3. �ռ� ���߾����� SKIP
		if (isDone == false) {
			for (int j = i; j < compareSize; j++) {
				if (compare[i] == compare[j]) {
					cnt++;
					complete[i] = compare[i];
					completeSize++;
				}
			}

			//2-1. ���ϴ� ����, count ���
			cout << compare[i] << cnt;
		}

		isDone = false;
		cnt = 0;
	}

	return 0;
}