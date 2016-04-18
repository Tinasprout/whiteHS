#include "CCard.h"


CCard::CCard(string strData)
{
	nCardID = -1;
	regex reg("(\\D)/(\\d)/(\\d)/(\\d)/(.*)/(.*)/(.*)/(.*)");
	smatch m;
	if( regex_match(strData, m, reg) )
	{
		strCardData = m[0];
		cType = m[1];
		nCost = std::stoi(m[2]);
		nAtk = std::stoi(m[3]);
		nHp = std::stoi(m[4]);
		strName = m[5];
		strBrood = m[6];
		strTextEffect = m[7];
		strScriptEffect = m[8];

	}
}

CCard::CCard()
{ 
}


CCard::~CCard(void)
{
}
