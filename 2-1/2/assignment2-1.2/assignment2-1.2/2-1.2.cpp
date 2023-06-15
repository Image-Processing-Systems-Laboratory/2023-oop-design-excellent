#include <iostream> //iostream선언
using namespace std; //namespace std 선언

const int visited = 1; //방문한 곳은 1로 설정(벽과 같게 만들어서 그쪽으로 못 들어가게 한다.)
const int unvisited = 0; //반대로 방문하지 않은 곳은 0
const int wall = 1; //벽도 1로 설정

void maze(int** world, int starty, int startx, int finaly, int finalx, int& countway, int row, int column, int again) //미로의 최단경로를 찾는 함수
{
    //전달인자 설명: world는 main함수에서 입력한 미로, starty&startx는 시작점, finaly&finalx는 도착점, countway는 최단경로의 길이를 받기 위한 변수
    //row와 coulumn은 미로 밖으로 못 빠져나가게 하기 위해 같이 전달, again은 재귀호출을 하면서 각자 증가하게 되고, 결국 최종 목적지에 도착한 again이 countway에 값을 넘겨준다.
    if (starty < 0 || startx < 0 ||starty >= column || startx >= row) //만약 현재 좌표의 값이 음수이거나 미로 밖으로 벗어났을 때
        return; //함수 종료
    if (world[starty][startx] != unvisited) //현재 좌표가 방문했던 곳이거나 벽일 때
        return; //함수 종료
    if (starty == finaly && startx == finalx) //만약 최종목적지에 도착했다면
    {
        countway = again; //again이 countway에 값을 넘겨준다.
        return; //그 후 함수 종료
    }
    else //그 외에 잘 가고 있는 경우
    {
        world[starty][startx] = visited; //재귀호출을 했을 때 현재 온 곳을 다시 가는 것을 방지하기 위해 방문했다고 표시
        maze(world, starty + 1, startx, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty - 1, startx, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty, startx + 1, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty, startx - 1, finaly, finalx, countway, row, column, again + 1); //동서남북으로 함수 호출(startx나 starty값을 변경 및 again도 1 증가)
        world[starty][startx] = unvisited; //재귀호출이 끝나면 다시 unvisited로 바꿔서 다른 경우에서 이 경로를 지나갈 수 있도록 원상복구
    }
} //maze함수 종료


int main()
{
    int row = 0, column = 0; //row와 column 변수 선언
    cin >> column >> row; //문제 예시처럼 column row 순서로 입력받기

    char** arr = new char* [column]; //column만큼 미로를 세로로 만들기 (띄어쓰기를 하지 않고 입력받기 때문에 우선 char형으로 입력받기)
    int** path = new int* [column]; //char형으로 받은 값들을 int형인 path에 옮겨담기 위해 같이 선언
    for (int i = 0; i < column; i++)
    {
        arr[i] = new char[row];
        path[i] = new int[row]; //row 가로 길이도 동일하게 선언
        for (int j = 0; j < row; j++)
        {
            cin >> arr[i][j]; //arr에 차례대로 입력받기
            //동시에 path에 정수값을 넣어주기
            if (arr[i][j] == '1') //만약 문자 1을 입력받으면
            {
                path[i][j] = wall; //path에 wall, 즉 1을 입력
            }
            else //그 외의 경우(문자 0을 입력받았을 때)
            {
                path[i][j] = unvisited; //path에 0을 입력
            }
        }
    }

    int firstx = 0, firsty = 0, lastx = 0, lasty = 0; 
    cin >> firstx >> firsty >> lastx >> lasty; //출발 좌표와 도착 좌표 입력받기
    int countway = 0; //최단거리를 출력할 변수 선언

    maze(path, firsty - 1, firstx - 1, lasty - 1, lastx - 1, countway, row, column, 1);
    //maze함수에 path배열, 시작좌표와 도착좌표, countway와 행과 열 사이즈, 그리고 again의 초깃값 1을 넘겨준다.

    cout << countway << endl; //최단경로 출력

    for (int i = 0; i < column; i++)
    {
        delete[] arr[i];
        delete[] path[i];
    }
    delete[] arr;
    delete[] path; //사용했던 배열들의 동적할당 해제

    return 0; //0의 반환
} //main함수 종료