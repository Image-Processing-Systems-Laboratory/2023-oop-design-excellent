#include <iostream>
#include <fstream>

#pragma warning(disable:4996)

using namespace std;


int searchCODE(int searchnum, char** searcharr);
void searchLINE(int searchnum, int searchcode, char** searcharr, char* file_name);


int searchCODE(int searchnum, char** searcharr)	// 검색 코드를 반환하는 함수.
{
	int Asterisk = 1;
	int Question = 1;

	int length = strlen(searcharr[searchnum]);	// searchnum번째 검색어의 길이

	for (int i = 0; i < length; i++)
	{
		if (searcharr[searchnum][i] == '*')
		{
			if (i == 0)
				Asterisk = -1;		// * 가 가장 앞에 있을 때 = 코드 4
			else
				Asterisk = Asterisk * 2;		// * 포함 = 코드 0
		}
		if (searcharr[searchnum][i] == '?')		// ? 포함 = 코드 1
			Question++;
	}

	if (Asterisk > 1 && Question == 1)
		return 0;
	if (Asterisk == 1 && Question > 1)	// ? 만 포함				OK
		return 1;
	if (Asterisk > 1 && Question > 1)	// *, ? 모두 포함		
		return 3;	
	if (Asterisk < 0 && Question == 1)	// 맨 앞 * 포함, ? 미포함
		return 4;
	if (Asterisk < 0 && Question > 1)	// 맨 앞 * 포함, ? 포함	
		return 5;
	if (Asterisk == 1 && Question == 1)	// 기본 검색 = 코드 2		OK
		return 2;
}

