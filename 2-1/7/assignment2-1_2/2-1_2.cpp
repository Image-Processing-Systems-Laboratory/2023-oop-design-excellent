#include <iostream>
using namespace std;

class go // 기본정보가 int형 데이터 하나가 아니고 아래와 같이 세가지이므로 class를 통해 따로 선언해줬다
{
public:
    int y; // 세로좌표
    int x; // 가로좌표
    int length; // 최단경로 찾기 위한(각 경로에 자취를 남길때 사용, 그리고 이 자취가 최소인 경로가 최단경로가 된다)
};

class Queue // queue를 클래스를 이용해 구현(왜 queue를 사용하는지에 대한 자세한 내용은 고찰에서 설명)
{
private:
    class Node // 노드 기본값 설정
    {
    public:
        go data; // data에는 위에서 말했듯 세가지가 포함돼야 하므로, 위에서 선언한 클래스인 go형으로 데이터를 설정해준다
        Node* next; // 다음 노드
    };
    // queue는 front와 rear가 존재한다. front는 pop했을때 나가지는 부분, rear는 push했을때 들어가는 부분이다.
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) // front와 rear는 처음 생성시에는 당연히 null로 초기화
    {
        // 이니셜라이저를 통해 이미 처리했고, 생성자에는 따로 내용이 없음
    }

    void push(go val) // stack과 다르게 queue는 선입선출구조이므로, stack과 push 방법이 약간 다르다
    {
        Node* newNode = new Node{ val, nullptr };
        if (rear == nullptr) // queue에 노드가 하나도 없는 경우
            front = rear = newNode; // front, rear 모두 새 노드로 설정해준다
        else
        {
            rear->next = newNode; // queue는 새 노드를 받는 부분이 rear다.
            rear = newNode;
        }
    }

    void pop() // pop 역시 stack과 다르다
    {
        Node* prevFront = front; // 처음 넣는 노드는 front에 존재한다
        front = front->next; // front는 다음 노드로 보내주고
        if (front == nullptr) // 그랬을때 front가 null일 경우(노드가 없음)
            rear = nullptr; // rear도 null이 된다
        delete prevFront; // front바로 전 노드(front에 있는 노드) 삭제(pop)
    }

    go getfront() // front 노드 값 반환
    {
        return front->data;
    }

    bool empty() // queue가 비어있는지 확인해주는 bool 함수
    {
        return front == nullptr;
    }
};

bool check = false; // 목적지에 도착했는지에 대한 여부를 확인하기 위한 check 변수
int length = 0; // 최단 경로의 length를 저장해줌(즉, 최단거리)

void BFS(int i1, int j1, int** maze, int i2, int j2, int a, int b)
{
    Queue Q;
    int imove[4] = { 0,0,1,-1 }; // 상하 움직임(세로). 상하좌우 4방향이므로 다음과 같이 길이 4의 배열로 해주었다
    int jmove[4] = { 1,-1,0,0 }; // 좌우 움직임(가로)
    Q.push({ i1,j1,1 }); // i1, j1에서 시작. 그리고 path의 경우 출발 지점 역시 거리로 포함하므로 1로 push해준다
    while (!Q.empty())
    {
        int temp_i = Q.getfront().y, temp_j = Q.getfront().x; // 현재 위치를 temp_i, temp_j에 저장. 정확히는 최단경로의 이전 좌표값 저장
        int temp_length = Q.getfront().length; // 길이 역시 저장
        if (temp_i == i2 && temp_j == j2) // 도착지에 도달했다면
        {
            check = true; // check 변수를 true로 변경
            length = temp_length; // 그리고 그 경로에서 계산한 거리를 최종 최단거리 length에 넣어준다
            return;
        }
        Q.pop(); // 그전 경로에 대한 data(node)를 pop해준다
        maze[temp_i][temp_j] = 1; // 지난 길은 1로 표시해준다(이미 지나간 길은 다시 갈 수 없기 때문)

        for (int i = 0; i < 4; i++)
        {
            // 다음 경로는 현재 위치에서 0, 1, -1 의 값을 더해준다
            int next_i = temp_i + imove[i];
            int next_j = temp_j + jmove[i];
            if ((next_i < a && next_i >= 0) && (next_j < b && next_j >= 0) && maze[next_i][next_j] == 0) // 만약에 더해주고 나서의 값이 maze 행렬 안에 있다면(행렬 밖으로 벗어날 수도 있으므로), 그리고 다음 경로의 값이 0이라면(1이면 못 지나가므로)
                Q.push({ next_i,next_j,temp_length + 1 }); // 그 더해준 값을 다음 위치로 정해준뒤에 push해준다. 이때 거리는 당연히 1 더해서 넣어줘야 한다
            // 이 과정이 끝나면 4방향으로의 경로들이 큐에 들어간다(push). 다만, 위 조건을 만족하지 않는다면(만약 값이 1이라면 못지나가므로 그 경로는 빼야됨, 그리고 행렬을 벗어나는 경우 역시 제외), 그 방향의 값들은 애초에 push되지 않는다
        }
    }
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    // 미로 행렬 동적할당
    int** maze = new int* [a];
    for (int i = 0; i < a; i++)
        maze[i] = new int[b];
    // 미로 행렬에 input 값 넣어주기(11001 10001 등...미로를 구성하는 값을 채우는 과정)
    for (int i = 0; i < a; i++)
    {
        char* temp = new char[b + 1];
        cin >> temp;
        for (int j = 0; j < b; j++)
            maze[i][j] = temp[j] - '0';
        delete[] temp;
    }

    int i1, j1, i2, j2; // 출발지점과 도착지점 좌표
    cin >> i1 >> j1 >> i2 >> j2;

    BFS(i1 - 1, j1 - 1, maze, i2 - 1, j2 - 1, a, b); // BFS 알고리즘(함수)으로 들어간다
    // -1을 해주는 이유는 우리는 행렬에서의 좌표(세로, 가로)를 사용하지만, 문제에서는 x,y 좌표 꼴로 받아서 실제 행렬 값보다 1씩 높기 때문이다(x y 좌표에서는 행렬과 달리 시작이 1이므로)

    if (check)
        cout << length << endl;
    else // 혹시라도 도착을 못하는 경우
        cout << "Error with maze!" << endl;


    for (int i = 0; i < a; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}