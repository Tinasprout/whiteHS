#pragma once
#include "CCard.h"
#include "CCharacter.h"

class CMinion : public CCard, CCharacter
{
public:
	CMinion(void);
	~CMinion(void);
};

