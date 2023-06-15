#include <iostream>

using namespace std;

void insertion(int list[], int len)
{
	int temp, i, j;

	for (i = 1; i < len; i++)  //0번째 원소는 그대로 두고 1번째 원소부터 비교 시작
	{
		temp = list[i];
		j = i - 1;

		for (;j >= 0 && list[j] > temp; j--)  //기준에서 왼쪽 배열의 끝에서부터 왼쪽으로 수를 비교하고 삽입할 수가 비교한 수보다 작을 경우
		{
			list[j + 1] = list[j];  //기준의 왼쪽의 배열의 원소들을 오른쪽으로 한 칸씩 이동시기면서 삽입할 수를 오름차순 정렬의 알맞은 자리에 저장함 
		}

		list[j + 1] = temp;  //그렇지 않고 삽입하는 수가 비교한 수보다 클 경우 비교한 수의 바로 오른쪽 위치에 수를 삽입함
	}

	return;
}

void swap(int* a, int* b)   //두 값을 서로 바꿔주는 swap함수 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int list[], int fst, int lst)
{
	int pivot = list[lst];  //맨 마지막 원소를 기준으로 잡음
	int i = (fst - 1);

	for (int j = fst; j <= lst - 1; j++) 
	{
		if (list[j] <= pivot)  //쪼개진 배열에서 맨 처음 원소부터 기준 원소보다 작은지 비교함
		{
			i++;
			swap(&list[i], &list[j]);  //기준 원소보다 작은 것들을 왼쪽으로 몰아줌
		}
	}

	swap(&list[i + 1], &list[lst]);  //왼쪽에서 부터 기준 원소보다 작은 값들을 몰아주고 그후 기준 원소를 저장하며
	                                 //오른쪽에는 기준 원소보다 큰 값들이 저장되어 있음
	return (i + 1);                 //기준이 되는 pivot의 위치를 반환 함
}

void quick(int list[], int fst, int lst)
{
	if (fst < lst)  //배열을 계속해서 분할 하다가 fst값과 lst값이 같아져 원소가 하나가 남을 때 재귀호출을 멈춤
	{
		int p = partition(list, fst, lst);

		quick(list, fst, p - 1);  //p번째 원소를 중심으로 왼쪽과 오른쪽 2개의 배열로 나누어 함수를 각각 재귀 호출시킴
		quick(list, p + 1, lst);
	}
}

void sort(int list[], int fst, int mid, int lst)
{
	int L, R, k;
	L = fst;
	R = mid + 1;
	k = fst;
	
	int* sorted = new int[lst + 1];  //2개로 찢은 배열을 정렬하여 저장할 임시 배열

	while (L <= mid && R <= lst)  //L, R이 각 조건을 만족하면 찢어진 배열의 원소가 최소 2개 이상이여서 정렬이 필요한 생태
	{
		if (list[L] <= list[R])   //작은값이 앞에 있을 떄
		{
			sorted[k] = list[L];  //임의의 배열에 작은값을 그대로 저장
			L++;
		}

		else             //큰값이 앞에 있어 정렬이 필요한 경우
		{
			sorted[k] = list[R];  //작은 값이 저장된 R번째 배열을 임의의 배열 맨 앞에서부터 저장시킴
			R++;
		}

		k++;  
	}

	if (L > mid)    //L++를 실행하여 L값이 mid값을 넘었을 경우
	{
		for (int i = R; i <= lst; i++)  //남은 오른쪽부터 끝까지를 임의의 배열에 통쨰로 저장함
		{
			sorted[k] = list[i];
			k++;
		}
	}

	else
	{
		for (int i = L; i <= mid; i++) //남은 왼쪽부터 중간까지를 임의의 배열에 통쨰로 저장함
		{
			sorted[k] = list[i];
			k++;
		}
	}

	for (int i = fst; i <= lst; i++)   //위에서 정렬과정을 마친 배열을 다시 복사해서 원래 배열에 저장함
	{
		list[i] = sorted[i];
	}

	delete[] sorted;   //할당된 메모리 해제
}

void merge(int list[], int fst, int lst)  //merge sort 구현
{
	if (fst < lst)   //계속해서 반으로 찢은 배열이 1개가 되면 fst와 lst의 값이 같아져 더 이상 재귀호출 하지 않음
	{
		int m = (fst + lst) / 2;

		merge(list, fst, m);          //중간값 m을 중심으로 함수를 재귀호출하여 2개의 배열로 찢음
		merge(list, m + 1, lst);

		sort(list, fst, m, lst);     //배열의 원소들을 오름차순으로 정렬 해주는 함수
	}
}

void bubbleUp(int list[], int len) //len은 배열의 길이
{
	for (int i = 0; i < len - 1; i++)   //한번 돌때마다 가장 큰 숫자가 제일 마지막에서부터 저장되므로 len - 1번 반복
	{
		for (int walker = 0; walker < len - 1; walker++)  //순차적으로 앞에서 부터 2개씩 비교
		{
			if (list[walker + 1] < list[walker])  //오른쪽 원소가 왼쪽보다 작으면 둘의 위치를 교환
			{
			    int temp = list[walker + 1];
			    list[walker + 1] = list[walker];
			    list[walker] = temp;
			}
		}
	}
	
	return;
}

int main()
{
	int num = 0;

	cin >> num;
	int* arr = new int[num];     //메모리를 배열로 동적할당

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	//insertion(arr, num);
	//quick(arr, 0, num - 1);
	//merge(arr, 0, num - 1);

	bubbleUp(arr, num);    //bubble sort로 결과 출력

	cout << "Sorted order: ";
	for (int i = 0; i < num; i++)    //정렬된 배열의 원소들을 순서대로 출력
	{
		cout << arr[i] << ' ';
	}

	cout << endl << "Median number: " << arr[num / 2];    //오름차순으로 정렬된 배열의 중간값을 출력함

	delete[] arr;      //동적할당한 메모리 해제

	return 0;
}