#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// 디코딩 클래스 선언
class decoding {
public:
	// decode 함수 선언
	void decode(const char* binary, const char* alphabet) {
		// fp1을 읽기, fp2를 쓰기로 파일 열기
		FILE* fp1 = NULL; 
		fopen_s(&fp1,binary, "rb");
		FILE* fp2 = NULL;
		fopen_s(&fp2,alphabet, "w");
		if (fp1 == NULL) {
			cout << binary<<"를 열 수 없습니다.";
			return;
		}
		if (fp2 == NULL) {
			cout << alphabet<<"를 열 수 없습니다.";
			return;
		}

		// 0 개수에 따라 알파벳 입력 (아스키 코드 이용)
		char read;
		int cnt = 0;
		while ((read = getc(fp1)) != EOF) {
			char alph;
			if (read == '0') {
				cnt++;
			}
			if(read=='1') {
				alph = cnt + 97;
				fputc(alph, fp2);
				cnt = 0;
			}
			if (cnt == 25) {
				alph = cnt + 97;
				fputc(alph, fp2);
				cnt = 0;
			}
		
		}
		// 열었던 파일 닫기
		fclose(fp1);
		fclose(fp2);
	}

	
};



int main() {

	// 클래스 불러오기 및 함수 실행
	decoding a;
	a.decode("binary.txt", "alphabet.txt");
	

	return 0;
}
