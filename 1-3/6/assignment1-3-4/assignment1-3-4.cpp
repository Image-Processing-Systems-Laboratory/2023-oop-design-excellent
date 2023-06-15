#include <iostream>
#include <time.h>
#define REPEAT 1000000
using namespace std;

void swap(int &x, int &y);
void showResult(int* arr, int size, clock_t start, clock_t finish);
void copyArray(int* dest, int* source, int size);
void insertionSort(int* arr, int size);
void quickSort(int* arr, int low, int high);
void mergeSort(int* arr, int* merge, int low, int high);
void bubbleSort(int* arr, int size);

int main()
{
    int count;
    clock_t time_start, time_finish;

    // 입력
    cout << "number of inputs: ";
    cin >> count;
    
    // 배열 할당
    int* input = new int[count];
    int* merge = new int[count];
    int* result = new int[count];

    // 정수 입력
    cout << "input " << count << " integers" << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> input[i];
    }

    // 삽입 정렬
    cout << "\n[Insertion Sort]\n";
    //copyArray(result, input, count);
    time_start = clock();
    for (int i = 0; i < REPEAT; i++)
    {
        copyArray(result, input, count);
        insertionSort(result, count);
    }
    time_finish = clock();
    showResult(result, count, time_start, time_finish);
    

    // 퀵 정렬
    cout << "\n[Quick Sort]\n";
    //copyArray(result, input, count);
    time_start = clock();
    for (int i = 0; i < REPEAT; i++)
    {
        copyArray(result, input, count);
        quickSort(result, 0, count - 1);
    }
    time_finish = clock();
    showResult(result, count, time_start, time_finish);

    // 합병 정렬
    cout << "\n[Merge Sort]\n";
    //copyArray(result, input, count);
    time_start = clock();
    for (int i = 0; i < REPEAT; i++)
    {
        copyArray(result, input, count);
        mergeSort(result, merge, 0, count - 1);
    }
    time_finish = clock();
    showResult(result, count, time_start, time_finish);

    // 버블 정렬
    cout << "\n[Bubble Sort]\n";
    //copyArray(result, input, count);
    time_start = clock();
    for (int i = 0; i < REPEAT; i++)
    {
        copyArray(result, input, count);
        bubbleSort(result, count);
    }
    time_finish = clock();
    showResult(result, count, time_start, time_finish);
    
    // 배열 해제
    delete[] input;
    delete[] merge;
    delete[] result;

    // 종료
    return 0;
}

// swap
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}

// 정렬 결과 출력
void showResult(int* arr, int size, clock_t start, clock_t finish)
{
    cout << "Sorted order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "\nMedian number: " << arr[size / 2] << endl;
    cout << "Time: " << ((double)(finish - start) / CLOCKS_PER_SEC) << "s" << endl;
    return;
}

// 배열 복사
void copyArray(int* dest, int* source, int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
    return;
}

// 삽입 정렬
void insertionSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j + 1] < arr[j])    swap(arr[j + 1], arr[j]);
            else                        break;
        }
    }
    return;
}

// 퀵 정렬
void quickSort(int* arr, int low, int high)
{
    int pivot = high, left = low, right = low;
    // 종료 조건
    if (high <= low)   return;
    
    // 로무토 파티션
    while (right < pivot)
    {
        if (arr[right] < arr[pivot])
        {
            swap(arr[left], arr[right]);
            left++;
        }
        right++;
    }
    swap(arr[pivot], arr[left]);

    // 재귀
    quickSort(arr, low, left -1);
    quickSort(arr, left + 1, high);
    return;
}

// 합병 정렬
void mergeSort(int* arr, int* merge, int low, int high)
{
    // 크기가 충분히 작을 경우 반환
    if (low >= high)
    {
        return;
    }

    // 분할
    int medium = (high + low) / 2;
    mergeSort(arr, merge, low, medium);
    mergeSort(arr, merge, medium + 1, high);

    // 합병
    int left = low, right = medium + 1, i = low;
    while (i <= high)
    {
        if (left > medium)
        {
            merge[i++] = arr[right++];
        }
        else if (right > high)
        {
            merge[i++] = arr[left++];
        }
        else if (arr[left] <= arr[right])
        {
            merge[i++] = arr[left++];
        }
        else if (arr[left] > arr[right])
        {
            merge[i++] = arr[right++];
        }
    }

    // 복사
    for (int j = low; j <= high; j++)
    {
        arr[j] = merge[j];
    }

    return;
}

// 버블 정렬
void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return;
}