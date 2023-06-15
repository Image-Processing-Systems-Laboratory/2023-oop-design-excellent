#include <iostream>
using namespace std;

class go // �⺻������ int�� ������ �ϳ��� �ƴϰ� �Ʒ��� ���� �������̹Ƿ� class�� ���� ���� ���������
{
public:
    int y; // ������ǥ
    int x; // ������ǥ
    int length; // �ִܰ�� ã�� ����(�� ��ο� ���븦 ���涧 ���, �׸��� �� ���밡 �ּ��� ��ΰ� �ִܰ�ΰ� �ȴ�)
};

class Queue // queue�� Ŭ������ �̿��� ����(�� queue�� ����ϴ����� ���� �ڼ��� ������ �������� ����)
{
private:
    class Node // ��� �⺻�� ����
    {
    public:
        go data; // data���� ������ ���ߵ� �������� ���Եž� �ϹǷ�, ������ ������ Ŭ������ go������ �����͸� �������ش�
        Node* next; // ���� ���
    };
    // queue�� front�� rear�� �����Ѵ�. front�� pop������ �������� �κ�, rear�� push������ ���� �κ��̴�.
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) // front�� rear�� ó�� �����ÿ��� �翬�� null�� �ʱ�ȭ
    {
        // �̴ϼȶ������� ���� �̹� ó���߰�, �����ڿ��� ���� ������ ����
    }

    void push(go val) // stack�� �ٸ��� queue�� ���Լ��ⱸ���̹Ƿ�, stack�� push ����� �ణ �ٸ���
    {
        Node* newNode = new Node{ val, nullptr };
        if (rear == nullptr) // queue�� ��尡 �ϳ��� ���� ���
            front = rear = newNode; // front, rear ��� �� ���� �������ش�
        else
        {
            rear->next = newNode; // queue�� �� ��带 �޴� �κ��� rear��.
            rear = newNode;
        }
    }

    void pop() // pop ���� stack�� �ٸ���
    {
        Node* prevFront = front; // ó�� �ִ� ���� front�� �����Ѵ�
        front = front->next; // front�� ���� ���� �����ְ�
        if (front == nullptr) // �׷����� front�� null�� ���(��尡 ����)
            rear = nullptr; // rear�� null�� �ȴ�
        delete prevFront; // front�ٷ� �� ���(front�� �ִ� ���) ����(pop)
    }

    go getfront() // front ��� �� ��ȯ
    {
        return front->data;
    }

    bool empty() // queue�� ����ִ��� Ȯ�����ִ� bool �Լ�
    {
        return front == nullptr;
    }
};

bool check = false; // �������� �����ߴ����� ���� ���θ� Ȯ���ϱ� ���� check ����
int length = 0; // �ִ� ����� length�� ��������(��, �ִܰŸ�)

void BFS(int i1, int j1, int** maze, int i2, int j2, int a, int b)
{
    Queue Q;
    int imove[4] = { 0,0,1,-1 }; // ���� ������(����). �����¿� 4�����̹Ƿ� ������ ���� ���� 4�� �迭�� ���־���
    int jmove[4] = { 1,-1,0,0 }; // �¿� ������(����)
    Q.push({ i1,j1,1 }); // i1, j1���� ����. �׸��� path�� ��� ��� ���� ���� �Ÿ��� �����ϹǷ� 1�� push���ش�
    while (!Q.empty())
    {
        int temp_i = Q.getfront().y, temp_j = Q.getfront().x; // ���� ��ġ�� temp_i, temp_j�� ����. ��Ȯ���� �ִܰ���� ���� ��ǥ�� ����
        int temp_length = Q.getfront().length; // ���� ���� ����
        if (temp_i == i2 && temp_j == j2) // �������� �����ߴٸ�
        {
            check = true; // check ������ true�� ����
            length = temp_length; // �׸��� �� ��ο��� ����� �Ÿ��� ���� �ִܰŸ� length�� �־��ش�
            return;
        }
        Q.pop(); // ���� ��ο� ���� data(node)�� pop���ش�
        maze[temp_i][temp_j] = 1; // ���� ���� 1�� ǥ�����ش�(�̹� ������ ���� �ٽ� �� �� ���� ����)

        for (int i = 0; i < 4; i++)
        {
            // ���� ��δ� ���� ��ġ���� 0, 1, -1 �� ���� �����ش�
            int next_i = temp_i + imove[i];
            int next_j = temp_j + jmove[i];
            if ((next_i < a && next_i >= 0) && (next_j < b && next_j >= 0) && maze[next_i][next_j] == 0) // ���࿡ �����ְ� ������ ���� maze ��� �ȿ� �ִٸ�(��� ������ ��� ���� �����Ƿ�), �׸��� ���� ����� ���� 0�̶��(1�̸� �� �������Ƿ�)
                Q.push({ next_i,next_j,temp_length + 1 }); // �� ������ ���� ���� ��ġ�� �����صڿ� push���ش�. �̶� �Ÿ��� �翬�� 1 ���ؼ� �־���� �Ѵ�
            // �� ������ ������ 4���������� ��ε��� ť�� ����(push). �ٸ�, �� ������ �������� �ʴ´ٸ�(���� ���� 1�̶�� ���������Ƿ� �� ��δ� ���ߵ�, �׸��� ����� ����� ��� ���� ����), �� ������ ������ ���ʿ� push���� �ʴ´�
        }
    }
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    // �̷� ��� �����Ҵ�
    int** maze = new int* [a];
    for (int i = 0; i < a; i++)
        maze[i] = new int[b];
    // �̷� ��Ŀ� input �� �־��ֱ�(11001 10001 ��...�̷θ� �����ϴ� ���� ä��� ����)
    for (int i = 0; i < a; i++)
    {
        char* temp = new char[b + 1];
        cin >> temp;
        for (int j = 0; j < b; j++)
            maze[i][j] = temp[j] - '0';
        delete[] temp;
    }

    int i1, j1, i2, j2; // ��������� �������� ��ǥ
    cin >> i1 >> j1 >> i2 >> j2;

    BFS(i1 - 1, j1 - 1, maze, i2 - 1, j2 - 1, a, b); // BFS �˰���(�Լ�)���� ����
    // -1�� ���ִ� ������ �츮�� ��Ŀ����� ��ǥ(����, ����)�� ���������, ���������� x,y ��ǥ �÷� �޾Ƽ� ���� ��� ������ 1�� ���� �����̴�(x y ��ǥ������ ��İ� �޸� ������ 1�̹Ƿ�)

    if (check)
        cout << length << endl;
    else // Ȥ�ö� ������ ���ϴ� ���
        cout << "Error with maze!" << endl;


    for (int i = 0; i < a; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}