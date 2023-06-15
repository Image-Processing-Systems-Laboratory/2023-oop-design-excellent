#include<iostream>
#include<fstream>
#include<cstdlib>

//���ڿ��� ũ�⸦ ���� ����
#define STRSIZE 50

using namespace std;

int main() {
	//���� ����Ʈ�� ��� ������ ���� ���ڿ�
	char fileList[STRSIZE];
	
	//ã����� ������ �̸��� ��� 2���� ���� �迭
	char **files;

	//ã�� ������ ������ ���� ����
	int size;

	cout << "Input file name : ";
	//�Է�
	cin >> fileList;
	cin >> size;
	//ã�� ������ ������ŭ �������� char* �Ҵ�
	files = (char**)malloc(sizeof(char*) * size);
	if (!files)
		return 1;
	//������ ������ŭ �������� STRSIZE ũ�⸸ŭ �Ҵ�
	for (int i = 0; i < size; i++) {
		files[i]= (char*)malloc(sizeof(char) * STRSIZE);
		if (!files[i])
			return 1;
		//ã�� ���� �̸� �Է�
		cin >> files[i];
	}
	cout << endl;
	//Ž�� ����
	for (int i = 0; i < size; i++) {
		//���� ��Ʈ�� ����
		ifstream list(fileList);
		//��Ʈ�� ���� ���н� ����
		if (!list) {
			return 1;
		}
		//������ ������ Ž��
		while (!list.eof()) {
			//���� ���� ���Ͽ� ��� ã�� ������ �̸��� name�� ����
			char name[STRSIZE];
			list.getline(name, STRSIZE);
			//ã�� ������ �̸��� ���� ���ڿ��� ���� �ּҸ� input�� ����
			char* input = files[i];
			
			//ã�� ���ϰ� ���� name�� ����� ���� �̸��� ������ Ȯ��
			for (int j = 0, cnt = 0, tmp = 0; j < STRSIZE; j++) {

				//���� ������ Ž�������� ã�� ���Ͽ� �ش�Ǹ� �̸��� ����ϰ� �ݺ��� Ż��
				if (name[j] == 0 && input[cnt] == 0) {
					cout << name << endl;
					break;
				} 
				//���� �ش��� �ȵ� �� �ݺ��� Ż��
				else if(name[j] == 0 && input[cnt] != 0){
					break;
				}

				//���� ã�� �������� �Էµ� �̸��� Ž���ϴ� �� *�� �߰ߵǸ�
				if (input[cnt] == '*'){
					//* ���� ���ڰ� ������ ���� �̸��� ����ϰ� �ݺ��� Ż��
					if (input[cnt + 1] == 0) {
						cout << name << endl;
						break;
					}
					//* �������� ���ڰ� ���� �� ���� ���ں��� ã�� ���� ���� ���ڸ� �⺻������ ����
					else if (name[j] == input[cnt + 1]) {
						cnt += 2;
						tmp = cnt;
					}
				}
				//���� ã���� �ϴ� ������ �̸��� ���� ��ġ�� �شܵǴ� ���ڰ� ? �̰ų� �� ���� Ž������ ���ڰ� ������ ��
				else if (name[j] == input[cnt] || input[cnt] == '?') {
					//ã���� �ϴ� ���� �̸��� ���ڸ� ���� ���ڷ� �̵�
					cnt++;
				}					
				//���� �̸��� �ٸ��� �ݺ��� Ż��
				else {
					break;
				}
			}
		}
		//���� ��Ʈ�� ����
		list.close();
	}
	//ã�� ������ �̸��� ������ ������ ����
	for (int i = 0; i < size; i++) {
		free(files[i]);
	}
	free(files);

	//����
	return 0;
}