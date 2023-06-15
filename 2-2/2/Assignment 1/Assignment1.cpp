#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* next; //���� ��带 ����Ű�� ������
    Node* sub; //�� ��庰 �ٽ� ��ũ�帮��Ʈ
};

Node* create_node(string data); //��� ����
string trim(string str); //���鹮�� ���� �Լ�
Node* return_linked_list(string str, int* i); //������� ������� ��� �����ϴ� �Լ�
Node* find_element(Node* head, string indices); //�ε����� ��ġ�� ã�� �Լ�
string print_element(Node* head, bool is_nested); //����ϴ� �Լ�


int main()
{
    string input_text;
    getline(cin, input_text);
    string index_string = ""; //��ɾ� ����

    int i = 0;
    Node* head;
    head = return_linked_list(input_text, &i); //��ũ ������ ���� �Լ� ȣ��

    while (1) //���� �ݺ��� ���
    {
        cin >> index_string; //��ɾ� �Է� ���� ���ڿ�
        if (index_string == "exit") //'exit'��ɾ� -> ���α׷� ����
        {
            return 0;
        }

        Node* element; //ã�� ���

        int bracket_start_index = index_string.find("["); //���ȣ ã��

        if (bracket_start_index == -1) //�ε����� ���� ��ɾ�
        {
            element = head->next;
            string result = print_element(element, false);
            cout << result << endl;
        }
        else //�ε��� �ִ� ��ɾ� ex) arr[3][1]
        {
            string index_info_string = index_string.substr(bracket_start_index);
            element = find_element(head->next, index_info_string);
            string result = print_element(element, false);

            int comma_index = result.find_last_of(",");
            cout << result.substr(0, comma_index) << endl;
        }
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

string trim(string str)
{
    int l_blank = str.find_first_not_of(" "); //���� ���� ����
    str.erase(0, l_blank);

    int r_blank = str.find_last_not_of(" "); //������ ���� ����
    str.erase(r_blank + 1);

    return str;
}

Node* return_linked_list(string str, int* i)
{
    Node* new_head = create_node(""); //���ο� ��� ����
    Node* cur = new_head; //������ ��带 ����Ŵ

    string temp = "";
    bool is_blank = true;
    while (*i < str.length())
    {
        if (str[*i] == '[') //[ ���ڸ� ������ ���, �ߺ�
        {
            *i += 1;
            Node* nested_linked_list = return_linked_list(str, i); //����Լ� ȣ��
            Node* next_node = create_node(""); //��� ����
            cur->next = next_node;
            cur = next_node;
            cur->sub = nested_linked_list;
        }
        else if (str[*i] == ']') // ]���� -> ����Ʈ�� ��
        {
            if (!is_blank)
            {
                Node* new_element = create_node(trim(temp));
                cur->next = new_element;
                cur = new_element;
                temp = "";
                is_blank = true;
            }
            return new_head; //������ ��带 ����Ű�� ��� ��� ��ȯ
        }
        else
        {
            if (str[*i] != ',') // ,���ڸ� ������ ���
            {
                temp += str[*i];
                is_blank = false;
            }
            else
            {
                if (trim(temp) != "") //������ �ƴ� ��� -> ���� ����
                {
                    Node* new_element = create_node(trim(temp));
                    cur->next = new_element;
                    cur = new_element;
                    temp = "";
                    is_blank = true;
                }
            }
        }
        *i += 1;
    }
    return new_head; //���������� ��� ��� ��ȯ
}

Node* find_element(Node* head, string indices)
{
    if (indices == "-1") //�ε��� ���� x
    {
        return head;
    }

    Node* cur = head;
    int i = 0;

    string index_string = "";
    int index_integer = -1;

    while (indices[i] != '\0')
    {
        if (indices[i] == '[') //[���ڷ� �����ϴ� ���
        {
            if (cur->sub == NULL)// sub�� ������ ���� -> ���� ó��
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
                    throw out_of_range("index�� ������ �ʰ��Ͽ����ϴ�."); //���� �ƿ� -> ����ó��
                }
                cur = cur->next;
            }
        }
        else
        {
            index_string += indices[i]; //���� �ޱ�
        }
        i += 1;
    }
    return cur;
}

string print_element(Node* head, bool is_nested)
{
    Node* cur = head;
    string temp = "";

    if (is_nested)
    {
        temp += "[";
        if (head->next == NULL) // ��Ұ� ���� nested
        {
            return temp;
        }
        cur = cur->next;
    }

    while (1)
    {
        if (cur->sub == NULL) // ��Ұ� ���ڿ��̸� ���
        {
            if (cur->next == NULL) // ������ �ܾ�� �޸� �� ����
            {
                temp += cur->data;
            }
            else
            {
                temp += cur->data + ", ";
            }


            if (!is_nested) // nested �ƴϸ� �ϳ��� ���
            {
                return temp;
            }

            if (cur->next != NULL)
            {
                cur = cur->next; // ���� ���ҷ� ����
            }
            else
            {
                return temp;
            }
        }
        else if (cur->sub != NULL) // nested array��� (���� ���Һ��� nested array�� ���� ��µǾ�� ��)
        {
            temp += print_element(cur->sub, true); // nested array ��
            if (cur->next != NULL)
                temp += "], ";
            else
                temp += "]";
            if (cur->next != NULL && is_nested)
            {
                cur = cur->next; // ���� ���ҷ� ����
            }
            else
            {
                return temp;
            }
        }
    }
    return temp;
}