#pragma once
#include "card.h"
#include <vector>
#include <deque>
class Player
{
public:
	//hand
    deque<card> hand;
    //guesses
    vector<int> guess;
	Player()
	{}
	virtual ~Player(void)
	{}
};