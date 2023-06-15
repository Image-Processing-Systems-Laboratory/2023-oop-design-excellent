#include <iostream>

void swap(int& a, int& b) // a�� b�� ��ġ�� ����
{
	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort(int* arr, int begin, int end)
{ // ���� ������ ����� ����
	for (int i = begin; i < end; i++) // i�� �̹� �ݺ����� ���ĵ� �ε���
	{
		for (int j = end; j > i; j--) // j�� �迭�� ������ i + 1���� ��ȸ
		{
			if (arr[j] < arr[j - 1]) // ���� �̿��� �� �� ���� ���� �� �۴ٸ�
				swap(arr[j], arr[j - 1]); // �� ���� swap
		}
	}
}

void insertion_sort(int* arr, int begin, int end)
{ // ���� ������ ����� ����
	int temp;
	int i, j;

	for (i = begin + 1; i <= end; i++) // begin�� ���ĵǾ��ٰ� �����ϰ�, begin + 1���� �ݺ�
	{
		if (arr[i - 1] < arr[i]) // ���� �ٷ� ���� ������ ũ�ٸ� ���ĵ�
			continue;
		temp = arr[i]; // �ӽú����� ������ġ�� ���� ����
		for (j = i; j > begin && arr[j - 1] >= temp; j--) // �迭�� ��ĭ�� �ڷ� �и� temp�� ��ġ Ž��
			arr[j] = arr[j - 1];
		arr[j] = temp; // temp ����
	}
}

void quick_sort(int* arr, int begin, int end)
{ // �� ������ ����� ����
	if (begin >= end) // ������ ������ �ڿ� ������ return 
		return;
	else if (end - begin < 2) // ���� �� ���� ���� ��� �� ���� ��Ҹ� ���Ͽ� swap
	{
		if (arr[end] < arr[begin])
			swap(arr[end], arr[begin]);
		return;
	}
	int pivot = arr[end]; // ������ ���� pivot ���� ����
	int idx1 = begin; // �� ó���� ����Ű�� �ε���
	int idx2 = end - 1; // pivot�� �����ϰ� �� �ڸ� ����Ű�� �ε���
	while (idx1 < idx2) // �� �ε����� ���� ������ �ݺ�
	{
		// ���� idx1�� pivot���� ���̰� idx2�� pivot ���� ���� ���
		if (arr[idx1] > pivot && arr[idx2] < pivot)
		{
			swap(arr[idx1], arr[idx2]); // �� ���� ��ȯ
			idx1++; // idx1�� ���� ���� ����Ŵ
			idx2--; // idx2�� ���� ���� ����Ŵ
		}
		else if (arr[idx1] > pivot) // idx1�� �ڷ� ���� �� ���� ����Ű�� �ִٸ�, idx2�� �̵��Ͽ� swap�� �� Ž��
			idx2--;
		else if (arr[idx2] < pivot) // idx2�� ������ ���� �� ���� ����Ű�� �ִٸ� idx1�� �̵��Ͽ� swap�� �� Ž��
			idx1++;
		else // ���� �� �� ���� ��ġ�� ������ ���� ����Ų�ٸ� �� �� �̵���Ŵ
		{
			idx1++;
			idx2--;
		}
	}
	if (arr[idx1] < pivot) // idx1�� ����Ű�� �ִ� ���� pivot �տ� �־�� �ϴ� ���� ���
		idx1++;
	swap(arr[end], arr[idx1]); // pivot�� idx1�� ����Ű�� �ִ� ���� swap
	quick_sort(arr, begin, idx1 - 1); // pivot���� ������ quick sort
	quick_sort(arr, idx1 + 1, end); // pivot ���� ������ quick sort
}

void merge_sort(int* arr, int begin, int end, int* temp)
{ // �պ� ������ ����� ����
	if (begin >= end) // ������ ������ �ڿ� ������ return 
		return;
	else if (end - begin < 2) // ���� �� ���� ���� ��� �� ���� ��Ҹ� ���Ͽ� swap
	{
		if (arr[end] < arr[begin])
			swap(arr[end], arr[begin]);
		return;
	}
	int mid = begin + (end - begin) / 2; //��� �ε��� ���
	merge_sort(arr, begin, mid - 1, temp); // ��� �� �κ� �պ�����
	merge_sort(arr, mid, end, temp); // ��� �� �κ� �պ�����

	// ���� ��Ʈ
	int idx1 = begin; // ���� ���ĵ� �迭�� ���� �κ�
	int idx2 = mid; // ���� ���ĵ� �迭�� ���� �κ�
	int temp_idx = begin; // ��� ������ �ӽ� �迭�� �ε���
	while (idx1 != mid || idx2 != end + 1) // �հ� �� �迭�� ��� ��ȸ�ϱ� ������ �ݺ�
	{
		if (idx1 == mid) // ù ��° �迭�� �� ��ȸ�ߴٸ� �� ��° �迭�� ��ȸ
		{
			temp[temp_idx++] = arr[idx2++];
		}
		else if (idx2 == end + 1) // �� ��° �迭�� �� ��ȸ�ߴٸ� ù ��° �迭�� ��ȸ
		{
			temp[temp_idx++] = arr[idx1++];
		}
		else // ���� �� �迭�� �� ��ȸ���� �ʾҴٸ�
		{
			if (arr[idx1] > arr[idx2]) // �� �迭�� �ε����� ���� ����Ű�� �ִ� ���� �� �� ���� ���� �ӽ� �迭�� ���
				temp[temp_idx++] = arr[idx2++];
			else
				temp[temp_idx++] = arr[idx1++];
		}
	}
	for (int i = begin; i <= end; i++) // �ӽ� �迭�� ����� �� �迭�� ����
	{
		arr[i] = temp[i];
	}
}

int main(void)
{
	int num_element; // �Է¹��� ���� ����
	int* arr; // �Է��� ������ ������ �迭
	int* temp; // merge sort�� ����� �ӽù迭

	std::cin >> num_element; // �Է¹��� ���� ����
	if (!std::cin || num_element < 0 || num_element % 2 == 0) // ���� �Է��� ¦�� ���ų�, 0�� ���ϰų� �Է� ������ ���
	{
		std::cerr << "Invalid input!" << std::endl;
		return (EXIT_FAILURE); // ���α׷� ����
	}
	arr = new int[num_element]; // �Է��� ���� �迭 �Ҵ�
	temp = new int[num_element]; // �ӽ� �迭(�պ� ���� �ÿ��� ���) �Ҵ�
	for (int i = 0; i < num_element; i++) // �ݺ��ϸ� �Է��� ����
	{
		std::cin >> arr[i]; // �Է��� ����
		if (!std::cin) // �Է¿� ������ �� ��� ���α׷� ����
		{
			delete[] arr;
			delete[] temp;
			std::cerr << "Invalid input!" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	// ���� ��� ����
	{
		//bubble_sort(arr, 0, num_element - 1); // ���� ����
		//insertion_sort(arr, 0, num_element - 1); // ���� ����
		quick_sort(arr, 0, num_element - 1); // �� ����
		//merge_sort(arr, 0, num_element - 1, temp); // ���� ����
	}

	std::cout << "Sorted order: ";
	for (int i = 0; i < num_element; i++) // ���ĵ� �� �ݺ��ϸ� ���
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Median number: " << arr[num_element / 2] << std::endl; // ��� �ִ� �� ���
	delete[] arr; // �Ҵ��� �迭 ����
	delete[] temp; // �Ҵ��� �迭 ����
	return (0);
}