#include <iostream>

using namespace std;

const int MAX_SIZE = 30; // 최대 maze 크기 상수 정의
const int INF = 1e9; // 무한대 값 설정

char maze_in[MAX_SIZE][MAX_SIZE]; // 문자로 이루어진 maze 배열
int maze[MAX_SIZE][MAX_SIZE]; // int형 maze 배열
int dist[MAX_SIZE][MAX_SIZE]; // 시작점으로부터 각 지점까지의 최단 거리 저장하는 배열
bool visited[MAX_SIZE][MAX_SIZE]; // 방문 여부를 저장하는 배열

int dir_row[] = { -1, 0, 1, 0 }; // 북, 동, 남, 서 방향을 나타내는 배열
int dir_col[] = { 0, 1, 0, -1 };

int rows, cols; // 행과 열의 개수
/*bfs 알고리즘을 사용한 do_maze 함수 내부에서는 while 루프를 돌면서 큐에 저장된 좌표들을 하나씩 꺼내서 상하좌우 인접한 좌표를 방문함.
이때, 인접한 좌표가 미로 내부에 있고, 갈 수 있는 곳이며, 아직 방문하지 않았다면 해당 좌표를 큐에 추가하고 dist 배열을 갱신함.
이 과정을 큐가 빌때까지 반복하면 dist 배열에는 시작점으로부터 도착점까지의 최단거리가 저장되게 됨.*/
void do_maze(int r, int c) { // do_maze 함수 정의(BFS 알고리즘 이용)
    for (int i = 0; i < rows; i++) { // dist와 visited 배열 초기화
        for (int j = 0; j < cols; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    dist[r][c] = 1; // 시작점의 거리는 1로 설정
    visited[r][c] = true;

    int queue[MAX_SIZE * MAX_SIZE]; // 큐 정의
    int front = 0, rear = 0; // 큐의 앞, 뒤 포인터 초기화
    queue[rear++] = r * cols + c; // 시작점 큐에 삽입

    while (front < rear) { // 큐가 비어있지 않은 동안 반복
        int n = queue[front++]; // 큐에서 하나 뽑아 n에 저장
        int n_row = n / cols, n_col = n % cols; // n에서의 행, 열 값 저장

        for (int i = 0; i < 4; i++) { // 상하좌우 방향 확인
            int visited_row = n_row + dir_row[i], visited_col = n_col + dir_col[i]; // 새로운 행, 열 값 계산

            if (visited_row >= 0 && visited_row < rows && visited_col >= 0 && visited_col < cols && maze[visited_row][visited_col] == 0 && !visited[visited_row][visited_col]) { // 범위 내에 있고 이동 가능하며 방문하지 않은 경우
                visited[visited_row][visited_col] = true; // 방문 여부 체크
                dist[visited_row][visited_col] = dist[n_row][n_col] + 1; // 거리 계산
                queue[rear++] = visited_row * cols + visited_col; // 큐에 추가
            }
        }
    }

}

int main() {
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) { // maze 입력받기
        for (int j = 0; j < cols; j++) {
            cin >> maze_in[i][j];
            maze[i][j] = maze_in[i][j] - '0'; // 문자를 숫자로 변환
        }
    }

    int start_row, start_column, end_row, end_column; // 시작점과 끝
    cin >> start_row >> start_column >> end_row >> end_column;

    do_maze(start_row-1, start_column-1);

    cout << dist[end_row-1][end_column-1] << endl;

    return 0;
}