#include "mymusiclist.h"

SongNode::SongNode()
{
	memset(song, 0, 512); // song[512]�� ���� 0���� �ʱ�ȭ
	pnext = 0;
}

void SongNode::setSong(char* arr)
{
	strcpy(song, arr); // arr ���ڿ��� song�� ����
}

void SongNode::setSongNext(SongNode* ptr)
{
	pnext = ptr; // ���� ��� ����
}

char* SongNode::getSong()
{
	return song; // ��� ���� song ����
}

SongNode* SongNode::getSongNext()
{
	return pnext; // ��� ���� pnext ��ȯ
}

ArtistNode::ArtistNode()
{
	memset(name, 0, 512); // name[512] 0���� �ʱ�ȭ
	psong = 0;
	pnext = 0;
}

ArtistNode::~ArtistNode()
{
	SongNode* tmp;

	if (psong) // psong�� head�� �ϴ� list �޸� ����
	{
		while (psong)
		{
			tmp = psong;
			psong = psong->getSongNext();
			delete tmp; // head ������ �� ��徿 �޸� ����
		}
	}
}

void ArtistNode::setArtist(char* arr)
{
	strcpy(name, arr); // arr�� name�� ����
}

void ArtistNode::setSongList(SongNode* ptr)
{
	SongNode* prev;

	if (!psong) // song list�� ���������
	{
		psong = ptr; // ptr�� head
		return;
	}
	if (strcmp(psong->getSong(), ptr->getSong()) > 0) // ptr�� head���� �� �տ� �´ٸ� 
	{
		ptr->setSongNext(psong); // ptr�� next�� head
		psong = ptr; // ptr�� �� head
		return;
	}
	for (prev = psong; prev->getSongNext(); prev = prev->getSongNext())
	{
		if (strcmp(prev->getSongNext()->getSong(), ptr->getSong()) > 0) // ������ ��ġ ã��
		{
			ptr->setSongNext(prev->getSongNext()); // ptr�� prev�� ���� ��带 ����Ŵ
			prev->setSongNext(ptr); // prev�� ������ ptr
			return;
		}
	}
	prev->setSongNext(ptr); // �������� ptr ����
}

void ArtistNode::setArtistNext(ArtistNode* pnext)
{
	this->pnext = pnext; // ��� ���� ����
}

char* ArtistNode::getArtist()
{
	return name; // ������� name ��ȯ
}

SongNode* ArtistNode::getSongList()
{
	return psong; // ������� psong ��ȯ
}

ArtistNode* ArtistNode::getArtistNext()
{
	return pnext; // ������� pnext ��ȯ
}

bool MyMusicManagementList::isblank(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13)) // ch�� ���鹮�ڸ�
		return true; // �� ��ȯ
	else
		return false;
}

void MyMusicManagementList::tolower_arr(char* arr)
{
	for (int i = 0; arr[i]; i++)
		arr[i] = tolower(arr[i]); // tolower�Լ��� �̿��� arr�� ���ڵ��� �ҹ��ڷ� ��ȯ
}

