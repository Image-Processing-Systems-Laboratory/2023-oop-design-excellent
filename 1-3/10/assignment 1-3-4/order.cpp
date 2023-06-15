#include <iostream>
#include <string.h>
using namespace std;

void bubbleOne(int list[], int current, int last);
void bubbleSort(int list[], int last);

void insertOne(int list[], int current);
void insertionSort(int list[], int last);

void mergeOne(int list[], int first, int mid, int last);
void mergeSort(int list[], int first, int last);

void quickSort(int list[], int first, int last);

int main(void)
{
	int i, num, array[100];

	//입력 받을 배열의 수를 입력 받는다
	cin >> num;

	//배열을 입력 받는다
	for (i = 0; i < num; i++)
	{
		cin >> array[i];
	}

	bubbleSort(array, num - 1);

	//정렬한 배열을 출력한다
	cout << "Sorted order: ";
	for (i = 0; i < num; i++)
	{
		cout << array[i] << " ";
	}

	//Median number을 출력한다
	cout << endl << "Median number: " << array[num / 2] << endl;

	return 0;
}

void bubbleOne(int list[], int current, int last)
{
	int walker, temp;
	//배열의 제일 뒤에 있는 값부터 비교해서 정렬하는 알고리즘
	for (walker = last; walker > current; walker--)
	{
		//연달아 있는 배열의 2개의 값 중 배열의 앞의 값이 뒤의 값보다 큰 경우
		if (list[walker] < list[walker - 1])
		{
			//두 개 값의 위치를 바꿔준다
			temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp;
		}
	}
	return;
}

void bubbleSort(int list[], int last)
{
	int current;
	for (current = 0; current < last; current++)
	{
		bubbleOne(list, current, last);
	}
	return;
}

void insertOne(int list[], int current)
{
	bool located = false;
	int temp = list[current];
	int walker;
	
	//값끼리의 크기 비교를 해서 중간에 삽입하는 알고리즘
	for (walker = current - 1; walker >= 0 && !located;)
	{
		if (temp < list[walker]) //temp 값이 list[walker] 값보다 작은 경우
		{
			list[walker + 1] = list[walker]; //temp 값보다 큰 값들은 배열의 위치를 한 칸씩 뒤로 옮겨준다
			walker--;
		}
		else
		{
			located = true;
		}
	}
	list[walker + 1] = temp; //temp 값을 삽입해준다
	return;
}

void insertionSort(int list[], int last)
{
	int current;
	for (current = 1; current <= last; current++)
	{
		insertOne(list, current);
	}
	return;
}

void mergeOne(int list[], int first, int mid, int last)
{
	int i = first;
	int j = mid + 1;
	int k = first;
	int l;
	int merge[100];

	while (i <= mid && j <= last)
	{
		//각 값을 비교해서 새로운 배열에 정렬해준다
		if (list[i] <= list[j])
		{
			merge[k] = list[i];
			i++;
		}
		else
		{
			merge[k] = list[j];
			j++;
		}
		k++;
	}

	//i 값이 mid 값보다 커진 경우
	if (i > mid)
	{
		//각 값들을 새로운 배열에 정렬해준다
		for (l = j; l <= last; l++)
		{
			merge[k] = list[l];
			k++;
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			merge[k] = list[l];
			k++;
		}
	}

	//새로 만들었던 배열을 원래 배열에 다시 옮겨 담는다
	for (l = first; l <= last; l++)
	{
		list[l] = merge[l];
	}
}

void mergeSort(int list[], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2; //중간값 설정
		mergeSort(list, first, mid); //배열을 devide 해준다
		mergeSort(list, mid + 1, last); //배열을 devide 해준다
		mergeOne(list, first, mid, last); //배열을 정렬해준다
	}
}

void quickSort(int list[], int first, int last)
{
	int pivot = first; //pivot을 첫 번째 요소의 인덱스 값으로 설정한다
	int i = first + 1; //i는 pivot의 다음 인덱스 값으로 설정한다
	int j = last; //j는 마지막 요소의 인덱스로 설정한자
	int temp;

	//배열이 하나만 있는 경우
	if (first >= last)
	{
		return;
	}

	while (i <= j)
	{
		//i는 pivot의 값보다 큰 값의 인덱스, j는 pivot의 값보다 작은 값의 인덱스를 담는다
		while (i <= last && list[i] <= list[pivot])
		{
			i++;
		}
		while (j>first&&list[j] >= list[pivot])
		{
			j--;
		}

		if (i > j)
		{
			//j와 pivot의 값을 swap 해준다
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else
		{
			//i<=j인 경우는 i와 j의 값을 swap 해준다
			temp = list[j];
			list[j] = list[i];
			list[i] = temp;
		}
	}

	//pivot을 고정한 뒤, 재귀함수를 이용해 각각의 배열들을 재정렬해준다
	quickSort(list, first, j - 1);
	quickSort(list, j + 1, last);

}