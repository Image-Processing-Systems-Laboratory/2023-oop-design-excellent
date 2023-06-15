#include "myMusic.h"

myMusic::myMusic() : track_no(0), year(0) {

}

myMusic::~myMusic() {

}

void myMusic::setTitle(Mstring title)
{
	this->title = title;
}


void myMusic::setSinger(Mstring singer)
{
	this->singer = singer;
}


void myMusic::setAlbum(Mstring album)
{
	this->album = album;
}


void myMusic::setYear(int year)
{
	this->year = year;
}


void myMusic::setTrack(int track_no)
{
	this->track_no = track_no;
}

Mstring& myMusic::getTitle()
{
	return title;
}


Mstring& myMusic::getSinger()
{
	return singer;
}


Mstring& myMusic::getAlbum()
{
	return album;
}


int myMusic::getYear()
{
	return year;
}


int myMusic::getTrackNo()
{
	return track_no;
}
