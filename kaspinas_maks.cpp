#include <iostream>

using namespace std;

int findMax(int n, int a, int b, int c) {
	//cout  << "n=" << n << " " << a << " " << b << " " << c << "\n";
	int first = n / a;
	int second = (n - first*a) / b;
	int third = (n - first*a - second*b) / c;
	return first + second + third;
}

int findEqal(int n, int a, int b) {
	//cout  << "n=" << n << " " << a << " " << b << "\n";
	int tmp;
	int first = n / a;
	
	if(first * a == n)
		return first;
	
	tmp = a * first;
	while(tmp > 0) {	 
		if(tmp + b == n) {
	//		cout << "BREAK. first: " << first <<  " tmp:" << tmp <<"\n";
			return first + 1;
			break;
		}
		tmp = tmp - a;
		first--;
	}
	return 0;
}
/*
 * Три цикла находят 6 возможных комбинаций перестановок a,b,c в массиве: 
 * 123, 132, 213, 231, 312, 321
 * По  каждой комбинации вызвываются функции нахождения максимально количества
 * отрезков(findMax) и количества отрезков при сложении которых получается ровно
 * исходный отрезок(findEqual) 
 */
int combinate(int n, int abc[]) {
	int result, max=0, equalMax=0;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++){
			for(int k=1; k<=3; k++) {
				if( (i + j == k) && (i != j) && (k !=j ) ) {
					result = findMax(n, abc[i-1],  abc[j-1], abc[k-1]);
					if(result >  max)
						max = result;
					result = findEqal(n, abc[i-1],  abc[j-1]);
					if(result >  equalMax)
						equalMax = result;
				}
				if( (i + k == j) && (i != k) && (i !=j ) ) {
					result = findMax(n, abc[i-1],  abc[j-1], abc[k-1]);
					if(result >  max)
						max = result;
					result = findEqal(n, abc[i-1],  abc[j-1]);
					if(result >  equalMax)
						equalMax = result;
				}
				if( (j + k == i) && (j != k) && (j != i ) ) {
					result = findMax(n, abc[i-1],  abc[j-1], abc[k-1]);
					if(result >  max)
						max = result;
					result = findEqal(n, abc[i-1],  abc[j-1]);
					if(result >  equalMax)
						equalMax = result;
				}
			}
		}			
	}
	//cout << "max: " << max << " maxEqual: " << equalMax << "\n";
	if(equalMax > 0)
		return equalMax;
	else
		return max;
}
int main() {
	int n, abc[4];
	//n=121; abc[0] = 94; abc[1] = 3; abc[2] = 4; //40
	//n=121; abc[0] = 5; abc[1] = 3; abc[2] = 7; // 39
	//n=7; abc[0] = 4; abc[1] = 3; abc[2] = 2;
	//n=7; abc[0] = 5; abc[1] = 5; abc[2] = 2;
	//n=5; abc[0] = 5; abc[1] = 3; abc[2] = 2;
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
	cout << "Входные данные. n:" <<  n << " a:" << abc[0] << " b:" << abc[1] << " c:" << abc[2] <<"\n";
	cout << "Result: " << combinate(n, abc) << "\n";
}

// 121 3,4,10 120-3=117  
//3*39 + 4=121


