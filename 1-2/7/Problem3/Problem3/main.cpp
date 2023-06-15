#include<iostream>
#include<fstream>
#include<cstdlib>

//문자열의 크기를 사전 지정
#define STRSIZE 50

using namespace std;

int main() {
	//파일 리스트가 담긴 파일을 담을 문자열
	char fileList[STRSIZE];
	
	//찾고싶은 파일의 이름을 담는 2차원 문자 배열
	char **files;

	//찾을 파일의 개수를 담을 변수
	int size;

	cout << "Input file name : ";
	//입력
	cin >> fileList;
	cin >> size;
	//찾을 파일의 개수만큼 힙영역에 char* 할당
	files = (char**)malloc(sizeof(char*) * size);
	if (!files)
		return 1;
	//파일의 개수만큼 힙영역에 STRSIZE 크기만큼 할당
	for (int i = 0; i < size; i++) {
		files[i]= (char*)malloc(sizeof(char) * STRSIZE);
		if (!files[i])
			return 1;
		//찾을 파일 이름 입력
		cin >> files[i];
	}
	cout << endl;
	//탐색 시작
	for (int i = 0; i < size; i++) {
		//파일 스트림 생성
		ifstream list(fileList);
		//스트림 생성 실패시 종료
		if (!list) {
			return 1;
		}
		//파일의 끝까지 탐색
		while (!list.eof()) {
			//한줄 한줄 파일에 담긴 찾을 파일의 이름을 name에 저장
			char name[STRSIZE];
			list.getline(name, STRSIZE);
			//찾을 파일의 이름을 담은 문자열의 시작 주소를 input에 저장
			char* input = files[i];
			
			//찾을 파일과 현재 name에 저장된 파일 이름이 같은지 확인
			for (int j = 0, cnt = 0, tmp = 0; j < STRSIZE; j++) {

				//만약 끝까지 탐색했을때 찾을 파일에 해당되면 이름을 출력하고 반복문 탈출
				if (name[j] == 0 && input[cnt] == 0) {
					cout << name << endl;
					break;
				} 
				//만약 해당이 안될 시 반복문 탈출
				else if(name[j] == 0 && input[cnt] != 0){
					break;
				}

				//만약 찾을 파일으로 입력된 이름을 탐색하던 중 *가 발견되면
				if (input[cnt] == '*'){
					//* 다음 글자가 없으면 파일 이름을 출력하고 반복문 탈출
					if (input[cnt + 1] == 0) {
						cout << name << endl;
						break;
					}
					//* 다음에도 글자가 있을 시 다음 글자부터 찾기 위해 다음 글자를 기본값으로 설정
					else if (name[j] == input[cnt + 1]) {
						cnt += 2;
						tmp = cnt;
					}
				}
				//만약 찾고자 하는 파일의 이름의 현재 위치에 해단되는 글자가 ? 이거나 와 지금 탐색중인 글자가 같거을 때
				else if (name[j] == input[cnt] || input[cnt] == '?') {
					//찾고자 하는 파일 이름을 글자를 다음 글자로 이동
					cnt++;
				}					
				//파일 이름이 다를시 반복문 탈출
				else {
					break;
				}
			}
		}
		//파일 스트림 해제
		list.close();
	}
	//찾을 파일의 이름을 저장한 공간을 해제
	for (int i = 0; i < size; i++) {
		free(files[i]);
	}
	free(files);

	//종료
	return 0;
}