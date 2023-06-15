#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE] = { 0 };//미로 방문여부를 저장할 배열
int row, col;
int dx[4] = { 1, 0, -1, 0 }; //동,북,서,남으로 이동할 때 x좌표 변화
int dy[4] = { 0, 1, 0, -1 }; //동,북,서,남으로 이동할 때 y좌표 변화
class Queue {
private:
    int front, rear;
    pair<int, int>arr[MAX_SIZE * MAX_SIZE];
public:
    //생성자 객체 생성시 front, rear를 0으로 초기화
    Queue() : front(0), rear(0) {}
    //queue에 새로운 원소 추가
    void push(pair<int, int> p) {
        arr[rear++] = p;
    }
    // 큐에서 원소 제거 후 반환
    pair<int, int> pop() {
        return arr[front++];
    }
    bool empty() {
        //foront=rear이면 true반환, 아니면 false반환
        return front == rear;
    }
};
// 미로에서 최단거리를 찾는 함수
int BFS(pair<int, int> start, pair<int, int> end) {
    Queue q;
    q.push(start); //시작점을 queue에 추가
    visited[start.first][start.second] = 1;

    while (!q.empty()) { // 큐가 비어있지 않을 동안 반복
        pair<int, int> curr = q.pop(); // 현재 위치를 큐에서 제거 후 저장
        if (curr == end) { // 도착점에 도달한 경우
            return visited[curr.first][curr.second]; // 도착지에 도달했을 때의 거리 반환
        }
        for (int i = 0; i < 4; i++) { // 현재 위치에서 4방향을 탐색
            int nx = curr.first + dx[i]; // 다음 위치의 x좌표 계산
            int ny = curr.second + dy[i]; // 다음 위치의 y좌표 계산
            if (nx >= 0 && nx < row && ny >= 0 && ny < col // 다음 위치가 미로의 범위 내에 있는지 확인
                && !visited[nx][ny] && maze[nx][ny] == 0) { // 다음 위치를 방문하지 않았고, 벽이 아닌 경우
                visited[nx][ny] = visited[curr.first][curr.second] + 1; // 다음 위치를 방문했다고 표시하고, 거리 계산
                q.push(make_pair(nx, ny)); // 다음 위치를 큐에 추가
            }
        }
    }
    return -1; // 도착지에 도달할 수 없는 경우 -1 반환
}
int main() {
    //사용자로부터 미로 입력받기
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char c;
            cin >> c;
            maze[i][j] = c - '0'; //char형을 int형으로 바꾸기 위해 0의 ASCII값 빼줌
        }
    }
    //시작점과 도착점 입력받기
    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y >> end_x >> end_y;
    pair<int, int> start = make_pair(start_x-1, start_y-1);
    pair<int, int> end = make_pair(end_x-1, end_y-1);
    int result = BFS(start, end);
    cout << result << endl;

    return 0;
}


