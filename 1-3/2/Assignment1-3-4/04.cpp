#include<iostream>

using namespace std;

void bubbleUp(int list[], int current, int last);
int bubbleSort(int list[], int last);
void insertOne(int list[], int current);
void insertionSort(int list[], int last);
void merge(int list[], int left, int mid, int right);
void mergeSort(int list[], int left, int right);
void quick(int list[], int left, int& pivot, int right);
void quickSort(int list[], int left, int right);

int main()
{
	int num;
	cout << "Input: ";
	cin >> num;

	/* 4���� �����Լ��� ���� ���ĵ� �迭�� ������ �����Ҵ�*/
	int** arr = new int* [4];
	for (int i = 0; i < 4; i++) {
		arr[i] = new int[num];
	}
	/* ����ڷκ��� �� �Է� �ޱ�*/
	for (int j = 0; j < num; j++)
		cin >> arr[0][j];
	/* ������ �迭�鿡�� �Ȱ��� ����*/
	for (int j = 0; j < num; j++) {
		arr[1][j] = arr[0][j];
		arr[2][j] = arr[0][j];
		arr[3][j] = arr[0][j];
	}
	
	/* Bubble Sort ���� �� ���*/
	int median = bubbleSort(arr[0], num - 1);
	cout << endl << "Bubble Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[0][j];
	/* Insertion Sort ���� �� ���*/
	insertionSort(arr[1], num - 1);
	cout << endl << "Insertion Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[1][j];
	/* Merge Sort ���� �� ���*/
	mergeSort(arr[2], 0, num - 1);
	cout << endl << "Merge Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[2][j];
	/* Quick Sort ���� �� ���*/
	quickSort(arr[3], 0, num - 1);
	cout << endl << "Quick Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[3][j];
	cout << endl << "Media number: " << median;
	
	/* �����Ҵ� ����*/
	for (int i = 0; i < 4; i++) {
		delete[]arr[i];
	}
	delete[] arr;
}

/* Bubble Sort*/
void bubbleUp(int list[], int current, int last) {
	/* �迭�� �޺κп������� ��*/
	for (int walker = last; walker > current; walker--) {
		/* walker�ε����� ���� �ٷ� �� �ε����� ������ ������ swap*/
		if (list[walker] < list[walker - 1]) {
			int temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp;
		}
	}
	return;
}
int bubbleSort(int list[], int last) {
	for (int current = 0; current < last; current++)
		bubbleUp(list, current, last);
	
	return list[last / 2];
}

/* Insertion Sort*/
void insertOne(int list[], int current) {
	bool located = false; // current�ε����� ���� ������ ��ġ�� ã���� true
	int temp = list[current]; // ���� �ε����� ���� temp�� �ӽ�����
	int walker; // temp�� ���� �ε���
	/* temp���� ������ ����� �� ����*/
	for (walker = current - 1; walker >= 0 && !located;) {
		/* temp�� �񱳴�󺸴� ������, ���������� �б�*/
		if (temp < list[walker]) {
			list[walker + 1] = list[walker];
			walker--;
		}
		/* temp�� �񱳴�󺸴� ũ��, located�� true�ٲ㼭 �ݺ��� Ż��*/
		else located = true;
	}
	list[walker + 1] = temp; // �񱳴�� �����ʿ� temp ����
	return;
}
void insertionSort(int list[], int last) {
	for (int current = 1; current <= last; current++)// insertOne�� current-1���� �迭�� �����ϹǷ� 1���� ����
		insertOne(list, current);
	return;
}

/* Merge Sort*/
void merge(int list[], int left, int mid, int right) {
	int* arr = new int[right - left + 1]; // ������ ���� ũ�⸸ŭ �����Ҵ�
	int idx = 0;
	int l = left;
	int m = mid;
	int r = right;
	
	/*���� ������ ������ ������ ù��° �ε������� ũ����ϸ� ���� ���� arr�� �����ϱ�*/
	while (l < mid && m <= right) {
		if (list[l] < list[m])
			arr[idx++] = list[l++];
		else
			arr[idx++] = list[m++];
	}

	/* ���� ������ �ε����� ������ ������ ���*/
	if (l == mid) {
		for (; m <= right;) // ������ ������ �����ִ� ������ arr�� ����
			arr[idx++] = list[m++];
	}
	/* ������ ������ �ε����� ������ ������ ���*/
	else if (m > right) {
		for (; l < mid;) // ���� ������ �����ִ� ������ arr�� ����
			arr[idx++] = list[l++];
	}

	/* ���ĵ� �迭 arr�� list�� ������ �ε����� ����*/
	for (int i = 0; left <= right;)
		list[left++] = arr[i++];
	delete[]arr;
}
void mergeSort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid); // �и��� ���� �迭�� ���
		mergeSort(list, mid + 1, right); // �и��� ������ �迭�� ���
		merge(list, left, mid + 1, right); // ���� �� �պ�
	}
}

/* Quick Sort*/
void quick(int list[], int left, int& pivot, int right) {
	int l = left;
	int r = right;
	int tmp = list[pivot]; // pivot�� �� tmp�� �ӽ�����
	
	while (1) {
		/* �迭�� �����ʿ������� tmp������ ���� �� Ž�� */
		while (list[r] > tmp && r > l)
			r--;
		if (r == l) // �ݺ��� Ż�� ����
			break;
		else { // tmp���� ���� �� Ž���ϸ� �ε��� l�� ����
			list[l] = list[r];
			l++;
		}
		/* �迭�� ���ʿ������� tmp������ ū �� Ž�� */
		while (list[l] < tmp && l < r)
			l++;
		if (r == l) // �ݺ��� Ż�� ����
			break;
		else { // tmp���� ū �� Ž���ϸ� �ε��� r�� ����
			list[r] = list[l];
			r--;
		}
	}
	/* l�� r�� �������� �ݺ����� Ż���ߴٴ� ���� �ε��� l�� ����ִٴ� ��*/
	pivot = l; // pivot�� l�� ����
	list[pivot] = tmp; // �ӽ������� �� ������ ����
}
void quickSort(int list[], int left, int right) {
	
	if (left < right) {
		int pivot = left; // pivot ������ �� �� index���� ����.
		quick(list, left, pivot, right); // pivot���� �������� �������� ū ���� ���������� ����
		quickSort(list, left, pivot - 1); // pivot ���ʺκ� ���
		quickSort(list, pivot + 1, right); // pivot �����ʺκ� ���
	}
}