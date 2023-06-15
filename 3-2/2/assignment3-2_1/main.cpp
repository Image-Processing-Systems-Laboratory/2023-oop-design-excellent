#include "List.h"
#include <iostream>

using namespace std;


void insertionSort(Node* head) {		// 삽입 정렬
	Node* ptr = head;
	for (int i = 1; ; i++) {
		int key = head[i].getData();		// 기준
		int j = i - 1;

		while (j >= 0 && head[j] < key) {		// 큰 경우
			head[j + 1] = head[j];
			j--;
		}

		head[j + 1] = key;
		if ((++ptr)->getNext() == nullptr)		// 마지막일 경우 종료
			break;
	}
}


Node& Binary_Search(Node* p, int n) {
	Node* ptr = p;
	size_t len = 0;			// 길이
	int prev = 1000;		// 0~200 이므로 1000 설정
	// 순회하며 검사
	while (ptr) {
		// 정렬이 안됐으면 삽입 정렬 시행
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
	
	// 이진 탐색 개시
	ptr = p;

	int temp = 0;			// 절댓값 비교를 위한 임시 값
	size_t low = 0;
	size_t high = len-1;
	size_t mid = (low + high) / 2;
	while (low <= high && high ) {
		mid = (low + high) / 2;
		cout << ptr[mid];
		temp = ptr[mid].getData();
		if (temp < n) {		// 작을 경우
			high = mid-1;
			cout << " -> ";
		}
		else if (temp > n) {		// 클 경우
			low = mid+1;
			cout << " -> ";
		}
		else {		// 같을 경우
			cout << endl;
			return ptr[mid];
		}
	}
	cout << endl;
	cout << "Unable to find " << n << endl;
	if (abs(ptr[low].getData() - n) < abs(ptr[high].getData() - n)) {		// 절댓값이 더 작은 값을 반환
		return ptr[low];
	}
	else {
		return ptr[high];
	}
}

int main() {
	List list(16);		// 16개의 unique한 정수 노드에 할당
	Node* p = list.getRoot();
	list.print();
	char cmd;
	do {
		cin >> cmd;
		if (cmd == 'f') {		// Binary_Search
			int num;
			cin >> num;
			cout << "result: " << Binary_Search(p, num) << endl;		// 해당 노드 반환 및 출력
		}
		else if (cmd == 'p') {	// print list
			list.print();
		}
	} while (cmd != 'b');		// break
}
