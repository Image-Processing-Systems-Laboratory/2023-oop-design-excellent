#include <iostream>
#include <string>

using namespace std;

class Node { // 노드 클래스 링크드 리스트
private:
    string data;
    Node* next;

public:
    Node(const string& data) : data(data), next(nullptr) {} // 생성자

    string getData() const { // 데이터 반환
        return data;
    }

    Node* getNext() const { // 다음 노드 반환
        return next;
    }

    void setNext(Node* newNext) { // 다음 노드 설정
        next = newNext;
    }
};

class NodeList { // 노드 리스트 클래스
private:
    Node* head;

public:
    NodeList() : head(nullptr) {} // 생성자

    void insertNode(const string& data) { // 노드 삽입
        Node* newNode = new Node(data); // 새로운 노드 생성
        string lowerData = toLowerCase(data); // 대소문자 구분 없이 정렬하기 위해 소문자로 변환

        if (head == nullptr || toLowerCase(head->getData()) > lowerData) { // 리스트가 비어있거나 새로운 노드가 가장 작은 경우
            newNode->setNext(head);
            head = newNode;
        }
        else { // 그 외의 경우
            Node* current = head; // 현재 노드를 가리키는 포인터
            while (current->getNext() != nullptr && // 다음 노드가 존재하고
                (toLowerCase(current->getNext()->getData()) < lowerData || // 다음 노드의 데이터가 새로운 노드의 데이터보다 크거나
                    (toLowerCase(current->getNext()->getData()) == lowerData && current->getNext()->getData() < data))) { // 다음 노드의 데이터가 새로운 노드의 데이터와 같고 사전순으로 더 작은 경우
                current = current->getNext(); // 다음 노드로 이동
            }
            newNode->setNext(current->getNext()); // 새로운 노드의 다음 노드를 현재 노드의 다음 노드로 설정
            current->setNext(newNode); // 현재 노드의 다음 노드를 새로운 노드로 설정
        }
    }
    static string toLowerCase(const string& str) { // 대문자를 소문자로 변환
        string lowerStr = str;
        for (auto& c : lowerStr) {
            c = tolower(c);
        }
        return lowerStr;
    }

    void printList() const { // 리스트 출력
        Node* current = head;
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    Node* getHead() const { // 헤드 반환
        return head;
    }
};

NodeList Merge_Lists(const NodeList& list1, const NodeList& list2) { // 두 리스트를 합치는 함수
    NodeList mergedList; // 합쳐진 리스트

    Node* cur1 = list1.getHead(); // 리스트1의 현재 노드
    Node* cur2 = list2.getHead(); // 리스트2의 현재 노드

    while (cur1 != nullptr && cur2 != nullptr) { // 두 리스트의 현재 노드가 nullptr이 아닐 때까지
        if (NodeList::toLowerCase(cur1->getData()) < NodeList::toLowerCase(cur2->getData())) { // 리스트1의 현재 노드의 데이터가 리스트2의 현재 노드의 데이터보다 작은 경우
            mergedList.insertNode(cur1->getData());
            cur1 = cur1->getNext();
        }
        else if (NodeList::toLowerCase(cur1->getData()) > NodeList::toLowerCase(cur2->getData())) { // 리스트1의 현재 노드의 데이터가 리스트2의 현재 노드의 데이터보다 큰 경우
            mergedList.insertNode(cur2->getData());
            cur2 = cur2->getNext();
        }
        else { // 두 리스트의 현재 노드의 데이터가 같은 경우
            mergedList.insertNode(cur1->getData());
            cur1 = cur1->getNext();
            mergedList.insertNode(cur2->getData());
            cur2 = cur2->getNext();
        }
    }

    while (cur1 != nullptr) { // 리스트1의 현재 노드가 nullptr이 아닐 때까지
        mergedList.insertNode(cur1->getData());
        cur1 = cur1->getNext();
    }

    while (cur2 != nullptr) { // 리스트2의 현재 노드가 nullptr이 아닐 때까지
        mergedList.insertNode(cur2->getData());
        cur2 = cur2->getNext();
    }

    return mergedList; // 합쳐진 리스트 반환
}


void processInput(NodeList& list, const string& input) { // 입력받은 문자열을 공백을 기준으로 나누어 리스트에 삽입하는 함수
    string word;
    size_t pos;

    string tempInput = input;

    while ((pos = tempInput.find(' ')) != string::npos) { // 공백을 기준으로 나누어 리스트에 삽입
        word = tempInput.substr(0, pos);
        list.insertNode(word);
        tempInput.erase(0, pos + 1);
    }
    list.insertNode(tempInput); // 마지막 단어 삽입
}

int main() {
    NodeList list1;
    NodeList list2;

    string input1, input2;

    cout << "input list 1 >> ";
    getline(cin, input1);

    cout << "input list 2 >> ";
    getline(cin, input2);

    processInput(list1, input1);
    processInput(list2, input2);

    NodeList mergedList = Merge_Lists(list1, list2);

    cout << "Result: ";
    mergedList.printList();

    return 0;
}
