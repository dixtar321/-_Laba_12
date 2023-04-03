#include <iostream>
#include "Header.h"
using namespace std;

// —оздайте класс с именем Rational 
// дл€ выполнени€ действий с дроб€ми и программу тестировани€ вашего класса.
int main(){ 
	Rational num;
	char a[50] = { 0 }, b[50] = { 0 };

	cout << "Enter the first number: ";
	cin >> a;
	
	cout << "Enter the second number: ";
	cin >> b;

	if (num.error_check(a, b) == -1) {
		goto end;
	}
	else {

		num.set(a, b);
		num.get();
		cout << "\nReduction: ";
		num.Functions();
	}
	end:
	return 0;
}
