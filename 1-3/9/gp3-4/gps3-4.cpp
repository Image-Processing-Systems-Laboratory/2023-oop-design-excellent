#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void IS(int* input, int count) // Insertion Sort
{
    int i, j, key;
    for (i = 1; i < count; i++)
    {
        key = input[i]; // key�� ���� ���
        j = i - 1; // input[j]�� key �� ��ҵ�
        while (j >= 0 && input[j] > key) // key�� key �� ��ҵ��� ���ϴ� ����
        {
            input[j + 1] = input[j]; // �� ũ�� �ڷ� ������
            j--; // �� ������(�ε���-1)���� �Ѿ��                  
        }
        input[j + 1] = key; // �ϳ��ϳ� �����ϴ°� �ƴ϶�, �ѱ� ������ ��� �ѱ�� ���� key�� ���� �Ѿ ���� swap ���ִ� ���̴�.
    }
}

void QS(int* input, int start, int end) // Quick Sort. start�� end�� ���� �迭�� ù �ε����� �� �ε����� ���Ѵ�. 
{
    // Quick Sort�� ��� �ɰ��� ���� �ٽ� �Ȱ��� ������ �ݺ��ؾ� �ϹǷ� ����Լ� ���·� �Լ��� �����ؾ� �Ѵ�.
    int i = start;
    int j = end;
    int key = input[(start + end) / 2]; // key�� �迭�� �߰�
    // ��� ����Ű�� ���� ��� ����� ����. ���� key�� �������� �¿찡 ����� ������ �� �ɶ����� ��� Quick Sort�� ������·� ���ư��� ���̴�

    while (i <= j) // i�� j�� �����Ҷ� �ݺ����� �����
    {
        while (input[i] < key) // key �̻��� ���� ã���� �ݺ��� �����
            i++;
        while (input[j] > key)
            j--; // key ������ ���� ã���� �ݺ��� �����
        if (i <= j)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp; // input[i]�� input[j]�� ����
            i++; // i�� ����ĭ����
            j--; // j�� ����ĭ���� �̵�
        }
    }

    if (start < j) // j�� ù �ε����� �����ϱ� ������
        QS(input, start, j); // ó�� �ε������� j���� ��� �ٽ� Quick Sort�� ������

    if (i < end) // i�� �� �ε����� �����ϱ� ������
        QS(input, i, end); // i���� �� �ε������� ��� �ٽ� Quick Sort�� ������
    // ���࿡ ������ �� ������ i�� ���� ����, j�� ó�� �ε����� ���� �ȴ�. �׷��� ����Լ��� ���߰� �� �Լ��� ����ȴ�. 
}

void merge(int* input, int start, int end) // �ɰ� �ڿ� �ٽ� ��ġ�� �պ��Լ�
{
    int* temp = new int[100]; // �ӽù迭
    int key = (start + end) / 2; // key�� �߰�

    int i = start; // i�� ����(0)
    int j = key + 1; // j�� �߰� �ٷ� ����
    int k = start; // k�� ����(temp�� �ε��� ����)
    while (i <= key && j <= end)
    {
        if (input[i] <= input[j]) // ũ�� ���Ŀ�
            temp[k++] = input[i++]; // �������� �����̹Ƿ� �� ���� ���� ���� �־��ش�
        else
            temp[k++] = input[j++];
    }

    int tempp = i > key ? j : i; // ���� �����ڸ� ���� ���� ������ ������ ���� �� �ε����� tempp�� �־��ش�.
    // �� �ݺ������� i�� key���� Ŭ�� Ȥ�� j�� end���� Ŭ�� �ݺ����� �������´�. �׷��� ������ ���� ���� �� temp�� ������ ���� ���°� �ȴ�.
    // ���� ��� i�� key���� Ŀ�� while���� �������Դٸ� i��(key ���� ����)�� temp�� �����ϴ� �ͱ��� ��� ���� ���´�. ���� ������������ temp�� ��������� �Ѵ�.

    while (k <= end)
        temp[k++] = input[tempp++]; // ���� temp�� ��ä���� ��ҵ� ���ʿ� ���ʴ�� ä���ֱ�(�� ��� �̹� ������ �� �ִ� ���¶� �� �ݺ������� ä������ ���� ���̴�)

    for (int i = start; i <= end; i++) // temp�� �Űܳ����� �ٽ� input�� �ű��(swap ������ �����)
        input[i] = temp[i];
    delete[] temp;
}

void divide(int* input, int start, int end) // ���� ���� ����(1)���� �ɰ����� ���� �Լ�
{
    int key;
    if (start < end)
    {
        key = (start + end) / 2; // key�� �迭�� �߰��ε���
        // �ϴ� ������ ��� �� ���� ���� ������ key ���� ���� divide�� ��� �����Ѵ�. ��, key ���� �迭 ��ҵ��� ��� �ɰ�����
        // �� ���� �Ȱ��� �����ʵ� �� �ɰ�����. �̷��� �Ǹ� ���� �迭�� ��� �Ѱ������� �ɰ��� �ְ� �ȴ�.
        // ���� ������ �Ѱ�¥������ �������� merge�� ���ش�. �׷� ��ĭ�� �ٰ� �ǰ�, �ٽ� ��ĭ�� ������ merge�ؼ� 4ĭ�� �ǰ� �̷������� �� �պ�(�̶� �����ϸ鼭 �պ��Ѵ�)�ؼ� �ٽ� ���� �迭�� ���ƿ´�.
        divide(input, start, key); // �߰����� ���ʺκ�(�߰� ����) ��������� �ɰ���
        divide(input, key + 1, end); // �߰����� �����ʺκ�(�߰� ������) ��������� �ɰ���
        merge(input, start, end); // divide�� �� ������ ���� merge
    }
}

void BS(int* input, int count) // Bubble Sort.
{
    for (int i = 0; i < count - 1; i++) // i�� 0�϶� ���� ū���� �ڷ� ���� �ǰ�, i�� 1�϶��� �� ū ���� ������ ������ �������� ������ ���� �� �� �ȿ��� ���� ū ���� �ڷ� ���� �̷����̴�
        for (int j = 0; j < count - i - 1; j++) // i�� 1�� �ü��� j�� 1�� �ٱ� ������, �����Ŀ� ���� ���� ū �� 1���� �����ϰ� ���������� ���ϴ� ���̴�.
            if (input[j] > input[j + 1]) // swap ����
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
}

int main()
{
    int count = 0; // input ����
    int* input = new int[100];
    cin >> count;
    for (int i = 0; i < count; i++)
        cin >> input[i];

    IS(input, count); // time complexity: n^2(worst and best)
    QS(input, 0, count - 1); // time complexity: nlogn(average and best), n^2(�־�). worst�� key�� ���� ũ�ų� ���� ���� ����϶� �߻�
    BS(input, count); // time complexity: n^2(worst and average), n(best). best�� �̹� ������ �� ��������
    divide(input, 0, count - 1); // time complexity: nlogn(worst, average, best)

    int median = input[(0 + count) / 2]; // median number

    cout << "Sorted order: ";
    for (int i = 0; i < count; i++) // ���� ȿ������ ���� �˰����� merge sort�� ���� ���ĵ� ������ ��µȴ�.
        cout << input[i] << " ";
    cout << endl;
    cout << "Median number: " << median << endl;

    delete[] input;
    return 0;
}