#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "CCard.h"
#include "CPlayer.h"
using namespace std;
//CGamaManager은 Singletone객체로써, 한 게임의 데이터와 플로우를 관리합니다.
class CGameManager
{
	CPlayer *player[2];
	std::vector<CCard> vecCardList; //카드리스트입니다.
	static CGameManager* pInstance;

	CGameManager(string strP0Deckfile, string strP1Deckfile)
	{
		player[0] = new CPlayer();
		player[1] = new CPlayer(); //TODO : 플레이어의 정보를 추가해줘야합니다.

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
		//TODO : 생성자를 사용하여서 게임이 시작할때 초기화해줍니다.

	}
	void Battle(int playerIndex, int attakCharacter, int attackedCharacter)
	{

	}
};

//카드 데이터 파일 서식
/*

M/3/5/1/Lava Rager////
카드종류/코스트/공격력/체력/이름/종족값/효과(텍스트)/효과(스크립트)
(M)inion, (S)pell, (A)rm

*/

// 덱 데이터 파일 서식
/*

ID quantity

ex)
1/2 (1번 카드를 2장)

*/