#include "myMusic.h"
#include <string>

// myMusic 클래스의 생성자
myMusic::myMusic()
{
    m_title[0] = '\0';      // null로 초기화
	m_singer[0] = '\0';
	m_album[0] = '\0';
	m_track_no = 0;
	m_year = 0;
}

myMusic::~myMusic() {}

// myMusic 클래스의 멤버 함수
void myMusic::setTitle(char* title)
{
    strncpy_s(m_title, sizeof(m_title), title, sizeof(m_title) - 1);        // m_title에 title을 복사
    m_title[sizeof(m_title) - 1] = '\0';        // m_title의 마지막에 null 문자를 추가
}

// myMusic 클래스의 멤버 함수
void myMusic::setSinger(char* singer)
{
    strncpy_s(m_singer, sizeof(m_singer), singer, sizeof(m_singer) - 1);        // m_singer에 singer를 복사
    m_singer[sizeof(m_singer) - 1] = '\0';      // m_singer의 마지막에 null 문자를 추가
}

void myMusic::setAlbum(char* album)
{
    strncpy_s(m_album, sizeof(m_album), album, sizeof(m_album) - 1);        // m_album에 album을 복사
    m_album[sizeof(m_album) - 1] = '\0';        // m_album의 마지막에 null 문자를 추가
}

// myMusic 클래스의 멤버 함수
void myMusic::setYear(int year)
{
    m_year = year;      // m_year에 year를 대입
}

// myMusic 클래스의 멤버 함수
void myMusic::setTrackNo(int track_no)
{
    m_track_no = track_no;      // m_track_no에 track_no를 대입
}

// myMusic 클래스의 멤버 함수
char* myMusic::getTitle()
{
    return m_title;     // m_title을 반환
}

char* myMusic::getSinger()
{
    return m_singer;        // m_singer를 반환
}

char* myMusic::getAlbum()
{
    return m_album;     // m_album을 반환
}

int myMusic::getYear()
{
    return m_year;      // m_year를 반환
}

int myMusic::getTrackNo()
{
    return m_track_no;      // m_track_no를 반환
}
