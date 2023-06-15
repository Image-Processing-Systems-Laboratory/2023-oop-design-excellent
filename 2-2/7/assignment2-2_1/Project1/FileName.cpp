#include<iostream>
#include<string>
using namespace std;

struct ARR   // 구조체 정의
{
	string arr = {};      // 사용자에게 받은 스트링을 저장하는 변수
	string arr2[50] = {};  // 사용자에게 받은 스트링을 분석한 배열을 저장하는 배열
	void make_Arr(string arr);  // 스트링을 분석하여 문자열을 만드는 함수
	int index;            // 문자열의 개수를 나타내는 변수
};

void ARR::make_Arr(string arr)  // 스트링을 분석하여 문자열을 만드는 함수 정의
{
	int count = 1;   
	index = 0;                                       // arr2 배열의 index를 나타내줄 변수
	int postion;                                      // 문자열을 나누어줄 변수 선언
	int index2 = 0;                                     // countarr 배열의 index를 나타내줄 변수
	int countarr[100] = {};                             // '[' 문자가 있는 위치를 나타내는 배열
	int countarr2[100] = {};                         // ']'문자가있는 위치를 나타내는 배열
	int index3 = 0;                                   // countarr2 배열의 index를 나타내줄 변수
	while ((postion = arr.find(',', count)) != string::npos)     // 문자열의 끝까지 ','가 나오면 문자열을 나누어 줌
	{
		int temp = postion - count;                             // 자른 문자열의 길이를 나타내는 변수
		arr2[index] = arr.substr(count, temp);                    // 자른 문자열을 arr2 배열에 삽입
		while (arr2[index].find(' ', 0) == 0)                    // 만약 문자열의 앞문자가 공백문자일 경우 공백을 전부 제거
		{
			arr2[index] = arr2[index].substr(1, temp - 1);
			temp--;
		}
		count = postion + 1;                                    // 위치를 ',' 에서 한칸 오른쪽으로 수정함
		index++;
	}
	arr2[index] = arr.substr(count,arr.length() -count-1);       // 문자열의 마지막은 ',' 가 없기 때문에 문자열의 마지막을 기준으로 잘라줌 
	int a = 1;
	while (arr2[index].find(' ', 0) == 0)                  // 만약 문자열의 앞문자가 공백문자일 경우 공백을 전부 제거
	{
		arr2[index] = arr2[index].substr(1, arr2[index].length() - 1);
		a++;
	}
	index++;
	for (int i = 0; i < index; i++)     // 배열의 처음부터 끝까지 반복
	{
		if (arr2[i].find('[', 0) != string::npos)      // 배열에 '['가 있는 경우
		{
			if (arr2[i].find('[', 1) == string::npos)  // '['가 반복하여 들어가 있지 않은 경우 그대로 countarr배열에 삽입
			{
				countarr[index2] = i;
				index2++;
			}
			else
			{
				while (arr2[i].find('[', 1) != string::npos)    //'['가 연속하여 들어가 있지 않을때 까지 반복
				{
					countarr[index2] = i;                       // 일단 그 위치를  countarr배열에 삽입
					index2++;
					index = index + 1;                        // arr2 배열의 크기를 1 올려주고 배열을 한칸씩 오르쪽으로 밀어줌
					for (int j = index-1; j > i+1; j--)
					{
						arr2[j] = arr2[j - 1];
					}
					arr2[i + 1] = arr2[i].substr(1, arr2[i].length() - 1);   // 현재 배열의 원소를 '['로 하고 그것을 제외한나머지 부분을 다음 배열에 삽입
					arr2[i] = '[';
				}
			}
		}
		if (arr2[i].find(']', 0) != string::npos)         // 문자열에 ']'가 있는 경우
		{
			if (arr2[i].find(']', 0) == arr2[i].length()-1)   // 문자열에 마지막에 ']'가 있다면 그대로 countarr2배열에 삽입
			{
				countarr2[index3] = i;
				index3++;
			}
			else
			{
				while ((arr2[i].find(']', 0) != arr2[i].length()-1)&& (arr2[i].find(']', 0) != string::npos))   // 문자열에 ']'문자가 없고 마지막 문자가 ']' 가 일때 까지 반복
				{
					countarr2[index3] = i;     // 일단 그 위치를  countarr2배열에 삽입
					index3++;
					index = index + 1;
					for (int j = index - 1; j > i+1; j--)  // arr2 배열의 크기를 1 올려주고 배열을 한칸씩 오른쪽으로 밀어줌
					{
						arr2[j] = arr2[j - 1];
					}
					arr2[i + 1] = arr2[i].substr(arr2[i].find(']', 0)+1, arr2[i].length() - arr2[i].find(']', 0)); // 현재 배열의 원소를 문자열의 가장 뒷문자가 ']'이며 ']'가 하나인 문자열로 하고 나머지를 다음 배열에 삽입
					arr2[i] = arr2[i].substr(0, arr2[i].find(']', 0)+1);
					i++;
				}
				if (arr2[i].find(']', 0) == arr2[i].length() - 1) // 문자열에 마지막에 ']'가 있다면 그대로 countarr2배열에 삽입
				{
					countarr2[index3] = i;
					index3++;
				}
			}
		}
	}
	int temp2 = 0;
	int i = 0;   // while문 반복을 위한 변수
	int j = 0;    // while문 반복을 위한 변수
	while (i < index3)      // countarr2의 크기 만큼 반복
	{
		int count2 = 0;
		while (j < index2)  // countarr의 크기 만큼 반복
		{
			if ((countarr[j] < countarr2[i]) && (countarr[j+1] < countarr2[i]&&j+1<index2))  // 처음 '['가 나올때 부터 다음 ']' 때까지 검사하여 그사이 '['가 몇개 있는지 카운팅하여 '[]' 쌍을 맞추어줌
			{
				count2++;
			}
			else
			{
				bool A = true;
				for (int k = countarr[temp2]; k < countarr2[i + count2]; k++)      // '[]' 쌍 사이에 있는 배열의 원소를 하나의 원소로 합쳐줌
				{
					if (arr2[k + 1] == "]"|| arr2[countarr[temp2]]=="[")       // 만약 원소가 '[', ']' 라면 원소를 합쳐줄때 ', '를 붙여주지 않음 그리고 합쳐진 원소의 자리를 전부 '0'로 바꿈
					{
						if (arr2[k + 1] != "["&&A)
						{
							A = false;
							arr2[countarr[temp2]] = arr2[countarr[temp2]] + arr2[k + 1];
							arr2[k + 1] = '0';
						}
						else
						{
							arr2[countarr[temp2]] = arr2[countarr[temp2]] + arr2[k + 1];
							arr2[k + 1] = '0';
						}
					}
					else                                                                // '[]'쌍 사이에 있는 모든 원소를 하나로 합쳐주며 합쳐줄때 사이에', ' 삽입 그리고 합쳐진 원소의 자리를 전부 '0'로 바꿈
					{
						arr2[countarr[temp2]] = arr2[countarr[temp2]] + ", " + arr2[k + 1];
						arr2[k + 1] = '0';
					}
				}
				temp2 = temp2 + count2+1;                     // 다음 쌍을 찾을 위치로 이동
				j++;
				i = i + count2;
				break;
			}
			j++;
		}
		i++;
	}
	for (int k = 0; k < index; k++)         // 배열의 끝까지 반복
	{
		if (arr2[k] == "0")              // 배열의 원소가 0일 경우 그 위치를 제거하여 배열을 한 칸씩 당기고 다시 그 위치를 검사
		{
			for (int h = k; h < index; h++)
			{
				arr2[h] = arr2[h + 1];
			}
			index--;
			k--;
		}
	}
}
int main()
{
	string input_arr;   
	getline(cin, input_arr);   // 사용자에게 문자열을 입력 받음
	ARR Arr[20];              // 구조체 배열 선언
	Arr[0].arr = input_arr;  // 사용자에게 입력받은 문자열을 구조체에 삽입
	Arr[0].make_Arr(input_arr);  // 입력 받은 문자열을 분석하여 배열로 만듬
	while (true)                  // 사용자가 exit입력시 까지 반복
	{
		string command;      // 사용자에게 입력 받을 문자열 선언
		cin >> command;    //  사용자에게 문자열 입력받음

		if (command == "exit")  // 사용자가 exit입력시 프로그램 종료
		{
			break;
		}
		if (command == "arr")    // 사용자가 arr 입력시 사용자가 원래 입력한 문자열 그대로 출력
		{
			cout << Arr[0]. arr<<endl;
		}
		if (command.substr(0, 4) == "arr[") // 사용자가 arr[x][x]... 형태로 입력시
		{
			int postion = 3;                          // 문자열을 잘라줄 위치를 알려주는 변수
			int index[100] = {};                     // 사용자가 출력하기 원하는 배열의 위치를 알려주는 변수
			int temp = 0;                          // 위의 배열의 인덱스를 표시하는 변수
			bool A = true;
			while (command.find('[',postion) != string::npos)   // 문자열을 계속잘라서 '['가 나오지 않을때까지 반복
			{
				if ((command.substr(command.find('[', postion) + 1, 1) >= "0" && (command.substr(command.find('[', postion) + 1, 1) <= "9"))&& command.substr(command.find('[', postion) + 2, 1)=="]")
					/*사용자가 입력한 문자열의 '['와 ']'사이에 있는 문자가 숫자인지 검색*/
				{
					index[temp] = stoi(command.substr(command.find('[', postion) + 1, 1)); //만약 맞다면 그부분을 int형으로 바꾸어 배열에 삽입
					temp++;
					postion = postion +3;  // 검사 위치를 3칸 이동함
				}
				else  //아닐 경우 bool 변수를 바꾸어 줌
				{
					A = false;
					break;
				}

			}
			if (!A) // 사용자가 입력한 형식이 잘못 되었으므로 다시 시작으로 이동
				continue;
			if (temp == 1)// 사용자가 입력한 문자열이 arr[x]형태일 경우 사용자가 입력한 문자열의 위치를 대입하여 해당위치의 원소 출력
			{
				cout << Arr[0].arr2[index[0]] << endl;
			}
			else    // 아닐 경우
			{
				int count=0;
				for (count = 1; count < temp; count++)   
				{
					Arr[count].make_Arr(Arr[count - 1].arr2[index[count - 1]]);// 현재 구초제 배열의 다음 구조체 배열에 현재 사용자가 원하는 배열의 상위 배열을 삽입하여 하위 배열을 만듬
				}
				cout << Arr[count-1].arr2[index[count - 1]] << endl;  // 사용자가 출력하기 바라는 배열 출력

			}
		}
	}
	return 0;
}