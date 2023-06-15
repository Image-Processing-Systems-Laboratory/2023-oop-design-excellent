#include <iostream>

using namespace std;

void insertion(int list[], int len)
{
	int temp, i, j;

	for (i = 1; i < len; i++)  //0��° ���Ҵ� �״�� �ΰ� 1��° ���Һ��� �� ����
	{
		temp = list[i];
		j = i - 1;

		for (;j >= 0 && list[j] > temp; j--)  //���ؿ��� ���� �迭�� ���������� �������� ���� ���ϰ� ������ ���� ���� ������ ���� ���
		{
			list[j + 1] = list[j];  //������ ������ �迭�� ���ҵ��� ���������� �� ĭ�� �̵��ñ�鼭 ������ ���� �������� ������ �˸��� �ڸ��� ������ 
		}

		list[j + 1] = temp;  //�׷��� �ʰ� �����ϴ� ���� ���� ������ Ŭ ��� ���� ���� �ٷ� ������ ��ġ�� ���� ������
	}

	return;
}

void swap(int* a, int* b)   //�� ���� ���� �ٲ��ִ� swap�Լ� 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int list[], int fst, int lst)
{
	int pivot = list[lst];  //�� ������ ���Ҹ� �������� ����
	int i = (fst - 1);

	for (int j = fst; j <= lst - 1; j++) 
	{
		if (list[j] <= pivot)  //�ɰ��� �迭���� �� ó�� ���Һ��� ���� ���Һ��� ������ ����
		{
			i++;
			swap(&list[i], &list[j]);  //���� ���Һ��� ���� �͵��� �������� ������
		}
	}

	swap(&list[i + 1], &list[lst]);  //���ʿ��� ���� ���� ���Һ��� ���� ������ �����ְ� ���� ���� ���Ҹ� �����ϸ�
	                                 //�����ʿ��� ���� ���Һ��� ū ������ ����Ǿ� ����
	return (i + 1);                 //������ �Ǵ� pivot�� ��ġ�� ��ȯ ��
}

void quick(int list[], int fst, int lst)
{
	if (fst < lst)  //�迭�� ����ؼ� ���� �ϴٰ� fst���� lst���� ������ ���Ұ� �ϳ��� ���� �� ���ȣ���� ����
	{
		int p = partition(list, fst, lst);

		quick(list, fst, p - 1);  //p��° ���Ҹ� �߽����� ���ʰ� ������ 2���� �迭�� ������ �Լ��� ���� ��� ȣ���Ŵ
		quick(list, p + 1, lst);
	}
}

void sort(int list[], int fst, int mid, int lst)
{
	int L, R, k;
	L = fst;
	R = mid + 1;
	k = fst;
	
	int* sorted = new int[lst + 1];  //2���� ���� �迭�� �����Ͽ� ������ �ӽ� �迭

	while (L <= mid && R <= lst)  //L, R�� �� ������ �����ϸ� ������ �迭�� ���Ұ� �ּ� 2�� �̻��̿��� ������ �ʿ��� ����
	{
		if (list[L] <= list[R])   //�������� �տ� ���� ��
		{
			sorted[k] = list[L];  //������ �迭�� �������� �״�� ����
			L++;
		}

		else             //ū���� �տ� �־� ������ �ʿ��� ���
		{
			sorted[k] = list[R];  //���� ���� ����� R��° �迭�� ������ �迭 �� �տ������� �����Ŵ
			R++;
		}

		k++;  
	}

	if (L > mid)    //L++�� �����Ͽ� L���� mid���� �Ѿ��� ���
	{
		for (int i = R; i <= lst; i++)  //���� �����ʺ��� �������� ������ �迭�� �뤊�� ������
		{
			sorted[k] = list[i];
			k++;
		}
	}

	else
	{
		for (int i = L; i <= mid; i++) //���� ���ʺ��� �߰������� ������ �迭�� �뤊�� ������
		{
			sorted[k] = list[i];
			k++;
		}
	}

	for (int i = fst; i <= lst; i++)   //������ ���İ����� ��ģ �迭�� �ٽ� �����ؼ� ���� �迭�� ������
	{
		list[i] = sorted[i];
	}

	delete[] sorted;   //�Ҵ�� �޸� ����
}

void merge(int list[], int fst, int lst)  //merge sort ����
{
	if (fst < lst)   //����ؼ� ������ ���� �迭�� 1���� �Ǹ� fst�� lst�� ���� ������ �� �̻� ���ȣ�� ���� ����
	{
		int m = (fst + lst) / 2;

		merge(list, fst, m);          //�߰��� m�� �߽����� �Լ��� ���ȣ���Ͽ� 2���� �迭�� ����
		merge(list, m + 1, lst);

		sort(list, fst, m, lst);     //�迭�� ���ҵ��� ������������ ���� ���ִ� �Լ�
	}
}

void bubbleUp(int list[], int len) //len�� �迭�� ����
{
	for (int i = 0; i < len - 1; i++)   //�ѹ� �������� ���� ū ���ڰ� ���� �������������� ����ǹǷ� len - 1�� �ݺ�
	{
		for (int walker = 0; walker < len - 1; walker++)  //���������� �տ��� ���� 2���� ��
		{
			if (list[walker + 1] < list[walker])  //������ ���Ұ� ���ʺ��� ������ ���� ��ġ�� ��ȯ
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
	int* arr = new int[num];     //�޸𸮸� �迭�� �����Ҵ�

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	//insertion(arr, num);
	//quick(arr, 0, num - 1);
	//merge(arr, 0, num - 1);

	bubbleUp(arr, num);    //bubble sort�� ��� ���

	cout << "Sorted order: ";
	for (int i = 0; i < num; i++)    //���ĵ� �迭�� ���ҵ��� ������� ���
	{
		cout << arr[i] << ' ';
	}

	cout << endl << "Median number: " << arr[num / 2];    //������������ ���ĵ� �迭�� �߰����� �����

	delete[] arr;      //�����Ҵ��� �޸� ����

	return 0;
}