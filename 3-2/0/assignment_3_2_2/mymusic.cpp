#include "mymusic.h"

myMusic::myMusic()
{
	memset(m_title, 0, 32);
	memset(m_singer, 0, 32);
	memset(m_album, 0, 32);
	m_track_no = 0;
	m_year = 0;
} // �迭�� �� ��Ҹ� 0����, ������ 0���� �ʱ�ȭ

myMusic::~myMusic()
{
	m_track_no = 0;
	m_year = 0;
} // ���� �Ҵ�� �޸𸮰� �����Ƿ� ��ǻ� �ʿ� X

void myMusic::setTitle(char* title)
{
	if (!title)
		return;
	strncpy(m_title, title, 32); // title�� ��Ҹ� strncpy�� ����
	m_title[31] = 0; // null-terminating
}

void myMusic::setSinger(char* singer)
{
	if (!singer)
		return;
	strncpy(m_singer, singer, 32);
	m_singer[31] = 0;
}

void myMusic::setAlbum(char* album)
{
	if (!album)
		return;
	strncpy(m_album, album, 32);
	m_album[31] = 0;
}

void myMusic::setYear(int year)
{
	m_year = year;
}

void myMusic::setTrackNo(int track_no)
{
	m_track_no = track_no; // ��� ������ �� �Ҵ�
}

char* myMusic::getTitle()
{
	return m_title;
}

char* myMusic::getSinger()
{
	return m_singer;
}

char* myMusic::getAlbum()
{
	return m_album;
}

int myMusic::getYear()
{
	return m_year;
}

int myMusic::getTrackNo()
{
	return m_track_no; // ��� ���� ��ȯ
}