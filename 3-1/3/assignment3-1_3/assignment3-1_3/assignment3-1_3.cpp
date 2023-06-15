#include<iostream> 
#include"oopstd.h"          //사용자 지정 헤더파일 선언

using namespace std;
using namespace oopstd;     //oopstd 내에 클래스가 선언되어있어 선언해줌

int main()
{
    Queue queue;        //Queue 클래스 객체 queue 선언
    char cmd[10];       //명령어 입력받을 문자열
    while (1)           //무한반복 시작
    {
        cout << "명령어 : ";
        cin >> cmd;     //명령어 입력 받기
        if (!strcmp(cmd, "size")) {     //명령어가 size라면
            int size;
            cin >> size;                //size입력 받기
            queue.SetSize(size);        //입력받은 size만큼 queue의 사이즈를 조절
        }
        else if (!strcmp(cmd, "push")) {    //명령어가 push라면
            int data;
            cin >> data;                    //데이터 입력받기
            Node* temp = new Node;
            temp->SetData(data);            //입력받은 데이터를 노드를 생성해 집어넣기
            if (queue.Push(temp)) {         //해당 노드를 push하기
                cout << data << "가 들어감" << endl;
            }
            else {                          //만약 들어가지 않는다면 가득찼다는 뜻
                cout << "가득참" <<endl;
            }
        }
        else if (!strcmp(cmd, "pop")) {     //명령어가 pop라면
            if (queue.IsEmpty()==true){     //큐가 비어있다면
                cout << "큐가 비어있음" << endl;  //비어있음 출력
            }
            else {                          //아니라면
                Node* temp = queue.Pop();      //pop함수 실행해 temp에 저장
                cout << "추출한 값 : " << temp->GetData() << endl;     //temp 값 출력
                delete temp;        //temp 삭제
            }
        }
        else if (!strcmp(cmd, "print")){     //명령어가 print라면
            if (queue.IsEmpty()==true) {        //큐가 비어있다면
                cout << "큐가 비어있음" << endl;
                continue;           //비어있음 출력 후 넘어가기
            }
            queue.PrintQueue();         //비어있지 않다면 큐 안에 데이터를 출력하는 함수 실행
        }
        else if (strcmp(cmd, "exit") == 0) {        //명령어가 exit라면
            cout << "프로그램 종료";          //반복문 나가면서 프로그램 종료
            break;
        }
    }

    return 0;
}