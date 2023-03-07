/*
 *  Задача  "Шалаш"
 *  ---------------
 *  (Ш+А+Л)^4 = ШАЛАШ
 *  Каждой букве соответствует цифра.
 *  Найти эти цифры, так чтобы выражение было верным.
 */

#include <iostream>
using std::cout;
using std::endl;


// Целочисленное возведение в степень
int step(int x, short y)
{
	int res = x;
	for (int i = 1; i < y; i++)
		res = res * x;
	return res;
}

// СТАРТ
int main()
{
	short x, y, z;									 // значения для букв Ш, А, Л
	int temp1, temp2;
	bool flag = false;
	// перебор для буквы Ш
	for (x = 0; x <= 9 && !flag; x++) {
		// перебор для буквы А
		for (y = 0; y <= 9 && !flag; y++) {
			if (y == x) continue;					 // не может быть совпадающих цифр слева
			// перебор для буквы Л
			for (z = 0; z <= 9; z++) {
				if ((z == y) || (z == x)) continue;	 // не может быть совпадающих цифр слева
				// расчет значений для левой и
				// правой части исходного выражения
				temp1 = step(x + y + z, 4);
				temp2 = x + y * 10 + z * 100 + y * 1000 + x * 10000;
				// проверка на верность равенства
				if (temp1 == temp2) {
					flag = true;					 // флаг показывает, что решение найдено
					break;
				}
			}
		}
	}
	// Если флаг установлен - то найдено решение
	if (flag) {
		x--; y--;	// компенсируем лишний инкремент циклов x и y
		cout << "The result is:" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
	else cout << "Result not found" << endl;
}
