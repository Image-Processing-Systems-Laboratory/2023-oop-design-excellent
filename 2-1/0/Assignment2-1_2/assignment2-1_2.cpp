#include<iostream>
using namespace std;

#define MAX 30		//�̷��� �ִ� ũ��

//�������� ����
char Maze[MAX][MAX];	//�̷θ� �����ϴ� 2���� �迭 ����
int len_Path[MAX];	//�̷� ���������� ���̸� ������
int col, row;	//��� ���� �����ϴ� ���� ����
int way = 0;		//�̷θ� Ż���� �� �ִ� ���� ��

//�Լ� ����
void Maze_Out(int start_x, int start_y, int dest_x, int dest_y, int path);	//�̷��� �ⱸ�� ���޽����ִ� �Լ�
int shortest_Path();		//�̷��� ���� �ִܰŸ� ���� ��ȯ���ִ� �Լ�

//x, y ��ǥ ����ü ����
typedef struct coordinate
{
	int x;		//x��ǥ
	int y;		//y��ǥ
}Coor;

int main()
{
	Coor start, dest;	//��������, �������� ��ǥ �����ϴ� ����ü ���� ����
	int path = 0;		//������ ���� ����
	cout << "col, row" << endl;
	cin >> col >> row;	//��� �� �Է¹ޱ�

	cout << "Maze" << endl;
	//�̷� ���� �Է¹ޱ�
	for (int i = 0;i < col;i++)
		for (int j = 0;j < row;j++)
			cin >> Maze[i][j];

	//���������� �������� �Է¹ޱ�
	cout << "start, end Coordinate" << endl;
	cin >> start.x >> start.y >> dest.x >> dest.y;
	
	//�̷θ� �ⱸ�� ���޽����ִ� �Լ� ȣ��
	Maze_Out(start.x - 1, start.y - 1, dest.x - 1, dest.y - 1, path);
	
	if (way == 0)		//Ż���� �� ������
		cout << "No way" << endl;
	else				//Ż�� �����ϸ�
		cout << shortest_Path() << endl;	//������ ������ �ִܰŸ��� ���
		
	return 0;
}
//�̷��� �ⱸ�� ���޽����ִ� �Լ�
void Maze_Out(int start_x, int start_y, int dest_x, int dest_y, int path) {
	//�̷� ���� ����� ���
	if (start_x < 0 || start_y < 0 || start_x >= row || start_y >= col )
		return ;
	//�������� �����ϴ°��
	else if (start_x == dest_x && start_y == dest_y)
	{
		//�̷��� �������� ����
		len_Path[way++] = path + 1;
	}

	//�̹� ������ ���̰ų� ���� ���
	else if (Maze[start_y][start_x] != '0')
		return ;
	else
	{
		//�̹� �����±��� '2'�� ������
		Maze[start_y][start_x] = '2';
		//���������� �̵�
		Maze_Out(start_x + 1, start_y, dest_x, dest_y, path + 1);
		//�������� �̵�
		Maze_Out(start_x - 1, start_y, dest_x, dest_y, path + 1);
		//���� �̵�
		Maze_Out(start_x, start_y + 1, dest_x, dest_y, path + 1);
		//�Ʒ��� �̵�
		Maze_Out(start_x, start_y - 1, dest_x, dest_y, path + 1);
		Maze[start_y][start_x] = '0';	//�������� �� �ٽ� '0'(��)���� �ʱ�ȭ
	}
}
//�̷��� ���� �ִܰŸ� ���� ��ȯ���ִ� �Լ�
int shortest_Path() {
	int Min = MAX * MAX;			//�ּҰ��� ��������
	//���� ������ ã��
	for (int i = 0; i < way; i++)
	{
		if (len_Path[i] < Min)		//Min������ ���� ���
			Min = len_Path[i];		//���� ���� �� ����
	}
	return Min;		//�ִ� �Ÿ� ��ȯ
}

