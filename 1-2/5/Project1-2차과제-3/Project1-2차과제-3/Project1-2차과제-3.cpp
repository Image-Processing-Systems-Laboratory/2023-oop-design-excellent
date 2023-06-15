#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // ������� ����
#include <fstream>
#include <string.h>

using namespace std; // ǥ�� ���̺귯�� ���
/* cin���� �Լ����� �տ� ���ǵ� Ŭ������ ������
C++ ǥ�� ���̺귯�� �Լ��� �޾Ƶ��̰ڴٴ� ��*/

bool compare(char* pattern, char* filename) {
    // ���ϵ�ī�� ���ϰ� ���� �̸��� ���Ͽ� ��ġ�ϴ��� Ȯ���ϴ� bool�� �Լ��̴�. ��ġ�ϸ� 1�� ��ġ���� ������ 0�� ��ȯ�Ѵ�. ����Լ��� �̿��Ͽ� '?'��'*'�� ã���� ���� �Լ��� �ݺ�
    if (*pattern == NULL && *filename == NULL) {
        // ���ϰ� ���� �̸� ��� ���� �������� ���
        return 1;
    }
    if (*pattern == '*' && *(pattern + 1) != NULL && *filename == NULL) { // ����ó�� : *pattern�� '*'������ ���� �̸��� ���������� ��� 0�� ��ȯ�Ѵ�. 
        // ������ '*'�� �����ϰ�, ���� �̸��� ���������� ���
        return 0;
    }
    if (*pattern == '?' || *pattern == *filename) { // ���ݱ��� *pattern�� *filename�� ��Ұ� ��ġ�߰�, ������ ? �̸� �� ���� ��ҵ��� ���Ͽ� ������ ��ġ�ϸ� 1�� ��ȯ�Ѵ�. 
        // ���� ���ڿ� ���� �̸� ���ڰ� ��ġ�ϴ� ���� ���� ���ڰ� '?'�� ���
        return compare(pattern + 1, filename + 1);
    }
    if (*pattern == '*') {
        // ���ݱ��� ���ϰ� ������ ��Ұ� ��ġ�߰�, ���� ���ڰ� '*'�� ��� ��͸� �̿��Ͽ� *pattern�� *filename�� ��� NULL���� ������ ������ ��͸� �̿��� �� 1�� ��ȯ
        // ������ *pattern�� ���� ������ �ʾ����� ���� �̸��� ���������� ��쿡�� 0�� ��ȯ�Ѵ�(����ó��)
        return compare(pattern + 1, filename) || compare(pattern, filename + 1);
    }
    return 0; // �� ���� ��� ��� 0�� ��ȯ
}

int main() { // main �Լ� ����
    char filename[100]; // char�� ���� filname ���� filename�� �Է¹ޱ����� ���
    cout << "Input file name : ";
    cin >> filename;
    int count = 0; // int�� ���� count���� ������ ������ �Է¹ޱ� ���� ���
    cin >> count;
    char input[100][100]; // char�� 2�����迭 input ������ �Է¹ޱ� ���� ���
    for (int i = 0; i < count; i++) {
        cin >> input[i];
    }

    ifstream file1(filename); // filename�� ��ġ�ϴ� ���� ����
    if (!file1) { // filename�� ��ġ�ϴ� ������ ���°��
        cout << "������ �� �� �����ϴ�.";
        return 0;
    }
    char buffer[100]; // ���Ͽ��� ���پ� data�� ���� buffer, �����͸� ���ǿ� ������ result�� �����ϱ� ���� ����
    char result[1000][101]; // ������� ������ �迭
    int idx = 0; // ����� �迭�� �ε���
    while (!file1.eof()) { // ������ ���� �ƴҶ����� �ݺ�
        file1.getline(buffer, 100);
        // ���� ���� ��� �ٿ� ���ؼ�
        for (int i = 0; i < count; i++) {
            // �Էµ� ��� ���Ͽ� ���ؼ�
            if (compare(input[i], buffer)) {
                // ��ġ�ϴ� ��� �迭�� ����, compare�Լ��� ȣ���Ͽ� 1�� return �Ǹ� result�� buffer�� �����Ѵ�.
                strcpy(result[idx], buffer);
                idx++;
                break;
            }
        }
    }
    file1.close(); // ���� �ݱ�

    // �Էµ� ���� ������� ����� ��� �ٽ��ѹ� compare�Լ��� ȣ���Ͽ� ���� �Էµ� ���Ϻ��� �����
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < idx; j++) {
            if (compare(input[i], result[j])) {
                cout << result[j] << endl;
            }
        }
    }

    return 0; // 0�� ��ȯ
}