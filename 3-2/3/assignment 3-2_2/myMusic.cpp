#include "myMusic.h"
#include <string>

// myMusic Ŭ������ ������
myMusic::myMusic()
{
    m_title[0] = '\0';      // null�� �ʱ�ȭ
	m_singer[0] = '\0';
	m_album[0] = '\0';
	m_track_no = 0;
	m_year = 0;
}

myMusic::~myMusic() {}

// myMusic Ŭ������ ��� �Լ�
void myMusic::setTitle(char* title)
{
    strncpy_s(m_title, sizeof(m_title), title, sizeof(m_title) - 1);        // m_title�� title�� ����
    m_title[sizeof(m_title) - 1] = '\0';        // m_title�� �������� null ���ڸ� �߰�
}

// myMusic Ŭ������ ��� �Լ�
void myMusic::setSinger(char* singer)
{
    strncpy_s(m_singer, sizeof(m_singer), singer, sizeof(m_singer) - 1);        // m_singer�� singer�� ����
    m_singer[sizeof(m_singer) - 1] = '\0';      // m_singer�� �������� null ���ڸ� �߰�
}

void myMusic::setAlbum(char* album)
{
    strncpy_s(m_album, sizeof(m_album), album, sizeof(m_album) - 1);        // m_album�� album�� ����
    m_album[sizeof(m_album) - 1] = '\0';        // m_album�� �������� null ���ڸ� �߰�
}

// myMusic Ŭ������ ��� �Լ�
void myMusic::setYear(int year)
{
    m_year = year;      // m_year�� year�� ����
}

// myMusic Ŭ������ ��� �Լ�
void myMusic::setTrackNo(int track_no)
{
    m_track_no = track_no;      // m_track_no�� track_no�� ����
}

// myMusic Ŭ������ ��� �Լ�
char* myMusic::getTitle()
{
    return m_title;     // m_title�� ��ȯ
}

char* myMusic::getSinger()
{
    return m_singer;        // m_singer�� ��ȯ
}

char* myMusic::getAlbum()
{
    return m_album;     // m_album�� ��ȯ
}

int myMusic::getYear()
{
    return m_year;      // m_year�� ��ȯ
}

int myMusic::getTrackNo()
{
    return m_track_no;      // m_track_no�� ��ȯ
}
