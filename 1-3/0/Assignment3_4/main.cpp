#include<iostream>
#include<ctime>	// 정렬하는데 걸리는 시간을 출력하기 위해 포함한 헤더파일
using namespace std;

//각 정렬들을 함수로 구현
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


	// 시간을 측정하기위해 아래와 같은 구조로 코드를 작성함
	start = clock();
	insert(arr, nums);
	end = clock();
	cout << "Sorted order: ";
	for (int i = 0; i < nums; i++)
		cout << arr[i]<<' ';
	double excut_time = (double)(end - start);

	cout << "\nMedian number: " << arr[nums / 2]<<endl;
	//cout << "execution time: " << excut_time<<"ms";	// 정렬이 시행되는동안 걸리는 시간 출력

	return 0;
	
}

void insert(int* arr, int n)
{
	int key = 0;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		//선택한 원소를 sel에 저장
		key = arr[i];

		//sel보다 
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}


}
void quick(int* arr, int i,int j)
{
	if (i >= j) // 원소가 1개인 경우에 정렬 종료
		return;
	int idx_low = i+1;
	int idx_high = j;
	int pivot_i = i;

	while (idx_low<=idx_high)//두 인덱스가 엇갈릴때까지 반복
	{
		while (arr[idx_low] <= arr[pivot_i] && idx_low <= j) // 배열의 앞 원소부터 접근하여 확인
		{
			idx_low++;
		}
		while (arr[idx_high] >= arr[pivot_i] && idx_high > i) // 배열의 뒤 원소부터 접근하여 확인
		{
			idx_high--;
		}

		if (idx_low > idx_high) // 두 인덱스가 엇갈릴때 피벗에 해당하는 수를 적절한 위치에 넣음
		{
			int tmp = arr[idx_high];
			arr[idx_high] = arr[pivot_i];
			arr[pivot_i] = tmp;
		}
		else// i와 j의 위치를 바꿈
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

	//mid를 기준으로 두 배열로 나누어 복사본을 만든다
	int* arr_L = new int[lenL];
	int* arr_R = new int[lenR];
	for (int i = 0; i < lenL; i++)
		arr_L[i] = arr[left + i];
	for (int i = 0; i < lenR; i++)
		arr_R[i] = arr[mid + 1 + i];

	// arr과 arr을 나눈 두 배열의 인덱스를 가리키는 변수들을 통해
	// 두배열의 원소들중 작은 값을 arr에 넣는다.
	int idx_L = 0, idx_R = 0, idx_A = left;
	while (idx_L < lenL && idx_R < lenR)
	{
		if (arr_L[idx_L] <= arr_R[idx_R])
			arr[idx_A++] = arr_L[idx_L++];
		else
			arr[idx_A++] = arr_R[idx_R++];
	}

	// arr_L과 arr_R중, 하나가 비어지면, 아래의 방식으로 arr을 left부터 right사이까지 채움
	//arr_R이 비어있는경우
	while (idx_L < lenL)
		arr[idx_A++] = arr_L[idx_L++];

	//arr_L이 비어있는경우
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
	int mid = (left + right) / 2;	// 반으로 나누어 재귀호출
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void bubble(int* arr, int n)
{
	// 비교의 범위를 결정 하기위한 인덱스는 n-1번째 까지만 지목하면 됨
	int i = n-1;

	int j = 0;
	while (i >1)
	{
		while (j < i)
		{	// arr[i]가 더 크면 swap실시
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