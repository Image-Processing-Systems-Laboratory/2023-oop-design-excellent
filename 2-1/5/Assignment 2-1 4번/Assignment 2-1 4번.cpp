#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// ���ڵ� Ŭ���� ����
class decoding {
public:
	// decode �Լ� ����
	void decode(const char* binary, const char* alphabet) {
		// fp1�� �б�, fp2�� ����� ���� ����
		FILE* fp1 = NULL; 
		fopen_s(&fp1,binary, "rb");
		FILE* fp2 = NULL;
		fopen_s(&fp2,alphabet, "w");
		if (fp1 == NULL) {
			cout << binary<<"�� �� �� �����ϴ�.";
			return;
		}
		if (fp2 == NULL) {
			cout << alphabet<<"�� �� �� �����ϴ�.";
			return;
		}

		// 0 ������ ���� ���ĺ� �Է� (�ƽ�Ű �ڵ� �̿�)
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
		// ������ ���� �ݱ�
		fclose(fp1);
		fclose(fp2);
	}

	
};



int main() {

	// Ŭ���� �ҷ����� �� �Լ� ����
	decoding a;
	a.decode("binary.txt", "alphabet.txt");
	

	return 0;
}
