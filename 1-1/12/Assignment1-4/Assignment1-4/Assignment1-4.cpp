#include <iostream>
using namespace std;

double finddet(int arr1[3][3]);   //행렬식을 구하는 함수 선언
void findinv(int arr2[3][3]);        //역행렬을 구하는 함수 선언
int matrix[3][3];                 //사용자로부터 입력받는 3x3 행렬 선언
double det;                          //행렬식의 값을 의미하는 변수 선언

int main()
{
    int i, j;                    //반복을 위한 변수 선언
    for (i = 0;i < 3;i++)        //사용자로부터 행렬을 입력받기 위한 반복문
    {
        for (j = 0;j < 3;j++)
        {
            cin >> matrix[i][j]; //행렬 입력받기
        }
    }
    cout << endl;
    det = finddet(matrix);       //finddet함수에서 얻은 행렬식의 값을 det 변수에 저장
    if (det == 0)                //행렬식의 값이 0이라면
        cout << "The inverse matrix does not exist." << endl;  //역행렬이 존재하지 않음을 출력
    else                         //행렬식의 값이 0이 아니라면
    {
        findinv(matrix);            //func 함수 호출
    }
    return 0;
}
double finddet(int arr1[3][3])  //행렬식을 구하는 함수 정의
{
    double ans = 0;       //행렬식을 구하기 위해 필요한 변수 선언 후 0으로 초기화
    ans += arr1[0][0] * (arr1[1][1] * arr1[2][2] - arr1[1][2] * arr1[2][1]);  //행렬식 구하기
    ans -= arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[1][2] * arr1[2][0]);  //행렬식 구하기
    ans += arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[1][1] * arr1[2][0]);  //행렬식 구하기
    return ans;  //행렬식 값 반환
}

void findinv(int arr2[3][3])     //역행렬을 구하는 함수 정의
{
    double cof[3][3] = { 0 };                //여인수 행렬 선언 후 0으로 초기화
    double adj[3][3] = { 0 };               //여인수 행렬의 전치 행렬(수반 행렬) 선언 후 0으로 초기화
    int i, j;                              //반복을 위한 변수 선언 
    double inverse[3][3] = { 0 };            //역행렬 선언 후 0으로 초기화

    //여인수 행렬 구하기
    cof[0][0] = arr2[1][1] * arr2[2][2] - arr2[1][2] * arr2[2][1];
    cof[0][1] = -1 * (arr2[1][0] * arr2[2][2] - arr2[1][2] * arr2[2][0]);
    cof[0][2] = arr2[1][0] * arr2[2][1] - arr2[1][1] * arr2[2][0];
    cof[1][0] = -1 * (arr2[0][1] * arr2[2][2] - arr2[0][2] * arr2[2][1]);
    cof[1][1] = arr2[0][0] * arr2[2][2] - arr2[0][2] * arr2[2][0];
    cof[1][2] = -1 * (arr2[0][0] * arr2[2][1] - arr2[0][1] * arr2[2][0]);
    cof[2][0] = arr2[0][1] * arr2[1][2] - arr2[0][2] * arr2[1][1];
    cof[2][1] = -1 * (arr2[0][0] * arr2[1][2] - arr2[0][2] * arr2[1][0]);
    cof[2][2] = arr2[0][0] * arr2[1][1] - arr2[0][1] * arr2[1][0];

    for (i = 0;i < 3;i++)            //여인수 행렬의 전치 행렬(수반 행렬)을 구하기 위한 반복문
    {
        for (j = 0;j < 3;j++)
        {
            adj[i][j] = cof[j][i];  //행과 열을 바꾸기
        }
    }
    det = finddet(matrix);           //finddet 함수를 이용하여 det 구하기
    for (i = 0;i < 3;i++)            //역행렬을 구하기 위한 반복문
    {
        for (j = 0;j < 3;j++)
        {
            inverse[i][j] = (1 / det) * adj[i][j];    //역행렬 구하기
        }
    }
    for (i = 0;i < 3;i++)            //역행렬을 출력하기 위한 반복문
    {
        for (j = 0;j < 3;j++)
        {
            cout << inverse[i][j] << " ";  //역행렬 출력
        }
        cout << endl;
    }
    return;
}
