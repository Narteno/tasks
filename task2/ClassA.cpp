#include "pch.h"
#include "ClassA.h"
#include"ClassB.h"

ClassA::ClassA() : m_update(false) 
{ 
	for (int j(0); j < 4; j++) 
		m_pB[j] = 0; 
} 
ClassA :: ~ClassA()
{
	for (int j(0); j < 4; j++) 
		m_pB[j] = 0; 
} 
//������� ���������� ������ 
const int ClassA:: getMultiplicity() const
{ 
	int n(0); 
	while (m_pB[n] && n < 4)
		++n; 
	return n; } 
//������� ��������� �� ��������� ������� 
const ClassB** ClassA:: getB() const 
{ 
	return const_cast <const ClassB**> (m_pB); 
} 
//��������� ������� ������ 
bool ClassA:: hasB() const 
{
	return m_pB[0] != 0;
} 
//��������� ����� � �������� 
bool ClassA:: hasB(const ClassB& r) const 
{ 
	int j(0); 
	while (m_pB[j]) 
	{
		if (m_pB[j] == &r) 
			return true; 
		j++; 
	} 
	return false; 
} 
//���������� ����� � �������� 
void ClassA::addB(ClassB& r)
{
	if (hasB(r))
		return;
	if (m_update)
		return;
	//������ ���� ����� ��� ���������� 
	if (getMultiplicity() >= 4) return;
	//r ������ ���� �������� 
	if (r.hasA()) 
		return; 
	m_update = true; 
	//������ r �� ���������� ����� 
	r.addA(*this); 
	//���������� ����� ������ 
	int n = getMultiplicity(); 
	m_pB[n] = &r; 
	m_update = false; 
} 
//��������� ����� � �������� 
void ClassA ::remove�(ClassB& r)
{
	if (m_update) return; 
	if (!hasB(r)) 
		return; 
	m_update = true; 
	//������ r � ������� ����� 
	r.removeA(); 
	//������ ����� ����� 
	int n = getMultiplicity(); 
	int j; 
	for (j = 0; j < n && m_pB[j] != &r; j++); 
	for (int i(j); i < n-1; i++) 
		m_pB[i] = m_pB[i+1]; 
	m_pB[n-1] = 0; 
	m_update = false; 
} 
//��������� ��� ����� 
void ClassA:: removeB()
{ 
	if (m_update) return; 
	m_update = true; 
	int j(0); 
	while (j < getMultiplicity())
	{ 
		m_pB[j]->removeA(); j++; 
	} 
	for (int j(0); j < 4; j++) 
		m_pB[j] = 0; 
	m_update = false;
}
