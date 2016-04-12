#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;
class CCard
{
	string strCardData; //텍스트파일에서 긁어온 원래 string입니다.
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

