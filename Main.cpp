#include <iostream>
using namespace std;
//===========================================================================================
struct Struct{
	bool Червона;
	bool Велика;
	bool Квадрат;
	bool Рамка;

	int отличия = 0;
};

void coutStruc(Struct struc[]) {
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		cout << "#" << i + 1 << ". ";
		cout << (struc[i].Червона == 1 ? "Червона  "	: "Зелена   ");
		cout << (struc[i].Велика == 1 ? "Велика  "		: "Мала    ");
		cout << (struc[i].Квадрат == 1 ? "Квадратна  "  : "Кругла     ");
		cout << (struc[i].Рамка == 1 ? "є     "			: "Нема ") << "\n";
		if (struc[i].отличия > temp)
			temp = i + 1;
	}
	cout << "\nФігура #" << temp << " має найбільше спільних властивостей з іншими фігурами.\n\n";
}

void check(Struct struc[]) {
	for (int i = 0; i < 5; i++) {
		int Index1 = 0, Index2 = 0;

		if (struc[i].Червона == true) 
			Index1++;
		else
			Index2++;

		if (struc[i].Велика == true) 
			Index1++;
		else
			Index2++;

		if (struc[i].Квадрат == true) 
			Index1++;
		else
			Index2++;

		if (struc[i].Рамка == true) 
			Index1++;
		else
			Index2++;

		if (Index1 == 4 || Index2 == 4) {
			struc[i].отличия++;
			return;
		}
	}
}

int main() {
	Struct* struc = new Struct[5];

	system("chcp 1251>nul");
	cout << "#" << "   Барва    " << "Розмір  " << "Форма      " << "Рамка\n\n";

	struc[0].Червона = true; struc[0].Рамка = true; struc[0].Велика = true; struc[0].Квадрат = true;
	struc[1].Червона = true; struc[1].Рамка = false; struc[1].Велика = true; struc[1].Квадрат = true;
	struc[2].Червона = true; struc[2].Рамка = true; struc[2].Велика = true; struc[2].Квадрат = false;
	struc[3].Червона =false; struc[3].Рамка = true; struc[3].Велика = true; struc[3].Квадрат = true;
	struc[4].Червона = true; struc[4].Рамка = true; struc[4].Велика = false; struc[4].Квадрат = true;

	check(struc);
	coutStruc(struc);

	return 0;
}


/*
Задано п’ять фігур, як показано на малюнку і в таблиці. Напишіть
функцію, яка виводитиме на екран пронумеровану таблицю з
властивостями фігур.
Обчисліть, яка із заданих фігур має найбільше спільних властивостей
з іншими фігурами.
*/
