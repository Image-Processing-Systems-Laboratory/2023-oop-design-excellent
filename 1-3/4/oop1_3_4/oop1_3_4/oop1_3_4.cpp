#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int temp, data_copy[100], cnt = 0;

#define swap(x, y) ((temp) = (x), (x)=(y), (y) = (temp))

void insertOne(int data[], int cur);
void insertionSort(int data[], int last);

int part(int data[], int cur, int last);
void quickSort(int data[], int cur, int last);

void merge(int data[], int left, int mie, int right);
void mergeSort(int data[], int left, int right);

void bubbleUp(int data[], int cur, int last);
void bubbleSort(int data[], int last);

int main() {

	int N; // 입력받을 숫자의 갯수
	int number[100] = { 0 };

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	cout << "Input: ";
	cin >> N;

	// N개의 숫자 입력
	cout << "Fill in N numbers" << endl;
	for (int i = 0; i < N; i++)
		cin >> number[i]; // 숫자 입력 받기

	int number_copy[100] = { 0 };



	for (int i = 0; i < N; i++)
		number_copy[i] = number[i];

	// insertion sort 인 경우
	cout << endl << "1. insertion sort" << endl;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	insertionSort(number_copy, N); // insert 방식으로 정렬

	QueryPerformanceCounter(&end);

	//측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;

	// 정렬해서 출력
	cout << "Sorted order: ";
	for (int i = 0; i < N; i++) // insertsort를 진행하면 맨 앞에 0이 옴 왜일까?
		cout << number_copy[i] << ' ';
	cout << endl << "Median number: " << number_copy[N / 2] << endl; // 그래서 중앙값도 달라짐


	cout << "time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * pow(10, 9) << " nano sec, cnt: " << cnt << endl << endl;



	for (int i = 0; i < N; i++)
		number_copy[i] = number[i];
	cnt = 0;

	// quick sort 인 경우
	cout << endl << "2. quick sort" << endl;


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	quickSort(number_copy, 0, N - 1); // quick 방식으로 정렬, 데이터의 처음과 끝을 인자로 갖는다

	QueryPerformanceCounter(&end);

	//측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;

	// 정렬해서 출력
	cout << "Sorted order: ";
	for (int i = 0; i < N; i++)
		cout << number_copy[i] << ' ';
	cout << endl << "Median number: " << number_copy[N / 2] << endl;


	cout << "time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * pow(10, 9)<< " nano sec, cnt: " << cnt << endl << endl;





	for (int i = 0; i < N; i++)
		number_copy[i] = number[i];
	cnt = 0;

	// merge sort 인 경우
	cout << endl << "3. merge sort" << endl;


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	mergeSort(number_copy, 0, N - 1); // merge 방식으로 정렬

	QueryPerformanceCounter(&end);

	//측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;

	// 정렬해서 출력
	cout << "Sorted order: ";
	for (int i = 0; i < N; i++)
		cout << number_copy[i] << ' ';
	cout << endl << "Median number: " << number_copy[N / 2] << endl;


	cout << "time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * pow(10, 9) << " nano sec, cnt: " << cnt << endl << endl;




	for (int i = 0; i < N; i++)
		number_copy[i] = number[i];
	cnt = 0;

	// bubble sort 인 경우
	cout << endl << "4. bubble sort" << endl;


	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	bubbleSort(number_copy, N - 1); // burble 방식으로 정렬 데이터의 갯수를 인수로 받는다

	QueryPerformanceCounter(&end);

	//측정값으로부터 실행시간 계산
	diff.QuadPart = end.QuadPart - start.QuadPart;

	// 정렬해서 출력
	cout << "Sorted order: ";
	for (int i = 0; i < N; i++)
		cout << number_copy[i] << ' ';
	cout << endl << "Median number: " << number_copy[N / 2] << endl;


	cout << "time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * pow(10, 9) << " nano sec, cnt: " << cnt << endl << endl;




}

