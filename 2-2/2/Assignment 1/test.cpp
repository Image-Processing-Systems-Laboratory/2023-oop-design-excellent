#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* sub;
};

Node* create_node(string data);
Node* return_linked_list(string str, int* i);

Node* create_node(string data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    new_node->sub = nullptr;
    return new_node;
}

Node* return_linked_list(string str, int* i) {
    Node* new_head = create_node("");
    Node* cur = new_head;

    string temp = "";
    while (*i < str.length()) {
        if (str[*i] == '[') {
            *i += 1;
            Node* nested_linked_list = return_linked_list(str, i);
            cur->sub = nested_linked_list;
        }
        else if (str[*i] == ']') {
            if (temp != "") {
                Node* new_element = create_node(temp);
                cur->next = new_element;
                cur = new_element;
                temp = "";
            }

            return new_head;
        }
        else {
            if (str[*i] != ',') {
                temp += str[*i];
            }
            else {
                if (temp != "") {
                    Node* new_element = create_node(temp);
                    cur->next = new_element;
                    cur = new_element;
                    temp = "";
                }
            }
        }

        *i += 1;
    }

    return new_head;
}

int main() {
    Node* head;
    int i = 0;

    string input_text;

    cin >> input_text;

    head = return_linked_list(input_text, &i);

    // 예시 출력
    cout << head->sub->next->data << endl; // 1
    cout << head->sub->next->sub->next->data << endl; // 2
    cout << head->sub->next->sub->next->next->data << endl; // 3
    cout << head->next->sub->next->data << endl; // 4

    return 0;
}
