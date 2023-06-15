#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 30;
int n, m;  // 행, 열의 개수
int maze[MAX][MAX];  // 미로 정보
int dist[MAX][MAX];  // 시작점부터의 거리

int dx[4] = { -1, 0, 1, 0 };  // 상하좌우 이동
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

    dist[x][y] = 1;  // 시작점 거리 1로 초기화
    int q[MAX * MAX][2] = {};  // 방문해야 할 노드를 저장하는 배열

    int front = 0, rear = 0;
    q[rear][0] = x;
    q[rear][1] = y;
    rear++;

    while (front < rear) {

        int cx = q[front][0];
        int cy = q[front][1];
        front++;

        for (int i = 0; i < 4; i++) {  // 상하좌우 이동
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  // 미로 범위 벗어남
            if (maze[nx][ny] == 0 && dist[nx][ny] == 0) {  // 길이고 아직 방문하지 않은 경우
                q[rear][0] = nx;
                q[rear][1] = ny;
                rear++;

                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }
}

int main() {
    // 입력 받기
    cout << "Enter the number of rows and columns:";
    cin >> n >> m;
    cout << "Enter the maze:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);  // 공백 없이 입력 받기
        }
    }

    memset(dist, 0, sizeof(dist));  // 거리 배열 초기화

    cout << "Enter the starting point and the destination:";

    int startX, startY, endX, endY;  // 시작점, 도착점
    cin >> startX >> startY >> endX >> endY;

    bfs(startX - 1, startY - 1);  // 시작점 좌표로 bfs 실행

    cout << "The shortest path is:";

    cout << dist[endY -1]   [endX - 1] << endl;  // 도착점 거리 출력

    return 0;
}
