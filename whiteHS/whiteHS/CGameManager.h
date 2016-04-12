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
	CPlayer *player1, *player2;
	std::vector<CCard> vecCardList;
	static CGameManager* pInstance;

	CGameManager()
	{
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
		//std::cout<<wholeString<<std::endl;
	}
	~CGameManager()
	{
	}
public:
	static CGameManager* GetInstance()
	{
		return pInstance;
	}
	static void Initalize()
	{
		pInstance = new CGameManager();
		//TODO : 생성자를 사용하여서 게임이 시작할때 초기화해줍니다.
	}
};

//데이터 파일 서식
/*

M/3/5/1/Lava Rager////
카드종류/코스트/공격력/체력/이름/종족값/효과(텍스트)/효과(스크립트)
(M)inion, (S)pell, (A)rm

*/