#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue queue;
    queue.SetSize(5); //queue������ ����
    //1��queue�� ����
    Node* pNode = new Node();
    pNode->SetData(1);
    queue.push(pNode);
    
    //2�� queue�� ����
    pNode = new Node();
    pNode->SetData(2);
    queue.push(pNode);
    
    //1��queue�� ����
    pNode = new Node();
    pNode->SetData(3);
    queue.push(pNode);
    
    //5��queue�� ����
    pNode = new Node();
    pNode->SetData(5);
    queue.push(pNode);

    //8��queue�� ����
    pNode = new Node();
    pNode->SetData(8);
    queue.push(pNode);

    //10��queue�� ����
    pNode = new Node();
    pNode->SetData(10);
    queue.push(pNode);
    queue.PrintQueue();

    //pop���� ��������
    pNode = queue.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ��������
    pNode = queue.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ��������
    pNode = queue.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //�����ִ� ���� ���
    cout << "�����ִ� ���� " << endl;
    queue.PrintQueue();

    //pop���� ��������
    pNode = queue.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;
    
    //pop���� ��������
    pNode = queue.pop();
    cout << "���ŵ� ����: " << pNode->GetData() << endl;
    delete pNode;

    //pop���� ���� ����
    pNode = queue.pop();
    delete pNode;

    return 0;
}