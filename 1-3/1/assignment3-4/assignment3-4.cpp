#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;
int sorted[10000]; // 정렬된 배열을 저장할 배열

void swap(int& a, int& b) // 두 변수의 값을 바꾸는 함수
{
	int temp = a; // a의 값을 임시 변수 temp에 저장
	a = b; // b의 값을 a에 저장
	b = temp; // temp의 값을 b에 저장
}

void insertionSort(int arr[], int n) // 삽입 정렬 함수
{
	int i, key, j; // 반복문을 위한 변수 선언
    for (i = 1; i < n; i++) // 배열의 두 번째 원소부터 마지막 원소까지 반복
    {
		key = arr[i]; // key에 현재 원소의 값을 저장
		j = i - 1; // j에 현재 원소의 바로 앞 원소의 인덱스를 저장
        while (j >= 0 && arr[j] > key) 
        {
			arr[j + 1] = arr[j]; // 현재 원소의 바로 앞 원소의 값을 현재 원소의 값으로 저장
			j--; // j를 1 감소
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) // 퀵 정렬 함수
{
    if (low < high) // low가 high보다 작을 때
    {
		int pivot = arr[high]; // pivot에 배열의 마지막 원소의 값을 저장
		int i = (low - 1); // i에 low - 1을 저장
        for (int j = low; j <= high - 1; j++) // low부터 high-1까지 반복
        {
            if (arr[j] < pivot) // 현재 원소의 값이 pivot보다 작을 때
            {
				i++; // i를 1 증가
				swap(arr[i], arr[j]); // 현재 원소와 i번째 원소의 값을 바꿈
            }
        }
		swap(arr[i + 1], arr[high]); // pivot과 i+1번째 원소의 값을 바꿈
		int pi = i + 1; // pi에 i+1을 저장
		quickSort(arr, low, pi - 1); // 재귀 호출
		quickSort(arr, pi + 1, high); // 재귀 호출
    }
}

void mergeSort(int arr[], int left, int right) // 병합 정렬 함수
{
	int mid; // 중간 인덱스를 저장할 변수 선언
    if (left < right) // left가 right보다 작을 때
    {
		mid = (left + right) / 2; // 중간 인덱스를 계산
		mergeSort(arr, left, mid); // 재귀 호출
		mergeSort(arr, mid + 1, right); // 재귀 호출
		int i, j, k, l; // 반복문을 위한 변수 선언
		i = left, j = mid + 1; k = left; // i, k는 left로 초기화, j는 mid+1로 초기화

		while (i <= mid && j <= right) // i가 mid보다 작거나 같고 j가 right보다 작거나 같을 때
        {
			if (arr[i] <= arr[j]) // i번째 원소의 값이 j번째 원소의 값보다 작거나 같을 때
				sorted[k++] = arr[i++]; // sorted[k]에 arr[i]의 값을 저장하고 i, k를 1 증가
			else // i번째 원소의 값이 j번째 원소의 값보다 클 때
				sorted[k++] = arr[j++]; // sorted[k]에 arr[j]의 값을 저장하고 j, k를 1 증가
        }

        if (i > mid) // i가 mid 보다 클 때
        {
			for (l = j; l <= right; l++) // j부터 right까지 반복
            {
				sorted[k++] = arr[l]; // sorted[k]에 arr[l]의 값을 저장하고 k를 1 증가
            }
        }
        else // 그외의 상황
        {
            for (l = i; l <= right; l++) // i부터 right까지 반복
            {
				sorted[k++] = arr[l]; // sorted[k]에 arr[l]의 값을 저장하고 k를 1 증가
            }
        }
        for (l = left; l <= right; l++) // left부터 right까지 반복
        {
			arr[l] = sorted[l]; // arr[l]에 sorted[l]의 값을 저장
        }
    }
}


void bubbleSort(int arr[], int n) // 버블 정렬 함수
{
    for (int i = 0; i < n; i++) // 0부터 n-1까지 반복
    {
        for (int j = 0; j < n - 1; j++) // 0부터 n-2까지 반복
        {
            if (arr[j] > arr[j + 1]) // 현재 원소의 값이 다음 원소의 값보다 클 때
            {
				swap(arr[j], arr[j + 1]); // 현재 원소와 다음 원소의 값을 바꿈
            }
        }
    }
}

int main()
{
	LARGE_INTEGER ticksPerSec; // 초당 틱 수를 저장할 변수 선언
	LARGE_INTEGER start, end, diff; // 시작 시간, 끝 시간, 시간 차이를 저장할 변수 선언
	int n, i, median, choice; // n은 배열의 크기, i는 반복문을 위한 변수, median은 중간값을 저장할 변수, choice는 사용자의 선택을 저장할 변수들을 선언
	cout << "Enter the number of inputs: "; // 정렬 할 원소의 개수를 입력받는 문구 출력
    cin >> n; 
    if (n % 2 == 0) // n이 짝수일 때
    {
		cout << "The number of inputs must be odd." << endl; // 홀수 개의 원소를 입력해야 한다는 문구 출력
        return 0;
    }

	int* arr = new int[n]; // 동적 배열 선언
	int* arr2 = new int[n]; //  동적 배열 선언
	int* arr3 = new int[n]; // 동적 배열 선언
	int* arr4 = new int[n]; // 동적 배열 선언
	int* arr5 = new int[n]; // 동적 배열 선언

	cout << "Enter " << n << " integers:"; // 정렬할 원소들의 값을 입력받는 문구 출력
    for (i = 0; i < n; i++) // 0부터 n-1까지 반복
    {
		cin >> arr[i]; // arr[i]에 원소의 값을 입력
		arr2[i] = arr[i]; // arr2[i]에 arr[i]의 값을 저장
		arr3[i] = arr[i]; // arr3[i]에 arr[i]의 값을 저장
		arr4[i] = arr[i]; // arr4[i]에 arr[i]의 값을 저장
		arr5[i] = arr[i]; // arr5[i]에 arr[i]의 값을 저장
    }

    cout << "1. Insertion Sort" << endl;
    cout << "2. Quick Sort" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "4. Bubble Sort" << endl;
    cin >> choice; // 선택을 받음

    switch (choice) // 사용자의 선택에 따라 정렬을 수행
    {
	case 1: // 선택이 1일 때
        insertionSort(arr, n);
        break;
	case 2: // 선택이 2일 때
        quickSort(arr, 0, n - 1);
        break;
	case 3: // 선택이 3일 때
        mergeSort(arr, 0, n - 1);
        break;
	case 4: // 선택이 4일 때
        bubbleSort(arr, n);
        break;
    }

	cout << "Sorted array: "; // 정렬된 배열을 출력하는 문구 출력
    for (i = 0; i < n; i++) // 정렬된 배열을 출력해줌
        cout << arr[i] << " ";
    cout << endl;

	median = arr[n / 2]; // 중간값을 저장
	cout << "Median: " << median << endl; // 중간값을 출력

	QueryPerformanceFrequency(&ticksPerSec); // 초당 틱 수를 구함
	QueryPerformanceCounter(&start); // 시작 시간을 구함
	insertionSort(arr2, n); // 삽입 정렬 수행
	QueryPerformanceCounter(&end); // 끝 시간을 구함
	diff.QuadPart = end.QuadPart - start.QuadPart; // 시간 차이를 구함
    cout << "Insertion Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // 시작 시간을 구함
	quickSort(arr3, 0, n - 1); // 퀵 정렬 수행
	QueryPerformanceCounter(&end); // 끝 시간을 구함
	diff.QuadPart = end.QuadPart - start.QuadPart; // 시간 차이를 구함
    cout << "Quick Sort Time!" << endl; 
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // 시작 시간을 구함
	mergeSort(arr4, 0, n - 1); // 병합 정렬 수행
	QueryPerformanceCounter(&end); // 끝 시간을 구함
	diff.QuadPart = end.QuadPart - start.QuadPart; // 시간 차이를 구함
    cout << "Merge Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // 시작 시간을 구함
	bubbleSort(arr5, n); // 버블 정렬 수행
	QueryPerformanceCounter(&end); // 끝 시간을 구함
	diff.QuadPart = end.QuadPart - start.QuadPart; // 시간 차이를 구함
    cout << "Bubble Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	delete[] arr; // 동적 할당 해제
	delete[] arr2; // 동적 할당 해제
	delete[] arr3; // 동적 할당 해제
	delete[] arr4; // 동적 할당 해제
	delete[] arr5; // 동적 할당 해제

    return 0;
}