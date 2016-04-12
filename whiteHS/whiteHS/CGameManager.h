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
		//TODO : �����ڸ� ����Ͽ��� ������ �����Ҷ� �ʱ�ȭ���ݴϴ�.
	}
};

//������ ���� ����
/*

M/3/5/1/Lava Rager////
ī������/�ڽ�Ʈ/���ݷ�/ü��/�̸�/������/ȿ��(�ؽ�Ʈ)/ȿ��(��ũ��Ʈ)
(M)inion, (S)pell, (A)rm

*/