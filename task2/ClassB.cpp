#include "pch.h"
#include "ClassB.h"
#include "ClassA.h"

ClassB :: ClassB(): m_update (false), m_рј(0) {}
ClassB :: ~ClassB()
{
	
	m_рј = 0;
} 
//вернуть указатель на св€занный объект 
const ClassA* ClassB :: getA() const 
{
	return m_рј;
}
//проверить наличие св€зи 
bool ClassB :: hasA() const 
{
	return m_рј != 0;
} 
//установить св€зь 
void ClassB :: addA (ClassA& r)
{
	if (m_update) return; 
	if (m_рј == &r) return; 
	//объект r должен быть свободен от этого объекта 
	if (r.hasB(*this)) return; 
	if (hasA()) removeA(); 
	//разрушение своей св€зи 
	//модификаци€ св€зи 
	m_update = true; 
	r.addB(*this); 
	m_рј = &r; 
	m_update = false; 
} 
//разрушить св€зь 
void ClassB :: removeA() 
{ 
	if (!hasA()) return; 
	if (m_update) return; 
	m_update = true; 
	m_рј->removeB(); 
	//разрушение своей св€зи 
	m_рј = 0; 
	m_update = false; 
}