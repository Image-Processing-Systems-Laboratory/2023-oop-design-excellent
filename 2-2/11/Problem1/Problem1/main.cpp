#include "Array.h"

int main() {
	//����ڷκ��� ���� �Է��� ���� �� ��
	char input[100001];
	//�Է� (\n�� ������ ����)
	cin.getline(input, 100001, '\n');
	//�迭�� input�� ���ڷ� �ְ� ����
	Array arr(input);
	while (true) {
		//�Է�
		cin.getline(input, 100001, '\n');
		//exit�� �� �ݺ��� Ż��
		if (!strncmp(input, "exit", 5))
			break;
		//arr�Ͻ�
		if (!strncmp(input, "arr", 3)) {
			//index���� ���� �� �迭
			int t[100] = { 0, };
			//index�� ���ڿ��� �Է¹��� �� �� �迭
			char tmp[10] = { 0, };
			//index�� ��
			int cnt = 0;
			//�Է� ���ڿ��� ������ ���� �ݺ�(arr ����)
			for (int i = 3; i < 100001 && input[i]; i++) {
				//[�� ���� �� index ����
				if (input[i] == '[') {
					//tmp ���ڿ��� ���� ��ġ�� ������ ����
					int tmpCnt = 0;
					i++;
					//]�� ������ ���� �ݺ�
					while (input[i] != ']') {
						//input�� ���ڸ� tmp�� ���ڿ��� ����
						tmp[tmpCnt] = input[i];
						//��ġ ��ĭ �ڷ�
						tmpCnt++;
						//��ġ ��ĭ �ڷ�
						i++;
					}
					//index�� �� ����
					cnt++;
					//null���ڸ� �������� ����
					tmp[tmpCnt] = 0;
					//������ ��ȯ �� �迭�� ����
					t[cnt] = atoi(tmp);
				}
			}
			//���� index��� �� ���� ���ڷ� �迭�� �����Ͽ� ���
			arr.printData(t, cnt);
			//�ٹٲ�
			cout << endl;
		}
	}
	return 0;
}