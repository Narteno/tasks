#pragma once
class ClassA; 
class ClassB {
	ClassA* m_��; //��������� �� ��������� ������ 
	bool m_update; //������� ���������� ����� 
public: ClassB();
		~ClassB(); //������� ��������� �� ��������� ������ 
		const ClassA* getA() const; 
		bool hasA() const;//��������� ������� ����� 
		void addA(ClassA&);//���������� ����� 
		void removeA(); //��������� ����� 
};
