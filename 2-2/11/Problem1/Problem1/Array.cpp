#include "Array.h"
//�迭�� ����Ʈ ������
#define DEFALTSIZE 10

//Array Ŭ���� ���Ǻ�

//������
Array::Array(char* input) {
	//�⺻ ũ��� �迭 ����, ���� ����
	datas = (IData**)calloc(sizeof(IData*), DEFALTSIZE);
	if (!datas)
		return;
	//�Է��� ���� �� ����
	while (*input) {
		//���� 10���� ä���ٸ� ũ�⸦ Ű�� ���Ҵ�
		if (cnt % 10 == 9) {
			size++;
			//�Ҵ�, ���� ����
			IData** tmp = (IData**)realloc(datas, sizeof(IData*) * DEFALTSIZE * size);
			if (!tmp)
				return;
			datas = tmp;
			
		}
		//������ ������ ����
		if (*input == ' ') {
			input++;
			continue;
		}
		//�迭�Ͻ�
		if (*input == '[') {
			//���ο� �迭�� �����ϰ�, datas�� ����
			datas[cnt] = new Array(++input);
			//�迭�� ��� ���� ����
			cnt++;
			int tmpCnt = 1;
			//���� [�� �´� [�� ã���� ���� �ݺ�(���� ���� ����)
			while (true) {
				if (*input == '[') {
					tmpCnt++;
				}
				else if (*input == ']') {
					tmpCnt--;
				}
				input++;
				if (tmpCnt == 0)
					break;
			}
			continue;
		}
		//','�� ������ ����
		if (*input == ',') {
			input++;
			continue;
		}
		//���� ���� ���������� �ݺ��� Ż��
		else if (*input == ']')
			break;
		else {//�ƴϸ� ���ڿ� ����, ����
			//���ڿ� Ŭ���� ����, data�� ����
			datas[cnt] = new String(input);
			//�迭�� ��� ���� ����
			cnt++;
		}
	}
}
//�Ҹ���
Array::~Array() {
	//����� ��ҵ鿡 �Ҵ�� ���� ����
	for (int i = 0; i < cnt; i++) {
		delete datas[i];
	}
	//�迭 ����
	free(datas);
}
//�� ���
void Array::printData(int *index, int cnt) {
	//���� ���̰� 0���� �۴ٸ� ���� ����ϰ� ����
	if (cnt < 0) {
		printData();
		return;
	}
	//���� �迭�� index�� ��ġ�� �迭�� ���� �ε����� ���̸� 1 �A ���� �μ��� �����Ͽ� ���;
	datas[*index]->printData(index + 1, cnt - 1);
}

//�迭�� ��� �� ���
void Array::printData() {
	//[���
	cout << '[';
	//�迭�� ��� ����� printData �޼ҵ� ȣ��
	for (int i = 0; i < cnt; i++) {
		if (i) {
			//ù ��Ұ� �ƴϸ� , �� ���
			cout << ", ";
		}
		//����� printData �޼ҵ� ȣ��
		datas[i]->printData();
	}
	//]���
	cout << ']';
}