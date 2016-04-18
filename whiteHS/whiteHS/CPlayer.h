#pragma once
#include <vector>
#include "CCard.h"
#include "CMinion.h"

class CPlayer
{
	int nowMana;
	int maxMana;
	int nowOverload;
	int nextOverload;
	std::vector<CCard> vecDeck;
	std::vector<CCard> vecHand;
	std::vector<CMinion> vecField;
public:
	void AddCardToDeck(CCard card)
	{
		cout << card.GetCardName() << endl;
		vecDeck.push_back(card);
	}
	CPlayer(void);
	~CPlayer(void);
};

