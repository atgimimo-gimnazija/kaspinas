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
	//cout << "Sorted:" << abc[0] << " " << abc[1] << " " << abc[2] << "\n";
	return abc;
}


int findMultiplicator(int x, int y) {
	for(int i=1; i<=y; i++){
		if((x*i) % y == 0){
			return x*i;
		}
	}
}

int calc(int n, int abc[]) {
	int result=0;
	int count =  n / abc[0]; 
	int k = count;
	int r = (count - findMultiplicator(abc[0], abc[1]) / abc[1]);
	int limitC = findMultiplicator(abc[1], abc[2]) / abc[2];
	int limitB = findMultiplicator(abc[0], abc[1]) / abc[1];
	//cout << "count:" << count << " r:" << r << " limitB:" << limitB << " limitC:" << limitC << " " << "\n";
	//cout << "count - limitB: " << count - limitB << " count - limitC:" << count - limitC << "\n"; 
	while(k >= r) {
		for(int i = 0; i < limitB; i++) {
			for(int j = 0; j <  limitC; j++) {
				//cout << "count:" << count << " i:" << i << " j:" << j  << "  Sum:" << (count * abc[0] +  abc[1] * i + abc[2] * j) << "\n";
				if( n == k * abc[0] +  abc[1] * i + abc[2	] * j) {
					//cout << " FOUND! count:" << count << " i:" << i << " j:" << j << " Result: " << (count + j + i) << "  Sum:" << count * abc[0] +  abc[1] * i + abc[2] * j << "\n";
					if(result == 0 ) {
						return count + j + i; 
					}
					break;
				}
			}
		}
		count--;
		k--;
	}
	if(result == 0)
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
	//n=121; abc[0] = 3; abc[1] = 5; abc[2] = 5; // 37*3 + 5*2 // 39 
	//n=121; abc[0] = 3; abc[1] = 7; abc[2] = 5; // 38*3 + 7*1 // 39
	//n=7; abc[0] = 4; abc[1] = 3; abc[2] = 2;  // 3
	//n=5; abc[0] = 2; abc[1] = 4; abc[2] = 3; //2
	
	//n=7; abc[0] = 5; abc[1] = 5; abc[2] = 2;
	//n=5; abc[0] = 5; abc[1] = 3; abc[2] = 2;
	
	cout << "Входные данные. n:" <<  n << " a:" << abc[0] << " b:" << abc[1] << " c:" << abc[2] <<"\n";
	abc = sort(abc);
	cout << "Ответ: " << calc(n, abc) << "\n";
}

