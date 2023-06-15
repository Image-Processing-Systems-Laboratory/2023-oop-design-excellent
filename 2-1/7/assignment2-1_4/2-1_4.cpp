#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class decode
{
private:
    char* binary; // binary.txt�� �ǹ�
    char* alphabet; // alphabet.txt�� �ǹ�
public:
    decode(const char* bfile, const char* afile) // ������. ���ڷ� �� ���� ���� �̸��� �޴´�
    {
        binary = new char[strlen(bfile) + 1]; // �����Ҵ��Ͽ� ����
        strcpy(binary, bfile); // binary�� ����
        alphabet = new char[strlen(afile) + 1]; // �����Ҵ��Ͽ� ����
        strcpy(alphabet, afile); // alphabet�� ����
    }

    void decode_binary()
    {
        char c[20]; // alphabet.txt�� �־��� �ؽ�Ʈ�� ������ ���ڿ�
        int idx = 0; // ���ڿ� �ε���
        ifstream input; // ���� �����
        input.open(binary); // binary��� �̸��� ���� ����(binary.txt)
        if (input.is_open())
            while (!input.eof())
            {
                char str[500];
                input.getline(str, 500); // str�� binary.txt�� �ؽ�Ʈ �ޱ�
                int len = strlen(str); // ���� ���ϱ�
                int count = 0;
                for (int i = 0; i < len; i++)
                {
                    if (count == 24 && str[i] == '0') // ���࿡ 0�� �̹� 24���� �������� 0�̶��
                    {
                        c[idx++] = 'z'; // �̴� z�� ���ۿ� �����Ƿ� z�� c�� �־��ش�
                        count = 0; // count �ʱ�ȭ
                        continue;
                    }
                    if (str[i] == '1') // ���࿡ 1�� ������
                    {
                        c[idx++] = 'a' + count; // 0������ ���� ���ĺ��� �����ȴ�. 0���϶��� a�̹Ƿ� 'a'�� 0 ������ count�� �����ش�
                        count = 0; // count �ʱ�ȭ
                        continue;
                    }
                    else // 1�� ������ ������
                        count++; // 0�� �����ٴ� ���̹Ƿ� count�� 1�� �����ش�
                }
            }
        input.close();

        ofstream output(alphabet); // alphabet�̶�� �̸��� ���� ����(alphabet.txt)
        if (output.is_open())
        {
            for (int i = 0; i < idx; i++)
                output << c[i]; // c �� output�� �־��ֱ�
        }

        output.close();
    }

    ~decode() // �Ҹ���
    {
        delete[] binary;
        delete[] alphabet;
    }
};

int main()
{
    char str1[100] = "binary.txt";
    char str2[100] = "alphabet.txt";
    decode* de = new decode(str1, str2); // ��ü ����
    de->decode_binary();
    return 0;
}