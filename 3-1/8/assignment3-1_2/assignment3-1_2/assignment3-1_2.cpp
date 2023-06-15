#include <iostream>
using namespace std;

char* my_strtok(char* str) 
{
    static char* pnext; // ���� ������ ������ ����
    static int callcheck = 1;  // �Լ��� ó�� ȣ��Ǿ����� Ȯ���ϴ� ����

    if (str != nullptr) // str�� nullptr�� �ƴϸ�
    {
        if (*str == '\0') // �� ���ڿ��� ��� 
        {  
            cout << "error" << endl;
            return nullptr;
        }
        if (*str == '@' || *str == '.') // @ , . ���� �����ϴ� ���
        {
            cout << "error" << endl;
            return nullptr;
        }

        const char* my_strlen = str; 
        while (*(my_strlen + 1) != '\0') // �� ���ڿ� ����
            ++my_strlen;
        if (*my_strlen == '@' || *my_strlen == '.') // @, . ���� ������ ���
        {
            cout << "error" << endl;
            return nullptr;
        }

        const char* dotcheck = str;
        while (*(dotcheck + 1) != '\0')
        {
            if (*dotcheck == '.' && *(dotcheck + 1) == '.') // .. �϶�
            {
                cout << "error" << endl;
                return nullptr;
            }
            else if (*dotcheck == '@' && *(dotcheck + 1) == '.') // @. �϶�
            {
                cout << "error" << endl;
                return nullptr;
            }
            else if (*dotcheck == '.' && *(dotcheck + 1) == '@') // .@ �϶�
            {
                cout << "error" << endl;
                return nullptr;
            }
            dotcheck++;
        }
        int Whelkcount = 0; // @ ���� Ȯ�� 
        const char* Whelkcheck = str;
        for (; *Whelkcheck != '\0'; ++Whelkcheck)        
            if (*Whelkcheck == '@') // @ �� �� ���� ����          
                ++Whelkcount;                  
        if (Whelkcount != 1) // @�� �Ѱ��� �ƴϸ� 
        {
            cout << "error" << endl;
            return nullptr;
        }

        pnext = str; // ���� ���� ��ġ
        callcheck = 0; // ó�� ȣ���� �ƴϹǷ� 0

    }
    else if (pnext == nullptr) // ������ �� ���ڿ��� ��� 
        return nullptr;  

    char* pstart = pnext;  // ���� ��ū�� ���� ����
    char* charcheck = pstart;  // ���� ���� ������ ������ ����
    while (*charcheck != '\0')   // �� ���ڰ� ���������� 
    {
        if (*charcheck == '@' || *charcheck == '.') // @ , . �� ���
        {          
            *charcheck = '\0';  // ���� ���ڸ� �� ���ڷ�   
            pnext = charcheck + 1; // ���� ���� ������ @, .�� ���� ������        
            return pstart; // ���� ���� ���� ��ȯ
        }
        charcheck++; // ���� ������ �̵�
    }
    pnext = nullptr; // ���� ���� nullptr
    return pstart;  // ���� ���� ��ȯ
}

int main() 
{
    char inputmail[1000]; // ���� ����
    cin >> inputmail; // ���� �Է�
   
    char* token; // ���� �ɰ���

    token = my_strtok(inputmail);
    while (token != nullptr) 
    {
        cout << token << endl;
        token = my_strtok(nullptr);
    }
    return 0;
}
