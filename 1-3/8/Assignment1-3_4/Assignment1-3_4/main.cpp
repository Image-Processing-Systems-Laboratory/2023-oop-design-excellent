#include <iostream>

void swap(int& a, int& b) // a와 b의 위치를 변경
{
	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort(int* arr, int begin, int end)
{ // 버블 정렬을 사용한 정렬
	for (int i = begin; i < end; i++) // i는 이번 반복에서 정렬될 인덱스
	{
		for (int j = end; j > i; j--) // j로 배열의 끝부터 i + 1까지 순회
		{
			if (arr[j] < arr[j - 1]) // 만약 이웃한 수 중 뒤의 수가 더 작다면
				swap(arr[j], arr[j - 1]); // 두 수를 swap
		}
	}
}

void insertion_sort(int* arr, int begin, int end)
{ // 삽입 정렬을 사용한 정렬
	int temp;
	int i, j;

	for (i = begin + 1; i <= end; i++) // begin은 정렬되었다고 상정하고, begin + 1부터 반복
	{
		if (arr[i - 1] < arr[i]) // 만약 바로 앞의 수보다 크다면 정렬됨
			continue;
		temp = arr[i]; // 임시변수에 현재위치의 수를 넣음
		for (j = i; j > begin && arr[j - 1] >= temp; j--) // 배열을 한칸씩 뒤로 밀며 temp의 위치 탐색
			arr[j] = arr[j - 1];
		arr[j] = temp; // temp 삽입
	}
}

void quick_sort(int* arr, int begin, int end)
{ // 퀵 정렬을 사용한 정렬
	if (begin >= end) // 시작이 끝보다 뒤에 있으면 return 
		return;
	else if (end - begin < 2) // 수가 두 개만 들어온 경우 두 수의 대소를 비교하여 swap
	{
		if (arr[end] < arr[begin])
			swap(arr[end], arr[begin]);
		return;
	}
	int pivot = arr[end]; // 마지막 수를 pivot 으로 설정
	int idx1 = begin; // 맨 처음을 가리키는 인덱스
	int idx2 = end - 1; // pivot을 제외하고 맨 뒤를 가리키는 인덱스
	while (idx1 < idx2) // 두 인덱스가 만날 때까지 반복
	{
		// 만약 idx1은 pivot뒤의 값이고 idx2는 pivot 앞의 값일 경우
		if (arr[idx1] > pivot && arr[idx2] < pivot)
		{
			swap(arr[idx1], arr[idx2]); // 두 수를 교환
			idx1++; // idx1은 다음 수를 가리킴
			idx2--; // idx2는 이전 수를 가리킴
		}
		else if (arr[idx1] > pivot) // idx1은 뒤로 가야 될 수를 가리키고 있다면, idx2만 이동하여 swap할 수 탐색
			idx2--;
		else if (arr[idx2] < pivot) // idx2는 앞으로 가야 될 수를 가리키고 있다면 idx1만 이동하여 swap할 수 탐색
			idx1++;
		else // 만약 둘 다 현재 위치에 적합한 수를 가리킨다면 둘 다 이동시킴
		{
			idx1++;
			idx2--;
		}
	}
	if (arr[idx1] < pivot) // idx1이 가리키고 있는 수가 pivot 앞에 있어야 하는 수인 경우
		idx1++;
	swap(arr[end], arr[idx1]); // pivot과 idx1이 가리키고 있는 수를 swap
	quick_sort(arr, begin, idx1 - 1); // pivot앞의 구간을 quick sort
	quick_sort(arr, idx1 + 1, end); // pivot 뒤의 구간을 quick sort
}

void merge_sort(int* arr, int begin, int end, int* temp)
{ // 합병 정렬을 사용한 정렬
	if (begin >= end) // 시작이 끝보다 뒤에 있으면 return 
		return;
	else if (end - begin < 2) // 수가 두 개만 들어온 경우 두 수의 대소를 비교하여 swap
	{
		if (arr[end] < arr[begin])
			swap(arr[end], arr[begin]);
		return;
	}
	int mid = begin + (end - begin) / 2; //가운데 인덱스 계산
	merge_sort(arr, begin, mid - 1, temp); // 가운데 앞 부분 합병정렬
	merge_sort(arr, mid, end, temp); // 가운데 뒷 부분 합병정렬

	// 병합 파트
	int idx1 = begin; // 앞쪽 정렬된 배열의 시작 부분
	int idx2 = mid; // 뒤쪽 정렬된 배열의 시작 부분
	int temp_idx = begin; // 결과 저장할 임시 배열의 인덱스
	while (idx1 != mid || idx2 != end + 1) // 앞과 뒤 배열을 모두 순회하기 전까지 반복
	{
		if (idx1 == mid) // 첫 번째 배열은 다 순회했다면 두 번째 배열만 순회
		{
			temp[temp_idx++] = arr[idx2++];
		}
		else if (idx2 == end + 1) // 두 번째 배열은 다 순회했다면 첫 번째 배열만 순회
		{
			temp[temp_idx++] = arr[idx1++];
		}
		else // 만약 두 배열이 다 순회되지 않았다면
		{
			if (arr[idx1] > arr[idx2]) // 두 배열의 인덱스가 각각 가리키고 있는 수들 중 더 작은 수를 임시 배열에 기록
				temp[temp_idx++] = arr[idx2++];
			else
				temp[temp_idx++] = arr[idx1++];
		}
	}
	for (int i = begin; i <= end; i++) // 임시 배열의 결과를 원 배열에 복사
	{
		arr[i] = temp[i];
	}
}

int main(void)
{
	int num_element; // 입력받을 수의 갯수
	int* arr; // 입력을 저장할 정수형 배열
	int* temp; // merge sort에 사용할 임시배열

	std::cin >> num_element; // 입력받을 수의 갯수
	if (!std::cin || num_element < 0 || num_element % 2 == 0) // 만약 입력이 짝수 개거나, 0개 이하거나 입력 오류인 경우
	{
		std::cerr << "Invalid input!" << std::endl;
		return (EXIT_FAILURE); // 프로그램 종료
	}
	arr = new int[num_element]; // 입력을 받을 배열 할당
	temp = new int[num_element]; // 임시 배열(합병 정렬 시에만 사용) 할당
	for (int i = 0; i < num_element; i++) // 반복하며 입력을 받음
	{
		std::cin >> arr[i]; // 입력을 받음
		if (!std::cin) // 입력에 오류가 난 경우 프로그램 종료
		{
			delete[] arr;
			delete[] temp;
			std::cerr << "Invalid input!" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	// 정렬 방법 선택
	{
		//bubble_sort(arr, 0, num_element - 1); // 버블 정렬
		//insertion_sort(arr, 0, num_element - 1); // 삽입 정렬
		quick_sort(arr, 0, num_element - 1); // 퀵 정렬
		//merge_sort(arr, 0, num_element - 1, temp); // 병합 정렬
	}

	std::cout << "Sorted order: ";
	for (int i = 0; i < num_element; i++) // 정렬된 수 반복하며 출력
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Median number: " << arr[num_element / 2] << std::endl; // 가운데 있는 수 출력
	delete[] arr; // 할당한 배열 해제
	delete[] temp; // 할당한 배열 해제
	return (0);
}