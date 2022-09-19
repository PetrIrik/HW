#include <sstream>
#include "Card.h"

Card::Card(const Value eValue, const Suit sSuit, const bool bShow)
{
	m_eValue = eValue;
	m_eSuit = sSuit;
	m_bShow = bShow;
}

const Value Card::GetValue() const
{
	return m_eValue;
}
const Suit Card::GetSuit() const
{
	return m_eSuit;
}

std::string Card::SuitToString(const Suit eSuit)
{
	switch (eSuit) {
	case Suit::CLUBS:
		return "треф";
		break;

	case Suit::DIAMONDS:
		return "бубен";
		break;

	case Suit::HEARTS:
		return "червей";
		break;

	case Suit::SPADES:
		return "пик";
		break;
	}

	return "undefined";
}

std::string Card::ValueToString(const Value eValue) 
{
	switch (eValue) {
	case Value::TWO:
		return "Двойка";
		break;

	case Value::THREE:
		return "Тройка";
		break;

	case Value::FOUR:
		return "Четвёрка";
		break;

	case Value::FIVE:
		return "Пятёрка";
		break;

	case Value::SIX:
		return "Шестёрка";
		break;

	case Value::SEVEN:
		return "Семёрка";
		break;

	case Value::EIGHT:
		return "Восьмёрка";
		break;

	case Value::NINE:
		return "Девятка";
		break;

	case Value::TEN:
		return "Десятка";
		break;

	case Value::JACK:
		return "Валет";
		break;

	case Value::QUEEN:
		return "Дама";
		break;

	case Value::KING:
		return "Король";
		break;

	case Value::ACE:
		return "Туз";
		break;
	}

	return "undefined";
}

int Card::ValueToScore(const Value eValue) 
{
	switch (eValue) 
	{
	case Value::TEN:
	case Value::JACK:
	case Value::QUEEN:
	case Value::KING:
		return 10;
		break;

	case Value::ACE:
		return 11;
		break;
	}

	return static_cast<int>(eValue);
}

const std::string Card::toString() const 
{
	return Card::ValueToString(m_eValue) + ' ' + Card::SuitToString(m_eSuit);
}


void Card::Filp() {
	m_bShow = !m_bShow;
}