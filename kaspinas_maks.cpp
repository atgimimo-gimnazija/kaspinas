#include <iostream>

using namespace std;

/*
 * сортировка массива по возрастанию
 */
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
	//cout << "Sorted:" << abc[0] << " " << abc[1] << " " << abc[2] << "\n";
	return abc;
}

/*
 * находит наименьшее общее кратное двух чисел, например,  для 6 и 9 это 18
 */
int findMultiplicator(int x, int y) {
	for(int i=1; i<=y; i++) {
		if((x*i) % y == 0) {
			//cout << " Multi:" << x << "x" << y << ": " << x*i << "\n";
			return x*i;
		}
	}
}
/*
 * 
 * вычисляет слагаемые.
 * Например, возьмем n=121.
 * на вход функции подаётся отсортированный массив кусочков abc и длина ленты n
 * сначала находится  на сколько  самых маленьких кусочков можно порезать ленту,
 * это переменная count. Остаток от разницы n - count*abc называем "хвостом":
 * 121 - 40*3 = 1
 * Теперь задача увеличивая хвост подобрать в  него оставшиеся два кусочки.
 * 
 * Первый цикл закручивается по k, начальное значение которого
 * равно count, а уменьшаем до предела r. r вычислям как разницу между количеством 
 * маленьких кусочков и тем количеством средних кусочков, сколько их поместится
 * в наименьшем кратном маленьких и средних кусочков( Для 3 и 4 это 12). Увеличивать хвост для 
 * подбора за этим ограничением нет смысла, так как потом будет повторение в цикле.
 * То есть:
 * 121 - 40*3 = 1
 * 121 - 39*3 = 4
 * 121 - 38*3 = 7
 * 121 - 37*3 = 11
 * 121 - 36*3 = 14
 * меньше 37 нет смысла, будет повторятся 12 в цикле.
 * Циклы по i и j так же ограничиваются по наименьшему общему кратном деленому
 * на кусочек перебор которого ведется.
 */

int calc(int n, int abc[]) {
	int count =  n / abc[0]; 
	int result=0;
	int k = count;
	int r = count - findMultiplicator(abc[0], abc[1]) / abc[1];
	int limitB = findMultiplicator(abc[0], abc[1]) / abc[1];
	int limitC = findMultiplicator(abc[1], abc[2]) / abc[2];
	//cout << "count:" << count << " r:" << r << " limitB:" << limitB << " limitC:" << limitC << " " << "\n";
	//cout << "count - limitB: " << count - limitB << " count - limitC:" << count - limitC << "\n"; 
	while(k >= r) {
		for(int i = 0; i < limitB; i++) {
			for(int j = 0; j <  limitC; j++) {
				//cout << "count:" << count << " i:" << i << " j:" << j  << "  Sum:" << (count * abc[0] +  abc[1] * i + abc[2] * j) << "\n";
				if( n == k * abc[0] +  abc[1] * i + abc[2	] * j) {
					//cout << " FOUND! count:" << count << " i:" << i << " j:" << j << " Result: " << (count + j + i) << "  Sum:" << count * abc[0] +  abc[1] * i + abc[2] * j << "\n";
					return count + j + i; 
				}
			}
		}
		count--;
		k--;
	}
	return n / abc[0];
}

int main() {
	int n;
	int *abc = new int[3];
	
	/**/
	// Ввод значений
	cout << "Enter n:";
	cin >> n;
	cout << "Enter a:";
	
	cin >> abc[0];
	
	cout << "Enter b:";
	cin >> abc[1];
	
	cout << "Enter c:";
	cin >> abc[2];
	/**/
	//n=1000000; abc[0] = 194; abc[1] = 222322; abc[2] = 12424; //40
	//n=121; abc[0] = 5; abc[1] = 3; abc[2] = 7; // 39
	//n=121; abc[0] = 3; abc[1] = 5; abc[2] = 8; // 37*3 + 5*2 // 39 
	//n=121; abc[0] = 3; abc[1] = 7; abc[2] = 5; // 38*3 + 7*1 // 39
	
	//n=22; abc[0] = 3; abc[1] = 5; abc[2] = 9; // 
	
	//n=12; abc[0] = 3; abc[1] = 10; abc[2] = 11; // 38*3 + 7*1 // 39
		
	//n=7; abc[0] = 4; abc[1] = 3; abc[2] = 2;  // 3
	//n=5; abc[0] = 2; abc[1] = 4; abc[2] = 3; //2
	
	//n=7; abc[0] = 5; abc[1] = 5; abc[2] = 2;
	//n=5; abc[0] = 5; abc[1] = 3; abc[2] = 2;
	
	cout << "Входные данные. n:" <<  n << " a:" << abc[0] << " b:" << abc[1] << " c:" << abc[2] <<"\n";
	abc = sort(abc);
	cout << "Ответ: " << calc(n, abc) << "\n";

}

