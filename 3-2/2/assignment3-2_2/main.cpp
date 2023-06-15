#include "Mstring.h"
#include "myMusic.h"
#include <iostream>

using namespace std;

// function to set the music's info
bool setInfo(myMusic& obj) {
	size_t maximum = 1000;
	char* buf = new char[maximum];
	int num = 0;
	cout << "Title: ";
	cin.getline(buf, maximum);
	obj.setTitle(buf);
	cout << "Singer: ";
	cin.getline(buf, maximum);
	obj.setSinger(buf);
	cout << "Album: ";
	cin.getline(buf, maximum);
	obj.setAlbum(buf);
	cout << "Year: ";
	cin >> num;
	obj.setYear(num);
	cout << "Track_no: ";
	cin >> num;
	obj.setTrack(num);

	delete[] buf;
	return true;
}

// function to print out the music's info
bool print(myMusic& obj) {
	cout << "Title: " << obj.getTitle() << endl;
	cout << "Singer: " << obj.getSinger() << endl;
	cout << "Album: " << obj.getAlbum() << endl;
	cout << "Year: " << obj.getYear() << endl;
	cout << "Track_no: " << obj.getTrackNo() << endl;
	return true;
}


int main() {
	Mstring cmd;			// 커맨드를 저장할 임시 변수
	myMusic* house = new myMusic[1000];		// myMusic 배열
	char* buf = new char[2048];
	size_t num_of_music=0;	// 등록된 음악의 수


	while (cmd != "b") {
		cin >> cmd;
		if (cmd == "add") {			// add new music
			cin.clear();		// 버퍼 초기화
			cin.ignore(100, '\n');
			setInfo(house[num_of_music++]);
			cout << "--------------------" << endl;
		}
		else if (cmd == "modify") {	// update music's info
			cin.get();
			cin.getline(buf, 2048);
			Mstring title = buf;
			for (size_t i = 0; i < num_of_music; i++) {
				if (house[i].getTitle() == title)
					setInfo(house[i]);
			}
			cout << "--------------------" << endl;
		}
		else if (cmd == "retrieve") {		// find a specific music
			cin.get();
			cin.getline(buf, 2048);
			Mstring title = buf;
			for (size_t i = 0; i < num_of_music; i++) {
				if (house[i].getTitle() == title)
					print(house[i]);
			}
			cout << "--------------------" << endl;

		}
	}

	delete[] house;
	delete[] buf;
}