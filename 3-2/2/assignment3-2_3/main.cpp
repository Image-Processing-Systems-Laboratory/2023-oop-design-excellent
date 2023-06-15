#include "MyMusicManagementList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	string file_name = "Music_Info.txt";
	MyMusicManagementList M(file_name);
	M.print();
}