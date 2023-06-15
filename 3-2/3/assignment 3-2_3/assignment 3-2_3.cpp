#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class SongNode
{
public:
    string song_name;       // 곡 제목
    SongNode* next_song;    // 다음 곡 노드의 주소

    SongNode(string name)
    {
        song_name = name;       // 곡 제목을 name으로 초기화
        next_song = nullptr;        // 다음 곡 노드의 주소를 nullptr로 초기화
    }
};

class ArtistNode
{
public:
    string artist_name;     // 아티스트 이름
    SongNode* song_head;        // 해당 아티스트의 곡 노드의 헤드 주소
    ArtistNode* next_artist;        // 다음 아티스트 노드의 주소

    ArtistNode(string name)
    {
        artist_name = name;     // 아티스트 이름을 name으로 초기화
        song_head = nullptr;        // 해당 아티스트의 곡 노드의 헤드 주소를 nullptr로 초기화
        next_artist = nullptr;      // 다음 아티스트 노드의 주소를 nullptr로 초기화
    }
};

class MyMusic
{
private:
    ArtistNode* artist_head;        // 아티스트 노드의 헤드 주소

    string to_lower(const string& str) {
        string lower_str = str;
        for (char& c : lower_str) {
            c = tolower((unsigned char) c);
        }
        return lower_str;
    }

    // 해당 아티스트의 곡 노드에 새로운 곡 노드를 추가하는 함수
    void insertion(ArtistNode* artist_node, string song_name)
    {
        SongNode* new_song = new SongNode(song_name);       // 새로운 곡 노드 생성

        // 해당 아티스트의 곡 노드가 없거나, 첫 번째 곡 노드의 곡 제목이 새로운 곡 제목보다 큰 경우
        if (artist_node->song_head == nullptr || artist_node->song_head->song_name > song_name)
        {
            new_song->next_song = artist_node->song_head;       // 새로운 곡 노드의 다음 곡 노드를 첫 번째 곡 노드로 지정
            artist_node->song_head = new_song;      // 새로운 곡 노드를 첫 번째 곡 노드로 지정
        }
        else
        {
            SongNode* current = artist_node->song_head;     // 현재 곡 노드를 첫 번째 곡 노드로 지정
            // 현재 곡 노드의 다음 곡 노드가 nullptr이 아니고, 현재 곡 노드의 다음 곡 노드의 곡 제목이 새로운 곡 제목보다 작은 경우
            while (current->next_song != nullptr && current->next_song->song_name < song_name)
            {
                current = current->next_song;    // 현재 곡 노드를 다음 곡 노드로 지정
            }
            new_song->next_song = current->next_song;       // 새로운 곡 노드의 다음 곡 노드를 현재 곡 노드의 다음 곡 노드로 지정
            current->next_song = new_song;      // 현재 곡 노드의 다음 곡 노드를 새로운 곡 노드로 지정
        }
    }

public:
    MyMusic()
    {
        artist_head = nullptr;      // 아티스트 노드의 헤드 주소를 nullptr로 초기화
    }

    // 파일을 읽고, 각 줄을 읽어들여 아티스트 노드와 곡 노드를 추가하는 함수
    void reading(const string& fp)
    {
        ifstream file(fp);       // fp 경로의 파일을 읽기 모드로 엶

        if (!file.is_open())
        {
            cout << "Not found the file" << endl;
            return;
        }

        string line;        // 파일의 한 줄을 저장할 변수
        // 파일의 끝까지 반복
        while (getline(file, line))
        {
            istringstream str(line);        // line을 읽어 str에 저장
            string artist_name, dummy, song_name;       // 아티스트 이름, 더미, 곡 이름을 저장할 변수

            getline(str, artist_name, '/');     // str을 '/'를 기준으로 분리하여 artist_name에 저장
            getline(str, dummy, '\t');      // str을 '\t'를 기준으로 분리하여 dummy에 저장
            getline(str, song_name);        // str을 song_name에 저장

            adding(artist_name, song_name);        // 아티스트 노드와 곡 노드를 추가하는 함수 호출
        }

        file.close();
    }

