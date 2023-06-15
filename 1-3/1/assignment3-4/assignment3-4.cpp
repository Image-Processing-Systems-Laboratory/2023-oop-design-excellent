#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;
int sorted[10000]; // ���ĵ� �迭�� ������ �迭

void swap(int& a, int& b) // �� ������ ���� �ٲٴ� �Լ�
{
	int temp = a; // a�� ���� �ӽ� ���� temp�� ����
	a = b; // b�� ���� a�� ����
	b = temp; // temp�� ���� b�� ����
}

void insertionSort(int arr[], int n) // ���� ���� �Լ�
{
	int i, key, j; // �ݺ����� ���� ���� ����
    for (i = 1; i < n; i++) // �迭�� �� ��° ���Һ��� ������ ���ұ��� �ݺ�
    {
		key = arr[i]; // key�� ���� ������ ���� ����
		j = i - 1; // j�� ���� ������ �ٷ� �� ������ �ε����� ����
        while (j >= 0 && arr[j] > key) 
        {
			arr[j + 1] = arr[j]; // ���� ������ �ٷ� �� ������ ���� ���� ������ ������ ����
			j--; // j�� 1 ����
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) // �� ���� �Լ�
{
    if (low < high) // low�� high���� ���� ��
    {
		int pivot = arr[high]; // pivot�� �迭�� ������ ������ ���� ����
		int i = (low - 1); // i�� low - 1�� ����
        for (int j = low; j <= high - 1; j++) // low���� high-1���� �ݺ�
        {
            if (arr[j] < pivot) // ���� ������ ���� pivot���� ���� ��
            {
				i++; // i�� 1 ����
				swap(arr[i], arr[j]); // ���� ���ҿ� i��° ������ ���� �ٲ�
            }
        }
		swap(arr[i + 1], arr[high]); // pivot�� i+1��° ������ ���� �ٲ�
		int pi = i + 1; // pi�� i+1�� ����
		quickSort(arr, low, pi - 1); // ��� ȣ��
		quickSort(arr, pi + 1, high); // ��� ȣ��
    }
}

void mergeSort(int arr[], int left, int right) // ���� ���� �Լ�
{
	int mid; // �߰� �ε����� ������ ���� ����
    if (left < right) // left�� right���� ���� ��
    {
		mid = (left + right) / 2; // �߰� �ε����� ���
		mergeSort(arr, left, mid); // ��� ȣ��
		mergeSort(arr, mid + 1, right); // ��� ȣ��
		int i, j, k, l; // �ݺ����� ���� ���� ����
		i = left, j = mid + 1; k = left; // i, k�� left�� �ʱ�ȭ, j�� mid+1�� �ʱ�ȭ

		while (i <= mid && j <= right) // i�� mid���� �۰ų� ���� j�� right���� �۰ų� ���� ��
        {
			if (arr[i] <= arr[j]) // i��° ������ ���� j��° ������ ������ �۰ų� ���� ��
				sorted[k++] = arr[i++]; // sorted[k]�� arr[i]�� ���� �����ϰ� i, k�� 1 ����
			else // i��° ������ ���� j��° ������ ������ Ŭ ��
				sorted[k++] = arr[j++]; // sorted[k]�� arr[j]�� ���� �����ϰ� j, k�� 1 ����
        }

        if (i > mid) // i�� mid ���� Ŭ ��
        {
			for (l = j; l <= right; l++) // j���� right���� �ݺ�
            {
				sorted[k++] = arr[l]; // sorted[k]�� arr[l]�� ���� �����ϰ� k�� 1 ����
            }
        }
        else // �׿��� ��Ȳ
        {
            for (l = i; l <= right; l++) // i���� right���� �ݺ�
            {
				sorted[k++] = arr[l]; // sorted[k]�� arr[l]�� ���� �����ϰ� k�� 1 ����
            }
        }
        for (l = left; l <= right; l++) // left���� right���� �ݺ�
        {
			arr[l] = sorted[l]; // arr[l]�� sorted[l]�� ���� ����
        }
    }
}


void bubbleSort(int arr[], int n) // ���� ���� �Լ�
{
    for (int i = 0; i < n; i++) // 0���� n-1���� �ݺ�
    {
        for (int j = 0; j < n - 1; j++) // 0���� n-2���� �ݺ�
        {
            if (arr[j] > arr[j + 1]) // ���� ������ ���� ���� ������ ������ Ŭ ��
            {
				swap(arr[j], arr[j + 1]); // ���� ���ҿ� ���� ������ ���� �ٲ�
            }
        }
    }
}

int main()
{
	LARGE_INTEGER ticksPerSec; // �ʴ� ƽ ���� ������ ���� ����
	LARGE_INTEGER start, end, diff; // ���� �ð�, �� �ð�, �ð� ���̸� ������ ���� ����
	int n, i, median, choice; // n�� �迭�� ũ��, i�� �ݺ����� ���� ����, median�� �߰����� ������ ����, choice�� ������� ������ ������ �������� ����
	cout << "Enter the number of inputs: "; // ���� �� ������ ������ �Է¹޴� ���� ���
    cin >> n; 
    if (n % 2 == 0) // n�� ¦���� ��
    {
		cout << "The number of inputs must be odd." << endl; // Ȧ�� ���� ���Ҹ� �Է��ؾ� �Ѵٴ� ���� ���
        return 0;
    }

	int* arr = new int[n]; // ���� �迭 ����
	int* arr2 = new int[n]; //  ���� �迭 ����
	int* arr3 = new int[n]; // ���� �迭 ����
	int* arr4 = new int[n]; // ���� �迭 ����
	int* arr5 = new int[n]; // ���� �迭 ����

	cout << "Enter " << n << " integers:"; // ������ ���ҵ��� ���� �Է¹޴� ���� ���
    for (i = 0; i < n; i++) // 0���� n-1���� �ݺ�
    {
		cin >> arr[i]; // arr[i]�� ������ ���� �Է�
		arr2[i] = arr[i]; // arr2[i]�� arr[i]�� ���� ����
		arr3[i] = arr[i]; // arr3[i]�� arr[i]�� ���� ����
		arr4[i] = arr[i]; // arr4[i]�� arr[i]�� ���� ����
		arr5[i] = arr[i]; // arr5[i]�� arr[i]�� ���� ����
    }

    cout << "1. Insertion Sort" << endl;
    cout << "2. Quick Sort" << endl;
    cout << "3. Merge Sort" << endl;
    cout << "4. Bubble Sort" << endl;
    cin >> choice; // ������ ����

    switch (choice) // ������� ���ÿ� ���� ������ ����
    {
	case 1: // ������ 1�� ��
        insertionSort(arr, n);
        break;
	case 2: // ������ 2�� ��
        quickSort(arr, 0, n - 1);
        break;
	case 3: // ������ 3�� ��
        mergeSort(arr, 0, n - 1);
        break;
	case 4: // ������ 4�� ��
        bubbleSort(arr, n);
        break;
    }

	cout << "Sorted array: "; // ���ĵ� �迭�� ����ϴ� ���� ���
    for (i = 0; i < n; i++) // ���ĵ� �迭�� �������
        cout << arr[i] << " ";
    cout << endl;

	median = arr[n / 2]; // �߰����� ����
	cout << "Median: " << median << endl; // �߰����� ���

	QueryPerformanceFrequency(&ticksPerSec); // �ʴ� ƽ ���� ����
	QueryPerformanceCounter(&start); // ���� �ð��� ����
	insertionSort(arr2, n); // ���� ���� ����
	QueryPerformanceCounter(&end); // �� �ð��� ����
	diff.QuadPart = end.QuadPart - start.QuadPart; // �ð� ���̸� ����
    cout << "Insertion Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // ���� �ð��� ����
	quickSort(arr3, 0, n - 1); // �� ���� ����
	QueryPerformanceCounter(&end); // �� �ð��� ����
	diff.QuadPart = end.QuadPart - start.QuadPart; // �ð� ���̸� ����
    cout << "Quick Sort Time!" << endl; 
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // ���� �ð��� ����
	mergeSort(arr4, 0, n - 1); // ���� ���� ����
	QueryPerformanceCounter(&end); // �� �ð��� ����
	diff.QuadPart = end.QuadPart - start.QuadPart; // �ð� ���̸� ����
    cout << "Merge Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	QueryPerformanceCounter(&start); // ���� �ð��� ����
	bubbleSort(arr5, n); // ���� ���� ����
	QueryPerformanceCounter(&end); // �� �ð��� ����
	diff.QuadPart = end.QuadPart - start.QuadPart; // �ð� ���̸� ����
    cout << "Bubble Sort Time!" << endl;
    cout << "Time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 1000000000 << " ns" << endl;

	delete[] arr; // ���� �Ҵ� ����
	delete[] arr2; // ���� �Ҵ� ����
	delete[] arr3; // ���� �Ҵ� ����
	delete[] arr4; // ���� �Ҵ� ����
	delete[] arr5; // ���� �Ҵ� ����

    return 0;
}