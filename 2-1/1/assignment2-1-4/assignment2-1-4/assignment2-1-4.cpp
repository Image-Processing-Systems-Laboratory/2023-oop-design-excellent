#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char  binary[1000] = { '0', }; // binary code 를 저장할 배열
    char Alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' }; // 알파벳을 저장할 배열
    int x = 0; // binary 배열의 크기를 저장할 변수
    int cnt = 0; // binary 배열의 인덱스를 저장할 변수
    int temp = 0; // 이전 0의 갯수를 저장할 변수
    ifstream fin;
    fin.open("binary.txt");
    if (fin.fail()) { // 파일이 없을 경우 에러 메시지 출력
        cout << "Error opening file" << endl;
        exit(1);
    }
    fin >> binary; // binary.txt 파일의 내용을 binary 배열에 저장
    while (1) { // binary 배열의 크기를 구함
        if (binary[x] == NULL) {
            break;
        }
        x++;
    }
    ofstream fout;
    fout.open("alphabet.txt");
    for (int i = 0; i < x; i++) { // binary 배열의 내용을 읽어서 알파벳으로 변환
        if (binary[cnt] == '1') {
            fout << Alphabet[cnt - temp];
            temp = cnt + 1;
        }
        if ((cnt - temp) == 25) { //Z 출력에 관한 예외처리
            fout << "Z";
            temp = cnt;
        }
        cnt++;
    }

    cout << "The file has been successfully created.";

    fin.close(); // 파일 닫기
    fout.close(); 

    return 0;
}
