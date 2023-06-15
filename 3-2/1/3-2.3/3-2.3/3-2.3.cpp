#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SongNode { //SongNode class
public:
    string songName; //노래 제목
    SongNode* nextSong; //다음 노래를 가리키는 포인터

    SongNode(string name) { //생성자
        songName = name;
        nextSong = this; //다음 노래를 자기 자신으로 초기화
    }
};

class ArtistNode { //ArtistNode class
public:
    string artistName; //아티스트 이름
    SongNode* songList; //해당 아티스트의 노래 목록을 가리키는 포인터
    ArtistNode* nextArtist; //다음 아티스트를 가리키는 포인터

    ArtistNode(string name) { //생성자
        artistName = name;
        songList = new SongNode(""); //빈 노래로 초기화
        songList->nextSong = songList; //다음 노래를 자기 자신으로 초기화
        nextArtist = this; //다음 아티스트를 자기 자신으로 초기화
    }
};

class MyMusicManagementList { //MyMusicManagementList class
private:
    ArtistNode* artistList; //아티스트 목록을 가리키는 포인터
    int numArtists; //아티스트 수를 저장하는 변수

public:
    MyMusicManagementList() { //생성자
        artistList = new ArtistNode(""); //빈 아티스트로 초기화
        artistList->nextArtist = artistList; //다음 아티스트를 자기 자신으로 초기화
        numArtists = 0; //아티스트 수를 0으로 초기화
    }
    ~MyMusicManagementList() {} //소멸자

    void read(string filename) { //음악 정보 파일을 읽어서 파싱하는 함수
        ifstream file(filename); //파일 열기

        if (!file) { //파일 열기를 실패하면 에러 메시지 출력 후 종료
            cout << "It's not available : " << filename << endl;
            return;
        }

        string line; //문자열을 저장할 변수
        while (getline(file, line)) { //파일에서 한 줄씩 읽어들임
            //문자열의 앞뒤 공백 제거
            size_t start = line.find_first_not_of(" \t"); //문자열의 첫 번째 공백이 아닌 위치 찾기
            if (start == string::npos) continue; //문자열이 공백으로만 이루어져 있는 경우 무시
            size_t end = line.find_last_not_of(" \t"); //문자열의 마지막 공백이 아닌 위치 찾기
            if (end == string::npos) continue; //문자열이 공백으로만 이루어져 있는 경우 무시
            line = line.substr(start, end - start + 1); //문자열의 앞뒤 공백 제거한 부분만 저장

            //문자열을 "/" 문자를 기준으로 나누어서 artistName과 songName으로 저장
            size_t delimIndex = line.find("/"); // "/" 문자가 있는 위치 찾기
            if (delimIndex == string::npos) continue; // "/" 문자가 없는 경우 무시
            string artistName = line.substr(0, delimIndex); // "/" 문자 이전 부분 저장
            string songName = line.substr(delimIndex + 1); // "/" 문자 이후 부분 저장

            //artistName에서 직전 공백과 직후 공백 제거
            artistName.erase(0, artistName.find_first_not_of(" \t")); //문자열의 첫 번째 공백이 아닌 위치 찾기
            artistName.erase(artistName.find_last_not_of(" \t") + 1); //문자열의 마지막 공백이 아닌 위치 찾기

            //songName에서 직전 공백과 직후 공백 제거
            songName.erase(0, songName.find_first_not_of(" \t")); //문자열의 첫 번째 공백이 아닌 위치 찾기
            songName.erase(songName.find_last_not_of(" \t") + 1); //문자열의 마지막 공백이 아닌 위치 찾기


            //artistName의 문자열을 끝까지 반복하며 대문자이면 소문자로 변환
            for (int i = 0; i < artistName.size(); i++) {
                if (artistName[i] >= 'A' && artistName[i] <= 'Z') {
                    artistName[i] = artistName[i] - 'A' + 'a';
                }
            }
            //songName의 문자열을 끝까지 반복하며 대문자이면 소문자로 변환
            for (int i = 0; i < songName.size(); i++) {
                if (songName[i] >= 'A' && songName[i] <= 'Z') {
                    songName[i] = songName[i] - 'A' + 'a';
                }
            }
            add(artistName, songName); //변환된 artistName과 songName으로 노래 정보를 추가
        }
        file.close(); //파일 닫기
    }

    void add(string artistName, string songName) {

        if (artistName.empty() || songName.empty()) { //artistName이나 songName이 빈 문자열이면
            return; //종료
        }

        //현재 아티스트와 이전 아티스트를 초기화
        ArtistNode* currArtist = artistList->nextArtist;
        ArtistNode* prevArtist = artistList;

        //아티스트를 찾거나 새로운 아티스트를 삽입
        while (currArtist != artistList && currArtist->artistName < artistName) {
            prevArtist = currArtist;
            currArtist = currArtist->nextArtist;
            if (currArtist != artistList && currArtist->artistName == artistName) {
                //이미 존재하는 아티스트이면 노래를 추가
                SongNode* currSong = currArtist->songList->nextSong;
                SongNode* prevSong = currArtist->songList;

                //노래를 찾거나 새로운 노래를 삽입
                while (currSong != currArtist->songList && currSong->songName < songName) {
                    prevSong = currSong;
                    currSong = currSong->nextSong;
                }

                if (currSong != currArtist->songList && currSong->songName == songName) { //이미 존재하는 노래이면
                    return; //그대로 종료
                }
                //노래가 존재하지 않으면 새로운 노래 삽입
                SongNode* newSong = new SongNode(songName);
                newSong->nextSong = currSong;
                prevSong->nextSong = newSong;
                return;
            }
        }

        ArtistNode* newArtist = new ArtistNode(artistName); //새로운 아티스트 노드 생성 및 초기화        
        newArtist->nextArtist = currArtist; //새 아티스트의 다음 노드를 현재 아티스트로 설정        
        prevArtist->nextArtist = newArtist; //이전 아티스트 노드의 다음 노드를 새로운 아티스트로 설정       

        SongNode* newSong = new SongNode(songName);  //새로운 노래 노드 생성 및 초기화        
        newArtist->songList->nextSong = newSong; //새 노래 노드를 새로운 아티스트의 노래 리스트의 다음 노드로 설정        
        newSong->nextSong = newArtist->songList; //새 노래 노드의 다음 노드를 새로운 아티스트의 노래 리스트로 설정        

        numArtists++; //numArtists 1 증가
    }

    void print() {        
        ArtistNode* currArtist = artistList->nextArtist; //첫 번째 아티스트 노드 설정        
        while (currArtist != artistList) { //마지막 아티스트 노드에 도달할 때까지 반복            
            cout << currArtist->artistName << ":\n"; //아티스트 이름 출력            
            SongNode* currSong = currArtist->songList->nextSong; //첫 번째 노래 노드 설정            
            while (currSong != currArtist->songList) { //마지막 노래 노드에 도달할 때까지 반복                
                cout << "-" << currSong->songName << endl; //노래 제목 출력                
                currSong = currSong->nextSong; //다음 노래 노드 설정
            }           
            currArtist = currArtist->nextArtist;  //다음 아티스트 노드 설정            
            cout << endl; //개행
        }        
        cout << "total artist number: " << numArtists << endl; //numArtists 출력해 총 아티스트 수 확인
    }
};

int main() {
   
    MyMusicManagementList myMusicList;  //객체 생성    
    myMusicList.read("Music_info.txt"); //readMusicInfoFile 호출해 음악 정보 파일 읽기    
    myMusicList.print(); //printMusicList 호출해 음악 리스트 출력

    return 0;
}