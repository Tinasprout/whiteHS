#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class CCard
{
	string strCardData; //�ؽ�Ʈ���Ͽ��� �ܾ�� ���� string�Դϴ�.
	char cType;
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
	virtual ~CCard(void);
};

