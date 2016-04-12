#include "CCard.h"


CCard::CCard(string strData)
{
	regex reg("(\\D)/(\\d)/(\\d)/(\\d)/(.*)/(.*)/(.*)/(.*)");
	smatch m;
	if( regex_match(strData, m, reg) )
	{
		for each(auto sm in m)
			cout<<sm<<endl;
	}
}

CCard::CCard()
{ 
}


CCard::~CCard(void)
{
}
