#include "Array.h"
//배열의 디폴트 사이즈
#define DEFALTSIZE 10

//Array 클래스 정의부

//생성자
Array::Array(char* input) {
	//기본 크기로 배열 생성, 오류 검출
	datas = (IData**)calloc(sizeof(IData*), DEFALTSIZE);
	if (!datas)
		return;
	//입력이 끝날 때 까지
	while (*input) {
		//만약 10개를 채웠다면 크기를 키워 재할당
		if (cnt % 10 == 9) {
			size++;
			//할당, 오류 검출
			IData** tmp = (IData**)realloc(datas, sizeof(IData*) * DEFALTSIZE * size);
			if (!tmp)
				return;
			datas = tmp;
			
		}
		//공백을 만나면 무시
		if (*input == ' ') {
			input++;
			continue;
		}
		//배열일시
		if (*input == '[') {
			//새로운 배열을 생성하고, datas에 저장
			datas[cnt] = new Array(++input);
			//배열의 요소 갯수 증가
			cnt++;
			int tmpCnt = 1;
			//만난 [에 맞는 [를 찾을때 까지 반복(안의 값은 무시)
			while (true) {
				if (*input == '[') {
					tmpCnt++;
				}
				else if (*input == ']') {
					tmpCnt--;
				}
				input++;
				if (tmpCnt == 0)
					break;
			}
			continue;
		}
		//','를 만나면 무시
		if (*input == ',') {
			input++;
			continue;
		}
		//만약 끝에 도달했으면 반복문 탈출
		else if (*input == ']')
			break;
		else {//아니면 문자열 생성, 저장
			//문자열 클래스 생성, data에 저장
			datas[cnt] = new String(input);
			//배열의 요소 갯수 증가
			cnt++;
		}
	}
}
//소멸자
Array::~Array() {
	//저장된 요소들에 할당된 공간 해제
	for (int i = 0; i < cnt; i++) {
		delete datas[i];
	}
	//배열 해제
	free(datas);
}
//값 출력
void Array::printData(int *index, int cnt) {
	//만약 깊이가 0보다 작다면 값을 출력하고 종료
	if (cnt < 0) {
		printData();
		return;
	}
	//현재 배열의 index에 위치한 배열에 다음 인덱스와 깊이를 1 뺸 값을 인수로 전달하여 출력;
	datas[*index]->printData(index + 1, cnt - 1);
}

//배열의 모든 값 출력
void Array::printData() {
	//[출력
	cout << '[';
	//배열의 모든 요소의 printData 메소드 호출
	for (int i = 0; i < cnt; i++) {
		if (i) {
			//첫 요소가 아니면 , 을 출력
			cout << ", ";
		}
		//요소의 printData 메소드 호출
		datas[i]->printData();
	}
	//]출력
	cout << ']';
}