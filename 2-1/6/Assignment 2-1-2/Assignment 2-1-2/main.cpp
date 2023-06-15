#define _CRT_SEUCRE_NO_WARNINGS
#include <iostream>
using namespace std;

/*�ִܰŸ��� ã�� ���� �Լ����� ����*/
int find(int startN, int startM, int desN, int desM, int n, int m);
/*�̷�*/
char maze[31][31] = { 0 };
/*�������� �������� ���� ���� ���� �� ���� ���� �� + 1�� �ؼ� �Ÿ��� ���ϱ� ���� �������迭*/
int alreadyPassed[31][31] = { 0 };
/*���ΰ��� �Ʒ��ΰ��� ���������ΰ��� �������ΰ��� �����ֱ� ���� �迭*/
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
/*Ŭ���� ���� �迭�� ����ִ��� Ȯ���ϱ� ���� ����*/
int emptyIndex = 0;
/*���� �� ���� ��� �����ϴ� Ŭ����*/
class asd {
public:
	int x[100];
	int y[100];
	int xFront();
	int yFront();
	void xPop();
	void yPop();
	void xPush(int v);
	void yPush(int v);
	int empty();	/*�迭�� ����ִ��� Ȯ���ϱ� ���� �Լ� ���� ����*/
};
/*�迭�� ����ִ��� Ȯ���ϱ� ���� �Լ�*/
int asd::empty() {
	/*emptyIndex�� 0�̸� 1��ȯ - ����ִٴ� ��*/
	if (emptyIndex == 0) return 1;
	else return 0;
}
/*x�迭�� ù��° �ε��� �� return */
int asd::xFront() {
	return x[0];
}
/*y�迭�� ù��° �ε��� �� return */
int asd::yFront() {
	return y[0];
}
/*x�迭�� ù��° �ε��� �� ����*/
void asd::xPop() {
	for (int i = 0; i < 99; i++) {
		x[i] = x[i + 1];
	}
	emptyIndex--;
}
/*y�迭�� ù��° �ε��� �� ����*/
void asd::yPop() {
	for (int i = 0; i < 99; i++) {
		y[i] = y[i + 1];
	}
}
/*x�迭 ��ĭ�� �ڷ� �а� ù��° �ε����� ��� ���� �� ����*/
void asd::xPush(int v) {
	/*memmove�Լ��� ��ĭ�� �ڷ� �а� �迭�� ù��° �ε��� ���� push v*/
	memmove(x + 1, x, 100);
	x[0] = v;
	emptyIndex++;
}
/*y�迭 ��ĭ�� �ڷ� �а� ù��° �ε����� ��� ���� �� ����*/
void asd::yPush(int v) {
	/*memmove�Լ��� ��ĭ�� �ڷ� �а� �迭�� ù��° �ε��� ���� push v*/
	memmove(y + 1, y, 100);
	y[0] = v;
}
int main(void) {
	/*n�� ��, m�� ��*/
	int n = 0, m = 0;
	int cnt = 0;
	cin >> n >> m;
	/*�̷� ����*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	int sn = 0, sm = 0, dn = 0, dm = 0;
	cin >> sn >> sm >> dn >> dm;
	int startN = sn - 1;	//���� �� �ε���
	int startM = sm - 1;	//���� �� �ε���
	int desN = dn - 1;		//������ �� �ε���
	int desM = dm - 1;		//������ �� �ε���
	cnt = find(startN, startM, desN, desM, n, m);	//�ִܰŸ� ���ϱ� ���� �Լ�
	cout << cnt;		//�ִܰŸ� ���
	return 0;
}

/*�ִܰŸ��� ã�� ���� �Լ�*/
int find(int startN, int startM, int desN, int desM, int n, int m) {
	/*�������� node ��ü �ȿ� �ִ� �迭�� ����*/
	asd node;
	node.xPush(startN);
	node.yPush(startM);
	/*�������� 1�� ����*/
	alreadyPassed[startN][startM] = 1;
	/*��ã�� ����*/
	while (!node.empty()) {
		/*���� ��ǥ�� ã�� ���� curN�� curM*/
		int curN = 0;
		curN = node.xFront(); // node ��ü ���� x�迭�� ù��° ��
		int curM = 0;
		curM = node.yFront(); // node ��ü ���� y�迭�� ù��° ��
		node.xPop(); //curN���� ù��° �� �Ѱ��ְ� �� �� ����
		node.yPop(); //curM���� ù��° �� �Ѱ��ְ� �� �� ����
		/*���� ���� ��ǥ�� �������� ������ return*/
		if (curN == desN && curM == desM) return alreadyPassed[curN][curM];
		/*���� ��ǥ �������� �����̱� �����ϴ� �ݺ���*/
		for (int i = 0; i < 4; i++) {
			/*���� ��ǥ�� ������ �� �ִ� ���� ã�� �� ���� ��� ���� nnn,mmm�� ����*/
			/*n�� ��� ��� ���õ� ��, m�� ��� ���� ���õ� ��*/
			int nnn = curN + moveX[i];
			int mmm = curM + moveY[i];
			/*���� ������ ���� �̷� ������ ����� continue*/
			if (nnn < 0 || mmm < 0 || nnn >= n || mmm >= m) continue;
			/*������ ���� ���̸� continue*/
			if (maze[nnn][mmm] == '1') continue;
			/*�ѹ� ���� ���̸� continue*/
			if (alreadyPassed[nnn][mmm] != 0) continue;
			/*ó�� ��ƺ��� ���̸� ���� �������� �ִܰŸ� + 1*/
			alreadyPassed[nnn][mmm] = alreadyPassed[curN][curM] + 1;
			for (int z = 0; z < n; z++) {
				for (int f = 0; f < m; f++) {
					cout << alreadyPassed[z][f] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			/*�� �� node��ü �ȿ� x�迭�� y�迭 ù��° �ε����� �����ϰ� �迭 ����
			������ ��ĭ�� �ڷ� �и�*/
			node.xPush(nnn);
			node.yPush(mmm);
		}
	}
}