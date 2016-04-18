#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "CCard.h"
#include "CPlayer.h"
using namespace std;
//CGamaManager�� Singletone��ü�ν�, �� ������ �����Ϳ� �÷ο츦 �����մϴ�.
class CGameManager
{
	CPlayer *player[2];
	std::vector<CCard> vecCardList; //ī�帮��Ʈ�Դϴ�.
	static CGameManager* pInstance;

	CGameManager(string strP0Deckfile, string strP1Deckfile)
	{
		player[0] = new CPlayer();
		player[1] = new CPlayer(); //TODO : �÷��̾��� ������ �߰�������մϴ�.

		std::string wholeString;
		std::fstream file;
		string buf;
		file.open("cards.txt", std::fstream::in);
		if(!file.is_open())cout<<"file read error"<<endl;
		while(getline(file,buf))
		{
			wholeString+=buf;
			CCard tmp(buf);
			vecCardList.push_back(tmp);
		}
		file.close();
		buf.clear();


		file.open(strP0Deckfile, std::fstream::in);
		while (getline(file, buf))
		{
			int cardID = buf[0] - 48; // '0' == 48
			int cardQuantity = buf[2] - 48;
			for (int i = 0; i < cardQuantity;i++)
				player[0]->AddCardToDeck(vecCardList[cardID-1]);
			
		}
		file.close();

		file.open(strP1Deckfile, std::fstream::in);
		while (getline(file, buf))
		{
			int cardID = buf[0] - 48; // '0' == 48
			int cardQuantity = buf[2] - 48;
			for (int i = 0; i < cardQuantity; i++)
				player[1]->AddCardToDeck(vecCardList[cardID - 1]);

		}
		file.close();
		

	}
	~CGameManager()
	{
	}
public:
	static CGameManager* GetInstance()
	{
		return pInstance;
	}
	static void Initalize(string strP0Deckfile, string strP1Deckfile)
	{
		pInstance = new CGameManager(strP0Deckfile, strP1Deckfile);
		//TODO : �����ڸ� ����Ͽ��� ������ �����Ҷ� �ʱ�ȭ���ݴϴ�.

	}
	void Battle(int playerIndex, int attakCharacter, int attackedCharacter)
	{

	}
};

//ī�� ������ ���� ����
/*

M/3/5/1/Lava Rager////
ī������/�ڽ�Ʈ/���ݷ�/ü��/�̸�/������/ȿ��(�ؽ�Ʈ)/ȿ��(��ũ��Ʈ)
(M)inion, (S)pell, (A)rm

*/

// �� ������ ���� ����
/*

ID quantity

ex)
1/2 (1�� ī�带 2��)

*/