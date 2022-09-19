#include <iostream>

#include "Card.h"
#include "Hand.h"


Hand::Hand() 
{
}


void Hand::Add(const Card* pCard) {
	m_aCards.push_back(pCard);
}


void Hand::Clear() {
	m_aCards.clear();
}


const int Hand::GetValue() {
	int nSum = 0;

	for (const Card* pCard : m_aCards) {
		Value eValue = pCard->GetValue();
		nSum += (eValue == Value::ACE && nSum > 10) ? 1 : Card::ValueToScore(eValue);
	}

	return nSum;
}


void Hand::Print() {
	if (!m_aCards.empty()) {
		for (const Card* pCard : m_aCards) {
			std::cout << pCard->toString() << std::endl;
		}
	}
	else {
		std::cout << "Рука пустая\n";
	}
}