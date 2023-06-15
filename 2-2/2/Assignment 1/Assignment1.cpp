#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* next; //다음 노드를 가리키는 포인터
    Node* sub; //각 노드별 다시 링크드리스트
};

Node* create_node(string data); //노드 생성
string trim(string str); //공백문자 제거 함수
Node* return_linked_list(string str, int* i); //재귀적인 방법으로 노드 생성하는 함수
Node* find_element(Node* head, string indices); //인덱스의 위치를 찾는 함수
string print_element(Node* head, bool is_nested); //출력하는 함수


int main()
{
    string input_text;
    getline(cin, input_text);
    string index_string = ""; //명령어 인자

    int i = 0;
    Node* head;
    head = return_linked_list(input_text, &i); //링크 연결을 위해 함수 호출

    while (1) //무한 반복문 사용
    {
        cin >> index_string; //명령어 입력 받을 문자열
        if (index_string == "exit") //'exit'명령어 -> 프로그램 종료
        {
            return 0;
        }

        Node* element; //찾을 요소

        int bracket_start_index = index_string.find("["); //대괄호 찾기

        if (bracket_start_index == -1) //인덱스가 없는 명령어
        {
            element = head->next;
            string result = print_element(element, false);
            cout << result << endl;
        }
        else //인덱스 있는 명령어 ex) arr[3][1]
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
    int l_blank = str.find_first_not_of(" "); //시작 공백 제거
    str.erase(0, l_blank);

    int r_blank = str.find_last_not_of(" "); //마지막 공백 제거
    str.erase(r_blank + 1);

    return str;
}

Node* return_linked_list(string str, int* i)
{
    Node* new_head = create_node(""); //새로운 노드 생성
    Node* cur = new_head; //생성된 노드를 가리킴

    string temp = "";
    bool is_blank = true;
    while (*i < str.length())
    {
        if (str[*i] == '[') //[ 문자를 만나는 경우, 중복
        {
            *i += 1;
            Node* nested_linked_list = return_linked_list(str, i); //재귀함수 호출
            Node* next_node = create_node(""); //노드 생성
            cur->next = next_node;
            cur = next_node;
            cur->sub = nested_linked_list;
        }
        else if (str[*i] == ']') // ]문자 -> 리스트의 끝
        {
            if (!is_blank)
            {
                Node* new_element = create_node(trim(temp));
                cur->next = new_element;
                cur = new_element;
                temp = "";
                is_blank = true;
            }
            return new_head; //생성된 노드를 가리키는 헤드 노드 반환
        }
        else
        {
            if (str[*i] != ',') // ,문자를 만나는 경우
            {
                temp += str[*i];
                is_blank = false;
            }
            else
            {
                if (trim(temp) != "") //공백이 아닌 경우 -> 도드 생성
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
    return new_head; //마찬가지로 헤드 노드 반환
}

Node* find_element(Node* head, string indices)
{
    if (indices == "-1") //인덱스 지정 x
    {
        return head;
    }

    Node* cur = head;
    int i = 0;

    string index_string = "";
    int index_integer = -1;

    while (indices[i] != '\0')
    {
        if (indices[i] == '[') //[문자로 시작하는 경우
        {
            if (cur->sub == NULL)// sub가 없으면 오류 -> 예외 처리
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
                    throw out_of_range("index가 범위를 초과하였습니다."); //범위 아웃 -> 예외처리
                }
                cur = cur->next;
            }
        }
        else
        {
            index_string += indices[i]; //문자 받기
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
        if (head->next == NULL) // 요소가 없는 nested
        {
            return temp;
        }
        cur = cur->next;
    }

    while (1)
    {
        if (cur->sub == NULL) // 요소가 문자열이면 출력
        {
            if (cur->next == NULL) // 마지막 단어면 콤마 안 붙임
            {
                temp += cur->data;
            }
            else
            {
                temp += cur->data + ", ";
            }


            if (!is_nested) // nested 아니면 하나만 출력
            {
                return temp;
            }

            if (cur->next != NULL)
            {
                cur = cur->next; // 다음 원소로 가기
            }
            else
            {
                return temp;
            }
        }
        else if (cur->sub != NULL) // nested array라면 (다음 원소보다 nested array가 먼저 출력되어야 함)
        {
            temp += print_element(cur->sub, true); // nested array 줌
            if (cur->next != NULL)
                temp += "], ";
            else
                temp += "]";
            if (cur->next != NULL && is_nested)
            {
                cur = cur->next; // 다음 원소로 가기
            }
            else
            {
                return temp;
            }
        }
    }
    return temp;
}