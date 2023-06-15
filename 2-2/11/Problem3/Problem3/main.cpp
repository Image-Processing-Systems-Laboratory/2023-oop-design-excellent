#include"CSVLoader.h"

int main() {

	//인스턴스 변수 생성
	CSVLoader csv("test.txt");
	//저장된 데이터 출력
	csv.print();

	//저장된 데이터와 비교하기 위해 데이터의 주소, 행, 열의 크기를 저장
	float** data = csv.getData();
	int col = csv.getCols();
	int row = csv.getRows();

	cout << endl;
	//행의 크기만큼 반복
	for (int i = 0; i < col; i++) {
		//열의 크기만큼 반복
		for (int j = 0; j < row; j++) {
			//첫번째 데이터가 아닐 시
			if (j)
				//, 출력
				cout << ", ";
			//값 출력
			cout << data[i][j];
		}
		//줄 바꿈
		cout << endl;
	}

}