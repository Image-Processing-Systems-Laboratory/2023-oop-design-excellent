#include <iostream>

using namespace std;
// queue와 maze_int 배열 선언 & 지났던 길 체크할 배열 선언
int maze_int[30][30];
int move_queue[30 * 30];
int check_visited[30][30] = {};
int check = -1, input = -1;

// queue에 방문한 좌표 저장해주는 함수 선언
void insert(int row, int col) {
	if (check == -1) {
		check++;
		input++;
		move_queue[input] = row*100 + col;
	}
	else {
		input++;
		move_queue[input] = row*100 + col;
	}

}
// queue에 저장된 좌표 출력 및 queue가 비어있으면 check와 input -1로 초기화해주는 함수 선언
int check_queue() {
	int a = move_queue[check];
	if (check == input) {
		check=-1;
		input=-1;
	}
	else
		check++;
	return a;
}
// 최단거리 계산하는 함수 선언
int shortest(int row_size, int col_size,int row_start, int col_start, int row_des, int col_des) {
	// 동서남북 표현
	int move[] = { -1,1};
	int dont_move[] = {0,0};
	// 시작 좌표 que에 넣어주기 및 지나간 좌표로 저장
	insert(row_start , col_start);
	check_visited[row_start][col_start] = 1;
	// queue가 비어있지 않는 동안 반복해서 이동하며 목적지에 도착하면 거리를 반환해줌
	while (check != -1 && input != -1) {
		int coordinate = check_queue();
		int x = coordinate / 100;
		int y = coordinate % 100;
		if (x == row_des && y == col_des)
			return maze_int[x][y] + 1;

		for (int i = 0; i < 2; i++) {
			int moved_x = x + move[i];
			int moved_y = y + dont_move[i];
			if (moved_x >= 0 && moved_x < row_size && moved_y >= 0 && moved_y < col_size && check_visited[moved_x][moved_y] != 1 && maze_int[moved_x][moved_y]!=1) {
				insert(moved_x, moved_y);
				check_visited[moved_x][moved_y] = 1;
				maze_int[moved_x][moved_y] = maze_int[x][y] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int moved_x2 = x + dont_move[i];
			int moved_y2 = y + move[i];
			if (moved_x2 >= 0 && moved_x2 < row_size && moved_y2 >= 0 && moved_y2 < col_size && check_visited[moved_x2][moved_y2] != 1 && maze_int[moved_x2][moved_y2]!= 1) {
				insert(moved_x2, moved_y2);
				check_visited[moved_x2][moved_y2] = 1;
				maze_int[moved_x2][moved_y2] = maze_int[x][y] + 1;
			}
		}
		
	}
	// 도착하지 못했으면 문장 출력 및 -1 반환
	cout << "도달하지 못했습니다.";
	return -1;

};




int main() {

	// 행 열 입력
	int row, column;
	cin >> row >> column;

	// 입력받은 행 열 크기 만큼의 이차원 문자열 동적할당
	char** maze = new char* [row];
	for (int i = 0; i < row; i++) {
		maze[i] = new char[column];
	}
	// 입력받은 문자열 정수형 배열로 변환
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> maze[i][j];
			maze_int[i][j] = maze[i][j] - '0';
			
		}
	}
	// 시작 행, 열 및 목적지 행, 열 입력
	int start_row, start_column, des_row, des_column;
	cin >> start_row >> start_column >> des_row >> des_column;

	int result = shortest(row, column, start_row-1, start_column-1, des_row-1, des_column-1);
	cout << result;
	// 동적할당 메모리 해제
	for (int i = 0; i < row; i++)
		delete maze[i];
	delete[] maze;

	return 0;
}