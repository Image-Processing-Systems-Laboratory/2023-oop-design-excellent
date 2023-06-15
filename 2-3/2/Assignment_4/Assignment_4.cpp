#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ooplinalg.h"
using namespace std;

int main()
{
    //3*3 Matrix 선언
    float data[3][3] = {{2.0,2.0,3.0},
                                    {1.0,1.0,2.0},
                                    {1.0,2.0,3.0} };
    ooplinalg::Matrix mat(3,3);
    cout << "mat : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat.setElement(i, j, data[i][j]);
            cout << mat.getElement(i, j) << "\t";
        }
        cout << endl;
    }
    
    //determinant 계산
    cout << "determinant of mat : " << mat.determinant() << endl;

    //elementAdd
    ooplinalg::Matrix mat1(3,3);
    ooplinalg::elementAdd(mat1, mat, 3);
    cout << endl << "elementAdd 3" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat1.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //elementSub
    ooplinalg::Matrix mat2(3, 3);
    ooplinalg::elementSub(mat2, mat, 2);
    cout << endl << "elementSub 2" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat2.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //elementMul
    ooplinalg::Matrix mat3(3, 3);
    ooplinalg::elementMul(mat3, mat, 4);
    cout << endl << "elementMul 4" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat3.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //elementDiv
    ooplinalg::Matrix mat4(3, 3);
    ooplinalg::elementDiv(mat4, mat, 3);
    cout << endl << "elementDiv 3" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat4.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //3*3 matrix 선언
    float data1[3][3] = { {1.0,2.0,3.0},
                                      {4.0,5.0,6.0},
                                      {7.0,8.0,9.0} };
    ooplinalg::Matrix mat5(3, 3);
    cout << endl << "mat5 : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat5.setElement(i, j, data1[i][j]);
            cout << mat5.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //add
    ooplinalg::Matrix mat6(3, 3);
    ooplinalg::add(mat6, mat, mat5);
    cout << endl << "add func with mat, mat5" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat6.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //sub
    ooplinalg::Matrix mat7(3, 3);
    ooplinalg::sub(mat7, mat, mat5);
    cout << endl << "sub func with mat, mat5" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat7.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //mul
    ooplinalg::Matrix mat8(3, 3);
    ooplinalg::mul(mat8, mat, mat5);
    cout << endl << "mul func with mat, mat5" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat8.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //transpose
    ooplinalg::Matrix mat10(mat5);
    ooplinalg::Matrix mat11(3,3);
    ooplinalg::transpose(mat11, mat10);
    cout << endl << "transpose of mat5" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat11.getElement(i, j) << "\t";
        }
        cout << endl;
    }


    //3*3 matrix 선언
    float data2[3][3] = { {1.0,4.0,1.0},
                                      {2.0,3.0,1.0},
                                      {0.0,2.0,1.0} };
    ooplinalg::Matrix mat9(3, 3);
    cout << endl << "mat9 : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat9.setElement(i, j, data2[i][j]);
            cout << mat9.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //adjoint
    ooplinalg::Matrix mat12(3, 3);
    ooplinalg::adjoint(mat12, mat9);
    cout << "adjoint matrix of mat9 : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat12.getElement(i, j) << "\t";
        }
        cout << endl;
    }

    //inverse
    ooplinalg::Matrix mat13(3, 3);
    ooplinalg::inverse(mat13, mat9);
    cout << "inverse matrix of mat9 : " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat13.getElement(i, j) << "\t";
        }
        cout << endl;
    }
}