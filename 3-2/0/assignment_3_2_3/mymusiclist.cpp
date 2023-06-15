#include "mymusiclist.h"

SongNode::SongNode()
{
	memset(song, 0, 512); // song[512]를 전부 0으로 초기화
	pnext = 0;
}

void SongNode::setSong(char* arr)
{
	strcpy(song, arr); // arr 문자열을 song에 복사
}

void SongNode::setSongNext(SongNode* ptr)
{
	pnext = ptr; // 다음 노드 설정
}

char* SongNode::getSong()
{
	return song; // 멤버 변수 song 반한
}

SongNode* SongNode::getSongNext()
{
	return pnext; // 멤버 변수 pnext 반환
}

ArtistNode::ArtistNode()
{
	memset(name, 0, 512); // name[512] 0으로 초기화
	psong = 0;
	pnext = 0;
}

ArtistNode::~ArtistNode()
{
	SongNode* tmp;

	if (psong) // psong을 head로 하는 list 메모리 해제
	{
		while (psong)
		{
			tmp = psong;
			psong = psong->getSongNext();
			delete tmp; // head 노드부터 한 노드씩 메모리 해제
		}
	}
}

void ArtistNode::setArtist(char* arr)
{
	strcpy(name, arr); // arr을 name에 복사
}

void ArtistNode::setSongList(SongNode* ptr)
{
	SongNode* prev;

	if (!psong) // song list가 비어있으면
	{
		psong = ptr; // ptr이 head
		return;
	}
	if (strcmp(psong->getSong(), ptr->getSong()) > 0) // ptr이 head보다 더 앞에 온다면 
	{
		ptr->setSongNext(psong); // ptr의 next가 head
		psong = ptr; // ptr이 새 head
		return;
	}
	for (prev = psong; prev->getSongNext(); prev = prev->getSongNext())
	{
		if (strcmp(prev->getSongNext()->getSong(), ptr->getSong()) > 0) // 삽입할 위치 찾음
		{
			ptr->setSongNext(prev->getSongNext()); // ptr이 prev의 다음 노드를 가리킴
			prev->setSongNext(ptr); // prev의 다음이 ptr
			return;
		}
	}
	prev->setSongNext(ptr); // 마지막에 ptr 삽입
}

void ArtistNode::setArtistNext(ArtistNode* pnext)
{
	this->pnext = pnext; // 멤버 변수 설정
}

char* ArtistNode::getArtist()
{
	return name; // 멤버변수 name 반환
}

SongNode* ArtistNode::getSongList()
{
	return psong; // 멤버변수 psong 반환
}

ArtistNode* ArtistNode::getArtistNext()
{
	return pnext; // 멤버변수 pnext 반환
}

bool MyMusicManagementList::isblank(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13)) // ch가 공백문자면
		return true; // 참 반환
	else
		return false;
}

void MyMusicManagementList::tolower_arr(char* arr)
{
	for (int i = 0; arr[i]; i++)
		arr[i] = tolower(arr[i]); // tolower함수를 이용해 arr의 문자들을 소문자로 변환
}

void MyMusicManagementList::push(ArtistNode* art, SongNode* son)
{
	ArtistNode* tmp;

	if (!head) // 리스트가 비어있으면
	{
		art->setArtistNext(art); // head의 다음은 head
		head = art;
		tail = art; // head, tail 설정
		art->setSongList(son); // art의 psong 설정
		return;
	}
	for (tmp = head; tmp != tail; tmp = tmp->getArtistNext())
	{
		if (!strcmp(tmp->getArtist(), art->getArtist())) // art의 artist가 이미 있다면
		{
			delete art; // art 메모리 해제
			tmp->setSongList(son); // song은 psong에 삽입
			return;
		}
	}
	if (!strcmp(tail->getArtist(), art->getArtist())) // tail에 art가 이미 있다면
	{
		delete art;
		tail->setSongList(son);
		return;
	}
	art->setArtistNext(head); // art가 기존에 없던 artist -> 맨 뒤에 삽입
	tail->setArtistNext(art); // art의 다음은 head, tail의 다음은 art
	tail = art;
	art->setSongList(son);
}

