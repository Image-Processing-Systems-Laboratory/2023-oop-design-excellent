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

	/* 4개의 정렬함수를 통해 정렬된 배열을 저장할 동적할당*/
	int** arr = new int* [4];
	for (int i = 0; i < 4; i++) {
		arr[i] = new int[num];
	}
	/* 사용자로부터 수 입력 받기*/
	for (int j = 0; j < num; j++)
		cin >> arr[0][j];
	/* 나머지 배열들에도 똑같이 복사*/
	for (int j = 0; j < num; j++) {
		arr[1][j] = arr[0][j];
		arr[2][j] = arr[0][j];
		arr[3][j] = arr[0][j];
	}
	
	/* Bubble Sort 정렬 및 출력*/
	int median = bubbleSort(arr[0], num - 1);
	cout << endl << "Bubble Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[0][j];
	/* Insertion Sort 정렬 및 출력*/
	insertionSort(arr[1], num - 1);
	cout << endl << "Insertion Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[1][j];
	/* Merge Sort 정렬 및 출력*/
	mergeSort(arr[2], 0, num - 1);
	cout << endl << "Merge Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[2][j];
	/* Quick Sort 정렬 및 출력*/
	quickSort(arr[3], 0, num - 1);
	cout << endl << "Quick Sorted order:";
	for (int j = 0; j < num; j++)
		cout << " " << arr[3][j];
	cout << endl << "Media number: " << median;
	
	/* 동적할당 해제*/
	for (int i = 0; i < 4; i++) {
		delete[]arr[i];
	}
	delete[] arr;
}

/* Bubble Sort*/
void bubbleUp(int list[], int current, int last) {
	/* 배열의 뒷부분에서부터 비교*/
	for (int walker = last; walker > current; walker--) {
		/* walker인덱스의 수가 바로 앞 인덱스의 수보다 작으면 swap*/
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
	bool located = false; // current인덱스의 수가 적절한 위치를 찾으면 true
	int temp = list[current]; // 현재 인덱스의 수를 temp에 임시저장
	int walker; // temp와 비교할 인덱스
	/* temp보다 왼쪽의 수들과 비교 시작*/
	for (walker = current - 1; walker >= 0 && !located;) {
		/* temp가 비교대상보다 작으면, 오른쪽으로 밀기*/
		if (temp < list[walker]) {
			list[walker + 1] = list[walker];
			walker--;
		}
		/* temp가 비교대상보다 크면, located를 true바꿔서 반복문 탈출*/
		else located = true;
	}
	list[walker + 1] = temp; // 비교대상 오른쪽에 temp 저장
	return;
}
void insertionSort(int list[], int last) {
	for (int current = 1; current <= last; current++)// insertOne이 current-1부터 배열을 참조하므로 1부터 시작
		insertOne(list, current);
	return;
}

/* Merge Sort*/
void merge(int list[], int left, int mid, int right) {
	int* arr = new int[right - left + 1]; // 나눠진 구간 크기만큼 동적할당
	int idx = 0;
	int l = left;
	int m = mid;
	int r = right;
	
	/*왼쪽 구간과 오른쪽 구간의 첫번째 인덱스부터 크기비교하며 작은 것을 arr에 저장하기*/
	while (l < mid && m <= right) {
		if (list[l] < list[m])
			arr[idx++] = list[l++];
		else
			arr[idx++] = list[m++];
	}

	/* 왼쪽 구간의 인덱스가 끝까지 진행한 경우*/
	if (l == mid) {
		for (; m <= right;) // 오른쪽 구간에 남아있는 수들을 arr에 저장
			arr[idx++] = list[m++];
	}
	/* 오른쪽 구간의 인덱스가 끝까지 진행한 경우*/
	else if (m > right) {
		for (; l < mid;) // 왼쪽 구간에 남아있는 수들을 arr에 저장
			arr[idx++] = list[l++];
	}

	/* 정렬된 배열 arr을 list의 적절한 인덱스에 저장*/
	for (int i = 0; left <= right;)
		list[left++] = arr[i++];
	delete[]arr;
}
void mergeSort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(list, left, mid); // 분리된 왼쪽 배열을 재귀
		mergeSort(list, mid + 1, right); // 분리된 오른쪽 배열을 재귀
		merge(list, left, mid + 1, right); // 정렬 및 합병
	}
}

/* Quick Sort*/
void quick(int list[], int left, int& pivot, int right) {
	int l = left;
	int r = right;
	int tmp = list[pivot]; // pivot의 값 tmp에 임시저장
	
	while (1) {
		/* 배열의 오른쪽에서부터 tmp값보다 작은 값 탐색 */
		while (list[r] > tmp && r > l)
			r--;
		if (r == l) // 반복문 탈출 조건
			break;
		else { // tmp보다 작은 값 탐색하면 인덱스 l에 저장
			list[l] = list[r];
			l++;
		}
		/* 배열의 왼쪽에서부터 tmp값보다 큰 값 탐색 */
		while (list[l] < tmp && l < r)
			l++;
		if (r == l) // 반복문 탈출 조건
			break;
		else { // tmp보다 큰 값 탐색하면 인덱스 r에 저장
			list[r] = list[l];
			r--;
		}
	}
	/* l과 r이 같아져서 반복문을 탈출했다는 것은 인덱스 l이 비어있다는 뜻*/
	pivot = l; // pivot을 l로 변경
	list[pivot] = tmp; // 임시저장해 둔 데이터 복구
}
void quickSort(int list[], int left, int right) {
	
	if (left < right) {
		int pivot = left; // pivot 기준은 맨 앞 index으로 정함.
		quick(list, left, pivot, right); // pivot보다 작은수는 왼쪽으로 큰 수는 오른쪽으로 정렬
		quickSort(list, left, pivot - 1); // pivot 왼쪽부분 재귀
		quickSort(list, pivot + 1, right); // pivot 오른쪽부분 재귀
	}
}