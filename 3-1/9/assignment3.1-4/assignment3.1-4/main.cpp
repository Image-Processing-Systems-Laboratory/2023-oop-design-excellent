#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack stack;
    stack.SetSize(5); //stack������ ����
    //1��stack�� ����
    Node* pNode = new Node();
    pNode->SetData(1);
    stack.push(pNode);

    //2�� stack�� ����
    pNode = new Node();
    pNode->SetData(2);
    stack.push(pNode);

    //1��stack�� ����
    pNode = new Node();
    pNode->SetData(3);
    stack.push(pNode);

    //5��stack�� ����
    pNode = new Node();
    pNode->SetData(5);
    stack.push(pNode);

    //8��stack�� ����
    pNode = new Node();
    pNode->SetData(8);
    stack.push(pNode);

    //10��stack�� ����
    pNode = new Node();
    pNode->SetData(10);
    stack.push(pNode);
    stack.PrintStack();

    //pop���� ��������
    pNode = stack.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ��������
    pNode = stack.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ��������
    pNode = stack.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //�����ִ� ���� ���
    cout << "�����ִ� ���� " << endl;
    stack.PrintStack();

    //pop���� ��������
    pNode = stack.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ��������
    pNode = stack.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;


    //pop���� ���� ����
    pNode = stack.pop();
    delete pNode;

    return 0;
}