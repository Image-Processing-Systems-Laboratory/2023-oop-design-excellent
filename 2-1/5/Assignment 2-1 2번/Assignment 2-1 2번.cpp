#include <iostream>

using namespace std;
// queue�� maze_int �迭 ���� & ������ �� üũ�� �迭 ����
int maze_int[30][30];
int move_queue[30 * 30];
int check_visited[30][30] = {};
int check = -1, input = -1;

// queue�� �湮�� ��ǥ �������ִ� �Լ� ����
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
// queue�� ����� ��ǥ ��� �� queue�� ��������� check�� input -1�� �ʱ�ȭ���ִ� �Լ� ����
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
// �ִܰŸ� ����ϴ� �Լ� ����
int shortest(int row_size, int col_size,int row_start, int col_start, int row_des, int col_des) {
	// �������� ǥ��
	int move[] = { -1,1};
	int dont_move[] = {0,0};
	// ���� ��ǥ que�� �־��ֱ� �� ������ ��ǥ�� ����
	insert(row_start , col_start);
	check_visited[row_start][col_start] = 1;
	// queue�� ������� �ʴ� ���� �ݺ��ؼ� �̵��ϸ� �������� �����ϸ� �Ÿ��� ��ȯ����
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
	// �������� �������� ���� ��� �� -1 ��ȯ
	cout << "�������� ���߽��ϴ�.";
	return -1;

};




int main() {

	// �� �� �Է�
	int row, column;
	cin >> row >> column;

	// �Է¹��� �� �� ũ�� ��ŭ�� ������ ���ڿ� �����Ҵ�
	char** maze = new char* [row];
	for (int i = 0; i < row; i++) {
		maze[i] = new char[column];
	}
	// �Է¹��� ���ڿ� ������ �迭�� ��ȯ
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> maze[i][j];
			maze_int[i][j] = maze[i][j] - '0';
			
		}
	}
	// ���� ��, �� �� ������ ��, �� �Է�
	int start_row, start_column, des_row, des_column;
	cin >> start_row >> start_column >> des_row >> des_column;

	int result = shortest(row, column, start_row-1, start_column-1, des_row-1, des_column-1);
	cout << result;
	// �����Ҵ� �޸� ����
	for (int i = 0; i < row; i++)
		delete maze[i];
	delete[] maze;

	return 0;
}