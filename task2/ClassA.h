#pragma once
class ClassB; 
class ClassA
{
private: 
	bool m_update; 
	ClassB* m_pB[4]; //������ ���������� �� ��������� ������� 
public: 
	ClassA();
	~ClassA();
	//������� ���������� ������
	const int getMultiplicity() const;
	//������� ��������� �� ��������� �������
	const ClassB** getB() const; 
	bool hasB() const; // ��������� ������� ������ 
	bool hasB(const ClassB&) const; //��������� ����� 
	void addB(ClassB&);//���������� ����� 
	void remove�(ClassB&);//��������� ����� 
	void removeB(); //��������� ��� ����� 
};