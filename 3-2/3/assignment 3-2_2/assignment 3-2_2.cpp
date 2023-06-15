#include <iostream>
#include <string>
#include <sstream>
#include "myMusic.h"

using namespace std;

int main()
{
    myMusic music;      // myMusic ��ü ����

    string input;       // ����� �Է��� ���� ����
    cout << "Input the music information: ";
    getline(cin, input);        // ����� �Է��� ����

    stringstream str(input);        // �Է¹��� ���ڿ��� stringstream�� ����
    string title, singer, album;        // ���� ������ ������ ����
    int year, track_no;     // ���� ������ ������ ����

    getline(str, title, ',');       // ','�� �������� ���ڿ��� �и��Ͽ� title�� ����
    getline(str, singer, ',');      // ','�� �������� ���ڿ��� �и��Ͽ� singer�� ����
    getline(str, album, ',');       // ','�� �������� ���ڿ��� �и��Ͽ� album�� ����
    str >> year;        // year�� ����
    str.ignore(1); // ,�� �����ϱ� ���� ���
    str >> track_no;        // track_no�� ����

    // myMusic ��ü�� ���� ����
    music.setTitle(&title[0]);
    music.setSinger(&singer[0]);
    music.setAlbum(&album[0]);
    music.setYear(year);
    music.setTrackNo(track_no);

    // myMusic ��ü�� ����� ���� ���
    cout << "Title: " << music.getTitle() << endl;
    cout << "Singer: " << music.getSinger() << endl;
    cout << "Album: " << music.getAlbum() << endl;
    cout << "Year: " << music.getYear() << endl;
    cout << "Track No.: " << music.getTrackNo() << endl;

    return 0;
}
