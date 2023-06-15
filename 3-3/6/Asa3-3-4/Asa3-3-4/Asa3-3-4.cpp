#include "Score.h"

using namespace std;

int main()
{
	StudentScoreList list;

	int score_math = 0; // 수학 점수
	int score_english = 0; // 영어 점수
	int score_science = 0; // 과학 점수
	double average = 0; // 세 점수의 평균
	string command;
	cout << "Please input command and value if exist!\nIf you want printlist, then input <print 1> or <print 0>." << endl;
	cout << "1 means ascending(0 1 2 3 4 5) , and 0 means descending(5 4 3 2 1 0)." << endl;
	while (1)
	{
		cout << "\ninput command>>> ";
		cin >> command;
		if (command == "input")
		{
			cin >> score_math >> score_english >> score_science;
			if (cin.fail() || score_math > 100 || score_math < 0 || score_english > 100 || score_english < 0 || score_science > 100 || score_science < 0)
			{
				cerr << "Error: number you inputed is over 100 or under 0, or non-integer value!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			} // 점수가 100점 이상 혹은 0점 이하인 경우와 int형이 아닌 경우를 catch
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				Score* new_node = new Score();
				average = (static_cast<double>(score_math + score_english + score_science)) / 3;
				// static_cast가 없으면 float으로 저장될 수 있다.
				new_node->SetAvg(average);
				list.Insert(new_node);
				
				cout << "Average is>>> "<< average << "\ninput Student Node success!\n";
				continue;
			}
		}
		if (command == "print")
		{
			if (list.islistempty())
			{
				cerr << "Error: list is empty!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			} // 입력한 Node가 없는 경우
			int order = 0;
			cin >> order;
			if (cin.fail())
			{
				cerr << "Error: number that you input is invalid!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			} 
			if (order != 0 && order != 1)
			{
				cerr << "Error: number that you input is invalid!" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}// 0 또는 1이 아닌 경우
			else
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (order == 1) list.printlist(true);
				else list.printlist(false);
				cout << "Print Success!" << endl;
				continue;
			} // 1이면 printlist에 true를 전달하여 오름차순 출력, 0이면 false를 전달하여 내림차순 출력
		}
		if (command == "exit")
		{
			cout << "Terminate program. Good-Bye!" << endl;
			return 1;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: unknown command, please re-input command." << endl;
			continue;
		}
	}
	return 0;
}