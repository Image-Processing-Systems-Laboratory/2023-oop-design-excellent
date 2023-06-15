#include <iostream>
#include <string>


using namespace std;

struct node {
	char arr[21] = {0};
	node* next = NULL;//�������� ���
	node* sub = NULL;//������ �İ� ���� ������
	node* prev_depth = NULL;// �İ�������� ����� �ּҰ��� ��� ������
};



void print_arr(node* head, char* command);
void print_sub(node* head);
void mem(node* current);




int main() {

	string total;//ó�� �Է¹޴� ���ڿ��� ���� ����
	node* head = new node;//���� ��带 ����Ű�� ���
	node* current = head;//�����带 ����Ű�� ���
	int count = 0;//���ڿ��� �����Ͽ����� �ε����� ǥ������

	


	getline(cin,total);//�Է°��� ����
	
	const char* loop = total.c_str();//string ���� ���ڿ� �����Ϳ� ����

	while (*++loop != NULL) {
		if (*loop == ' ') {
			continue;//��ĭ�� ������ �� ���� �Է¹��� ����
		}

		if (*loop == '[') {//�ε����� ������ ������ �İ� ���� ��� ����
			node* make = new node; 
			current->sub = make;// �迭�� ����Ű�� ��忡 sub ����� ���� �˸�
			make->prev_depth = current;// ���� ǥ��
			current = make;
			count = 0;
			continue;
			
			
		}


		else if (*loop == ',') {//��ǥ�� ������ ����ϳ� ����

				node* make = new node;
				current->next = make;
				make->prev_depth = current->prev_depth;//���� ���� ����ؼ� ǥ��
				current = make;
				count = 0;
				continue;
				
	
		}

		else if (*loop ==	']') {
			current = current->prev_depth;//���� ���������� �ǵ��ƿ� 
			continue;
			
		}
	
		
		current->arr[count] = *loop;
		count++;
		
	
	}

	

	while (true) {

		char* command = new char[100000];//�Է°��� ������ ����
	
		cin >> command;

		if (!strcmp(command, "exit")) {
			break;
		}
	
				
		if (strncmp(command, "arr",3)) {// �Է°��� arr�� �ƴҰ�� �ٽ� �Է��� �ް� ��
			cout << "invalid value" << endl;;
			continue;
		}

		print_arr(head, command);

		cout << endl;
	}// exit�� �Է� �� �� ���� �ݺ�

	mem(head);// �޸� �Ҵ�����
	
}


void print_sub(node* head) {

	node* current = head;

	cout << '[';
	
	while (current != NULL) {
		cout << current->arr; //���� ��尡 ���� �ִ� ���ڿ� ���



		if (current->next != NULL) {

			if (current->sub != NULL) {

			}
			else { cout << ", "; };// ���� ��尡 ������ ��� ��ǥ ���

		}


		if (current->sub != NULL) {
			print_sub(current->sub);//sub ��尡 �����Ұ�� ��������� �Լ��� ȣ���Ͽ� �ε��� ���
			if (current->next != NULL) {
				cout << ", ";// ���� ��尡 ������ ��� ��ǥ ���
			}
		}

		current = current->next;// ���� ���� �̵�
	}
	cout << ']';


}



void print_arr(node* head, char* command) {


	int count = -1;
	int* index = new int[1000];

	while (*command != NULL) {

		if (*command == '[') {
			count++;
			index[count] = 0;// index[count]�� �� �ʱ�ȭ
			while (isdigit(*(command+ 1))) {
				index[count] *= 10;
				index[count] += ( * (command + 1) - 48);//�ε������� ���� �������� 
				index[count + 1] = -1;//�ε����� ���� ǥ���ϱ� ���� ���� ����
			
				command++;
			}
	
			continue;
			}
		command++;
	}

	node* current = head;
	char pass[] = "pass";// ����Լ��� ���� ���� ���ڿ�


	
	if (count == -1) {
		print_sub(head);// ��ü ��� ���

	}


	if (count != -1) {// �ε����� ������ ��� 
		int new_index = 0;
		while (index[new_index] != -1) {// �ε����� ����ŭ �ݺ��� �ݺ�

			for (int i = index[new_index]; i > 0; i--) {
				current = current->next;// ���� ���� �̵�
			
			}
			if (index[new_index + 1] != -1) {
				current = current->sub;//sub�� �����ϴ� ����� ��ġ �����Ͽ��⿡ sub node�� �̵�
			}
			new_index++;
			
		}


		if (current->sub!= NULL) {// ������ ��尡 �迭 ����ϰ�� 
				print_sub(current->sub);
			
			}//�迭 ����� ��ü ���
		
		
	
		else {
		
			cout << current->arr;// �迭��尡 �ƴ� ��� ����� ���ڿ� ���
		
		}


	
	}

	
	}

void mem(node* current) {

    if (current == NULL) {
        return;
    }
	if (current->sub != NULL) {
		mem(current->sub);// sub ��尡 �����ҽ� ��������� �Լ��� ȣ���Ͽ� �����޸� ����
	}

	else if(current->next!=NULL) {
		mem(current->next);//sub ��尡 �������� ���� ��� ���� ���� �̵�
		
	}
	delete current;// ������ ��� ������ �Ҵ�����
}

	

