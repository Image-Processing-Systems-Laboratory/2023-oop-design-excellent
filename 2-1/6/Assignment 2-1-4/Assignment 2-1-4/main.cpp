#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*Ŭ���� ����*/
class Decode {
public:
	/*��� �Լ� ���� ����*/
	void read_file(ifstream& readFile);
};

/*DecodeŬ���� ���� �Լ�*/
void Decode::read_file(ifstream& readFile) {
	char c;
	/*���ĺ��� �����ϱ� ���� �迭*/
	char str[100];
	int i = 0;
	int cnt = 0;
	/*���� ������ ����*/
	while (!readFile.eof()) {
		/*�� ���ھ� ����*/
		readFile.get(c);
		/*���� c�� 0�̸� cnt++*/
		if (c == '0') { 
			cnt++; 
			/*�ص��ߴµ� z�ϰ��� '1'�� ���� Ư�� ���̽� �̹Ƿ� ���� ����*/
			if (cnt == 25) {
				str[i++] = 'z';
				cnt = 0;
			}
		}
		/*c�� 1�̸� str�迭�� 0�� ���� + ������ �ƽ�Ű�ڵ带 ������ ���ϴ� ���ĺ� ����*/
		if (c == '1') {
			str[i++] = cnt + 97;
			/*�ѹ� 1�� ������ 0���� �ʱ�ȭ*/
			cnt = 0;
		}
		/*�ѹ� �ݺ����� ���� �ʱ�ȭ*/
		c = 0;
	}
	/*���ڿ��� ���� �˸��� ���� �ι���*/
	str[i] = '\0';
	ofstream writeFile;
	/*"alpha.txt" ���� ���� �ϰ� ��*/
	writeFile.open("alpha.txt");
	/*������ �� ������ no!! ���*/
	if (!writeFile) cout << "no!!" << endl;
	/*���Ͽ� ���ڿ� �� readFile.eof()�Լ��� ����ϴ� �߰��� �ѹ����� �� ���Ƽ�
	a�� ����ǹǷ� ���� ���ڿ��� ���̺��� �� ���� ���� ���ڿ��� ���Ͽ� ��*/
	writeFile.write(str, strlen(str));
	/*���� ����*/
	writeFile.close();
}

int main(void) {
	ifstream readFile;
	/*decode ��ü ����*/
	Decode decode;
	/*"binary.txt ���� ����"*/
	readFile.open("binary.txt");
	/*���� �ȿ����� no!! ���*/
	if (!readFile) cout << "no!!" << endl;
	/*decode ��ü�� ����Լ��� ����*/
	decode.read_file(readFile);
	/*���� ����*/
	readFile.close();
	return 0;
}