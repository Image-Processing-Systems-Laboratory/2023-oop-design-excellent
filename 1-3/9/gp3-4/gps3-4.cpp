#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void IS(int* input, int count) // Insertion Sort
{
    int i, j, key;
    for (i = 1; i < count; i++)
    {
        key = input[i]; // key는 비교할 요소
        j = i - 1; // input[j]는 key 전 요소들
        while (j >= 0 && input[j] > key) // key와 key 전 요소들을 비교하는 과정
        {
            input[j + 1] = input[j]; // 더 크면 뒤로 보내기
            j--; // 그 다음값(인덱스-1)으로 넘어가기                  
        }
        input[j + 1] = key; // 하나하나 스왑하는게 아니라, 넘길 값들을 모두 넘기고 나서 key를 최종 넘어간 값과 swap 해주는 것이다.
    }
}

void QS(int* input, int start, int end) // Quick Sort. start와 end는 각각 배열의 첫 인덱스와 끝 인덱스를 말한다. 
{
    // Quick Sort의 경우 쪼개고 나서 다시 똑같은 과정을 반복해야 하므로 재귀함수 형태로 함수를 구성해야 한다.
    int i = start;
    int j = end;
    int key = input[(start + end) / 2]; // key는 배열의 중간
    // 사실 기준키는 어디로 잡든 상관이 없다. 잡은 key를 기준으로 좌우가 나뉘어서 정렬이 다 될때까지 계속 Quick Sort가 재귀형태로 돌아가는 것이다

    while (i <= j) // i와 j가 교차할때 반복문을 벗어난다
    {
        while (input[i] < key) // key 이상의 값을 찾으면 반복문 벗어나기
            i++;
        while (input[j] > key)
            j--; // key 이하의 값을 찾으면 반복문 벗어나기
        if (i <= j)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp; // input[i]와 input[j]를 스왑
            i++; // i는 다음칸으로
            j--; // j는 이전칸으로 이동
        }
    }

    if (start < j) // j가 첫 인덱스에 도착하기 전에는
        QS(input, start, j); // 처음 인덱스부터 j까지 잡고 다시 Quick Sort를 돌린다

    if (i < end) // i가 끝 인덱스에 도착하기 전에는
        QS(input, i, end); // i부터 끝 인덱스까지 잡고 다시 Quick Sort를 돌린다
    // 만약에 정렬이 다 끝나면 i가 끝에 가고, j가 처음 인덱스에 가게 된다. 그러면 재귀함수가 멈추고 이 함수는 종료된다. 
}

void merge(int* input, int start, int end) // 쪼갠 뒤에 다시 합치는 합병함수
{
    int* temp = new int[100]; // 임시배열
    int key = (start + end) / 2; // key는 중간

    int i = start; // i는 시작(0)
    int j = key + 1; // j는 중간 바로 다음
    int k = start; // k도 시작(temp의 인덱스 역할)
    while (i <= key && j <= end)
    {
        if (input[i] <= input[j]) // 크기 비교후에
            temp[k++] = input[i++]; // 오름차순 정렬이므로 더 작은 값을 먼저 넣어준다
        else
            temp[k++] = input[j++];
    }

    int tempp = i > key ? j : i; // 삼항 연산자를 통해 아직 정렬이 끝나지 않은 쪽 인덱스를 tempp에 넣어준다.
    // 위 반복문에서 i가 key보다 클때 혹은 j가 end보다 클때 반복문을 빠져나온다. 그러면 만족한 곳은 정렬 밑 temp에 저장이 끝난 상태가 된다.
    // 예를 들어 i가 key보다 커서 while문을 빠져나왔다면 i쪽(key 기준 왼쪽)은 temp에 저장하는 것까지 모두 끝난 상태다. 이제 나머지한쪽을 temp에 저장해줘야 한다.

    while (k <= end)
        temp[k++] = input[tempp++]; // 아직 temp에 못채운쪽 요소들 뒤쪽에 차례대로 채워주기(이 경우 이미 정렬이 돼 있는 상태라서 위 반복문에서 채워주지 않은 것이다)

    for (int i = start; i <= end; i++) // temp에 옮겨놓은걸 다시 input에 옮기기(swap 과정과 비슷함)
        input[i] = temp[i];
    delete[] temp;
}

void divide(int* input, int start, int end) // 가장 작은 단위(1)까지 쪼개내는 분할 함수
{
    int key;
    if (start < end)
    {
        key = (start + end) / 2; // key는 배열의 중간인덱스
        // 일단 세개의 재귀 중 가장 먼저 나오는 key 기준 왼쪽 divide를 모두 수행한다. 즉, key 왼쪽 배열 요소들이 모두 쪼개진다
        // 그 다음 똑같이 오른쪽도 다 쪼개진다. 이렇게 되면 이제 배열은 모두 한개씩으로 쪼개져 있게 된다.
        // 이제 역으로 한개짜리들을 차곡차곡 merge를 해준다. 그럼 두칸씩 붙게 되고, 다시 두칸씩 붙은걸 merge해서 4칸씩 되고 이런식으로 쭉 합병(이때 정렬하면서 합병한다)해서 다시 원래 배열로 돌아온다.
        divide(input, start, key); // 중간기준 왼쪽부분(중간 포함) 재귀적으로 쪼개기
        divide(input, key + 1, end); // 중간기준 오른쪽부분(중간 미포함) 재귀적으로 쪼개기
        merge(input, start, end); // divide가 다 끝나고 나면 merge
    }
}

void BS(int* input, int count) // Bubble Sort.
{
    for (int i = 0; i < count - 1; i++) // i가 0일때 가장 큰수가 뒤로 가게 되고, i가 1일때는 그 큰 수를 제외한 나머지 수끼리의 정렬을 통해 또 그 안에서 가장 큰 수가 뒤로 가고 이런식이다
        for (int j = 0; j < count - i - 1; j++) // i가 1씩 늘수록 j는 1씩 줄기 때문에, 정렬후에 나온 가장 큰 수 1개를 제외하고 나머지끼리 비교하는 것이다.
            if (input[j] > input[j + 1]) // swap 과정
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
}

int main()
{
    int count = 0; // input 개수
    int* input = new int[100];
    cin >> count;
    for (int i = 0; i < count; i++)
        cin >> input[i];

    IS(input, count); // time complexity: n^2(worst and best)
    QS(input, 0, count - 1); // time complexity: nlogn(average and best), n^2(최악). worst는 key가 가장 크거나 가장 작은 요소일때 발생
    BS(input, count); // time complexity: n^2(worst and average), n(best). best는 이미 정렬이 다 돼있을때
    divide(input, 0, count - 1); // time complexity: nlogn(worst, average, best)

    int median = input[(0 + count) / 2]; // median number

    cout << "Sorted order: ";
    for (int i = 0; i < count; i++) // 가장 효율적인 정렬 알고리즘인 merge sort를 통해 정렬된 값들이 출력된다.
        cout << input[i] << " ";
    cout << endl;
    cout << "Median number: " << median << endl;

    delete[] input;
    return 0;
}