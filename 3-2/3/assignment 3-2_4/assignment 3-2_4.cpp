#include "PolyTerm.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void InputPolynomial(Polynomial& Poly);     // ���׽��� �Է¹޴� �Լ�

int main()
{
    Polynomial poly1, poly2;        // �� ���� ���׽� ��ü ����

    cout << "Input first polynomial: ";
    InputPolynomial(poly1);     // ù ��° ���׽� �Է¹ޱ�
    cout << "Input second polynomial: ";
    InputPolynomial(poly2);     // �� ��° ���׽� �Է¹ޱ�

    cout << endl;

    cout << "First polynomial: ";
    poly1.PrintList();      // ù ��° ���׽� ���
    cout << "Second polynomial: ";
    poly2.PrintList();      // �� ��° ���׽� ���

    cout << endl;

    Polynomial sumPoly, subPoly;        // �� ���׽��� �հ� ���� ������ ��ü ����

    sumPoly.Add(poly1);     // ù ��° ���׽��� ���ϱ�
    sumPoly.Add(poly2);     // �� ��° ���׽��� ���ϱ�

    subPoly.Add(poly1);     // ù ��° ���׽��� ���ϱ�
    subPoly.Sub(poly2);     // �� ��° ���׽��� ����

    cout << "Test Add Function poly1 + poly2: ";
    sumPoly.PrintList();        // �� ���׽��� �� ���
    cout << "Test Sub Function poly1 - poly2: ";
    subPoly.PrintList();        // �� ���׽��� �� ���

    return 0;
}

void InputPolynomial(Polynomial& Poly)
{
    string input;       // ���׽��� �Է¹��� ���ڿ�
    getline(cin, input);        // ������ �����Ͽ� ���ڿ� �Է¹ޱ�

    stringstream str(input);        // ���ڿ��� stringstream ��ü�� ��ȯ
    bool isNegative = false;        // �������� Ȯ���ϴ� ����
    int coefficient = 0;        // ����� ������ ����
    int exponent = 0;       // ������ ������ ����
    bool coeffRead = false;     // ����� �о����� Ȯ���ϴ� ����

    // ���ڿ��� �� ���ھ� �о���̸鼭 ���׽��� �����ϴ� ���� �ϳ��� �о����
    while (true)
    {
        char c;     // ���ڸ� ������ ����
        str >> c;       // ���� �ϳ� �о���̱�

        // ���ڿ��� ���� �����ϸ� �ݺ��� ����
        if (str.eof())
        {
            // ������ ���� ���׽Ŀ� �߰�
            Term* term = new Term();        // ���ο� ���� ������ ��� ����
            term->SetCoeff(coefficient);        // ��� ����
            term->SetExponent(exponent);        // ���� ����
            Poly.Insert(term);      // ���׽Ŀ� �� �߰�
            break;
        }

        // ���� ���ڴ� ����
        if (c == ' ')
        {
            continue;
        }

        // ���� ��ȣ�� ���
        if (c == '-')
        {
            isNegative = true;      // ���� ��ȣ���� ǥ��
            continue;
        }

        // ��� ��ȣ�� ���
        if (isdigit(c))
        {
            str.unget();        // �о���� ���ڸ� �ٽ� �Է� ��Ʈ���� �ǵ���
            str >> coefficient;     // ����� �о����
            // ���� ��ȣ�� �־����� ����� ������ ����
            if (isNegative)
            {
                coefficient = -coefficient;     // ����� ������ ����
            }
            coeffRead = true;       // ����� �о����� ǥ��

            // ��� �ڿ� 'x'�� ���� ���
            if (str.peek() != 'x')
            {
                exponent = 0;       // ������ 0���� ����
                Term* term = new Term();        // ���ο� ���� ������ ��� ����
                term->SetCoeff(coefficient);        // ��� ����
                term->SetExponent(exponent);        // ���� ����
                Poly.Insert(term);      // ���׽Ŀ� �� �߰�

                isNegative = false;     // ���� ��ȣ�� �ʱ�ȭ
                coefficient = 0;        // ��� �ʱ�ȭ
                exponent = 0;       // ���� �ʱ�ȭ
                coeffRead = false;      // ����� ���� �ʾ����� ǥ��
            }
            continue;
        }

        // 'x'�� ���
        if (c == 'x')
        {
            // ����� ���� �ʾ����� ����� 1
            if (!coeffRead)
            {
                coefficient = 1;        // ����� 1�� ����
                // ���� ��ȣ�� �־����� ����� ������ ����   
                if (isNegative)
                {
                    coefficient = -coefficient;     // ����� ������ ����
                }
            }

            // ������ �о����
            if (str.peek() == '^')
            {
                str >> c;       // '^' ���ڸ� �о����
                bool isExpNegative = false;     // ������ �������� Ȯ���ϴ� ����

                // ������ ������ ���
                if (str.peek() == '-')
                {
                    isExpNegative = true;       // ������ �������� ǥ��
                    str.get();      // '-' ���ڸ� �о����
                }

                string strExp;      // ������ ������ ���ڿ�
                // ������ �о����
                while (isdigit(str.peek()))
                {
                    strExp.push_back(str.get());        // ���ڸ� �о�鿩 ���ڿ��� �߰�
                }

                exponent = stoi(strExp);        // ���ڿ��� ������ ��ȯ
                // ������ ���������� ������ ������ ����
                if (isExpNegative)
                {
                    exponent = -exponent;       // ������ ������ ����
                }
            }
            // ������ ���� ���
            else
            {
                exponent = 1;       // ������ 1�� ����
            }

            Term* term = new Term();        // ���ο� ���� ������ ��� ����
            term->SetCoeff(coefficient);        // ��� ����
            term->SetExponent(exponent);        // ���� ����
            Poly.Insert(term);      // ���׽Ŀ� �� �߰�

            isNegative = false;     // ���� ��ȣ�� �ʱ�ȭ
            coefficient = 0;        // ��� �ʱ�ȭ
            exponent = 0;       // ���� �ʱ�ȭ
            coeffRead = false;      // ����� ���� �ʾ����� ǥ��
        }
    }
}
