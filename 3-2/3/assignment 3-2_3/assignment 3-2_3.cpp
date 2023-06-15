#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class SongNode
{
public:
    string song_name;       // �� ����
    SongNode* next_song;    // ���� �� ����� �ּ�

    SongNode(string name)
    {
        song_name = name;       // �� ������ name���� �ʱ�ȭ
        next_song = nullptr;        // ���� �� ����� �ּҸ� nullptr�� �ʱ�ȭ
    }
};

class ArtistNode
{
public:
    string artist_name;     // ��Ƽ��Ʈ �̸�
    SongNode* song_head;        // �ش� ��Ƽ��Ʈ�� �� ����� ��� �ּ�
    ArtistNode* next_artist;        // ���� ��Ƽ��Ʈ ����� �ּ�

    ArtistNode(string name)
    {
        artist_name = name;     // ��Ƽ��Ʈ �̸��� name���� �ʱ�ȭ
        song_head = nullptr;        // �ش� ��Ƽ��Ʈ�� �� ����� ��� �ּҸ� nullptr�� �ʱ�ȭ
        next_artist = nullptr;      // ���� ��Ƽ��Ʈ ����� �ּҸ� nullptr�� �ʱ�ȭ
    }
};

class MyMusic
{
private:
    ArtistNode* artist_head;        // ��Ƽ��Ʈ ����� ��� �ּ�

    string to_lower(const string& str) {
        string lower_str = str;
        for (char& c : lower_str) {
            c = tolower((unsigned char) c);
        }
        return lower_str;
    }

    // �ش� ��Ƽ��Ʈ�� �� ��忡 ���ο� �� ��带 �߰��ϴ� �Լ�
    void insertion(ArtistNode* artist_node, string song_name)
    {
        SongNode* new_song = new SongNode(song_name);       // ���ο� �� ��� ����

        // �ش� ��Ƽ��Ʈ�� �� ��尡 ���ų�, ù ��° �� ����� �� ������ ���ο� �� ���񺸴� ū ���
        if (artist_node->song_head == nullptr || artist_node->song_head->song_name > song_name)
        {
            new_song->next_song = artist_node->song_head;       // ���ο� �� ����� ���� �� ��带 ù ��° �� ���� ����
            artist_node->song_head = new_song;      // ���ο� �� ��带 ù ��° �� ���� ����
        }
        else
        {
            SongNode* current = artist_node->song_head;     // ���� �� ��带 ù ��° �� ���� ����
            // ���� �� ����� ���� �� ��尡 nullptr�� �ƴϰ�, ���� �� ����� ���� �� ����� �� ������ ���ο� �� ���񺸴� ���� ���
            while (current->next_song != nullptr && current->next_song->song_name < song_name)
            {
                current = current->next_song;    // ���� �� ��带 ���� �� ���� ����
            }
            new_song->next_song = current->next_song;       // ���ο� �� ����� ���� �� ��带 ���� �� ����� ���� �� ���� ����
            current->next_song = new_song;      // ���� �� ����� ���� �� ��带 ���ο� �� ���� ����
        }
    }

public:
    MyMusic()
    {
        artist_head = nullptr;      // ��Ƽ��Ʈ ����� ��� �ּҸ� nullptr�� �ʱ�ȭ
    }

    // ������ �а�, �� ���� �о�鿩 ��Ƽ��Ʈ ���� �� ��带 �߰��ϴ� �Լ�
    void reading(const string& fp)
    {
        ifstream file(fp);       // fp ����� ������ �б� ���� ��

        if (!file.is_open())
        {
            cout << "Not found the file" << endl;
            return;
        }

        string line;        // ������ �� ���� ������ ����
        // ������ ������ �ݺ�
        while (getline(file, line))
        {
            istringstream str(line);        // line�� �о� str�� ����
            string artist_name, dummy, song_name;       // ��Ƽ��Ʈ �̸�, ����, �� �̸��� ������ ����

            getline(str, artist_name, '/');     // str�� '/'�� �������� �и��Ͽ� artist_name�� ����
            getline(str, dummy, '\t');      // str�� '\t'�� �������� �и��Ͽ� dummy�� ����
            getline(str, song_name);        // str�� song_name�� ����

            adding(artist_name, song_name);        // ��Ƽ��Ʈ ���� �� ��带 �߰��ϴ� �Լ� ȣ��
        }

        file.close();
    }

