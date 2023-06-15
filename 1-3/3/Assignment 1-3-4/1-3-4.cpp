#include <iostream>
#include <Windows.h>
using namespace std;

void insertone(int list[], int current);
void insertionSort(int list[], int last);
void bubbleUp(int list[], int current, int last);
void bubbleSort(int list[], int last);
void merge(int list[], int start, int mid, int end);
void mergeSort(int list[], int start, int end);
void quickSort(int list[], int start, int end);

int main() {
	int n, arr[100];

	// �Է� Ƚ�� �Է� �ޱ�
	cin >> n;
	// ���� ¦���� �Է����� ��� ���α׷� ����
	if (n % 2 == 0) {
		cout << "Enter odd number!";
		return 0;
	}

	// ������ ������ �Է�
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// ���� (�� ���� �߿� �ϳ��� ���Ͽ� ���)

	insertionSort(arr, n - 1);
	//bubbleSort(arr, n - 1);
	//mergeSort(arr, 0, n - 1);
	//quickSort(arr, 0, n - 1);

	// ���ĵ� ���� ���
	cout << "Sorted order : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	// �߰��� ���
	cout << "Median number : " << arr[n / 2];
	return 0;
}

void insertone(int list[], int current) {
	bool located = false;
	int temp = list[current];
	int walker;
	// �� �Ŀ� ������ �����ϱ�
	for (walker = current - 1; walker >= 0 && !located;) {
		if (temp < list[walker]) {
			list[walker + 1] = list[walker];
			walker--;
		}
		else located = true;
	}
	list[walker + 1] = temp;
	return;
}
void insertionSort(int list[], int last) {
	// ������ ������ ���� ���� �Űܰ��� �ݺ�
	for (int current = 1; current <= last; current++) {
		insertone(list, current);
	}
	return;
}
void bubbleUp(int list[], int current, int last) {
	// �ڿ������� ���� ���Ͽ� ���� ���� ���� �ҷ���
	for (int walker = last; walker > current; walker--) {
		if (list[walker] < list[walker - 1]) {
			int temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp;
		}
	}
	return;
}
void bubbleSort(int list[], int last) {
	// ������ ������ �� ���� �κк��� ����Ͽ� ����
	for (int current = 0; current < last; current++)
		bubbleUp(list, current, last);
	return;
}
void merge(int list[], int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	int sorted[100];

	// ���� ���ϰ� ������ �Ŀ� ��ħ
	while (i <= mid && j <= end) {
		// list[i] < list[j]�� ���
		if (list[i] <= list[j]) {
			sorted[k] = list[i];
			i++;
		}
		else {
			// list[i] > list[j]�� ���
			sorted[k] = list[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = list[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = list[t];
			k++;
		}
	}

	// ���ĵ� �迭�� ����
	for (int t = start; t <= end; t++) {
		list[t] = sorted[t];
	}
}
void mergeSort(int list[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(list, start, mid); // ������ ���� ���� �κ� 
		mergeSort(list, mid + 1, end); // ������ ���� ������ �κ�
		merge(list, start, mid, end); // ��ġ��
	}
}
void quickSort(int list[], int start, int end) {
	// ���Ұ� 1���� ���
	if (start >= end) {
		return;
	}

	int pivot = start; // ó�� ���� pivot���� ����
	int i = pivot + 1; // ���� ���� ���� 
	int j = end; // ������ ���� ����
	int temp;

	while (i <= j) {
		// ������������ �ݺ�
		while (i <= end && list[i] <= list[pivot]) {
			i++;
		}
		while (j > start && list[j] >= list[pivot]) {
			j--;
		}

		if (i > j) {
			// ������
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else {
			// i��°�� j��°�� ��ȯ�ϱ�
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}

	// �����Ͽ� ���
	quickSort(list, start, j - 1);
	quickSort(list, j + 1, end);
}