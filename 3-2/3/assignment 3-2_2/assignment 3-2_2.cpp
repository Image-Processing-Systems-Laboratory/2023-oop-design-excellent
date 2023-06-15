#include <iostream>
#include <string>
#include <sstream>
#include "myMusic.h"

using namespace std;

int main()
{
    myMusic music;      // myMusic 객체 생성

    string input;       // 사용자 입력을 받을 변수
    cout << "Input the music information: ";
    getline(cin, input);        // 사용자 입력을 받음

    stringstream str(input);        // 입력받은 문자열을 stringstream에 저장
    string title, singer, album;        // 음악 정보를 저장할 변수
    int year, track_no;     // 음악 정보를 저장할 변수

    getline(str, title, ',');       // ','를 기준으로 문자열을 분리하여 title을 저장
    getline(str, singer, ',');      // ','를 기준으로 문자열을 분리하여 singer를 저장
    getline(str, album, ',');       // ','를 기준으로 문자열을 분리하여 album을 저장
    str >> year;        // year를 저장
    str.ignore(1); // ,를 무시하기 위해 사용
    str >> track_no;        // track_no를 저장

    // myMusic 객체에 정보 저장
    music.setTitle(&title[0]);
    music.setSinger(&singer[0]);
    music.setAlbum(&album[0]);
    music.setYear(year);
    music.setTrackNo(track_no);

    // myMusic 객체에 저장된 정보 출력
    cout << "Title: " << music.getTitle() << endl;
    cout << "Singer: " << music.getSinger() << endl;
    cout << "Album: " << music.getAlbum() << endl;
    cout << "Year: " << music.getYear() << endl;
    cout << "Track No.: " << music.getTrackNo() << endl;

    return 0;
}