void MyMusicManagementList::push(ArtistNode* art, SongNode* son)
{
	ArtistNode* tmp;

	if (!head) // ����Ʈ�� ���������
	{
		art->setArtistNext(art); // head�� ������ head
		head = art;
		tail = art; // head, tail ����
		art->setSongList(son); // art�� psong ����
		return;
	}
	for (tmp = head; tmp != tail; tmp = tmp->getArtistNext())
	{
		if (!strcmp(tmp->getArtist(), art->getArtist())) // art�� artist�� �̹� �ִٸ�
		{
			delete art; // art �޸� ����
			tmp->setSongList(son); // song�� psong�� ����
			return;
		}
	}
	if (!strcmp(tail->getArtist(), art->getArtist())) // tail�� art�� �̹� �ִٸ�
	{
		delete art;
		tail->setSongList(son);
		return;
	}
	art->setArtistNext(head); // art�� ������ ���� artist -> �� �ڿ� ����
	tail->setArtistNext(art); // art�� ������ head, tail�� ������ art
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
		while (head != tail) // head���� tail ������ �޸� ����
		{
			tmp = head;
			head = head->getArtistNext();
			delete tmp;
		}
		delete tail; // tail �޸� ����
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

	fin.open(file_name); // ���� �Է� ��Ʈ�� ����
	if (!fin) // ������ �������� �ʾ� ��Ʈ���� �� �����
	{
		std::cout << "file no exist" << std::endl;
		return false; // ���� ��ȯ
	}
	fin.getline(buf, 1024); // �� �ٿ� ������ �����Ƿ� getline���� ����, ù ���� artist / song -> �н�
	while (!fin.eof())
	{
		fin.getline(buf, 1024);
		strcpy(artist_buf, strtok(buf, "/")); // �������� �������� artist_buf, song_buf�� �ɰ�
		strcpy(song_buf, strtok(0, "/"));
		for (i = 0; artist_buf[i]; i++)
		{
			if (isblank(artist_buf[i]) && (artist_buf[i + 1] == 0 || isblank(artist_buf[i + 1])))
			{ // artist ���� �ڿ� �̾����� ������ ����
				artist_buf[i] = 0;
				break;
			}
		}
		for (i = 0; song_buf[i] && isblank(song_buf[i]); i++);
		strcpy(song_buf, song_buf + i); // song ���� ������ ���ӵǴ� ������ ����
		tolower_arr(song_buf); // song�� ��Ȱ�� ������ ���� �ҹ��ڷ� ��ȯ
		art = new ArtistNode;
		art->setArtist(artist_buf);
		son = new SongNode;
		son->setSong(song_buf); // art, son ��� ����
		push(art, son); // ����Ʈ�� ����
	}
	fin.close(); // ��Ʈ�� �ݱ�
	return true;
}

void MyMusicManagementList::print_all()
{
	ArtistNode* tmp;

	if (!head)
		return;
	std::cout << head->getArtist() << ":" << std::endl; // head ����� artist �̸� ���
	for (SongNode* tmp2 = head->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
			std::cout << "    " << tmp2->getSong() << std::endl; // �� artist�� song list ���
	for (tmp = head->getArtistNext(); tmp && tmp != head; tmp = tmp->getArtistNext())
	{
		std::cout << tmp->getArtist() << ":" << std::endl;
		for (SongNode* tmp2 = tmp->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
			std::cout << "    " << tmp2->getSong() << std::endl;
	} // tmp�� list�� ��ȸ�ϸ� head ��带 ������ ������ ������ ���
}

void MyMusicManagementList::search_next_artist(char* artist)
{
	if (!strcmp(head->getArtist(), artist)) // head�� artist���
	{
		std::cout << head->getArtistNext()->getArtist() << ":" << std::endl;
		for (SongNode* tmp = head->getArtistNext()->getSongList(); tmp; tmp = tmp->getSongNext())
			std::cout << "    " << tmp->getSong() << std::endl;
		return; // �Է¹��� artist ����� ���� ��� ���� ��� �� ����
	}
	for (ArtistNode* tmp = head->getArtistNext(); tmp != head; tmp = tmp->getArtistNext())
	{
		if (!strcmp(tmp->getArtist(), artist)) // �Է¹��� artist�� ã����
		{
			std::cout << tmp->getArtistNext()->getArtist() << ":" << std::endl;
			for (SongNode* tmp2 = tmp->getArtistNext()->getSongList(); tmp2; tmp2 = tmp2->getSongNext())
				std::cout << "    " << tmp2->getSong() << std::endl;
			return; // �� ���� ����� ������ ���
		}
	}
	std::cout << "search failed" << std::endl; // ��带 ã�� ���ϸ� ���� ���
}