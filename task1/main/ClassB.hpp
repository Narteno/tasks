// Rep: https://github.com/Blackgard
// Name File : ClassB.h
// Date Edit : 02.11.2020

class ClassB {

	//член-данное части
	int m_x; 

public:
	ClassB();
	~ClassB();

	//методы установки и получения значения m_х
	void setX(const int);

	const int getX() const;

	//проверить объект
	bool verify (const int) const;

	//перегрузка оператора =
	ClassB& operator = (const ClassB&);

	//перегрузка операторов == 
	bool operator == (const ClassB&) const;

	//перегрузка операторов != 
	bool operator != (const ClassB&) const;
};