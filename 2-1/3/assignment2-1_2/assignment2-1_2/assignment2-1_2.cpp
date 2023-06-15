#include <iostream>     //헤더파일 선언

using namespace std;

void bfs(int a, int b, int start_x, int start_y, int end_x, int end_y);      //bfs, check 함수 정의
bool check(int now_x, int now_y, int a, int b);

int visit[31][31] = { 0 };
int miro[31][31];      //visit, miro 배열 선언
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };      //4가지 방향으로 움직일 좌표 설정

int main(void)
{
    int wid = 0, len = 0, start_x = 0, start_y = 0, end_x = 0, end_y = 0;      //변수 선언 후 초기화
    char arr[30][30] = { 0 };      //배열 선언 후 초기화

    cin >> wid >> len;      //열, 행 입력받기
    for (int i = 1; i <= wid; i++) {
        for (int j = 1; j <= len; j++) {      //for문 실행
            cin >> arr[i][j];      //미로 입력 받기
            miro[i][j] = arr[i][j] - ('0' - 0);      //미로 배열에 '0'-0을 빼서 넣음
        }
    }

    cin >> start_x >> start_y >> end_x >> end_y;      //시작좌표와 도착좌표를 입력받음
    bfs(wid, len, start_x, start_y, end_x, end_y);      //미로의 최단거리 출력

    return 0;
}

void bfs(int a, int b, int start_x, int start_y, int end_x, int end_y)      //미로의 최단거리를 구하는 함수
{

    visit[start_x][start_y] = 1;      //초기 좌표를 방문함

    int path[31][31] = { };      //배열 선언 후 초기화
    path[start_x][start_y] = 1;      //시작 좌표에 1을 넣음

    int tail = 0, head = 0;      //변수 선언 후 초기화
    int arr_y[500] = { };
    int arr_x[500] = { };

    arr_y[tail] = start_y;      //시작 좌표의 열을 넣음
    arr_x[tail++] = start_x;      //시작 좌표의 행을 넣음

    while (tail > head) {      //tail > head일 때 동안 반복
        int y = arr_y[head];
        int x = arr_x[head];      //방문할 좌표 꺼내기
        head++;
        for (int i = 0; i < 4; i++) {       //for문 실행
            int now_y = y + dy[i];
            int now_x = x + dx[i];      //상하좌우로 인접한 좌표의 값 계산
            if (check(now_x, now_y, a, b)) {        //만약 방문할 수 있으면
                visit[now_x][now_y]++;      //방문 횟수 증가
                arr_y[tail] = now_y;        //좌표 넣기
                arr_x[tail++] = now_x;
                path[now_x][now_y] = path[x][y] + 1;        //최단 거리를 계산하여 넣음

            }
        }
    }
    cout << path[end_x][end_y];     //최단 거리 출력
}

bool check(int now_x, int now_y, int a, int b) {        //지나갈 수 있는지 확인하는 함수

    if (miro[now_x][now_y] == 1)        //벽일 때
        return false;       //false 반환
    else if (visit[now_x][now_y] == 1)      //방문한 좌표일 때
        return false;       //false 반환
    else if (now_x <= 0 || now_x > b || now_y <= 0 || now_y > a)        //범위를 넘어설 때
        return false;       //false 반환
    else
        return true;        //true 반환

}