void insertOne(int data[], int cur)
{
	bool located = false;
	int tmp = data[cur];
	int wal;
	for (wal = cur - 1; wal >= 0 && !located; ) {
		cnt++;
		if (tmp < data[wal]) {
			data[wal + 1] = data[wal];
			wal--;
		}
		else located = true;
	}
	data[wal + 1] = tmp;
	return;

}

void insertionSort(int data[], int last) // last는 배열의 크기
{
	for (int cur = 0; cur < last; cur++) {// 0부터 N-1개까지 탐색
		insertOne(data, cur);
		cnt++;
	}
	return;
}

int part(int data[], int cur, int last) // 가운데 부분을 탐색하면서 정렬
{
	int Pivot, tmp, low = cur, high = last + 1;

	Pivot = data[cur]; //  피벗은 가장 왼쪽값에서 시작한다.

	do {
		cnt++;
		while (data[++low] < Pivot) cnt++; // 왼쪽에서부터 피벗보다 작은 것을 탐색

		while (data[--high] > Pivot) cnt++; // 오른쪽에서 부터 피벗보다 큰 것을 탐색

		if (low < high) // low와 high는 서로 가까워져 가며 교체한다. 
			swap(data[low], data[high]);

	} while (low < high);


	//low와 high가 교차하는 순간 비교는 멈추고 맨 앞자리에 있는 Pivot과 중간에 있는 high의 값을 서로 교환한다. 
	swap(data[cur], data[high]);

	return high; // 모든 연산이 끝나고 나면 high는 N개의 배열 크기에서 중간을 가리킨다. 

}

void quickSort(int data[], int cur, int last) // 정렬할 범위는 cur부터 last
{
	if (cur < last) {
		int Pivot = part(data, cur, last);
		quickSort(data, cur, Pivot - 1); // 피벗을 기준으로 왼쪽에서 재탐색
		quickSort(data, Pivot + 1, last); //피벗을 기준으로 오른쪽에서 재탐색
	}
}

void merge(int data[], int left, int mid, int right)
{
	int a = left, b = mid + 1, k = left;

	while (a <= mid && b <= right) {
		cnt++;
		if (data[a] <= data[b]) { // 왼쪽부터 중간
			data_copy[k] = data[a]; // 크기가 작은 걸 복사해서 저장
			k++;
			a++;
		}
		else {
			data_copy[k] = data[b]; // 얘도 마찬가지
			k++;
			b++;
		}
	}

	if (a > mid) // 크기가 작은 것들이 좌측에만 있을 경우 (a가 조건을 어겨 나올 경우)
		for (int i = b; i < right + 1; i++) {
			cnt++;
			data_copy[k++] = data[i];
		}

	else
		for (int i = a; i < mid + 1; i++) {
			cnt++;
			data_copy[k++] = data[i];
		}

	for (int i = left; i < right + 1; i++) {
		cnt++;
		data[i] = data_copy[i]; // 정렬된 카피본을 다시 원본데이터로 카피
	}

	return;
}

void mergeSort(int data[], int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2; // 왼쪽 끝과 오른쪽 끝의 가운데
		mergeSort(data, left, mid);  // 왼쪽부터 가운데까지 정렬
		mergeSort(data, mid + 1, right); // 가운데부터 오른쪽 정렬
		merge(data, left, mid, right); // 합병
	}
	return;
}

void bubbleUp(int data[], int cur, int last)
{
	for (int wal = last; wal > cur; wal--) {
		cnt++;
		if (data[wal] < data[wal - 1]) {
			swap(data[wal], data[wal - 1]);
		}
	}
	return;
}

void bubbleSort(int data[], int last)
{
	for (int cur = 0; cur < last; cur++) {// 0부터 N-1개 까지 N개 탐색
		cnt++;
		bubbleUp(data, cur, last);
	}
	return;
}

