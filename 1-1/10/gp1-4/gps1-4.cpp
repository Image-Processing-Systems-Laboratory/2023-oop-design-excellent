#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int** arr = new int* [3]; // 사용자에게 받은 값을 저장할 배열(행렬) 동적할당으로 생성
    for (int i = 0; i < 3; i++)
        arr[i] = new int[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];

    double** nar = new double* [3]; // 역행렬 값을 저장할 배열(행렬) 동작할당으로 생성
    for (int i = 0; i < 3; i++)
        nar[i] = new double[3];

    int det = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]) // determinant 구하기(추후에 출력시에 det로 나눠서 출력)
        - arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0])
        + arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

    if (det == 0) // determinant가 0이면 분모가 0이돼서 역행렬이 성립하지 않음
    {
        cout << "The inverse Matrix does not exist.";
        return 0;
    }

    // 여인수 행렬을 구하고 뒤바꾸는 과정. 코드를 간결화하기 위해 구하고 바꾸는 과정을 한번에 묶어서 진행했다.
    nar[0][0] = (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]);
    nar[0][1] = -(arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1]);
    nar[0][2] = (arr[0][1] * arr[1][2] - arr[0][2] * arr[1][1]);
    nar[1][0] = -(arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
    nar[1][1] = (arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0]);
    nar[1][2] = -(arr[0][0] * arr[1][2] - arr[1][0] * arr[0][2]);
    nar[2][0] = (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]);
    nar[2][1] = -(arr[0][0] * arr[2][1] - arr[2][0] * arr[0][1]);
    nar[2][2] = (arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1]);

    for (int i = 0; i < 3; i++) // 전체출력
    {
        for (int j = 0; j < 3; j++)
        {
            nar[i][j] /= det; // det로 나눠주기
            cout << nar[i][j] << '\t'; // 행렬 틀을 맞추기 위해 '\t' 사용
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) // delete 해주기
        delete[] arr[i];
    delete[] arr;

    for (int i = 0; i < 3; i++) // delete
        delete[] nar[i];
    delete[] nar;
    return 0;
}