#include <iostream>
using namespace std;

char* my_strtok(char* str) 
{
    static char* pnext; // 다음 번지를 저장할 변수
    static int callcheck = 1;  // 함수가 처음 호출되었는지 확인하는 변수

    if (str != nullptr) // str이 nullptr이 아니면
    {
        if (*str == '\0') // 빈 문자열일 경우 
        {  
            cout << "error" << endl;
            return nullptr;
        }
        if (*str == '@' || *str == '.') // @ , . 으로 시작하는 경우
        {
            cout << "error" << endl;
            return nullptr;
        }

        const char* my_strlen = str; 
        while (*(my_strlen + 1) != '\0') // 총 문자열 개수
            ++my_strlen;
        if (*my_strlen == '@' || *my_strlen == '.') // @, . 으로 끝나는 경우
        {
            cout << "error" << endl;
            return nullptr;
        }

        const char* dotcheck = str;
        while (*(dotcheck + 1) != '\0')
        {
            if (*dotcheck == '.' && *(dotcheck + 1) == '.') // .. 일때
            {
                cout << "error" << endl;
                return nullptr;
            }
            else if (*dotcheck == '@' && *(dotcheck + 1) == '.') // @. 일때
            {
                cout << "error" << endl;
                return nullptr;
            }
            else if (*dotcheck == '.' && *(dotcheck + 1) == '@') // .@ 일때
            {
                cout << "error" << endl;
                return nullptr;
            }
            dotcheck++;
        }
        int Whelkcount = 0; // @ 개수 확인 
        const char* Whelkcheck = str;
        for (; *Whelkcheck != '\0'; ++Whelkcheck)        
            if (*Whelkcheck == '@') // @ 일 때 개수 증가          
                ++Whelkcount;                  
        if (Whelkcount != 1) // @이 한개가 아니면 
        {
            cout << "error" << endl;
            return nullptr;
        }

        pnext = str; // 다음 시작 위치
        callcheck = 0; // 처음 호출이 아니므로 0

    }
    else if (pnext == nullptr) // 다음이 빈 문자열인 경우 
        return nullptr;  

    char* pstart = pnext;  // 현재 토큰의 시작 번지
    char* charcheck = pstart;  // 현재 문자 번지를 저장할 변수
    while (*charcheck != '\0')   // 널 문자가 오기전까지 
    {
        if (*charcheck == '@' || *charcheck == '.') // @ , . 인 경우
        {          
            *charcheck = '\0';  // 현재 문자를 널 문자로   
            pnext = charcheck + 1; // 다음 시작 번지를 @, .의 다음 번지로        
            return pstart; // 현재 시작 번지 반환
        }
        charcheck++; // 다음 번지로 이동
    }
    pnext = nullptr; // 다음 번지 nullptr
    return pstart;  // 현재 번지 반환
}

int main() 
{
    char inputmail[1000]; // 메일 변수
    cin >> inputmail; // 메일 입력
   
    char* token; // 메일 쪼개기

    token = my_strtok(inputmail);
    while (token != nullptr) 
    {
        cout << token << endl;
        token = my_strtok(nullptr);
    }
    return 0;
}
