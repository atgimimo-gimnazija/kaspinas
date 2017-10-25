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

//Объявляем переменные
long int a, b, c, n;

/*******************************************************************/
/* Функция: diofant2                                               */
/* Описание: Решение диофантова уравнения Ax + By = C              */
/* в целых положительных числах                                    */
/*******************************************************************/
int *diofant2(int A, int B, int C) {
   int *result = new int[2];
   int dX;
   	for(int y = 0; y < A; y++){
   		dX = (C - B * y);
   		if(dX % A == 0){
   			result[0] = dX / A;
   			result[1] = y;
   			return result;
   		}
   	}
   	return result;
}

/*******************************************************************/
/* Функция: diofant3                                               */
/* Описание: Поиск наибольшей суммы целых положительных решений    */
/* диофантова уравнения Ax + By + Cz = N                           */
/*******************************************************************/
int *diofant3(int A, int B, int C, int N) {
	int t, suma = 0, sumaMax = 0;
	int *q = new int[2];
	int *w = new int[3];
	int *result = new int[4];
	w[1] = -1;
	for(int i = 0; i < (N / C); i++){
		q = diofant2(A, B, (N - C * i));
		if((q[0] >=  0) && (q[1] >= 0)){
			suma = (q[0] + q[1] + i);
			if(suma > sumaMax){
				sumaMax = suma;
				w[0] = q[0];
				w[1] = q[1];
				w[2] = i;
			}
		}
	}
	result[0] = sumaMax;
	result[1] = w[0];
	result[2] = w[1];
	result[3] = w[2];
	return result;
}

int min(int a, int b, int c){
	int *abc = new int[3];
	int tmp;
	abc[0] = a;
	abc[1] = b;
	abc[2] = c;
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
	//cout << "MIN:" << abc[0] << "\n";
	return abc[0];
}
/*******************************************************************/
/* Функция: kaspinas                                               */
/* Описание: Поиск наибольшей суммы положительных целых решений    */
/* диофантова уравнения Ax + By + Cz = N                           */
/*******************************************************************/
int *kaspinas(int a, int b, int c, int n) {
	int *ww = new int[4];
	ww = diofant3(a, b, c, n);
	while((ww[1] == -1) && (n > min(a, b, c))){
		if(ww[1] == -1) --n;
		ww = diofant3(a, b, c, n);
	}
	return ww;
}

int main() {
	//n=7; a=2; b=5; c=5;
	//n=21; a=5; b=5; c=5;
	// Ввод значений
	cout << "Enter n:";
	cin >> n;
	
	cout << "Enter a:";
	cin >> a;
	
	cout << "Enter b:";
	cin >> b;
	
	cout << "Enter c:";
	cin >> c;
	int *r = new int[4];
	if((n<c) || (n<b) || (n<a)){
		cout << "Ошибка: части превышают длину ленты!\n";
	}else{
		r = kaspinas(a, b, c, n);
		cout << "Ответ: " <<  r[0] << "\n";
	}
}
