#include <iostream>
using namespace std;

void    swap(double *a, double *b);
int     get_det(int arr[][3]); // 주어진 행렬의 행렬식을 반환하는 함수
void    make_adj(int arr[][3], double adj[][3]);
// 주어진 행렬의 수반 행렬을 만들어주는 함수

int main()
{
    int arr[3][3];
    double adj[3][3]; // 생성할 수반 행렬
    int det;

    cout << "Input: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }
    det = get_det(arr);
    if (det == 0)
    {
        cout << "The inverse matrix does not exist" << endl;
        return (0);
        // 역행렬 공식: (1 / (행렬식)) *(수반 행렬)
        // 행렬식 값이 0이면 분모가 0이므로 행렬이 만들어질 수 없음
    }
    make_adj(arr, adj); // 입력받은 arr의 수반행렬을 adj에 입력
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            adj[i][j] /= det;
    }// 수반 행렬의 각 항을 행렬식 값으로 나눔(역행렬 공식)
    cout << "Output: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return (0);
}

void	swap(double *a, double *b)
{
    double		temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int get_det(int arr[][3])
{
    int a, b;

    a = 0, b = 0;
    for (int i = 0; i < 3; i++)
        a += arr[0][i] * arr[1][(i + 1) % 3] * arr[2][(i + 2) % 3];
    for (int i = 0; i < 3; i++)
        b += arr[0][i] * arr[1][(i + 2) % 3] * arr[2][(i + 1) % 3];
    // 3 X 3 행렬식의 공식: (a_11*a_22*a_33 + a_12*a_23*a_31 + a_13*a_21*a_32)
    //                      - (a_11*a_23*a_32 + a_12*a_21*a_33 + a_13*a_22*a_31)
    // 인덱스를 그냥 1씩 증가시키면 최대 인덱스(2)를 넘어가지만, 이를 3으로 나머지 연산하면
    // 0 ~ 2의 값이 반복됨
    return (a - b);
}

void    make_adj(int arr[][3], double adj[][3])
{
    // 수반 행렬 == 여인수 행렬의 전치 행렬
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            adj[j][i] = (arr[(i + 1) % 3][(j + 1) % 3]
                * arr[(i + 2) % 3][(j + 2) % 3]
                - arr[(i + 2) % 3][(j + 1) % 3]
                * arr[(i + 1) % 3][(j + 2) % 3]);
        }
        // 여인수 행렬의 공식 이용
        // adj[i][j]가 아닌 [j][i]로 작성한 이유는
        // 여인수 행렬를 만듦과 동시에 전치행렬을 생성하기 위함
    }
}