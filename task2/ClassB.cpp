#include "pch.h"
#include "ClassB.h"
#include "ClassA.h"

ClassB :: ClassB(): m_update (false), m_��(0) {}
ClassB :: ~ClassB()
{
	
	m_�� = 0;
} 
//������� ��������� �� ��������� ������ 
const ClassA* ClassB :: getA() const 
{
	return m_��;
}
//��������� ������� ����� 
bool ClassB :: hasA() const 
{
	return m_�� != 0;
} 
//���������� ����� 
void ClassB :: addA (ClassA& r)
{
	if (m_update) return; 
	if (m_�� == &r) return; 
	//������ r ������ ���� �������� �� ����� ������� 
	if (r.hasB(*this)) return; 
	if (hasA()) removeA(); 
	//���������� ����� ����� 
	//����������� ����� 
	m_update = true; 
	r.addB(*this); 
	m_�� = &r; 
	m_update = false; 
} 
//��������� ����� 
void ClassB :: removeA() 
{ 
	if (!hasA()) return; 
	if (m_update) return; 
	m_update = true; 
	m_��->removeB(); 
	//���������� ����� ����� 
	m_�� = 0; 
	m_update = false; 
}