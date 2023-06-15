#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int i = 0, j, k = 0, cnt[2] = { 0, }, word, start = 0, num;
	char arr[100000], order[50];
	cin.getline(arr, 100000, '\n');
	while (1)
	{
		cin >> order;					//명령 입력
		//arr이 입력되면
		if (strcmp(order, "arr") == 0)
		{
			cout << arr << endl;					//전체 출력
		}
		//arr배열 속 데이터를 특정해 입력하면
		else if (strncmp(order, "arr", 3) == 0)
		{
			//명령 문자열에서
			while (order[k] != '\0')
			{
				//배열 속 데이터의 위치 찾기
				while ((order[k] < '0' || order[k] > '9')&&order[k] !='\0')
				{
					order[k] = ' ';				//atoi가 중단되지 않게 제거
					k++;
				}
				if (order[k] == '\0')
					break;
				num = atoi(order);		//찾고자 하는 배열 속 데이터의 위치를 저장 arr[i]면 i
				while (order[k] >= '0' && order[k] <= '9')
				{
					order[k] = ' ';				//atoi가 중단되지 않게 제거
					k++;
				}
				cnt[1] = cnt[0];
				cnt[0]++;			// 찾고자 하는 데이터 위치 개수 = []의 개수 , arr[i]-큰 배열 하나=[]가 1,arr[i][j]-배열 속 배열 둘 =[]가 2 ... 
				word = -1;
				i = start;			//시작지점 맨 처음은 0 그 다음부턴 데이터 위치
				//arr 배열에서 
				while (word != num + 1)
				{
					//[]에 대한 코드
					if (arr[i] == '[')			//[가 나오면
					{
						cnt[1]++;				//[]의 개수 세기
						if (cnt[0] != cnt[1])	//찾으려는 배열의 깊이보다 더 깊은 배열을 만나면 ex)arr[3]이면 [] 1개, arr의 []를 제외한 []를 만나면
						{
							i++;
							while (cnt[0] != cnt[1])	//[]이 닫힐 때 까지
							{
								if (arr[i] == '[')		//[가 나오면 ++
									cnt[1]++;
								else if (arr[i] == ']')	//]가 나오면 --
									cnt[1]--;
								i++;
							}
						}
						else					//배열 속 배열을 무시하지 않아도 될 경우
						{
							word++;				//배열의 시작이어서 ++
							if (word == num)	//word와 num이 같으면 시작점
								start = i + 1;	//i가,일 때 word word++하고 검사하는 거기 때문에 ,다음인 i+1 값을 start로 저장
						}
					}
					if (arr[i] == ']')			//]가 출력되면(배열의 끝)
					{
						word++;						//word ++를 해 마지막 데이터도 출력될 수 있게
					}
					//단어의 시작
					if (arr[i] == ',')	//단어의 끝, 다음단어의  시작 전
					{
						word++;			//다음 단어의 위치 ++
						if (word == num)	//word와 num이 같으면 시작점
							start = i + 1;	//i가,일 때 word word++하고 검사하는 거기 때문에 ,다음인 i+1 값을 start로 저장
					}
					i++;			//진행
				}
			}
			for (j = start; j < i - 1; j++)
			{
				cout << arr[j];					//start 부터 ,전까지 출력
			}
			cout << endl;
			//변수 초기화
			i = 0;
			k = 0;
			cnt[0] = 0;
			cnt[1] = 0;
			start = 0;
		}
		//exit를 포함한 그 외의 경우
		else
			break;		//종료
	}
	return 0;
}