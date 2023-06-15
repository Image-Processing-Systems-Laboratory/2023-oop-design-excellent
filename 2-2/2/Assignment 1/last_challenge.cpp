#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* next; //다음 노드를 가리키는 포인터
    Node* sub; //각 노드별 다시 링크드리스트
};

Node* create_node(string data);
Node* return_linked_list(string str, int* i);
Node* find_element(Node* head, string indices);

void print_element(Node* head, bool is_nested);

int main()
{

    string input_text;
    cin >> input_text;

    string index_string = "";

    int i = 0;
    Node* head;
    head = return_linked_list(input_text, &i);

    while (1) 
    {
        cin >> index_string;
        if (index_string == "exit")
        {
            return 0;
        }
        else if (index_string == "arr")
        {
            cout << input_text << endl;
            continue;
        }

        Node* element;

        int bracket_start_index = index_string.find("[");
        string index_info_string = index_string.substr(bracket_start_index);

        element = find_element(head->next, index_info_string);

        print_element(element, false);
        cout << endl;
    }
    return 0;
}

Node* create_node(string data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->sub = NULL;
    return new_node;
}
//[a,[[b,c,[1,2],4],d],e,[f,g],h,[i,j],[]]

Node* return_linked_list(string str, int* i)
{
    Node* new_head = create_node("");
    Node* cur = new_head;

    string temp = "";
    while (*i < str.length())
    {
        if (str[*i] == '[')
        {
            *i += 1;
            Node* nested_linked_list = return_linked_list(str, i);
            Node* next_node = create_node("");
            cur->next = next_node;
            cur = next_node;
            cur->sub = nested_linked_list;
        }
        else if (str[*i] == ']')
        {
            Node* new_element = create_node(temp);
            cur->next = new_element;
            cur = new_element;
            temp = "";

            return new_head;
        }
        else if (str[*i] == ' ') //공백이 있는 경우
        {
            continue;
        }
        else
        {
            if (str[*i] != ',')
            {
                temp += str[*i];
            }
            else
            {
                if (temp != "")
                {
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

Node* find_element(Node* head, string indices)
{
    Node* cur = head;
    int i = 0;

    string index_string = "";
    int index_integer = -1;

    while (indices[i] != '\0')
    {
        if (indices[i] == '[')
        {
            if (cur->sub == NULL) // sub가 없으면 오류
            { 
                throw out_of_range("index가 범위를 초과하였습니다.");
            }
            else // sub가 있으면 sub로 감
            { 
                cur = cur->sub;
                index_string = "";
                index_integer = -1;
            }
        }
        else if (indices[i] == ']') // 인덱스 파싱 완료
        { 
            index_integer = stoi(index_string);
            index_string = "";

            for (int j = 0; j < index_integer + 1; j++)
            {
                if (cur->next == NULL)
                {
                    throw out_of_range("index가 범위를 초과하였습니다."); //예외처리
                }
                cur = cur->next;
            }
        }
        else
        {
            index_string += indices[i];
        }
        i += 1;
    }

    return cur;
}

void print_element(Node* head, bool is_nested)
{
    Node* cur = head;

    if (is_nested)
        cout << "[";

    while (1) 
    {
        if (cur->sub == NULL) { // 요소가 문자열이면 출력

            if (cur->next == NULL) //마지막 단어면 콤만 x
            {
                cout << cur->data;
            }
            else
            {
                cout << cur->data << ", ";
            }

            if (!is_nested) //nested 아니면 하나만 출력
            { 
                return;
            }

            if (cur->next != NULL)
            {
                cur = cur->next; // 다음 원소로 가기
            }
            else //노드 없음
            {
                cout << "], ";
                return;
            }
        }
        else if (cur->sub != NULL) // nested array가 존재한다면 (다음 원소보다 nested array가 먼저 출력되어야 함)
        { 
            print_element(cur->sub->next, true); // nested array 줌
            if (cur->next != NULL && is_nested)
            {
                cur = cur->next; // 다음 원소로 가기
            }
            else
            {
                return;
            }
        }
    }
}