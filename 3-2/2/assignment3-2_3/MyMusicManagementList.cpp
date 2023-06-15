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

string small(string temp) {     // �ҹ��� ��ȯ �Լ�
    for (char& i : temp) {
        if (i >= 'A' && 'Z' >= i) {     // �빮���� ��� �ҹ��ڷ�
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
        // ���ο� �뷡 ������ ������ ��ġ�� ã��
        SongNode* curr = songs;
        SongNode* prev = nullptr;

        while (curr && small(curr->title) < small(title)) {       // ���ĺ� ������ ����
            prev = curr;
            curr = curr->next;
        }

        // ���ο� �뷡 ������ ������ ��ġ�� ����
        if (prev == nullptr) {
            // �� �տ� �����ϴ� ���
            newSong->next = songs;
            songs = newSong;
        }
        else {
            // �߰��� �뷡 ������ �����ϴ� ���
            prev->next = newSong;
            newSong->next = curr;
        }
    }
}


MyMusicManagementList::MyMusicManagementList(string& file_name): pHead(nullptr), size(0) {
	ifstream fin(file_name);
	string buf;
	getline(fin, buf);		// ù ���� ����
    while (getline(fin, buf)) {
        size_t pos = buf.find('\t');        // find�� �ε��� ����
        if (pos != string::npos) {
            string artist = buf.substr(0, pos);     // artist ����
            while (buf[pos] == '\t' || buf[pos] == '/' || buf[pos] == ' ')      // ������ �ǳ� �ٱ�
                pos++;
            string title = buf.substr(pos);         // title ����
            append(artist, title);          // ���� ��ũ�� ����Ʈ�� �߰�
        }
    }
}

MyMusicManagementList::~MyMusicManagementList() {
    if (pHead == nullptr) {
        return; // �� ����Ʈ�� ���
    }

    ArtistNode* curr = pHead;
    ArtistNode* next = nullptr;

    while (curr->next != pHead) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    delete curr; // ������ ��� ����
}



void MyMusicManagementList::append(string& artist, string& title)
{
    if (pHead == nullptr) {     // ó�� �߰��� ���
        ArtistNode* temp = new ArtistNode(artist);
        temp->addSong(title);
        temp->next = temp;      // �ڱ� �ڽ��� ����Ų��
        pHead = temp;
    }
    else {                      // �� ��
        ArtistNode* curr = pHead;
        while (curr->next != pHead) {       // ȸ�� ������
            if (curr->artist == artist) {
                curr->addSong(title);
                return;
            }
            curr = curr->next;
        }

        if (curr->artist == artist) {     // special case�� ����
            curr->addSong(title);
            return;
        }

        // ��ġ�ϴ� artist�� ���� ���
        ArtistNode* temp = new ArtistNode(artist);
        temp->addSong(title);
        temp->next = pHead;
        curr->next = temp;
    }
}



void MyMusicManagementList::print()
{
    // ��� ���� ���
    if (pHead == nullptr) {
        cout << "No data to print." << endl;
        return;
    }
    // ��ȸ�� ������
    ArtistNode* curr = pHead;

    do {
        cout << curr->artist << ": ";
        // song ���
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

