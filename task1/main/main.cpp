#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ClassA.hpp"
#include "ClassB.hpp"
using namespace std;
/*	ClassA имеет 6 функций.
    ClassA - является интерфейсом для взаимодействия с ClassB.
    Функции: add, del, find, getN, getB

    add - добавляет в classA новый уникальный экземпляр (m_pB)ClassB;
        добавляет в себя только уникальные элементы. Если старые значения уже были,
        происходит удаление их.
    del - удаляет из classA экземпляр (m_pB)ClassB по номеру;
    find - ищет в (m_pB)ClassB элемент по переданному номеру.

    Для демонстрации работы с классами создаю экземпляр A класса и добавляю в него
    100 рандомный чисел (gn), в диапазоне от 0 до 100 (dn).
*/
int main() {


    ClassA obj;
    int gn = 100;
	int dn = 100;

    // Генерирую массив (add)

	for (int i = 0; i < gn; i++) {
        obj.add(rand() % dn);
	}

    // Вывожу весь массив
    int n = obj.getN();
    string message = "";

    cout << "ARRAY:" << endl << "[";
	for (int i = 0; i < n; i++) {
        message += to_string(obj.getX(i)) + ", ";
	}
    // в конце остается ", " убираю это
    // логичнее было бы использовать replace, но у меня возникает ошибка
    message.erase(message.length()-2,2);
    cout << message << "]" << endl;

    // Удалю только числа кратные 5 (del)

    // Кол-во элементов в массиве (хотя в c# легче бы работать было через Лист а не через массивы)
    n = obj.getN();

	for (int i = 0; i < n; i++) {

        // Получаю элемент массива по номеру i
        int x = obj.getX(i);

        if (x % 5 == 0) {
            obj.del(x);
			n--;
            // при удалении элемента всегда счетчик возвращаем на то же место, где произошло удаление
            // т.к. при удалении происходит сдвиг
			i--; 
		}
	}

    // Вывожу весь массив
    cout << "removed array:" << endl;
    n = obj.getN();
    message = "";
    cout << "[";
    for (int i = 0; i < n; i++) {
        message += to_string(obj.getX(i)) + ", ";
	}
    message.erase(message.length() - 2,2);
    cout << message << "]" << endl;


    // Найду 5 рандомных значений (find)
	
    cout << "Random 5 values:\n";
    for (int i = 0; i < 5; i++) {
		auto ranV = rand() % dn;
        cout << "[" << ranV << "] - " << obj.find(ranV) << endl;
	}


	system("pause"); 
	return 0;
}
