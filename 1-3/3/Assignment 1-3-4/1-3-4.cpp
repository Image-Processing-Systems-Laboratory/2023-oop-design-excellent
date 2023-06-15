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

	// 입력 횟수 입력 받기
	cin >> n;
	// 만약 짝수를 입력햇을 경우 프로그램 종료
	if (n % 2 == 0) {
		cout << "Enter odd number!";
		return 0;
	}

	// 정렬할 수들을 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 정렬 (네 가지 중에 하나를 택하여 사용)

	insertionSort(arr, n - 1);
	//bubbleSort(arr, n - 1);
	//mergeSort(arr, 0, n - 1);
	//quickSort(arr, 0, n - 1);

	// 정렬된 순서 출력
	cout << "Sorted order : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	// 중간값 출력
	cout << "Median number : " << arr[n / 2];
	return 0;
}

void insertone(int list[], int current) {
	bool located = false;
	int temp = list[current];
	int walker;
	// 비교 후에 앞으로 삽입하기
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
	// 삽입이 끝나면 다음 수로 옮겨가며 반복
	for (int current = 1; current <= last; current++) {
		insertone(list, current);
	}
	return;
}
void bubbleUp(int list[], int current, int last) {
	// 뒤에서부터 값을 비교하여 가장 작은 값을 불러옴
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
	// 정렬이 끝나면 그 다음 부분부터 계산하여 정렬
	for (int current = 0; current < last; current++)
		bubbleUp(list, current, last);
	return;
}
void merge(int list[], int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	int sorted[100];

	// 수를 비교하고 정렬한 후에 합침
	while (i <= mid && j <= end) {
		// list[i] < list[j]인 경우
		if (list[i] <= list[j]) {
			sorted[k] = list[i];
			i++;
		}
		else {
			// list[i] > list[j]인 경우
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

	// 정렬된 배열을 삽입
	for (int t = start; t <= end; t++) {
		list[t] = sorted[t];
	}
}
void mergeSort(int list[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(list, start, mid); // 절반을 나눈 왼쪽 부분 
		mergeSort(list, mid + 1, end); // 절반을 나눈 오른쪽 부분
		merge(list, start, mid, end); // 합치기
	}
}
void quickSort(int list[], int start, int end) {
	// 원소가 1개인 경우
	if (start >= end) {
		return;
	}

	int pivot = start; // 처음 수를 pivot으로 지정
	int i = pivot + 1; // 왼쪽 시작 지점 
	int j = end; // 오른쪽 시작 지점
	int temp;

	while (i <= j) {
		// 엇갈릴때까지 반복
		while (i <= end && list[i] <= list[pivot]) {
			i++;
		}
		while (j > start && list[j] >= list[pivot]) {
			j--;
		}

		if (i > j) {
			// 엇갈림
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else {
			// i번째와 j번째를 교환하기
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}

	// 분할하여 계산
	quickSort(list, start, j - 1);
	quickSort(list, j + 1, end);
}