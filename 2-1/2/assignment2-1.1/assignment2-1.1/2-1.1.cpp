#include <iostream> //iostream ����
#include <string.h> //strcmp �Լ� ����� ���� ����
using namespace std; //namespace std ����

int stack[128]; //������ �迭 stack����, �ִ� ũ�� 128

int locate = 0; //������ ��ġ�� �����ϱ� ���� locate ���� ����

void push(int num) //push �Լ�: ���ÿ� ��Ҹ� �ִ� ���
{
	if (locate == 128) //stack�� �ִ�ġ�� ���� 
	{
		cout << "You cannot push the elements anymore." << endl; //�ȳ��� ���
	}
	else //�� ���� ���
	{
		stack[locate] = num; //stack�� locate�ε����� num�� �߰�
		locate++; //locate ����
	}

	return;
} //push�Լ� ����

void pop(void) //���� ���� �ִ� ��Ҹ� ����ϰ� �����ϴ� �Լ�
{

	if (locate == 0) //���� ���ÿ� �ƹ��͵� ������
	{
		cout << "No elements exist." << endl; //�ȳ��� ���
	}
	else //�� �ܿ�
	{
		cout << stack[locate-1] << endl; //���� ���� ���� �ִ� ��Ҹ� ����Ѵ�. �̹� locate�� �����Ǿ��ִ� ��Ȳ�̱� ������ 1�� ���ҽ��Ѿ� �Ѵ�.
		stack[locate] = ' '; //pop��Ų �ε����� ������ ä���ش�.
		locate--; //�ε��� ����
	}

	return;
} //pop�Լ� ����

void top(void) //���� ���� �ִ� ��Ҹ� �����ִ� �Լ�
{
	if (locate == 0) //���� ���ÿ� �ƹ��͵� ������
	{
		cout << "No elements exist." << endl; //�ȳ��� ���
	}
	else //�� �ܿ�
	{
		cout << stack[locate - 1] << endl; //���� ���� �ִ� ��Ҹ� ����Ѵ�. pop�� ���������� �̹� �����Ǿ� �ִ� �����̱⿡ 1�� ���ҽ��Ѿ� �Ѵ�.
		}
	

	return;
} //top�Լ� ����

void print(void) //stack�� �ִ� ��ҵ��� ������ִ� �Լ�
{
	if (locate == 0) //���� �ƹ��͵� ������
	{
		cout << "No elements exist." << endl; //�ȳ��� ���
	}
	else //�� �ܿ�
	{
		for (int i = 0; i < locate; i++) //���� �׿��ִ� ��� ������ ��ҵ��� ������ش�.
			cout << stack[i] << " ";

		cout << endl;
	}

	return;
} //print�Լ� ����

int empty(void) //������ ������� �ƴ��� ��ȯ������ �����ִ� �Լ�
{
	if (locate == 0) //���ÿ� �ƹ��͵� ������
		return 1; //1�� ��ȯ
	else //���ÿ� ��� ��Ҷ� ������
		return 0; //0�� ��ȯ
} //empty�Լ� ����


int main() //main�Լ� ����
{
	char control[300]={0}; //command�� �Է¹��� control ���ڿ� ����
	int element = 0; //push�Լ��� �� ��Ҹ� ���� ���� ����

	
	while (1) //�ݺ��� (exit�� ���� ����ȴ�.)
	{
		cin >> control; //command�� �Է¹ޱ�
		if (!strcmp(control,"push")) //control�� push�� ������ strcmp�� ��ȯ���� 0�̴�. �� push��� �ܾ control�� �ԷµǸ�
		{
			cin >> element; //element�� �Է¹ް�
			push(element); //push�Լ��� ����
			
		}
		else if (!strcmp(control,"pop")) //control�� pop�� �ԷµǸ�
		{
			pop(); //pop�Լ� ����
		}
		else if (!strcmp(control, "top")) //control�� top�� �ԷµǸ�
		{
			top(); //top�Լ� ����
		}
		else if (!strcmp(control, "print")) //control�� print�� �ԷµǸ�
		{
			print(); //print�Լ� ����
		}
		else if (!strcmp(control, "empty")) //control�� empty�� �ԷµǸ�
		{
			cout << empty() << endl; //empty�Լ��� ��ȯ���� ���
		}
		else if (!strcmp(control, "exit")) //control�� exit�� �ԷµǸ�
		{
			break; //�ݺ��� ����
		}
		else //control�� �������� ���� command�� �ԷµǸ�
		{
			cout << "Wrong Command Entered. Please Try Again." << endl; //�ȳ��� ���
		}
	}

	return 0; //0�� ��ȯ
} //main�Լ� ����