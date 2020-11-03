// Rep: https:/github.com/Blackgard
// Name File : ClassA.h
// Date Edit : 02.11.2020

class ClassB;

class ClassA {

	//����������� ����� ������ 
	int m_n; 
	bool trigger; 
	//������ ���������� �� �����
	ClassB* m_pB[100];  

public: 
	ClassA();
	~ClassA();

	//������� ����� ������
	const int getN () const; 
	 

	//������� ����� 
	const ClassB** getB (int&) const; 

	//�������� ����� 
	bool add (const int); 

	//������� �����
	bool del (const int); 
	 
	//������� ������ �����
	int find (const int) const;

	//������� �������� ������� 
	const int getX(const int) const;
};
