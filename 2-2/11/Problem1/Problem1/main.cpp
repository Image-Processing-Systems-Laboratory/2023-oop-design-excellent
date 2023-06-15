#include "Array.h"

int main() {
	//사용자로부터 받은 입력을 저장 할 값
	char input[100001];
	//입력 (\n을 만날때 까지)
	cin.getline(input, 100001, '\n');
	//배열에 input을 인자로 주고 생성
	Array arr(input);
	while (true) {
		//입력
		cin.getline(input, 100001, '\n');
		//exit일 시 반복문 탈출
		if (!strncmp(input, "exit", 5))
			break;
		//arr일시
		if (!strncmp(input, "arr", 3)) {
			//index들을 저장 할 배열
			int t[100] = { 0, };
			//index를 문자열로 입력받을 때 쓸 배열
			char tmp[10] = { 0, };
			//index의 수
			int cnt = 0;
			//입력 문자열이 끝날떄 까지 반복(arr 제외)
			for (int i = 3; i < 100001 && input[i]; i++) {
				//[을 만날 시 index 저장
				if (input[i] == '[') {
					//tmp 문자열의 현재 위치를 저장할 변수
					int tmpCnt = 0;
					i++;
					//]을 만날때 까지 반복
					while (input[i] != ']') {
						//input의 숫자를 tmp에 문자열로 저장
						tmp[tmpCnt] = input[i];
						//위치 한칸 뒤로
						tmpCnt++;
						//위치 한칸 뒤로
						i++;
					}
					//index의 수 증가
					cnt++;
					//null문자를 마지막에 설정
					tmp[tmpCnt] = 0;
					//정수로 변환 후 배열에 저장
					t[cnt] = atoi(tmp);
				}
			}
			//구한 index들과 그 수를 인자로 배열에 전잘하여 출력
			arr.printData(t, cnt);
			//줄바꿈
			cout << endl;
		}
	}
	return 0;
}