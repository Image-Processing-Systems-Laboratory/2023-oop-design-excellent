#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node     // Node 구조체
{
    int data;       // 데이터를 저장하는 변수
    Node* next;     // 다음 노드를 가리키는 포인터
};

// Node를 추가하는 함수
Node* addNode(int data)
{
    Node* newNode = new Node();     // 새로운 노드 생성
    newNode->data = data;		   // 데이터 저장
    newNode->next = nullptr;        // 다음 노드를 nullptr로 초기화
    return newNode;     // 새로운 노드의 포인터 반환
}

// Node가 존재하는지 확인하는 함수
bool Existence(Node* head, int data)
{
    Node* current = head;       // 현재 노드를 가리키는 포인터
    // 현재 노드가 nullptr일 때까지 반복
    while (current)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Node를 삽입하는 함수
void insertNode(Node*& head, int data)
{
    Node* newNode = addNode(data);      // 새로운 노드 생성
    newNode->next = head;       // 새로운 노드의 다음 노드를 head로 지정
    head = newNode;     // head를 새로운 노드로 지정
}

// Node를 출력하는 함수
void printLinkedList(Node* head)
{
    Node* temp = head;      // 현재 노드를 가리키는 포인터
    // 현재 노드가 nullptr일 때까지 반복
    while (temp)
    {
        cout << temp->data << " ";      // 현재 노드의 데이터 출력
        temp = temp->next;      // 현재 노드를 다음 노드로 이동
    }
    cout << endl;
}

// 랜덤한 숫자로 구성된 Node를 생성하는 함수
Node* randomList()
{
    Node* head = nullptr;       // head를 nullptr로 초기화
    int count = 0;	  // 현재 노드 개수를 저장하는 변수
    srand(time(0));     // 난수 생성기 초기화

    // 16개의 노드를 가질 때까지 반복
    while (count < 16)
    {
        int randomNumber = rand() % 201;        // 0~200 사이의 난수 생성
        // 생성한 난수가 존재하지 않을 경우
        if (!Existence(head, randomNumber))
        {
            insertNode(head, randomNumber);     // 생성한 난수를 삽입
            count++;		// 현재 노드 개수 1 증가
        }
    }
    return head;    // head를 반환
}

// Node를 정렬하는 함수
void InsertionSort(Node*& head)
{
    if (!head || !head->next)       // 노드가 0개 또는 1개일 경우
        return;	 // 함수 종료

    Node* sorted = nullptr;     // 정렬된 노드를 가리키는 포인터

    // head가 nullptr일 때까지 반복
    while (head)
    {
        Node* current = head;       // 현재 노드를 가리키는 포인터
        head = head->next;      // head를 다음 노드로 이동

        // 정렬된 노드가 없거나 현재 노드의 데이터가 정렬된 노드의 데이터보다 작을 경우
        if (!sorted || current->data > sorted->data)
        {
            current->next = sorted;     // 현재 노드의 다음 노드를 정렬된 노드로 지정
            sorted = current;       // 정렬된 노드를 현재 노드로 지정
        }
        // 정렬된 노드의 데이터보다 현재 노드의 데이터가 클 경우
        else
        {
            Node* temp = sorted;        // 현재 노드를 삽입할 위치를 찾는 포인터
            // 현재 노드를 삽입할 위치를 찾을 때까지 반복
            while (temp->next && temp->next->data > current->data)
            {
                temp = temp->next;      // 다음 노드로 이동
            }
            current->next = temp->next;     // 현재 노드의 다음 노드를 temp의 다음 노드로 지정
            temp->next = current;       // temp의 다음 노드를 현재 노드로 지정
        }
    }

    head = sorted;      // head를 정렬된 노드로 지정
}

// Node의 길이를 반환하는 함수
int listLength(Node* head)
{
    int length = 0;     // Node의 길이를 저장하는 변수
    Node* current = head;       // 현재 노드를 가리키는 포인터
    // 현재 노드가 nullptr일 때까지 반복
    while (current)
    {
        length++;       // 길이 1 증가
        current = current->next;        // 다음 노드로 이동
    }
    return length;      // 길이 반환
}

// Node의 위치를 반환하는 함수
Node* NodeAt(Node* head, int index)
{
    Node* current = head;       // 현재 노드를 가리키는 포인터
    int currentIndex = 0;	   // 현재 노드의 위치를 저장하는 변수
    // 현재 노드가 nullptr이 아니고 현재 노드의 위치가 index보다 작을 경우 반복
    while (current && currentIndex < index)
    {
        current = current->next;        // 다음 노드로 이동
        currentIndex++;     // 현재 노드의 위치 1 증가
    }
    return current;     // 현재 노드 반환
}

// Node에서 원하는 값을 찾는 함수
Node* Binary_Search(Node* head, int target)
{
    InsertionSort(head);        // Node를 정렬
    cout << "Sorted List: ";
    printLinkedList(head);      // 정렬된 Node 출력

    int low = 0;        // Low point를 저장하는 변수
    int high = listLength(head) - 1;        // High point를 저장하는 변수

    // low가 high보다 작거나 같을 경우 반복
    while (low <= high)
    {
        int mid = (low + high) / 2;     // 중간 위치를 저장하는 변수
        Node* midNode = NodeAt(head, mid);      // 중간 위치의 Node를 가리키는 포인터

        // 중간 위치의 Node의 데이터가 target과 같을 경우
        if (midNode->data == target) 
        {
            return midNode;     // 중간 위치의 Node 반환
        }
        // 중간 위치의 Node의 데이터가 target보다 클 경우
        else if (midNode->data < target)
        {
            high = mid - 1;
        }
        // 중간 위치의 Node의 데이터가 target보다 작을 경우
        else
        {
            low = mid + 1;
        }
    }

    Node* closestNode;	  // 가장 가까운 Node를 가리키는 포인터
    Node* lowNode = NodeAt(head, low);      // low 위치의 Node를 가리키는 포인터
    Node* highNode = NodeAt(head, high);        // high 위치의 Node를 가리키는 포인터

    // low가 0보다 작을 경우
    if (high < 0)
    {
        closestNode = lowNode;      // lowNode를 가장 가까운 Node로 지정
    }
    // high가 Node의 길이보다 클 경우
    else if (low >= listLength(head))
    {
        closestNode = highNode;     // highNode를 가장 가까운 Node로 지정
    }
    // lowNode와 highNode의 데이터의 차이가 작을 경우
    else
    {
        closestNode = (abs(target - lowNode->data) <= abs(target - highNode->data)) ? lowNode : highNode;       // 가장 가까운 Node를 지정
    }
    
    // 가장 가까운 Node의 데이터가 target보다 클 경우
    if(closestNode->data > target)
    {
		cout << "Node not found, below node does not exist" << endl;
        cout << "Closest node is result " << endl;
        return closestNode;
	}

    cout << "Node not found, below node is result " << endl;

    return closestNode;     // 가장 가까운 Node 반환
}

int main()
{
    Node* head = randomList();      // 랜덤한 데이터를 가진 Node를 생성
    cout << "List: ";
    printLinkedList(head);      // Node 출력

    int target = 0;     // 탐색할 데이터를 저장하는 변수
    cout << "Write Binary Search: ";
    cin >> target;	  // 탐색할 데이터를 입력받음
    Node* result = Binary_Search(head, target);		// Node를 탐색

    cout << "Result: " << result->data << endl;		// 탐색 결과 출력

    return 0;
}