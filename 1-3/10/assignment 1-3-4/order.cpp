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

	//�Է� ���� �迭�� ���� �Է� �޴´�
	cin >> num;

	//�迭�� �Է� �޴´�
	for (i = 0; i < num; i++)
	{
		cin >> array[i];
	}

	bubbleSort(array, num - 1);

	//������ �迭�� ����Ѵ�
	cout << "Sorted order: ";
	for (i = 0; i < num; i++)
	{
		cout << array[i] << " ";
	}

	//Median number�� ����Ѵ�
	cout << endl << "Median number: " << array[num / 2] << endl;

	return 0;
}

void bubbleOne(int list[], int current, int last)
{
	int walker, temp;
	//�迭�� ���� �ڿ� �ִ� ������ ���ؼ� �����ϴ� �˰���
	for (walker = last; walker > current; walker--)
	{
		//���޾� �ִ� �迭�� 2���� �� �� �迭�� ���� ���� ���� ������ ū ���
		if (list[walker] < list[walker - 1])
		{
			//�� �� ���� ��ġ�� �ٲ��ش�
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
	
	//�������� ũ�� �񱳸� �ؼ� �߰��� �����ϴ� �˰���
	for (walker = current - 1; walker >= 0 && !located;)
	{
		if (temp < list[walker]) //temp ���� list[walker] ������ ���� ���
		{
			list[walker + 1] = list[walker]; //temp ������ ū ������ �迭�� ��ġ�� �� ĭ�� �ڷ� �Ű��ش�
			walker--;
		}
		else
		{
			located = true;
		}
	}
	list[walker + 1] = temp; //temp ���� �������ش�
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
		//�� ���� ���ؼ� ���ο� �迭�� �������ش�
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

	//i ���� mid ������ Ŀ�� ���
	if (i > mid)
	{
		//�� ������ ���ο� �迭�� �������ش�
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

	//���� ������� �迭�� ���� �迭�� �ٽ� �Ű� ��´�
	for (l = first; l <= last; l++)
	{
		list[l] = merge[l];
	}
}

void mergeSort(int list[], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2; //�߰��� ����
		mergeSort(list, first, mid); //�迭�� devide ���ش�
		mergeSort(list, mid + 1, last); //�迭�� devide ���ش�
		mergeOne(list, first, mid, last); //�迭�� �������ش�
	}
}

void quickSort(int list[], int first, int last)
{
	int pivot = first; //pivot�� ù ��° ����� �ε��� ������ �����Ѵ�
	int i = first + 1; //i�� pivot�� ���� �ε��� ������ �����Ѵ�
	int j = last; //j�� ������ ����� �ε����� ��������
	int temp;

	//�迭�� �ϳ��� �ִ� ���
	if (first >= last)
	{
		return;
	}

	while (i <= j)
	{
		//i�� pivot�� ������ ū ���� �ε���, j�� pivot�� ������ ���� ���� �ε����� ��´�
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
			//j�� pivot�� ���� swap ���ش�
			temp = list[j];
			list[j] = list[pivot];
			list[pivot] = temp;
		}
		else
		{
			//i<=j�� ���� i�� j�� ���� swap ���ش�
			temp = list[j];
			list[j] = list[i];
			list[i] = temp;
		}
	}

	//pivot�� ������ ��, ����Լ��� �̿��� ������ �迭���� ���������ش�
	quickSort(list, first, j - 1);
	quickSort(list, j + 1, last);

}