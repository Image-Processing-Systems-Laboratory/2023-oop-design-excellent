#include <iostream>

using namespace std;

int main() {
	string inputF, inputS;
	int compare[100];
	int complete[100];
	int cnt = 0;
	int compareSize = 0, completeSize = 0;

	bool isDone = false;
	
	//1. 배열에 입력받기
	// compare : 두 input을 합친 배열 compareSize : 배열의 길이
	cout << "please give two integer : ";
	cin >> inputF >> inputS;

	for (int i = 0; i < inputF.size(); i++) {
		compare[i] = inputF[i] - '0';
		compareSize++;
	}

	int j = 0;
	for (int i = compareSize; j < inputS.size(); i++) {
		compare[i] = inputS[j] - '0';
		j++;
		compareSize++;
	}
	
	//2. 탐색하는 글자가 그 글자 이하 순번에 몇개 존재하는지 세기



	for (int i = 0; i < compareSize; i++) {

		//2-1. 앞서 비교했었는지 검사
		for (int k = 0; k < completeSize; k++) {
			if (complete[k] == compare[i]) isDone = true;
		}

		//2-3. 앞서 비교했었으면 SKIP
		if (isDone == false) {
			for (int j = i; j < compareSize; j++) {
				if (compare[i] == compare[j]) {
					cnt++;
					complete[i] = compare[i];
					completeSize++;
				}
			}

			//2-1. 비교하는 글자, count 출력
			cout << compare[i] << cnt;
		}

		isDone = false;
		cnt = 0;
	}

	return 0;
}