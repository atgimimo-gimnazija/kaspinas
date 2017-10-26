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
/* Функция: diofant2                                               */
/* Описание: Поиск наибольшей суммы целых положительных решений    */
/* диофантова уравнения Ax + By + Cz = N                           */
/*******************************************************************/
int *diofant(int A, int B, int C, int N) {
	 int z, sumaMax = 0;
	 int *w = new int[3];
	 int *result = new int[4];
	    for(int z = 0; z < (N / C); z++){

	        int  x, y;
	        int t = (N - C * z);
	        for(int y = 0; y < A; y++){
	            if((t - B * y) % A == 0){
	                x = (t - B * y) / A;
	                break;
	            }
	        }

	        if((x >= 0) && (y >= 0)){
	            if((x + y + z) > sumaMax){
	                sumaMax = (x + y + z);
	                w[0] = x;
	                w[1] = y;
	                w[2] = z;
	            }
	        }
	    }
	    result[0] = sumaMax;
	    result[1] = w[0];
	    result[2] = w[1];
	    result[3] = w[2];
	    return result;
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
	int *r = new int[4];
	if((n<abc[2]) || (n<abc[1]) || (n<abc[0])){
		cout << "Ошибка: части превышают длину ленты!\n";
	}else{
		abc = sort(abc);
		r = diofant(abc[0],abc[1],abc[2], n);
		cout << "Ответ: " <<  r[0] << "\n";
	}
}
