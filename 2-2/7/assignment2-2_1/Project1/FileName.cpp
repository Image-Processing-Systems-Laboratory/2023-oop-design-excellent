#include<iostream>
#include<string>
using namespace std;

struct ARR   // ����ü ����
{
	string arr = {};      // ����ڿ��� ���� ��Ʈ���� �����ϴ� ����
	string arr2[50] = {};  // ����ڿ��� ���� ��Ʈ���� �м��� �迭�� �����ϴ� �迭
	void make_Arr(string arr);  // ��Ʈ���� �м��Ͽ� ���ڿ��� ����� �Լ�
	int index;            // ���ڿ��� ������ ��Ÿ���� ����
};

void ARR::make_Arr(string arr)  // ��Ʈ���� �м��Ͽ� ���ڿ��� ����� �Լ� ����
{
	int count = 1;   
	index = 0;                                       // arr2 �迭�� index�� ��Ÿ���� ����
	int postion;                                      // ���ڿ��� �������� ���� ����
	int index2 = 0;                                     // countarr �迭�� index�� ��Ÿ���� ����
	int countarr[100] = {};                             // '[' ���ڰ� �ִ� ��ġ�� ��Ÿ���� �迭
	int countarr2[100] = {};                         // ']'���ڰ��ִ� ��ġ�� ��Ÿ���� �迭
	int index3 = 0;                                   // countarr2 �迭�� index�� ��Ÿ���� ����
	while ((postion = arr.find(',', count)) != string::npos)     // ���ڿ��� ������ ','�� ������ ���ڿ��� ������ ��
	{
		int temp = postion - count;                             // �ڸ� ���ڿ��� ���̸� ��Ÿ���� ����
		arr2[index] = arr.substr(count, temp);                    // �ڸ� ���ڿ��� arr2 �迭�� ����
		while (arr2[index].find(' ', 0) == 0)                    // ���� ���ڿ��� �չ��ڰ� ���鹮���� ��� ������ ���� ����
		{
			arr2[index] = arr2[index].substr(1, temp - 1);
			temp--;
		}
		count = postion + 1;                                    // ��ġ�� ',' ���� ��ĭ ���������� ������
		index++;
	}
	arr2[index] = arr.substr(count,arr.length() -count-1);       // ���ڿ��� �������� ',' �� ���� ������ ���ڿ��� �������� �������� �߶��� 
	int a = 1;
	while (arr2[index].find(' ', 0) == 0)                  // ���� ���ڿ��� �չ��ڰ� ���鹮���� ��� ������ ���� ����
	{
		arr2[index] = arr2[index].substr(1, arr2[index].length() - 1);
		a++;
	}
	index++;
	for (int i = 0; i < index; i++)     // �迭�� ó������ ������ �ݺ�
	{
		if (arr2[i].find('[', 0) != string::npos)      // �迭�� '['�� �ִ� ���
		{
			if (arr2[i].find('[', 1) == string::npos)  // '['�� �ݺ��Ͽ� �� ���� ���� ��� �״�� countarr�迭�� ����
			{
				countarr[index2] = i;
				index2++;
			}
			else
			{
				while (arr2[i].find('[', 1) != string::npos)    //'['�� �����Ͽ� �� ���� ������ ���� �ݺ�
				{
					countarr[index2] = i;                       // �ϴ� �� ��ġ��  countarr�迭�� ����
					index2++;
					index = index + 1;                        // arr2 �迭�� ũ�⸦ 1 �÷��ְ� �迭�� ��ĭ�� ���������� �о���
					for (int j = index-1; j > i+1; j--)
					{
						arr2[j] = arr2[j - 1];
					}
					arr2[i + 1] = arr2[i].substr(1, arr2[i].length() - 1);   // ���� �迭�� ���Ҹ� '['�� �ϰ� �װ��� �����ѳ����� �κ��� ���� �迭�� ����
					arr2[i] = '[';
				}
			}
		}
		if (arr2[i].find(']', 0) != string::npos)         // ���ڿ��� ']'�� �ִ� ���
		{
			if (arr2[i].find(']', 0) == arr2[i].length()-1)   // ���ڿ��� �������� ']'�� �ִٸ� �״�� countarr2�迭�� ����
			{
				countarr2[index3] = i;
				index3++;
			}
			else
			{
				while ((arr2[i].find(']', 0) != arr2[i].length()-1)&& (arr2[i].find(']', 0) != string::npos))   // ���ڿ��� ']'���ڰ� ���� ������ ���ڰ� ']' �� �϶� ���� �ݺ�
				{
					countarr2[index3] = i;     // �ϴ� �� ��ġ��  countarr2�迭�� ����
					index3++;
					index = index + 1;
					for (int j = index - 1; j > i+1; j--)  // arr2 �迭�� ũ�⸦ 1 �÷��ְ� �迭�� ��ĭ�� ���������� �о���
					{
						arr2[j] = arr2[j - 1];
					}
					arr2[i + 1] = arr2[i].substr(arr2[i].find(']', 0)+1, arr2[i].length() - arr2[i].find(']', 0)); // ���� �迭�� ���Ҹ� ���ڿ��� ���� �޹��ڰ� ']'�̸� ']'�� �ϳ��� ���ڿ��� �ϰ� �������� ���� �迭�� ����
					arr2[i] = arr2[i].substr(0, arr2[i].find(']', 0)+1);
					i++;
				}
				if (arr2[i].find(']', 0) == arr2[i].length() - 1) // ���ڿ��� �������� ']'�� �ִٸ� �״�� countarr2�迭�� ����
				{
					countarr2[index3] = i;
					index3++;
				}
			}
		}
	}
	int temp2 = 0;
	int i = 0;   // while�� �ݺ��� ���� ����
	int j = 0;    // while�� �ݺ��� ���� ����
	while (i < index3)      // countarr2�� ũ�� ��ŭ �ݺ�
	{
		int count2 = 0;
		while (j < index2)  // countarr�� ũ�� ��ŭ �ݺ�
		{
			if ((countarr[j] < countarr2[i]) && (countarr[j+1] < countarr2[i]&&j+1<index2))  // ó�� '['�� ���ö� ���� ���� ']' ������ �˻��Ͽ� �׻��� '['�� � �ִ��� ī�����Ͽ� '[]' ���� ���߾���
			{
				count2++;
			}
			else
			{
				bool A = true;
				for (int k = countarr[temp2]; k < countarr2[i + count2]; k++)      // '[]' �� ���̿� �ִ� �迭�� ���Ҹ� �ϳ��� ���ҷ� ������
				{
					if (arr2[k + 1] == "]"|| arr2[countarr[temp2]]=="[")       // ���� ���Ұ� '[', ']' ��� ���Ҹ� �����ٶ� ', '�� �ٿ����� ���� �׸��� ������ ������ �ڸ��� ���� '0'�� �ٲ�
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
					else                                                                // '[]'�� ���̿� �ִ� ��� ���Ҹ� �ϳ��� �����ָ� �����ٶ� ���̿�', ' ���� �׸��� ������ ������ �ڸ��� ���� '0'�� �ٲ�
					{
						arr2[countarr[temp2]] = arr2[countarr[temp2]] + ", " + arr2[k + 1];
						arr2[k + 1] = '0';
					}
				}
				temp2 = temp2 + count2+1;                     // ���� ���� ã�� ��ġ�� �̵�
				j++;
				i = i + count2;
				break;
			}
			j++;
		}
		i++;
	}
	for (int k = 0; k < index; k++)         // �迭�� ������ �ݺ�
	{
		if (arr2[k] == "0")              // �迭�� ���Ұ� 0�� ��� �� ��ġ�� �����Ͽ� �迭�� �� ĭ�� ���� �ٽ� �� ��ġ�� �˻�
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
	getline(cin, input_arr);   // ����ڿ��� ���ڿ��� �Է� ����
	ARR Arr[20];              // ����ü �迭 ����
	Arr[0].arr = input_arr;  // ����ڿ��� �Է¹��� ���ڿ��� ����ü�� ����
	Arr[0].make_Arr(input_arr);  // �Է� ���� ���ڿ��� �м��Ͽ� �迭�� ����
	while (true)                  // ����ڰ� exit�Է½� ���� �ݺ�
	{
		string command;      // ����ڿ��� �Է� ���� ���ڿ� ����
		cin >> command;    //  ����ڿ��� ���ڿ� �Է¹���

		if (command == "exit")  // ����ڰ� exit�Է½� ���α׷� ����
		{
			break;
		}
		if (command == "arr")    // ����ڰ� arr �Է½� ����ڰ� ���� �Է��� ���ڿ� �״�� ���
		{
			cout << Arr[0]. arr<<endl;
		}
		if (command.substr(0, 4) == "arr[") // ����ڰ� arr[x][x]... ���·� �Է½�
		{
			int postion = 3;                          // ���ڿ��� �߶��� ��ġ�� �˷��ִ� ����
			int index[100] = {};                     // ����ڰ� ����ϱ� ���ϴ� �迭�� ��ġ�� �˷��ִ� ����
			int temp = 0;                          // ���� �迭�� �ε����� ǥ���ϴ� ����
			bool A = true;
			while (command.find('[',postion) != string::npos)   // ���ڿ��� ����߶� '['�� ������ ���������� �ݺ�
			{
				if ((command.substr(command.find('[', postion) + 1, 1) >= "0" && (command.substr(command.find('[', postion) + 1, 1) <= "9"))&& command.substr(command.find('[', postion) + 2, 1)=="]")
					/*����ڰ� �Է��� ���ڿ��� '['�� ']'���̿� �ִ� ���ڰ� �������� �˻�*/
				{
					index[temp] = stoi(command.substr(command.find('[', postion) + 1, 1)); //���� �´ٸ� �׺κ��� int������ �ٲپ� �迭�� ����
					temp++;
					postion = postion +3;  // �˻� ��ġ�� 3ĭ �̵���
				}
				else  //�ƴ� ��� bool ������ �ٲپ� ��
				{
					A = false;
					break;
				}

			}
			if (!A) // ����ڰ� �Է��� ������ �߸� �Ǿ����Ƿ� �ٽ� �������� �̵�
				continue;
			if (temp == 1)// ����ڰ� �Է��� ���ڿ��� arr[x]������ ��� ����ڰ� �Է��� ���ڿ��� ��ġ�� �����Ͽ� �ش���ġ�� ���� ���
			{
				cout << Arr[0].arr2[index[0]] << endl;
			}
			else    // �ƴ� ���
			{
				int count=0;
				for (count = 1; count < temp; count++)   
				{
					Arr[count].make_Arr(Arr[count - 1].arr2[index[count - 1]]);// ���� ������ �迭�� ���� ����ü �迭�� ���� ����ڰ� ���ϴ� �迭�� ���� �迭�� �����Ͽ� ���� �迭�� ����
				}
				cout << Arr[count-1].arr2[index[count - 1]] << endl;  // ����ڰ� ����ϱ� �ٶ�� �迭 ���

			}
		}
	}
	return 0;
}