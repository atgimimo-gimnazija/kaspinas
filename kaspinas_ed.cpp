/*******************************************************************/
/* Имя: kaspinas_ed.cpp                                             */
/* Язык: C++	                                                   */
/* Описание: Разрезание ленты длиной N на максимальное             */
/* число отрезков длиной A, B, C                                   */
/* A*x + B*y + C*z = N                                             */
/* http://открытыйурок.рф/статьи/501260/
	A*x + B*y + C*z = N
	A*x + B*y = N - C*z; t(z) = N - C*z;
	A*x + B*y = t(z);
	x = q[0] + B*t(z); x = q[1] + A*t(z);
*/
/*******************************************************************/
#include <iostream>
using namespace std;

int* sort(int abc[]){
	int tmp;
	// Сортировка abc по возрастанию 
	for(int j = 0; j <= 2; j++) {
		for(int i = 0; i <= 1; i++) {
			if(abc[i + 1] < abc[i]) {
				tmp = abc[i + 1];
				abc[i + 1] = abc[i];
				abc[i] = tmp;
			}
		}
	}
	cout << "Sorted:" << abc[0] << " " << abc[1] << " " << abc[2] << "\n";
	return abc;
}

/*******************************************************************/
/* Функция: diofant                                               */
/* Описание: Поиск наибольшей суммы целых положительных решений    */
/* диофантова уравнения Ax + By + Cz = N                           */
/*******************************************************************/
int diofant(int abc[], int n) {
	int a = abc[0]; int b = abc[1]; int c = abc[2];

	int iR=-1, iX=-1, iY, iZ;
	while((iX==-1) & (n > abc[0])){
		if(iR!=-1) --n;
		int sumaMax = 0;
		for(int z=0; z < (n/c); z++){
			int x, y, t = (n - c*z);
			for(y = 0; y < a; y++){
				if((t - b*y) % a == 0){
					x = (t - b*y) / a;
					break;
				}
			}
			if((x >= 0) && (y >= 0)){
				if((x+y+z) > sumaMax){
					sumaMax = (x+y+z);
					iX=x;
					iY=y;
					iZ=z;
				}
			}
		}
		iR = sumaMax;
	}
	return iR;
}


int main() {
	//Объявляем переменные
	long int n;
	int *abc = new int[3];

	//n=7; a=2; b=5; c=5;
	//n=21; a=5; b=5; c=5;
	// Ввод значений
	cout << "Enter n:";
	cin >> n;
	
	cout << "Enter a:";
	cin >> abc[0];
	
	cout << "Enter b:";
	cin >> abc[1];
	
	cout << "Enter c:";
	cin >> abc[2];

	if((n<abc[2]) || (n<abc[1]) || (n<abc[0])){
		cout << "Ошибка: части превышают длину ленты!\n";
	}else{
		abc = sort(abc);
		
		cout << "Ответ: " <<  diofant(abc, n) << "\n";
	}
}
