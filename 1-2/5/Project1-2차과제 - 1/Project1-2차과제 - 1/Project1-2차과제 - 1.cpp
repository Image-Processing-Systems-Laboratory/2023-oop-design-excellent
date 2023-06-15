#include <iostream> // 헤더파일 선언
#include <cmath>
using namespace std; // 표준 라이브러리 사용
/* cin같은 함수들의 앞에 정의된 클래스가 없으면
C++ 표준 라이브러리 함수로 받아들이겠다는 뜻*/

int main() {
	unsigned long long input1; // 첫번째 입력받을 변수 선언
	unsigned long long input2; // 두번째 입력받을 변수 선언
	
	int arr1[20] = { 0, }; // 배열 1 첫번째 입력을 각 요소로 나누어 배열로 나타내기위해
	int arr2[20] = { 0, }; // 배열 2 두번째 입력을 각 요소로 나누어 배열로 나타내기위해
	//[19]로 배열을 선언한 이유는 unsigned long long형으로 입력을 받았으므로, 최대 20자리의 정수까지 입력을 받을 수 있기 떄문이다.
	//0~18,446,744,073,709,551,615
	int count[9] = { 0, }; // 숫자를 카운트 해주기 위해 1~9까지의 수를 카운트
	int print[9] = { 10, }; // 배열 1, 2의 요소를 문제의 조건대로 저장(출력 위해 선언)

	int x = 0; // 배열에 접근하기 위한 변수
	int c = 1; // 배열 count에 숫자가 맞는 것이 있으면 카운드 해주기 위한 변수

	cin >> input1; // 입력 받음
	cin >> input2;


	for (int i = 0; i < 20; i++) { // input1을 각 요소로 나누어 배열1에 저장 
		// 이는 예를들어 123456789라는 수를 입력 받으면, 배열에 각각 1,2,3,4,5,6,7,8,9 의 값을 넣어준다.
		long long  num = 0; 
		num = input1 / pow(10, 19 - i);
		if (num == 0) { // num이 0이라면 아래의 과정을 건너뛰고 i++를 해주고 다시 조건을 확인
			continue;
		}

		if (num > 9) {
			num %= 10;
			arr1[x] = num;
			x++;
		}
		else {// num = input2 / pow(10, 11 - i); 과정을 거쳤을때 값이 10이상이면 10으로 나눈 나머지가 그 요소가 되므로, num에 10을나눈 나머지값을 저장해두고 배열로 옮김
			arr1[x] = num;
			x++;
		}
	}

	x = 0; // 다음의 과정을 위해 x를 0으로 초기화 해둠

	for (int i = 0; i < 20; i++) { // input2을 각 요소로 나누어 배열2에 저장 
		// 이는 예를들어 123456789라는 수를 입력 받으면, 배열에 각각 1,2,3,4,5,6,7,8,9 의 값을 넣어준다.
		long long num = 0;
		num = input2 / pow(10, 19 - i);
		if (num == 0) {// num이 0이라면 아래의 과정을 건너뛰고 i++를 해주고 다시 조건을 확인
			continue;
		}
		if (num <= 9) { 
			arr2[x] = num;
			x++;
		}
		else { // num = input2 / pow(10, 11 - i); 과정을 거쳤을때 값이 10이상이면 10으로 나눈 나머지가 그 요소가 되므로, num에 10을나눈 나머지값을 저장해두고 배열로 옮김
			num %= 10;
			arr2[x] = num;
			x++;
		}
	}

	for (int i = 0; i < 9; i++) { // 각 배열의 요소를 카운트 해주기 위해 사용
		for (int j = 0; j < 20; j++) {
			if (arr1[j] == c) { // 배열1에 저장되어있는 숫자들을 카운트 해줌
				count[c - 1] += 1;
			}
		}
		for (int j = 0; j < 20; j++) { // 배열2에 저장되어있는 숫자들을 카운트 해줌
			if (arr2[j] == c) {
				count[c - 1] += 1;
			}
		}
		c++;
	}

	x = 0; // 다음의 과정을 위해 x를 0으로 초기화 해둠

	for (int i = 0; i < 20; i++) {
		/*먼저 배열1에 저장되어있는 요소들을 배열 print에 저장해두고 
		만약 앞에서 이미 같은 수가 나왔으면 그때 배열 print의 값을 10으로 초기화 해둠
		10으로 초기화 해두는 이유는 숫자는 어차피 1~9까지의 값을 카운트하고 출력하기 때문 => 쓰레기 값*/
		if (x <= 8) { // if(x<=8)으로 지정해둔 이유는 숫자가 1~9까지 밖에없으면 이를 벗어날 일은 없지만, 그래도 print의 메모리를 초과하지 않기 위해 사용함
			print[x] = arr1[i];
			for (int j = 0; j < x; j++) {
				if ((print[x] == print[j]) || print[x] == 0) {
					print[x] = 10;
					x--; // 여기서 x--를 해주는이유는 만약 배열 print에 0 또는 배열 print의 요소들 중 같은값이 있다면 연산을 한번 더 진행하기 위함
				}
			}
			x++;
		}
	}
	/*그다음으로 배열2에 저장되어있는 요소들을 배열 print에 저장한다
	만약 배열1에서 나온 숫자가 이미 print에 저장되어있으면 마찬가지로 배열 print의 값을 10으로 초기화 해둠 숫자가*/ 
	for (int i = 0; i < 20; i++) {
		if (x <= 8) { // if(x<=8)으로 지정해둔 이유는 숫자가 1~9까지 밖에없으면 이를 벗어날 일은 없지만, 그래도 print의 메모리를 초과하지 않기 위해 사용함
			print[x] = arr2[i];
			for (int j = 0; j < x; j++) {
				if (print[x] == print[j] || print[x] == 0) {
					print[x] = 10;
					x--; // 여기서 x--를 해주는이유는 만약 배열 print에 0 또는 배열 print의 요소들 중 같은값이 있다면 연산을 한번 더 진행하기 위함
				}
			}
			x++;
		}
	}

	for (int i = 0; i < 9; i++) { // 결과값을 출력하는 반복문
		x = print[i];
		if (x == 10) { // 만약 print에 저장되어있는 요소가 10이면 0을 반환해줌 그 이유는
			// 예를들어 입력으로 12 12를 받았으면 print에 1,2 두 요소만 출력하고 그 다음 배열 print에 있는 요소를 출력하지 않기 위함
			return 0;
		}
		cout << print[i] << count[x - 1]; // 만약 x가 3이라면 배열count는 3번째 요소에 숫자 3의 개수가 저장되어있으므로 count[x-1]을 출력한다
	}

	return 0; // 0의 반환
}