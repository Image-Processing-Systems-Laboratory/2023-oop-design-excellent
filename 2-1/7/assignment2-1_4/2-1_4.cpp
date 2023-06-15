#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class decode
{
private:
    char* binary; // binary.txt를 의미
    char* alphabet; // alphabet.txt를 의미
public:
    decode(const char* bfile, const char* afile) // 생성자. 인자로 두 개의 파일 이름을 받는다
    {
        binary = new char[strlen(bfile) + 1]; // 동적할당하여 저장
        strcpy(binary, bfile); // binary에 복사
        alphabet = new char[strlen(afile) + 1]; // 동적할당하여 저장
        strcpy(alphabet, afile); // alphabet에 복사
    }

    void decode_binary()
    {
        char c[20]; // alphabet.txt에 넣어줄 텍스트를 저장할 문자열
        int idx = 0; // 문자열 인덱스
        ifstream input; // 파일 입출력
        input.open(binary); // binary라는 이름의 파일 열기(binary.txt)
        if (input.is_open())
            while (!input.eof())
            {
                char str[500];
                input.getline(str, 500); // str에 binary.txt의 텍스트 받기
                int len = strlen(str); // 길이 구하기
                int count = 0;
                for (int i = 0; i < len; i++)
                {
                    if (count == 24 && str[i] == '0') // 만약에 0이 이미 24갠데 다음값도 0이라면
                    {
                        c[idx++] = 'z'; // 이는 z의 경우밖에 없으므로 z를 c에 넣어준다
                        count = 0; // count 초기화
                        continue;
                    }
                    if (str[i] == '1') // 만약에 1을 만나면
                    {
                        c[idx++] = 'a' + count; // 0개수에 따라 알파벳이 결정된다. 0개일때가 a이므로 'a'에 0 개수인 count를 더해준다
                        count = 0; // count 초기화
                        continue;
                    }
                    else // 1을 만나지 않으면
                        count++; // 0을 만났다는 것이므로 count에 1을 더해준다
                }
            }
        input.close();

        ofstream output(alphabet); // alphabet이라는 이름의 파일 열기(alphabet.txt)
        if (output.is_open())
        {
            for (int i = 0; i < idx; i++)
                output << c[i]; // c 값 output에 넣어주기
        }

        output.close();
    }

    ~decode() // 소멸자
    {
        delete[] binary;
        delete[] alphabet;
    }
};

int main()
{
    char str1[100] = "binary.txt";
    char str2[100] = "alphabet.txt";
    decode* de = new decode(str1, str2); // 객체 생성
    de->decode_binary();
    return 0;
}