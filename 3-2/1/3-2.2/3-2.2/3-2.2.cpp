#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100; //최대 음악 개수
const int MAX_INPUT = 100; //최대 입력 길이

class myMusic { //MyMusic class
private:
    char m_title[32]; //음악 제목
    char m_singer[32]; //가수 이름
    char m_album[32]; //앨범 제목
    int m_track_no; //트랙 번호
    int m_year; //발매 연도

public:
    myMusic() {} //생성자
    ~myMusic() {} //소멸자

    void setTitle(char* title) { //음악 제목 설정
        strcpy(m_title, title);
    }
    void setSinger(char* singer) { //가수 이름 설정
        strcpy(m_singer, singer);
    }
    void setAlbum(char* album) { //앨범 제목 설정
        strcpy(m_album, album);
    }
    void setYear(int year) { //발매 연도 설정
        m_year = year;
    }
    void setTrackNo(int track_no) { //트랙 번호 설정
        m_track_no = track_no;
    }

    char* getTitle() { //음악 제목 반환
        return m_title;
    }
    char* getSinger() { //가수 이름 반환
        return m_singer;
    }
    char* getAlbum() { //앨범 제목 반환
        return m_album;
    }
    int getYear() { //발매 연도 반환
        return m_year;
    }
    int getTrackNo() { //트랙 번호 반환
        return m_track_no;
    }
};


int main() {
    
    myMusic list[MAX_SIZE]; //객체 선언
    int num = 0; //저장된 음악 개수

    while (num < MAX_SIZE) {
        char music[MAX_INPUT];
        cout << "[음악 제목, 가수 이름, 앨범 제목, 트랙 번호, 발매 연도]을 입력하세요\n(retrieve/modify/print/break)\n";
        cin.getline(music, MAX_INPUT); //음악 정보 입력 받기
        //입력 처리
        char* token = strtok(music, ",");        
        if (strcmp(token, "retrieve") == 0) { 
            //검색할 음악 제목 입력 받기
            char search_title[32];  
            cout << "\n검색하고 싶은 음악 제목을 입력하세요 \n "; 
            cin.getline(search_title, 32);

            //해당 음악 찾기
            int search_index = -1;
            for (int i = 0; i < num; i++) {
                if (strcmp(list[i].getTitle(), search_title) == 0) {
                    search_index = i;
                    break;
                }
            }
            //음악 정보 출력하기
            if (search_index != -1) {
                cout << "음악 제목: " << list[search_index].getTitle() << endl;
                cout << "가수 이름: " << list[search_index].getSinger() << endl;
                cout << "앨범 제목: " << list[search_index].getAlbum() << endl;
                cout << "트랙 번호: " << list[search_index].getTrackNo() << endl;
                cout << "발매 연도: " << list[search_index].getYear() << endl;
            }
        }
        else if (strcmp(token, "modify") == 0) {
            char modify_title[32];
            cout << "수정하고 싶은 음악 제목을 입력하세요\n";
            cin.getline(modify_title, 32);

            bool found = false; //입력된 제목의 음악을 찾았는지 여부를 저장하는 변수
            for (int i = 0; i < num; i++) {
                if (strcmp(list[i].getTitle(), modify_title) == 0) {
                    found = true; //입력된 제목의 음악을 찾았음을 표시
                    cout << "[음악 제목, 가수 이름, 앨범 제목, 트랙 번호, 발매 연도]을 입력해 수정하세요\n";
                    char modify_input[MAX_INPUT];
                    cin.getline(modify_input, MAX_INPUT);
                    //입력받은 정보를 각 항목으로 나누어 저장하기
                    char* token = strtok(modify_input, ",");
                    if (token != NULL) {
                        list[i].setTitle(token);
                    }
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        list[i].setSinger(token);
                    }
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        list[i].setAlbum(token);
                    }
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        list[i].setTrackNo(atoi(token));
                    }
                    token = strtok(NULL, ",");
                    if (token != NULL) {
                        list[i].setYear(atoi(token));
                    }
                    break;
                }
            }
            if (!found) { //입력된 제목의 음악을 찾지 못한 경우
                cout << "해당 음악이 목록에 없습니다\n" << endl;
            }
        }
        else if (strcmp(token, "print") == 0) {
            //음악 정보 출력
            for (int i = 0; i < num; i++) {
                cout << "음악 " << i + 1 << " :" << endl;
                cout << "음악 제목: " << list[i].getTitle() << endl;
                cout << "가수 이름: " << list[i].getSinger() << endl;
                cout << "앨범 제목: " << list[i].getAlbum() << endl;
                cout << "트랙 번호: " << list[i].getTrackNo() << endl;
                cout << "발매 연도: " << list[i].getYear() << endl;
            }
        }
        //입력이 끝났는지 확인
        else if (strcmp(token, "break") == 0) {
            break;
        }
        else {
            //음악 정보 입력받기
            list[num].setTitle(token);
            token = strtok(NULL, ",");
            list[num].setSinger(token);
            token = strtok(NULL, ",");
            list[num].setAlbum(token);
            token = strtok(NULL, ",");
            list[num].setTrackNo(atoi(token));
            token = strtok(NULL, ",");
            list[num].setYear(atoi(token));

            num++; //음악 정보 개수 증가
        }
    }
    return 0;
}