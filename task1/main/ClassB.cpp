// Rep: https://github.com/Blackgard
// Name File : ClassB.cpp
// Date Edit : 02.11.2020

#include "ClassB.hpp"

ClassB::ClassB(): m_x(0) {} 
ClassB::~ClassB() {} 

//установить m_х
void ClassB::setX(const int x){
	m_x = x;
}

//получить значение т_х
const int ClassB::getX() const {
	return m_x;
}

bool ClassB::verify(const int x) const {
	return m_x == x;
}

//перегрузка оператора =
ClassB& ClassB::operator = (const ClassB& r) {
	if (this != &r)
		m_x = r.m_x;
	return *this;
}

//перегрузка оператора ==
bool ClassB::operator == (const ClassB& r) const {
	return m_x == r.m_x;
}

//перегрузка оператор !=
bool ClassB::operator != (const ClassB& r) const {
	return m_x != r.m_x;
}