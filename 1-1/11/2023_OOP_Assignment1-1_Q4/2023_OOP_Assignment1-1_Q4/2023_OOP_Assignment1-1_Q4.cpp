// 2023_OOP_Assignment1-1_Q4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
//3by3 행렬이니 int[3][3]로 하면 될 듯??
#include <iostream>
#include <cmath>

using namespace std;

void input_m(float a[3][3]);            //행렬 입력 함수
void output_m(double a[3][3]);         //행렬 출력 함수


int main()
{
    float matrix[3][3];         //행렬
    double c_matrix[3][3];     //여인수 행렬
    double ct_matrix[3][3];    //수반 행렬
    double i_matrix[3][3];      //inverse matrix
    float determinant, idet = 0;        //determinant, idet 선언
   


    input_m(matrix);            //행렬 입력

    determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);     //determinant 계산

    if (determinant == 0) {         //determinant=0일 떄
        cout << "\nThe inverse matrix does not exist." << endl;         //inverse matrix가 존재하지 않는다는 문장 출력
    }
    else {
        idet = 1 / determinant;         //idet 계산


        c_matrix[0][0] = (double)pow(-1, (1 + 1)) * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);    //소행렬 이용하여 cofactor matrix에 저장

        c_matrix[0][1] = (double)pow(-1, (1 + 2)) * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);    

        c_matrix[0][2] = (double)pow(-1, (1 + 3)) * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

        c_matrix[1][0] = (double)pow(-1, (2 + 1)) * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);

        c_matrix[1][1] = (double)pow(-1, (2 + 2)) * (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]);

        c_matrix[1][2] = (double)pow(-1, (2 + 3)) * (matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);

        c_matrix[2][0] = (double)pow(-1, (3 + 1)) * (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);

        c_matrix[2][1] = (double)pow(-1, (3 + 2)) * (matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);

        c_matrix[2][2] = (double)pow(-1, (3 + 3)) * (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);




        ct_matrix[0][0] = c_matrix[0][0];      
        ct_matrix[0][1] = c_matrix[1][0];       //여인수 행렬 이용하여 수반 행렬 저장
        ct_matrix[0][2] = c_matrix[2][0];
        ct_matrix[1][1] = c_matrix[1][1];
        ct_matrix[1][0] = c_matrix[0][1];
        ct_matrix[2][0] = c_matrix[0][2];
        ct_matrix[1][2] = c_matrix[2][1];
        ct_matrix[2][1] = c_matrix[1][2];
        ct_matrix[2][2] = c_matrix[2][2];

        for (int i = 0; i < 3; i++) {   
            for (int j = 0; j < 3; j++) {                          
                i_matrix[i][j] = (double)ct_matrix[i][j] * idet;    //  '역행렬에 수반 행렬/determinant'를 저장한다
            }
        }

        /*cout << "\nThe determinant is: " << endl;               
        cout << determinant << endl;                        

        cout << "\nThe cofactor matrix is: " << endl;       
        output_m(c_matrix);

        cout << "\nThe transpose cofactor matrix is: " << endl;
        output_m(ct_matrix);*/

        cout << "\nThe inverse matrix is: " << endl;        //inverse matrix 출력하기
        output_m(i_matrix);

    }

    return 0;

}

void input_m(float a[3][3]) {    //matrix를 입력하는 함수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];             //입력받아 저장
        }
    }
    return;
}

void output_m(double a[3][3]) {    //matrix를 출력하는 함수
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << ' ';    //행렬 출력
        }
        cout << endl;               //개행
    }
    return;
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