    // ��Ƽ��Ʈ ���� �� ��带 �߰��ϴ� �Լ�
    void adding(const string& artist_name, const string& song_name)
    {
        // ��Ƽ��Ʈ ��尡 ���� ���
        if (artist_head == nullptr)
        {
            artist_head = new ArtistNode(artist_name);      // ���ο� ��Ƽ��Ʈ ��� ����
            artist_head->next_artist = artist_head;     // ���ο� ��Ƽ��Ʈ ����� ���� ��Ƽ��Ʈ ��带 �ڱ� �ڽ����� ����
            insertion(artist_head, song_name);        // ���ο� ��Ƽ��Ʈ ��忡 �� ��带 �߰��ϴ� �Լ� ȣ��
        }
        else
        {
            ArtistNode* current = artist_head;      // ���� ��Ƽ��Ʈ ��带 ù ��° ��Ƽ��Ʈ ���� ����
            ArtistNode* prev = nullptr;     // ���� ��Ƽ��Ʈ ��带 nullptr�� �ʱ�ȭ

            do
            {
                // ���� ��Ƽ��Ʈ ����� ��Ƽ��Ʈ �̸��� artist_name�� ���� ���
                if (current->artist_name == artist_name)
                {
                    insertion(current, to_lower(song_name));        // ���� ��Ƽ��Ʈ ��忡 �ҹ��ڷ� ��ȯ�� �� ��带 �߰��ϴ� �Լ� ȣ��
                    return;
                }
                prev = current;     // ���� ��Ƽ��Ʈ ��带 ���� ��Ƽ��Ʈ ���� ����
                current = current->next_artist;     // ���� ��Ƽ��Ʈ ��带 ���� ��Ƽ��Ʈ ���� ����
            } while (current != artist_head);       // ���� ��Ƽ��Ʈ ��尡 ù ��° ��Ƽ��Ʈ ��尡 �ƴ� ��� �ݺ�

            ArtistNode* new_artist = new ArtistNode(artist_name);       // ���ο� ��Ƽ��Ʈ ��� ����
            prev->next_artist = new_artist;     // ���� ��Ƽ��Ʈ ����� ���� ��Ƽ��Ʈ ��带 ���ο� ��Ƽ��Ʈ ���� ����
            new_artist->next_artist = artist_head;      // ���ο� ��Ƽ��Ʈ ����� ���� ��Ƽ��Ʈ ��带 ù ��° ��Ƽ��Ʈ ���� ����

            insertion(new_artist, to_lower(song_name));     // to_lower �Լ��� �̿��Ͽ� ���ο� ��Ƽ��Ʈ ��忡 �� ��带 �߰��ϴ� �Լ� ȣ��
        }
    }

    // ��Ƽ��Ʈ ��忡 �� ��带 �߰��ϴ� �Լ�
    void printMusic()
    {
        if (artist_head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }

        ArtistNode* current_artist = artist_head;       // ���� ��Ƽ��Ʈ ��带 ù ��° ��Ƽ��Ʈ ���� ����
        
        do
        {
            // ���� ��Ƽ��Ʈ ����� ��Ƽ��Ʈ �̸��� "Artist\t\t\t"�� �ƴ� ���
            if (current_artist->artist_name != "Artist\t\t\t")
            {
                cout << "Artist: " << current_artist->artist_name << endl;      // ���� ��Ƽ��Ʈ ����� ��Ƽ��Ʈ �̸� ���
                SongNode* current_song = current_artist->song_head;     // ���� �� ��带 ù ��° �� ���� ����
                while (current_song != nullptr)
                {
                    // ���� �� ����� �� �̸��� "Songs"�� �ƴ� ���
                    if (current_song->song_name != "Songs")
                    {
                        string lower_song_name = to_lower(current_song->song_name); // �ҹ��ڷ� ��ȯ
                        if(lower_song_name == current_song->song_name)
                        {
                            cout << "Song: " << current_song->song_name << endl;        // ���� �� ����� �� �̸� ���
                        }
                    }
                    current_song = current_song->next_song;     // ���� �� ��带 ���� �� ���� ����
                }
                cout << endl;
            }
            current_artist = current_artist->next_artist;       // ���� ��Ƽ��Ʈ ��带 ���� ��Ƽ��Ʈ ���� ����

        } while (current_artist != nullptr);        // ���� ��Ƽ��Ʈ ��尡 ù ��° ��Ƽ��Ʈ ��尡 �ƴ� ��� �ݺ�
        
    }
};

int main()
{
    MyMusic music_list;       // MyMusic ��ü ����

    music_list.reading("Music_Info.txt");     // ������ �д� �Լ� ȣ��
    music_list.printMusic();       // ���� ������ ������ ����ϴ� �Լ� ȣ��

    return 0;
}