void searchLINE(int searchnum, int searchcode, char** searcharr, char* file_name)
{
	ifstream file;
	file.open(file_name);
	char data[20];
	////////////////////////////////////////////////////////////// 파일 오픈과 각 줄의 문자열을 담을 data 선언
	switch (searchcode)
	{
	case 0:	// wildcard * search

		while (!file.eof())
		{
			file.getline(data, 20);							// 길이 20만큼의 데이터를 eof까지 각 줄에서 받는다.
			int asterisk = 0;
			for (int i = 0; i < strlen(searcharr[searchnum]); i++)
			{
				if (searcharr[searchnum][i] == '*')
					asterisk++;	// asterisk의 수 세기
			}
			int length = strlen(searcharr[searchnum]) - asterisk;// searcharr(검색어)의 끝의 *을 모두 제거한 길이.
			int check = 0;

			for (int i = 0; i < length; i++)
			{
				if (data[i] == searcharr[searchnum][i])	// 줄의 처음부터 검색어 - 1의 길이까지 단어를 하나씩 확인
					check++;

			}
			if (check == length)			// 맞다면 check는 확인한 길이와 같을 것이다.
				cout << data << endl;
		}
		file.close();
		break;

		//////////////////////////////////////////////////////////////
	case 1:	// wildcard ? search

		while (!file.eof())
		{
			file.getline(data, 20);

			int length = strlen(searcharr[searchnum]);
			int check = 0;

			if (length == strlen(data))			// *와는 달리 데이터의 길이가 다르면 제외한다.
			{
				for (int i = 0; i < length; i++)
				{
					if (searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == data[i])
						check++;
				}								// ?는 와일드카드로 같지 않아도 같은 것으로 한다.
			}
			if (check == length)
				cout << data << endl;		// 문자가 하나라도 다르면 check = length가 될 수 없다.
		}
		file.close();
		break;

		//////////////////////////////////////////////////////////////
	case 2:	// default line search
		while (!file.eof())
		{
			file.getline(data, 20);

			int length = strlen(searcharr[searchnum]);
			int check = 0;

			if (length == strlen(data))		// *와는 달리 데이터의 길이가 다르면 제외한다.
			{
				for (int i = 0; i < length; i++)
				{
					if (data[i] == searcharr[searchnum][i])
						check++;
				}
			}
			if (check == length)
				cout << data << endl;		// 문자가 하나라도 다르면 check = length가 될 수 없다.
		}
		file.close();
		break;

	case 3:	// *, ? 모두 포함
		while (!file.eof())
		{
			file.getline(data, 20);

			int asterisk = 0;
			for (int i = 0; i < strlen(searcharr[searchnum]); i++)
			{
				if (searcharr[searchnum][i] == '*')
					asterisk++;	// asterisk의 수 세기
			}
			int length = strlen(searcharr[searchnum]) - asterisk;// searcharr(검색어)의 끝의 *을 모두 제거한 길이.
			//////////////////////////////////////////////////////////////////////////////
			int check = 0;

			for (int i = 0; i < length; i++)
			{
				if (searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == data[i] || searcharr[searchnum][i] == '*')
				{
					if(data[i] != NULL)
					check++;
				}
			}

			if (check == length)
				cout << data << endl;		// 문자가 하나라도 다르면 check = length가 될 수 없다.
		}
		file.close();
		break;

	case 4:	// 맨앞 *, ? 미포함
	{
		int length = strlen(searcharr[searchnum]);
		int asterisk = 0;
		int i = 0;
		while (searcharr[searchnum][0] == '*')
		{
			for (int j = 0; j < length; j++)
			{
				searcharr[searchnum][j] = searcharr[searchnum][j + 1];
			}
			searcharr[searchnum][length - i] = NULL;
			i++;
		}
		length = strlen(searcharr[searchnum]);

		/////////////////	맨앞의 *의 개수만큼 배열을 지워 앞으로 민다. 그리고 길이 또한 지운만큼으로 다시 설정한다.

		while (!file.eof())
		{
			file.getline(data, 20);

			int check = 0;

			if (length == 0)	// 검색어가 전부 *로 이루어져있을때
			{
				cout << data << endl;
				continue;
			}

			for (int k = 0; k < strlen(data) - length + 2; k++)	// 데이터의 길이 - 검색어의 길이의 차 + 1만큼 실행
			{											// k를 검색어 포인터라고 하면 검색어를 비교하기위해 포인터를 옮겨간다.
				for (int i = 0; i < length; i++)	// 검색어의 길이만큼 실행: 각 데이터를 비교
				{
					if (data[k + i] == searcharr[searchnum][i] || searcharr[searchnum][i] == '*')	// 포인터의 위치에서 검색어를 비교한다.
					{
						if (data[i] != NULL)	// 검색할 데이터의 길이를 초과해서 검색하지 않도록함
							check++;
					}
				}
				if (check == length)		// 검색어의 일치 개수가 검색어와 같으면 올바른 출력.
				{
					cout << data << endl;
				}
					check = 0;	// 다음 검색을 위해 초기화
			}
		}
		file.close();
		break;
	}

	case 5:	// 맨앞 *, ? 포함 > 맨앞이 *일때와 같지만 ?도 check에 포함되는 것이 다르다.
	{
		int length = strlen(searcharr[searchnum]);
		int asterisk = 0;
		while (searcharr[searchnum][asterisk] == '*')
		{
			asterisk++;
		}
		for (int i = 0; i < asterisk; i++)
		{
			for (int j = 0; j < length; j++)
			{
				searcharr[searchnum][j] = searcharr[searchnum][j + 1];
			}
			searcharr[searchnum][length - i] = NULL;
		}
		length = length - asterisk;
		/////////////////

		while (!file.eof())
		{
			file.getline(data, 20);

			int check = 0;

			for (int k = 0; k < strlen(data) - length + 2; k++)
			{
				for (int i = 0; i < length; i++)
				{
					if (data[k + i] == searcharr[searchnum][i] || searcharr[searchnum][i] == '?' || searcharr[searchnum][i] == '*') // ?도 check에 포함
					{
						if (data[i] != NULL)
							check++;
					}
				}
				if (check == length)
				{
					cout << data << endl;
				}
					check = 0;
			}
		}
		file.close();
		break;
	}

	}
	return;
}











int main()
{
	char file_name[20];

	cout << "Input file name : ";
	cin >> file_name;

	ifstream file;
	file.open(file_name);

	if (!file)	// 파일이 열리지 않았으면 오류 출력
	{
		cout << "No File" << endl;
		return 1;
	}
	file.close();

	////////////////////////////////////////////////////////////// 파일의 이름 입력 받기

	int N;
	cin >> N;

	char searchline[20];
	char** searcharr;
	searcharr = new char* [N];		// searcharr의 동적할당 N개의 행과 검색어 길이 + 1의 길이를 가지고 있다.


	for (int i = 0; i < N; i++)
	{
		cin >> searchline;
		searcharr[i] = new char[strlen(searchline) + 1];	// searharr[i]에 검색어가 저장된다.
		strcpy(searcharr[i], searchline);
	}

	////////////////////////////////////////////////////////////// searcharr의 동적 할당

	cout << endl;

	for (int i = 0; i < N; i++)
		searchLINE(i, searchCODE(i, searcharr), searcharr, file_name);	// searchCODE에 검색어 번호와 검색어, searchLINE에는 코드와 파일명, 검색어를 전달한다.
	
	////////////////////////////////////////////////////////////// searchLINE의 실행

	for (int i = 0; i < N; i++)
		delete[] searcharr[i];		//메모리 해제

	return 0;
	//////////////////////////////////////////////////////////////  반환
}