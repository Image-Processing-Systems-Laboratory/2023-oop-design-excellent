#include "List.h"
#include <iostream>

using namespace std;


void insertionSort(Node* head) {		// ���� ����
	Node* ptr = head;
	for (int i = 1; ; i++) {
		int key = head[i].getData();		// ����
		int j = i - 1;

		while (j >= 0 && head[j] < key) {		// ū ���
			head[j + 1] = head[j];
			j--;
		}

		head[j + 1] = key;
		if ((++ptr)->getNext() == nullptr)		// �������� ��� ����
			break;
	}
}


Node& Binary_Search(Node* p, int n) {
	Node* ptr = p;
	size_t len = 0;			// ����
	int prev = 1000;		// 0~200 �̹Ƿ� 1000 ����
	// ��ȸ�ϸ� �˻�
	while (ptr) {
		// ������ �ȵ����� ���� ���� ����
		if (*ptr > prev) {
			cout << "Commence sorting" << endl;
			insertionSort(p);
		}
		else if (*ptr == prev) {
			cout << "Commence sorting" << endl;
			insertionSort(p);
		}
		len++;
		prev = ptr->getData();
		ptr = ptr->getNext();
	}
	
	// ���� Ž�� ����
	ptr = p;

	int temp = 0;			// ���� �񱳸� ���� �ӽ� ��
	size_t low = 0;
	size_t high = len-1;
	size_t mid = (low + high) / 2;
	while (low <= high && high ) {
		mid = (low + high) / 2;
		cout << ptr[mid];
		temp = ptr[mid].getData();
		if (temp < n) {		// ���� ���
			high = mid-1;
			cout << " -> ";
		}
		else if (temp > n) {		// Ŭ ���
			low = mid+1;
			cout << " -> ";
		}
		else {		// ���� ���
			cout << endl;
			return ptr[mid];
		}
	}
	cout << endl;
	cout << "Unable to find " << n << endl;
	if (abs(ptr[low].getData() - n) < abs(ptr[high].getData() - n)) {		// ������ �� ���� ���� ��ȯ
		return ptr[low];
	}
	else {
		return ptr[high];
	}
}

int main() {
	List list(16);		// 16���� unique�� ���� ��忡 �Ҵ�
	Node* p = list.getRoot();
	list.print();
	char cmd;
	do {
		cin >> cmd;
		if (cmd == 'f') {		// Binary_Search
			int num;
			cin >> num;
			cout << "result: " << Binary_Search(p, num) << endl;		// �ش� ��� ��ȯ �� ���
		}
		else if (cmd == 'p') {	// print list
			list.print();
		}
	} while (cmd != 'b');		// break
}
