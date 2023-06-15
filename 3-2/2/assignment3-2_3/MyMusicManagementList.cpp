#include "MyMusicManagementList.h"


SongNode::SongNode(string& s): title(s), next(nullptr) {
}

ArtistNode::ArtistNode(string& artist): artist(artist), songs(nullptr), next(nullptr) {

}

ArtistNode::~ArtistNode() {
    SongNode* curr = songs;
    while (curr != nullptr) {
        SongNode* next = curr->next;
        delete curr;
        curr = next;
    }
}

string small(string temp) {     // 소문자 변환 함수
    for (char& i : temp) {
        if (i >= 'A' && 'Z' >= i) {     // 대문자일 경우 소문자로
            i += 32;
        }
    }
    return temp;
}

void ArtistNode::addSong(string& title) {
    SongNode* newSong = new SongNode(title);

    if (songs == nullptr) {
        songs = newSong;
    }
    else {
        // 새로운 노래 제목을 삽입할 위치를 찾음
        SongNode* curr = songs;
        SongNode* prev = nullptr;

        while (curr && small(curr->title) < small(title)) {       // 알파벳 순으로 결정
            prev = curr;
            curr = curr->next;
        }

        // 새로운 노래 제목을 적절한 위치에 삽입
        if (prev == nullptr) {
            // 맨 앞에 삽입하는 경우
            newSong->next = songs;
            songs = newSong;
        }
        else {
            // 중간에 노래 제목을 삽입하는 경우
            prev->next = newSong;
            newSong->next = curr;
        }
    }
}


MyMusicManagementList::MyMusicManagementList(string& file_name): pHead(nullptr), size(0) {
	ifstream fin(file_name);
	string buf;
	getline(fin, buf);		// 첫 문장 생략
    while (getline(fin, buf)) {
        size_t pos = buf.find('\t');        // find로 인덱스 결정
        if (pos != string::npos) {
            string artist = buf.substr(0, pos);     // artist 결정
            while (buf[pos] == '\t' || buf[pos] == '/' || buf[pos] == ' ')      // 구분자 건너 뛰기
                pos++;
            string title = buf.substr(pos);         // title 결정
            append(artist, title);          // 원형 링크드 리스트에 추가
        }
    }
}

MyMusicManagementList::~MyMusicManagementList() {
    if (pHead == nullptr) {
        return; // 빈 리스트인 경우
    }

    ArtistNode* curr = pHead;
    ArtistNode* next = nullptr;

    while (curr->next != pHead) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    delete curr; // 마지막 노드 삭제
}



void MyMusicManagementList::append(string& artist, string& title)
{
    if (pHead == nullptr) {     // 처음 추가할 경우
        ArtistNode* temp = new ArtistNode(artist);
        temp->addSong(title);
        temp->next = temp;      // 자기 자신을 가리킨다
        pHead = temp;
    }
    else {                      // 그 외
        ArtistNode* curr = pHead;
        while (curr->next != pHead) {       // 회귀 전까지
            if (curr->artist == artist) {
                curr->addSong(title);
                return;
            }
            curr = curr->next;
        }

        if (curr->artist == artist) {     // special case에 실행
            curr->addSong(title);
            return;
        }

        // 일치하는 artist가 없을 경우
        ArtistNode* temp = new ArtistNode(artist);
        temp->addSong(title);
        temp->next = pHead;
        curr->next = temp;
    }
}



void MyMusicManagementList::print()
{
    // 비어 있을 경우
    if (pHead == nullptr) {
        cout << "No data to print." << endl;
        return;
    }
    // 순회할 포인터
    ArtistNode* curr = pHead;

    do {
        cout << curr->artist << ": ";
        // song 출력
        SongNode* songCurr = curr->songs;
        while (songCurr != nullptr) {
            cout << songCurr->title << " - ";
            songCurr = songCurr->next;
        }
        cout << endl;
        cout << endl;
        curr = curr->next;
    } while (curr != pHead);
    
}

