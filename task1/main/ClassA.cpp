// Rep: https://github.com/Blackgard
// Name File : ClassA.cpp
// Date Edit : 02.11.2020

#include <iostream>

#include "ClassA.hpp"
#include "ClassB.hpp"

ClassA::ClassA(): m_n(0), trigger(false) {}

ClassA::~ClassA() {
	for (int j(0); j < m_n; j++)
		delete m_pB[j];
}

//вернуть количество частей
const int ClassA::getN() const {
	return m_n;
}

//вернуть части const
const ClassB**ClassA::getB (int& n) const {
	n = m_n;
	return const_cast <const ClassB**> (m_pB);
}

//добавить часть
//метод получает все необходимые параметры для создания части
bool ClassA::add(const int x) {
	// Добавляемый элемент должен быть больше нуля
	if (find(x) >= 0) return false;

	// Проверяем выход за рамки массива
	if (m_n > 100) {
		if (!trigger) {
			std::cout << "You are out of array!" << std::endl ;
			trigger = true;
		}
		return false;
	}

	// Создаем новый экземпляр класса B
	m_pB[m_n] = new ClassB;
	// Записываем в класс B через метод ClassB::setX(x) переданный x
	m_pB[m_n]->setX(x);
	// Увеличиваем индекс элемента на 1  и возвращаем true
	m_n++; return true;
}

//удалить часть
bool ClassA::del(int key) {
	int JDel = find(key);

	//поиск индекса части
	if (JDel < 0)
		return false;

	//часть не найдена
	delete m_pB[JDel];

	//разрушение части
	while (JDel < m_n - 1) {
		//сжатие массива
		m_pB[JDel] = m_pB[JDel+1];
		JDel++;
	}
	
	m_n--;
	return true;
}

//вернуть индекс части
int ClassA::find(const int key) const {
	for (int j(0); j < m_n; j++)
		if (m_pB[j]->verify(key))
			return j;
	return -1;
}

// вернуть значение объекта с индексом
// вызывается метод класса частей m_pB[j]->getX();
const int ClassA::getX(const int j) const {
	return m_pB[j]->getX();
}
