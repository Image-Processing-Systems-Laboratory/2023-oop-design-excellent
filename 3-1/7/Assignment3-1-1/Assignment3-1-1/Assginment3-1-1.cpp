#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node //Node class
{
public:
    char data[100]; // 문자열 데이터
    Node* next; // 다음 노드를 가리키는 포인터
    Node() // 디폴트 생성자
    {
        next = NULL; // 다음 노드 초기화
    }
    Node(char* temp) // 생성자
    {
        strcpy(data, temp); // 문자열 복사
        next = NULL; // 다음 노드 초기화
    }
    ~Node() {} // 소멸자
};

Node* Merge_List(Node* p1, Node* p2, Node* p3) // 두 개의 연결 리스트 병합 함수
{
    Node* curr = p3;  // p3의 시작 위치
    while (p1 != NULL && p2 != NULL) // 하나가 끝날 때 까지 반복
    {
        if (_stricmp(p1->data, p2->data) < 0) // p1의 데이터가 더 작으면
        {
            curr->next = p1; // p1 연결
            p1 = p1->next; // 다음 노드로 이동
        }
        else // p2의 데이터가 더 작으면
        {
            curr->next = p2; // p2를 연결
            p2 = p2->next; // 다음 노드로 이동
        }
        curr = curr->next; // 다음 노드로 이동
    }
    if (p1 == NULL) // p1이 끝나면
    {
        curr->next = p2; // p2 연결
    }
    else // p2가 끝나면
    {
        curr->next = p1; // p1 연결
    }
    curr = p3; // curr을 p3으로 초기화
    p3 = p3->next; // p3을 다음 노드로 이동
    delete curr; // curr 메모리 해제
    return p3; // p3 반환
}

int main()
{
    // 문자열 입력 받음
    char str1[100], str2[100];
    cout << "Input>>" << endl;
    cout << "Input list 1:";
    cin.getline(str1, 100);
    cout << "Input list 2:";
    cin.getline(str2, 100);

    Node* p1; // 첫번째 리스트 연결 리스트
    Node* p2; // 두번째 리스트 연결 리스트
    Node* p1_tail; // p1의 마지막 노드를 가리키는 포인터
    Node* p2_tail; // p2의 마지막 노드를 가리키는 포인터
    // 문자열 파싱시 사용할 포인터 변수
    char* temp1 = NULL; 
    char* temp2 = NULL;

    // 첫번째 리스트 파싱하여 연결 리스트에 추가
    temp1 = strtok(str1, " ");
    Node* tok1 = new Node{ temp1 };
    p1 = tok1;
    p1_tail = p1;
    while (temp1 = strtok(NULL, " "))
    {
        tok1 = new Node{ temp1 }; // 노드 생성
        Node* p1_tail_next = p1_tail->next;
        while (p1_tail != NULL)
        {
            if (_stricmp(p1_tail->data, tok1->data) < 0) // p1_tail의 다음 노드보다 tok1이 작으면 삽입
            {
                if (p1_tail_next == NULL) // p1_tail의 다음 노드가 없을 경우 tok1을 추가
                {
                    p1_tail->next = tok1;
                    break;
                }
                else if (_stricmp(p1_tail_next->data, tok1->data) < 0) // p1_tail의 다음 노드가 있을 경우 더 큰 노드를 찾을 때까지 다음 노드로 이동
                {
                    p1_tail = p1_tail->next;
                    p1_tail_next = p1_tail_next->next;
                    continue;
                }
                else // p1_tail과 p1_tail_next 사이에 tok1 삽입
                {
                    p1_tail->next = tok1;
                    tok1->next = p1_tail_next;
                    break;
                }
            }
            else  // tok1이 p1_tail보다 작은 경우 첫번째 노드로 삽입
            {
                p1 = tok1;
                p1->next = p1_tail;
                break;
            }   
        }
        p1_tail = p1;
    }
   
    // 두번째 리스트 파싱하여 연결 리스트에 추가
    temp2 = strtok(str2, " ");
    Node* tok2 = new Node{ temp2 };
    p2 = tok2;
    p2_tail = p2;
    while (temp2 = strtok(NULL, " "))
    {
        tok2 = new Node{ temp2 }; // 노드 생성
        Node* p2_tail_next = p2_tail->next;
        while (p2_tail != NULL)
        {
            if (_stricmp(p2_tail->data, tok2->data) < 0) // p2_tail의 다음 노드보다 tok2이 작으면 삽입
            {
                if (p2_tail_next == NULL) // p2_tail의 다음 노드가 없을 경우 tok2을 추가
                {
                    p2_tail->next = tok2;
                    break;
                }
                else if (_stricmp(p2_tail_next->data, tok2->data) < 0) // p2_tail의 다음 노드가 있을 경우 더 큰 노드를 찾을 때까지 다음 노드로 이동
                {
                    p2_tail = p2_tail->next;
                    p2_tail_next = p2_tail_next->next;
                    continue;
                }
                else // p2_tail과 p2_tail_next 사이에 tok2 삽입
                {
                    p2_tail->next = tok2;
                    tok2->next = p2_tail_next;
                    break;
                }
            }
            else // tok2가 p2_tail보다 작은 경우 첫번째 노드로 삽입
            {
                p2 = tok2;
                p2->next = p2_tail;
                break;
            }
        }
        p2_tail = p2;
    }
    Node* p3 = new Node{  }; // 결과 저장할 연결 리스트 생성

    Node* node = Merge_List(p1, p2, p3); // 두 연결 리스트 병합해 p3에 저장

    cout << "Output>>" << endl;
    cout << "Result:";
    while (node != NULL)
    {
        cout << node->data << " "; // p3의 데이터 출력
        node = node->next; // 다음 노드로 이동
    }
    return 0;
}