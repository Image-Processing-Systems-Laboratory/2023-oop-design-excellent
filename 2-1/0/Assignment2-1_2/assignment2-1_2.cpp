#include<iostream>
using namespace std;

#define MAX 30		//미로의 최대 크기

//전역변수 선언
char Maze[MAX][MAX];	//미로를 저장하는 2차원 배열 선언
int len_Path[MAX];	//미로 도착지점의 길이를 저장함
int col, row;	//행과 열을 저장하는 변수 선언
int way = 0;		//미로를 탈출할 수 있는 가지 수

//함수 선언
void Maze_Out(int start_x, int start_y, int dest_x, int dest_y, int path);	//미로의 출구에 도달시켜주는 함수
int shortest_Path();		//미로의 가장 최단거리 값을 반환해주는 함수

//x, y 좌표 구조체 선언
typedef struct coordinate
{
	int x;		//x좌표
	int y;		//y좌표
}Coor;

int main()
{
	Coor start, dest;	//시작지점, 도착지점 좌표 저장하는 구조체 변수 선언
	int path = 0;		//지나온 길이 저장
	cout << "col, row" << endl;
	cin >> col >> row;	//행과 열 입력받기

	cout << "Maze" << endl;
	//미로 정보 입력받기
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> Maze[i][j];

	//시작지점과 도착지점 입력받기
	cout << "start, end Coordinate" << endl;
	cin >> start.x >> start.y >> dest.x >> dest.y;
	
	//미로를 출구에 도달시켜주는 함수 호출
	Maze_Out(start.x - 1, start.y - 1, dest.x - 1, dest.y - 1, path);
	
	if (way == 0)		//탈출할 수 없으면
		cout << "No way" << endl;
	else				//탈출 가능하면
		cout << shortest_Path() << endl;	//지나온 길이의 최단거리를 출력
		
	return 0;
}
//미로의 출구에 도달시켜주는 함수
void Maze_Out(int start_x, int start_y, int dest_x, int dest_y, int path) {
	//미로 밖을 벗어나는 경우
	if (start_x < 0 || start_y < 0 || start_x >= row || start_y >= col )
		return ;
	//도착지에 도달하는경우
	else if (start_x == dest_x && start_y == dest_y)
	{
		//미로의 도착지점 저장
		len_Path[way++] = path + 1;
	}

	//이미 지나온 길이거나 벽인 경우
	else if (Maze[start_y][start_x] != '0')
		return ;
	else
	{
		//이미 지나온길을 '2'로 저장함
		Maze[start_y][start_x] = '2';
		//오른쪽으로 이동
		Maze_Out(start_x + 1, start_y, dest_x, dest_y, path + 1);
		//왼쪽으로 이동
		Maze_Out(start_x - 1, start_y, dest_x, dest_y, path + 1);
		//위로 이동
		Maze_Out(start_x, start_y + 1, dest_x, dest_y, path + 1);
		//아래로 이동
		Maze_Out(start_x, start_y - 1, dest_x, dest_y, path + 1);
		Maze[start_y][start_x] = '0';	//지나간곳 길 다시 '0'(길)으로 초기화
	}
}
//미로의 가장 최단거리 값을 반환해주는 함수
int shortest_Path() {
	int Min = MAX * MAX;			//최소값을 저장해줌
	//가장 작은값 찾기
	for (int i = 0; i < way; i++)
	{
		if (len_Path[i] < Min)		//Min값보다 작을 경우
			Min = len_Path[i];		//가장 작은 값 저장
	}
	return Min;		//최단 거리 반환
}

