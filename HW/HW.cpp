
#include <iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>
#include"ArrayInt.h"

#include "Card.h"
#include "Hand.h"


/*1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
• для удаления последнего элемента массива (аналог функции pop_back() в векторах)
• для удаления первого элемента массива (аналог pop_front() в векторах)
• для сортировки массива
• для вывода на экран элементов.*/

template <typename T>
size_t count_unique(const std::vector<T>& v) {
	std::unordered_set<T> s(v.begin(), v.end());

	return s.size();
}


template<typename T>
void print_vector(const std::vector<T>& v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
}

int main()
{
	setlocale(LC_ALL, "rus");

	ArreyInt Arrey;
	Arrey.push_back(5);
	Arrey.push_back(6);
	Arrey.push_back(1);
	Arrey.push_back(4);
	Arrey.push_back(-4);

	std::cout << " Началный Массив : ";
	Arrey.print();

	std::cout << " Сортируем Массив "<<std::endl;
	Arrey.sort();

	std::cout << " Результат сортировки : ";
	Arrey.print();

	std::cout << " Убираем первый элимент из массива : " << Arrey.pop_front() << std::endl;
	std::cout << " результат " ;
	Arrey.print();

	std::cout << "Убираем послединй элимент из массива : " << Arrey.pop_back() << std::endl;
	std::cout << " результат ";
	Arrey.print();
	std::cout << std::endl;
	//2 Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.
	std::cout << "task 2" << std::endl;
	std::vector<int>arrey{-5, -2, -1, 0, 2, 4, 6, 7, 8, 10, -10, 0};

	std::cout << "Исходный вектор: ";
	print_vector(arrey);
	std::cout<<std::endl;
	std::cout << "Всего элементов в векторе: " << arrey.size() << std::endl;
	std::cout << "Из них уникальных: " << count_unique(arrey) << std::endl;
	/* Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).*/

	Hand* pHand = new Hand;

	Card* pCard1 = new Card(Value::THREE, Suit::HEARTS);
	Card* pCard2 = new Card(Value::JACK, Suit::CLUBS);

	pHand->Add(pCard1);
	pHand->Add(pCard2);

	std::cout << "Текущее карты:\n";
	pHand->Print();

	std::cout << "\nСтоимость карт: " << +pHand->GetValue();
	std::cout << "\nДобавляем туз пик...\n";

	Card* pCard3 = new Card(Value::ACE, Suit::SPADES);
	pHand->Add(pCard3);

	std::cout << "\nТекущее карты:\n";
	pHand->Print();

	std::cout << "\nСтоимость карт: " << +pHand->GetValue();
	std::cout << "\nОчищаем руку...\n\n";

	pHand->Clear();
	pHand->Print();

	delete pCard1;
	delete pCard2;
	delete pCard3;
}

