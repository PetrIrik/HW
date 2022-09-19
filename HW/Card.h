#ifndef Card_h
#define Card_h
#include<string>
enum class Suit : int { CLUBS, DIAMONDS, HEARTS, SPADES };
enum class Value : int { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };


class Card {
public:
	Card() = delete;
	Card(const Value eValue, const Suit sSuit, const bool bShow = false);

	const Value GetValue() const;
	const Suit GetSuit() const;

	static std::string SuitToString(const Suit eSuit);
	static std::string ValueToString(const Value eValue);
	static int ValueToScore(const Value eValue);

	const std::string toString() const;

	void Filp();

protected:
	Suit m_eSuit;
	Value m_eValue;
	bool m_bShow;
};
#endif // !Card_h

