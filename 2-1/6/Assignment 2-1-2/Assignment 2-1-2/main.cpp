#define _CRT_SEUCRE_NO_WARNINGS
#include <iostream>
using namespace std;

/*최단거리를 찾기 위한 함수원형 선언*/
int find(int startN, int startM, int desN, int desM, int n, int m);
/*미로*/
char maze[31][31] = { 0 };
/*시작점을 기준으로 다음 밟을 땅은 그 전에 밟은 땅 + 1을 해서 거리를 구하기 위한 이차원배열*/
int alreadyPassed[31][31] = { 0 };
/*위로갈지 아래로갈지 오른쪽으로갈지 왼쪽으로갈지 정해주기 위한 배열*/
int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };
/*클래스 안의 배열이 비어있는지 확인하기 위한 변수*/
int emptyIndex = 0;
/*가야 할 곳을 모두 저장하는 클래스*/
class asd {
public:
	int x[100];
	int y[100];
	int xFront();
	int yFront();
	void xPop();
	void yPop();
	void xPush(int v);
	void yPush(int v);
	int empty();	/*배열이 비어있는지 확인하기 위한 함수 원형 선언*/
};
/*배열이 비어있는지 확인하기 위한 함수*/
int asd::empty() {
	/*emptyIndex가 0이면 1반환 - 비어있다는 뜻*/
	if (emptyIndex == 0) return 1;
	else return 0;
}
/*x배열의 첫번째 인덱스 값 return */
int asd::xFront() {
	return x[0];
}
/*y배열의 첫번째 인덱스 값 return */
int asd::yFront() {
	return y[0];
}
/*x배열의 첫번째 인덱스 값 삭제*/
void asd::xPop() {
	for (int i = 0; i < 99; i++) {
		x[i] = x[i + 1];
	}
	emptyIndex--;
}
/*y배열의 첫번째 인덱스 값 삭제*/
void asd::yPop() {
	for (int i = 0; i < 99; i++) {
		y[i] = y[i + 1];
	}
}
/*x배열 한칸씩 뒤로 밀고 첫번째 인덱스에 방금 들어온 값 저장*/
void asd::xPush(int v) {
	/*memmove함수로 한칸씩 뒤로 밀고 배열의 첫번째 인덱스 값에 push v*/
	memmove(x + 1, x, 100);
	x[0] = v;
	emptyIndex++;
}
/*y배열 한칸씩 뒤로 밀고 첫번째 인덱스에 방금 들어온 값 저장*/
void asd::yPush(int v) {
	/*memmove함수로 한칸씩 뒤로 밀고 배열의 첫번째 인덱스 값에 push v*/
	memmove(y + 1, y, 100);
	y[0] = v;
}
int main(void) {
	/*n은 행, m은 열*/
	int n = 0, m = 0;
	int cnt = 0;
	cin >> n >> m;
	/*미로 생성*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	int sn = 0, sm = 0, dn = 0, dm = 0;
	cin >> sn >> sm >> dn >> dm;
	int startN = sn - 1;	//시작 행 인덱스
	int startM = sm - 1;	//시작 열 인덱스
	int desN = dn - 1;		//목적지 행 인덱스
	int desM = dm - 1;		//목적지 열 인덱스
	cnt = find(startN, startM, desN, desM, n, m);	//최단거리 구하기 위한 함수
	cout << cnt;		//최단거리 출력
	return 0;
}

/*최단거리를 찾기 위한 함수*/
int find(int startN, int startM, int desN, int desM, int n, int m) {
	/*시작점을 node 객체 안에 있는 배열에 저장*/
	asd node;
	node.xPush(startN);
	node.yPush(startM);
	/*시작점은 1로 잡음*/
	alreadyPassed[startN][startM] = 1;
	/*길찾기 시작*/
	while (!node.empty()) {
		/*현재 좌표를 찾기 위한 curN과 curM*/
		int curN = 0;
		curN = node.xFront(); // node 객체 안의 x배열의 첫번째 값
		int curM = 0;
		curM = node.yFront(); // node 객체 안의 y배열의 첫번째 값
		node.xPop(); //curN에게 첫번째 값 넘겨주고 그 값 지움
		node.yPop(); //curM에게 첫번째 값 넘겨주고 그 값 지움
		/*만약 현재 좌표가 도착점과 같으면 return*/
		if (curN == desN && curM == desM) return alreadyPassed[curN][curM];
		/*현재 좌표 기준으로 움직이기 시작하는 반복문*/
		for (int i = 0; i < 4; i++) {
			/*현재 좌표에 움직일 수 있는 곳을 찾아 그 곳의 행과 열값 nnn,mmm에 저장*/
			/*n은 모두 행과 관련된 것, m은 모두 열과 관련된 것*/
			int nnn = curN + moveX[i];
			int mmm = curM + moveY[i];
			/*만약 움직인 곳이 미로 범위를 벗어나면 continue*/
			if (nnn < 0 || mmm < 0 || nnn >= n || mmm >= m) continue;
			/*움직인 곳이 벽이면 continue*/
			if (maze[nnn][mmm] == '1') continue;
			/*한번 갔던 곳이면 continue*/
			if (alreadyPassed[nnn][mmm] != 0) continue;
			/*처음 밟아보는 땅이면 직전 땅까지의 최단거리 + 1*/
			alreadyPassed[nnn][mmm] = alreadyPassed[curN][curM] + 1;
			for (int z = 0; z < n; z++) {
				for (int f = 0; f < m; f++) {
					cout << alreadyPassed[z][f] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			/*그 땅 node객체 안에 x배열과 y배열 첫번째 인덱스에 저장하고 배열 안의
			값들은 한칸씩 뒤로 밀림*/
			node.xPush(nnn);
			node.yPush(mmm);
		}
	}
}