MyMusicManagementList::MyMusicManagementList()
{
	head = 0;
	tail = 0;
}

MyMusicManagementList::~MyMusicManagementList()
{
	ArtistNode* tmp;

	if (head)
	{
		while (head != tail) // head부터 tail 전까지 메모리 해제
		{
			tmp = head;
			head = head->getArtistNext();
			delete tmp;
		}
		delete tail; // tail 메모리 해제
	}
}

bool MyMusicManagementList::make_list(char* file_name)
{
	std::ifstream fin;
	char buf[1024];
	char artist_buf[512];
	char song_buf[512];
	ArtistNode* art;
	SongNode* son;
	int i;

	fin.open(file_name); // 파일 입력 스트림 생성
	if (!fin) // 파일이 존재하지 않아 스트림이 안 생기면
	{
		std::cout << "file no exist" << std::endl;
		return false; // 거짓 반환
	}
	fin.getline(buf, 1024); // 한 줄에 공백이 있으므로 getline으로 받음, 첫 줄은 artist / song -> 패스
	while (!fin.eof())
	{
		fin.getline(buf, 1024);
		strcpy(artist_buf, strtok(buf, "/")); // 슬래쉬를 기준으로 artist_buf, song_buf로 쪼갬
		strcpy(song_buf, strtok(0, "/"));
		for (i = 0; artist_buf[i]; i++)
		{
			if (isblank(artist_buf[i]) && (artist_buf[i + 1] == 0 || isblank(artist_buf[i + 1])))
			{ // artist 정보 뒤에 이어지는 공백을 제거
				artist_buf[i] = 0;
				break;
			}
		}
		for (i = 0; song_buf[i] && isblank(song_buf[i]); i++);
		strcpy(song_buf, song_buf + i); // song 정보 앞쪽의 연속되는 공백을 제거
		tolower_arr(song_buf); // song의 원활한 정렬을 위해 소문자로 변환
		art = new ArtistNode;
		art->setArtist(artist_buf);
		son = new SongNode;
		son->setSong(song_buf); // art, son 노드 생성
		push(art, son); // 리스트에 삽입
	}
	fin.close(); // 스트림 닫기
	return true;
}

void MyMusicManagementList::print_all()
{
	ArtistNode* tmp;

	if (!head)
		return;
	std::cout << head->getArtist() << ":" << std::endl; // head 노드의 artist 이름 출력
	for (SongNode* tmp2 = head->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
			std::cout << "    " << tmp2->getSong() << std::endl; // 위 artist의 song list 출력
	for (tmp = head->getArtistNext(); tmp && tmp != head; tmp = tmp->getArtistNext())
	{
		std::cout << tmp->getArtist() << ":" << std::endl;
		for (SongNode* tmp2 = tmp->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
			std::cout << "    " << tmp2->getSong() << std::endl;
	} // tmp가 list를 순회하며 head 노드를 만나기 전까지 정보를 출력
}

void MyMusicManagementList::search_next_artist(char* artist)
{
	if (!strcmp(head->getArtist(), artist)) // head가 artist라면
	{
		std::cout << head->getArtistNext()->getArtist() << ":" << std::endl;
		for (SongNode* tmp = head->getArtistNext()->getSongList(); tmp; tmp = tmp->getSongNext())
			std::cout << "    " << tmp->getSong() << std::endl;
		return; // 입력받은 artist 노드의 다음 노드 정보 출력 후 종료
	}
	for (ArtistNode* tmp = head->getArtistNext(); tmp != head; tmp = tmp->getArtistNext())
	{
		if (!strcmp(tmp->getArtist(), artist)) // 입력받은 artist를 찾으면
		{
			std::cout << tmp->getArtistNext()->getArtist() << ":" << std::endl;
			for (SongNode* tmp2 = tmp->getArtistNext()->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
				std::cout << "    " << tmp2->getSong() << std::endl;
			return; // 그 다음 노드의 정보를 출력
		}
	}
	std::cout << "search failed" << std::endl; // 노드를 찾지 못하면 에러 출력
}