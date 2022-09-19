#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
	Hand();

	void Add(const Card* pCard);
	void Clear();
	const int GetValue();
	void Print();

protected:
	std::vector<const Card*> m_aCards;
};

#endif // __HAND_H