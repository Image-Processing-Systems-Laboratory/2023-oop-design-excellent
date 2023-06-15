#include <iostream> //iostream����
using namespace std; //namespace std ����

const int visited = 1; //�湮�� ���� 1�� ����(���� ���� ���� �������� �� ���� �Ѵ�.)
const int unvisited = 0; //�ݴ�� �湮���� ���� ���� 0
const int wall = 1; //���� 1�� ����

void maze(int** world, int starty, int startx, int finaly, int finalx, int& countway, int row, int column, int again) //�̷��� �ִܰ�θ� ã�� �Լ�
{
    //�������� ����: world�� main�Լ����� �Է��� �̷�, starty&startx�� ������, finaly&finalx�� ������, countway�� �ִܰ���� ���̸� �ޱ� ���� ����
    //row�� coulumn�� �̷� ������ �� ���������� �ϱ� ���� ���� ����, again�� ���ȣ���� �ϸ鼭 ���� �����ϰ� �ǰ�, �ᱹ ���� �������� ������ again�� countway�� ���� �Ѱ��ش�.
    if (starty < 0 || startx < 0 ||starty >= column || startx >= row) //���� ���� ��ǥ�� ���� �����̰ų� �̷� ������ ����� ��
        return; //�Լ� ����
    if (world[starty][startx] != unvisited) //���� ��ǥ�� �湮�ߴ� ���̰ų� ���� ��
        return; //�Լ� ����
    if (starty == finaly && startx == finalx) //���� ������������ �����ߴٸ�
    {
        countway = again; //again�� countway�� ���� �Ѱ��ش�.
        return; //�� �� �Լ� ����
    }
    else //�� �ܿ� �� ���� �ִ� ���
    {
        world[starty][startx] = visited; //���ȣ���� ���� �� ���� �� ���� �ٽ� ���� ���� �����ϱ� ���� �湮�ߴٰ� ǥ��
        maze(world, starty + 1, startx, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty - 1, startx, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty, startx + 1, finaly, finalx, countway, row, column, again + 1);
        maze(world, starty, startx - 1, finaly, finalx, countway, row, column, again + 1); //������������ �Լ� ȣ��(startx�� starty���� ���� �� again�� 1 ����)
        world[starty][startx] = unvisited; //���ȣ���� ������ �ٽ� unvisited�� �ٲ㼭 �ٸ� ��쿡�� �� ��θ� ������ �� �ֵ��� ���󺹱�
    }
} //maze�Լ� ����


int main()
{
    int row = 0, column = 0; //row�� column ���� ����
    cin >> column >> row; //���� ����ó�� column row ������ �Է¹ޱ�

    char** arr = new char* [column]; //column��ŭ �̷θ� ���η� ����� (���⸦ ���� �ʰ� �Է¹ޱ� ������ �켱 char������ �Է¹ޱ�)
    int** path = new int* [column]; //char������ ���� ������ int���� path�� �Űܴ�� ���� ���� ����
    for (int i = 0; i < column; i++)
    {
        arr[i] = new char[row];
        path[i] = new int[row]; //row ���� ���̵� �����ϰ� ����
        for (int j = 0; j < row; j++)
        {
            cin >> arr[i][j]; //arr�� ���ʴ�� �Է¹ޱ�
            //���ÿ� path�� �������� �־��ֱ�
            if (arr[i][j] == '1') //���� ���� 1�� �Է¹�����
            {
                path[i][j] = wall; //path�� wall, �� 1�� �Է�
            }
            else //�� ���� ���(���� 0�� �Է¹޾��� ��)
            {
                path[i][j] = unvisited; //path�� 0�� �Է�
            }
        }
    }

    int firstx = 0, firsty = 0, lastx = 0, lasty = 0; 
    cin >> firstx >> firsty >> lastx >> lasty; //��� ��ǥ�� ���� ��ǥ �Է¹ޱ�
    int countway = 0; //�ִܰŸ��� ����� ���� ����

    maze(path, firsty - 1, firstx - 1, lasty - 1, lastx - 1, countway, row, column, 1);
    //maze�Լ��� path�迭, ������ǥ�� ������ǥ, countway�� ��� �� ������, �׸��� again�� �ʱ갪 1�� �Ѱ��ش�.

    cout << countway << endl; //�ִܰ�� ���

    for (int i = 0; i < column; i++)
    {
        delete[] arr[i];
        delete[] path[i];
    }
    delete[] arr;
    delete[] path; //����ߴ� �迭���� �����Ҵ� ����

    return 0; //0�� ��ȯ
} //main�Լ� ����