    // 아티스트 노드와 곡 노드를 추가하는 함수
    void adding(const string& artist_name, const string& song_name)
    {
        // 아티스트 노드가 없는 경우
        if (artist_head == nullptr)
        {
            artist_head = new ArtistNode(artist_name);      // 새로운 아티스트 노드 생성
            artist_head->next_artist = artist_head;     // 새로운 아티스트 노드의 다음 아티스트 노드를 자기 자신으로 지정
            insertion(artist_head, song_name);        // 새로운 아티스트 노드에 곡 노드를 추가하는 함수 호출
        }
        else
        {
            ArtistNode* current = artist_head;      // 현재 아티스트 노드를 첫 번째 아티스트 노드로 지정
            ArtistNode* prev = nullptr;     // 이전 아티스트 노드를 nullptr로 초기화

            do
            {
                // 현재 아티스트 노드의 아티스트 이름이 artist_name과 같은 경우
                if (current->artist_name == artist_name)
                {
                    insertion(current, to_lower(song_name));        // 현재 아티스트 노드에 소문자로 변환한 곡 노드를 추가하는 함수 호출
                    return;
                }
                prev = current;     // 이전 아티스트 노드를 현재 아티스트 노드로 지정
                current = current->next_artist;     // 현재 아티스트 노드를 다음 아티스트 노드로 지정
            } while (current != artist_head);       // 현재 아티스트 노드가 첫 번째 아티스트 노드가 아닌 경우 반복

            ArtistNode* new_artist = new ArtistNode(artist_name);       // 새로운 아티스트 노드 생성
            prev->next_artist = new_artist;     // 이전 아티스트 노드의 다음 아티스트 노드를 새로운 아티스트 노드로 지정
            new_artist->next_artist = artist_head;      // 새로운 아티스트 노드의 다음 아티스트 노드를 첫 번째 아티스트 노드로 지정

            insertion(new_artist, to_lower(song_name));     // to_lower 함수를 이용하여 새로운 아티스트 노드에 곡 노드를 추가하는 함수 호출
        }
    }

    // 아티스트 노드에 곡 노드를 추가하는 함수
    void printMusic()
    {
        if (artist_head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        ArtistNode* current_artist = artist_head;       // 현재 아티스트 노드를 첫 번째 아티스트 노드로 지정
        
        do
        {
            // 현재 아티스트 노드의 아티스트 이름이 "Artist\t\t\t"가 아닌 경우
            if (current_artist->artist_name != "Artist\t\t\t")
            {
                cout << "Artist: " << current_artist->artist_name << endl;      // 현재 아티스트 노드의 아티스트 이름 출력
                SongNode* current_song = current_artist->song_head;     // 현재 곡 노드를 첫 번째 곡 노드로 지정
                while (current_song != nullptr)
                {
                    // 현재 곡 노드의 곡 이름이 "Songs"가 아닌 경우
                    if (current_song->song_name != "Songs")
                    {
                        string lower_song_name = to_lower(current_song->song_name); // 소문자로 변환
                        if(lower_song_name == current_song->song_name)
                        {
                            cout << "Song: " << current_song->song_name << endl;        // 현재 곡 노드의 곡 이름 출력
                        }
                    }
                    current_song = current_song->next_song;     // 현재 곡 노드를 다음 곡 노드로 지정
                }
                cout << endl;
            }
            current_artist = current_artist->next_artist;       // 현재 아티스트 노드를 다음 아티스트 노드로 지정

        } while (current_artist != nullptr);        // 현재 아티스트 노드가 첫 번째 아티스트 노드가 아닌 경우 반복
        
    }
};

int main()
{
    MyMusic music_list;       // MyMusic 객체 생성

    music_list.reading("Music_Info.txt");     // 파일을 읽는 함수 호출
    music_list.printMusic();       // 읽은 파일의 정보를 출력하는 함수 호출

    return 0;
}