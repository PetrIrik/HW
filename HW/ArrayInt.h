#ifndef ARREYINT_H
#define	ARREYINT_H

#include<cassert>
#define Swap(a, b) a = a ^ b; b = a ^ b; a = a ^ b;

class ArreyInt
{
public:
	ArreyInt();
	ArreyInt(int length);
	
	~ArreyInt();
	
	void erase();
	int getLegth();
	int& operator[](int index);// перезагрузили оператор индексации чтоб иметь доступ к элементам мапссива 
	void resize(int newLength);
	void insertBefort(int value, int index);
	void push_back(int value);
	int pop_back();
	int pop_front();
	void sort();
	void print();
	
	

private:
	int m_length = 0;
	int* m_data = nullptr;
};

#endif // !1



