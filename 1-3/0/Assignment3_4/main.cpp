#include<iostream>
#include<ctime>	// �����ϴµ� �ɸ��� �ð��� ����ϱ� ���� ������ �������
using namespace std;

//�� ���ĵ��� �Լ��� ����
void insert(int* arr,int n);
void quick(int* arr, int i,int j);

void merge(int* arr, int left, int mid, int right);
void merge_sort(int* arr, int left, int right);

void bubble(int* arr, int n);


int main(void)
{
	clock_t start, end;
	int nums = 0;
	cin >> nums;

	int* arr = new int[nums];

	for (int i = 0; i < nums; i++)
		cin >> arr[i];


	// �ð��� �����ϱ����� �Ʒ��� ���� ������ �ڵ带 �ۼ���
	start = clock();
	insert(arr, nums);
	end = clock();
	cout << "Sorted order: ";
	for (int i = 0; i < nums; i++)
		cout << arr[i]<<' ';
	double excut_time = (double)(end - start);

	cout << "\nMedian number: " << arr[nums / 2]<<endl;
	//cout << "execution time: " << excut_time<<"ms";	// ������ ����Ǵµ��� �ɸ��� �ð� ���

	return 0;
	
}

void insert(int* arr, int n)
{
	int key = 0;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		//������ ���Ҹ� sel�� ����
		key = arr[i];

		//sel���� 
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}


}
void quick(int* arr, int i,int j)
{
	if (i >= j) // ���Ұ� 1���� ��쿡 ���� ����
		return;
	int idx_low = i+1;
	int idx_high = j;
	int pivot_i = i;

	while (idx_low<=idx_high)//�� �ε����� ������������ �ݺ�
	{
		while (arr[idx_low] <= arr[pivot_i] && idx_low <= j) // �迭�� �� ���Һ��� �����Ͽ� Ȯ��
		{
			idx_low++;
		}
		while (arr[idx_high] >= arr[pivot_i] && idx_high > i) // �迭�� �� ���Һ��� �����Ͽ� Ȯ��
		{
			idx_high--;
		}

		if (idx_low > idx_high) // �� �ε����� �������� �ǹ��� �ش��ϴ� ���� ������ ��ġ�� ����
		{
			int tmp = arr[idx_high];
			arr[idx_high] = arr[pivot_i];
			arr[pivot_i] = tmp;
		}
		else// i�� j�� ��ġ�� �ٲ�
		{
			int tmp = arr[idx_low];
			arr[idx_low] = arr[idx_high];
			arr[idx_high] = tmp;
		}
	}

	quick(arr, i, idx_high - 1);
	quick(arr, idx_high + 1, j);
}

void merge(int* arr, int left, int mid, int right)
{
	int lenL = mid -left +1;
	int lenR = right - mid;

	//mid�� �������� �� �迭�� ������ ���纻�� �����
	int* arr_L = new int[lenL];
	int* arr_R = new int[lenR];
	for (int i = 0; i < lenL; i++)
		arr_L[i] = arr[left + i];
	for (int i = 0; i < lenR; i++)
		arr_R[i] = arr[mid + 1 + i];

	// arr�� arr�� ���� �� �迭�� �ε����� ����Ű�� �������� ����
	// �ι迭�� ���ҵ��� ���� ���� arr�� �ִ´�.
	int idx_L = 0, idx_R = 0, idx_A = left;
	while (idx_L < lenL && idx_R < lenR)
	{
		if (arr_L[idx_L] <= arr_R[idx_R])
			arr[idx_A++] = arr_L[idx_L++];
		else
			arr[idx_A++] = arr_R[idx_R++];
	}

	// arr_L�� arr_R��, �ϳ��� �������, �Ʒ��� ������� arr�� left���� right���̱��� ä��
	//arr_R�� ����ִ°��
	while (idx_L < lenL)
		arr[idx_A++] = arr_L[idx_L++];

	//arr_L�� ����ִ°��
	while (idx_R < lenR)
		arr[idx_A++] = arr_R[idx_R++];

	delete[] arr_L;
	delete[] arr_R;

	return;

}
void merge_sort(int* arr, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;	// ������ ������ ���ȣ��
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void bubble(int* arr, int n)
{
	// ���� ������ ���� �ϱ����� �ε����� n-1��° ������ �����ϸ� ��
	int i = n-1;

	int j = 0;
	while (i >1)
	{
		while (j < i)
		{	// arr[i]�� �� ũ�� swap�ǽ�
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				continue;
			}
			else
				j++;
		}i--;
		j = 0;
	}
	return;
}