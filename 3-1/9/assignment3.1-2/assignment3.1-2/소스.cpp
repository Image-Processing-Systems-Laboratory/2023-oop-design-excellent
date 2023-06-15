#include <iostream>
using namespace std;
char* my_strtok(char* str) {
    //����ƽ ������ ����� ��ȯ�� ��ġ�� ���
    static char* p = nullptr;
    //�Ű������� ���� str1�� null�� �ƴϸ�
    if (str != nullptr) {
        p = str;
    }
    //p�� null�̸�
    if (p == nullptr) {
        return nullptr;
    }
    
    char* token = p;
    //'@', '.' �� ������� �� ������ �ι��ڸ� ���� �� ���� ��ġ�� ����Ű�� ����
    while (*p != '\0') {
        if (*p == '@' || *p == '.') {
            *p = '\0';
            p++;
            break;
        }
        p++;
    }
    if (*token == '\0') { //��ū�� �� ���ڿ��̸� 
        return nullptr;
    }
    return token;
}

int main() {
    char email[100];
    cout << "�̸����� �Է��ϼ���: ";
    cin >> email;

    char* token; 
    //���ڿ��� �����Ͽ�  null�� �ƴҶ����� �ݺ��ذ��� ���
    for (token = my_strtok(email); token != nullptr; token = my_strtok(nullptr)) {
        cout << token << endl;
    }

    return 0;
}