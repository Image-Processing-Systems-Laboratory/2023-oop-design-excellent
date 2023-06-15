#include <iostream>
using namespace std;

char* my_strtok(char* str) 
{
    static char* ptr; // ���� ������ ����
    if (str != NULL) // str�� NULL�� �ƴϸ�
    {
        ptr = str; // ptr�� str�� ����Ŵ
    }
    char* token_start = ptr; // token�� ���� ��ġ�� ptr�� ������
    while (*ptr != '\0') // ptr�� ����Ű�� ���� NULL�� �ƴϸ�
    {
        if (*ptr == '@' || *ptr == '.') // ptr�� ����Ű�� ���� @ or . �� ���
        {
            *ptr = '\0'; // ptr�� ����Ű�� �� NULL�� ����
            ptr++; // �̵�
            return token_start; // token ���� ��ġ ��ȯ
        }
        ptr++; // ���� ��ġ �̵�
    }
    if (token_start != ptr) // token�� ������
    {
        return token_start; //token ���� ��ġ ��ȯ
    }
    return NULL; // ������ NULL ��ȯ
}

int main() 
{
    // �̸��� �Է� ����
    char email[100];
    cout << "Enter an email address: ";
    cin >> email;

    char* token = my_strtok(email); // ���ڿ� ��ūȭ �ؼ� ù ��° ��ū�� ���� ��ġ ��ȯ
    while (token != NULL) // ��ȯ�� ���� NULL�� �ƴϸ�
    {
        cout << token << endl; // ��ū ���
        token = my_strtok(NULL); // ���� ��ū ���� ��ġ ��ȯ
    }
    return 0;
}