#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class CCard
{
	int nCardID; //ī���� ������ȣ�Դϴ�.
	string strCardData; //�ؽ�Ʈ���Ͽ��� �ܾ�� ���� string�Դϴ�.
	string cType;
	int nCost;
	int nAtk;
	int nHp;
	string strName;
	string strBrood;
	string strTextEffect;
	string strScriptEffect;

public:
	CCard(string);
	CCard(void);
	string GetCardName(void)
	{
		return strName;
	}
	virtual ~CCard(void);
};

