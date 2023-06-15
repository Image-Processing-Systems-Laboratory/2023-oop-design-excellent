#include <iostream>
#include <string>

using namespace std;
//리스트 구조체
struct Node {
    string data;//데이터
    Node* next;//다음 노드의 포인터
};
//연결리스트에 노드를 추가하는 함수
void Insert(Node*& head, string value) {
    Node* newNode = new Node; //새 노드 동적 할당
    newNode->data = value; //노드에 데이터 추가
    newNode->next = nullptr; //새 노드 다음 포인터는 Null
   //연결 리스트가 비어있으면
    if (head == nullptr) {// 새 노드를 Head로
        head = newNode;
    }
    else {//비어있지 않다면 마지막 노드에 새 노드 추가
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
//두 연결리스트를 하나로 합치는 함수
void Merge_List(Node* p1, Node* p2, Node*& p3) {
    //둘중 하나가 비어있으면 p3에 하나를 그대로 복사
    if (!p1) {
        p3 = p2;
        return;
    }
    if (!p2) {
        p3 = p1;
        return;
    }
   
    string data1 = p1->data;
    string data2 = p2->data;
    // 모든 문자열을 소문자로 변환
    for (int i = 0; i < data1.size(); i++) {
        data1[i] = tolower(data1[i]);
    }
    for (int i = 0; i < data2.size(); i++) {
        data2[i] = tolower(data2[i]);
    }
    //data1이 data2보다 작거나 같을 때 p1노드를 p3에 추가하고 p1 다음 노드와 p2노드를 비교
    if (data1 <= data2) {
        p3 = p1;
        Merge_List(p1->next, p2, p3->next);
    }
    //data2이 data1보다 작거나 같을 때 p1노드를 p3에 추가하고 p1 다음 노드와 p2노드를 비교
    else {
        p3 = p2;
        Merge_List(p1, p2->next, p3->next);
    }
}
// 리스트를 정렬하는 함수
Node* MergeSort(Node* head) {
    //연결리스트 크기가0이나 1이면 반환
    if (!head || !head->next) {
        return head;
    }

    Node* sub1 = head;
    Node* sub2 = head->next;

    while (sub2 && sub2->next) {//sub1은 한번에 한칸 sub2는 한번에 두칸씩이동
        sub1 = sub1->next;  //sub1은 끝가지 도달했을때 중간에 앞노드를 가르킴
        sub2 = sub2->next->next;
    }

    Node* rightHead = sub1->next;
    sub1->next = nullptr;
    //각각재귀호출
    Node* left = MergeSort(head);
    Node* right = MergeSort(rightHead);
    Node* sorted = nullptr;
    //하나로 합치기 위한 함수 호출
    Merge_List(left, right, sorted);

    return sorted;
}

//리스트를 출력하는 함수
void PrintList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    Node* addList = nullptr;
    //입력받는 문자열 변수
    string input1;
    string input2;
    cout << "input1 : ";
    //엔터를 치기 전까지 input1에 무한 반복 입력
    while (cin >> input1) {
        Insert(list1, input1); //input1값 list1에 저장
        if (cin.get() == '\n') {
            break;
        }
    }
    //엔터를 치기 전까지 input2에 무한 반복 입력
    cout << "input2 : ";
    while (cin >> input2) {
        Insert(list2, input2); //input2값 list2에 저장
        if (cin.get() == '\n') {
            break;
        }
    }
    //
    list1 = MergeSort(list1);//list1정렬
    list2 = MergeSort(list2);//list2 정렬
    Merge_List(list1, list2, addList);//1과 2를 합쳐 하나에 정렬된 addlist를 생성

    cout << "Resilt: ";
    PrintList(addList);//출력

    return 0;
}