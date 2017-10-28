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

int main() {
	int n, count, result=0;
	int *abc = new int[3];

	//n=121; abc[0] = 94; abc[1] = 3; abc[2] = 4; //40
	//n=121; abc[0] = 5; abc[1] = 3; abc[2] = 7; // 39
	//n=121; abc[0] = 3; abc[1] = 5; abc[2] = 5; // 37*3 + 5*2 // 39 
	//n=121; abc[0] = 3; abc[1] = 7; abc[2] = 5; // 38*3 + 7*1 // 39
	//n=7; abc[0] = 4; abc[1] = 3; abc[2] = 2;
	//n=7; abc[0] = 5; abc[1] = 5; abc[2] = 2;
	//n=5; abc[0] = 5; abc[1] = 3; abc[2] = 2;
	//n=5; abc[0] = 2; abc[1] = 4; abc[2] = 3;
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
	
	abc = sort(abc);
	count =  n / abc[0]; 
		
	while(count > 0){
		for(int i = 0; i < abc[0] * abc[1]; i++) {
			for(int j=0; j < abc[0] * abc[1]; j++) {
				if( n == count * abc[0] +  abc[0] * i + abc[1] * j) {
					if(result == 0)
						result = count + j; 
					break;
				}
			}
		}
		count--;
	}
	
	if(result == 0)
		result = n / abc[0];
	
	cout << "Ответ: " << result << "\n";
}

