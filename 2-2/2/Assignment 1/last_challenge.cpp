#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* next; //���� ��带 ����Ű�� ������
    Node* sub; //�� ��庰 �ٽ� ��ũ�帮��Ʈ
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
        else if (str[*i] == ' ') //������ �ִ� ���
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
            if (cur->sub == NULL) // sub�� ������ ����
            { 
                throw out_of_range("index�� ������ �ʰ��Ͽ����ϴ�.");
            }
            else // sub�� ������ sub�� ��
            { 
                cur = cur->sub;
                index_string = "";
                index_integer = -1;
            }
        }
        else if (indices[i] == ']') // �ε��� �Ľ� �Ϸ�
        { 
            index_integer = stoi(index_string);
            index_string = "";

            for (int j = 0; j < index_integer + 1; j++)
            {
                if (cur->next == NULL)
                {
                    throw out_of_range("index�� ������ �ʰ��Ͽ����ϴ�."); //����ó��
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
        if (cur->sub == NULL) { // ��Ұ� ���ڿ��̸� ���

            if (cur->next == NULL) //������ �ܾ�� �޸� x
            {
                cout << cur->data;
            }
            else
            {
                cout << cur->data << ", ";
            }

            if (!is_nested) //nested �ƴϸ� �ϳ��� ���
            { 
                return;
            }

            if (cur->next != NULL)
            {
                cur = cur->next; // ���� ���ҷ� ����
            }
            else //��� ����
            {
                cout << "], ";
                return;
            }
        }
        else if (cur->sub != NULL) // nested array�� �����Ѵٸ� (���� ���Һ��� nested array�� ���� ��µǾ�� ��)
        { 
            print_element(cur->sub->next, true); // nested array ��
            if (cur->next != NULL && is_nested)
            {
                cur = cur->next; // ���� ���ҷ� ����
            }
            else
            {
                return;
            }
        }
    }
}