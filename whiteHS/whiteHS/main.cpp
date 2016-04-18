#pragma once
#include "CGameManager.h"
CGameManager* CGameManager::pInstance = NULL;
int main(void)
{
	CGameManager::Initalize("deck01.txt", "deck02.txt");
	CGameManager* gman = CGameManager::GetInstance();
	getchar();

	/*regex reg("(\\d)/(\\d)");
	smatch m;
	string str = "1/2";
	if (regex_match(str, m, reg))
	{
		cout << m[0] << endl;
		cout << m[1] << endl;
		cout << m[2] << endl;
	}*/

	getchar();

	return 0;
}