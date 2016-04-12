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
	CPlayer(void);
	~CPlayer(void);
};

