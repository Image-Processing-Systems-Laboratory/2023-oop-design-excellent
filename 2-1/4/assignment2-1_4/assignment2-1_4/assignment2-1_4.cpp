#include <iostream>
#include <fstream>

using namespace std;

class Decoding {
private:
    ifstream binaryFile; // binary.txt 파일을 읽기 위한 ifstream 객체
    ofstream alphabetFile; // alphabet.txt 파일을 쓰기 위한 ofstream 객체
    char alphabet[100]; // 알파벳으로 변환한 결과를 저장할 배열
    int zero_count = 0; // 연속으로 나온 0의 개수
    int i = 0; // alphabet 배열의 인덱스

public:
    Decoding(string binaryFileName, string alphabetFileName) {
        // binary.txt 파일 열기
        binaryFile.open(binaryFileName);

        // binary파일 열기에 실패했을 때
        if (!binaryFile.is_open()) {
            cout<<"Error opening binary.txt";
        }

        // alphabet.txt 파일 열기
        alphabetFile.open(alphabetFileName);

        // alphabet 파일 열기에 실패했을 때
        if (!alphabetFile.is_open()) {
            cout<<"Error opening alphabet.txt";
        }
    }

    void decoding() {
        // 파일에서 0 또는 1을 하나씩 읽어서 알파벳으로 변환
        char binaryChar;
        while (binaryFile.get(binaryChar)) {
            //0이 나오면 0의 개수를 +1하고 다음 글자로 넘어가기, 0이 25번 나오면 z로 디코딩
            if (binaryChar == '0') {
                zero_count++;
                if (zero_count == 25) {
                    char alphabetChar = 'z';
                    zero_count = 0;
                    alphabet[i++] = alphabetChar;
                }
            }
            //1이 나오면 그전까지 0이 나왔던 개수를 통해 알바펫으로 디코딩
            else if (binaryChar == '1') {
                char alphabetChar = 97 + zero_count; //a ASCII 97
                zero_count = 0;
                alphabet[i++] = alphabetChar;
            }
            else {
                // 0 과 1 이외의 문자가 나올 때
                cout<<("Error: invalid character");
            }
        }
        alphabet[i++] = '\0';

        // 알파벳으로 변환한 결과를 alphabet.txt 파일에 저장
        alphabetFile.write(alphabet, i);
        cout << endl<<"conversion complete";
    }

    Decoding() {
        // 파일 닫기
        binaryFile.close();
        alphabetFile.close();
    }
};

int main() {

    Decoding converter("binary.txt", "alphabet.txt");
    converter.decoding();

    return 0;
}




