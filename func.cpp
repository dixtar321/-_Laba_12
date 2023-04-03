#include "Header.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void Rational::Functions() {
	check_reduction (n_1, d_1); // сокращение 1 дроби
	check_reduction (n_2, d_2); // сокращение 2 дроби
	get();
	sum(n_1, d_1, n_2, d_2); // сложение
	subration(n_1, d_1, n_2, d_2); // вычитание
	multiplication(n_1, d_1, n_2, d_2); // умножение
	division(n_1, d_1, n_2, d_2); // деление
	float_type(n_1, d_1, n_2, d_2); //float type
}

void Rational::set(char a[], char b[]){
	n_1 = make_numerator(a);
	d_1 = make_denominator(a);
	n_2 = make_numerator(b);
	d_2 = make_denominator(b);
}

void Rational::get() {
	cout << endl << n_1 << "/" << d_1;
	cout << endl << n_2 << "/" << d_2 << endl;
}

int Rational::make_numerator(char a[]) {
	int m = 0;
	m = atoi(&a[0]);
	return m;
}

int Rational::make_denominator(char a[]) {
	int m = 0;
	for (int i = 0; i < 50; i++) {
		if (a[i] == '/') {
			m = atoi(&a[i + 1]);
			break;
		}
	}
	return m;
}

int Rational::nod(int x, int y) {
	if (y == 0)
		return x;
	return nod(y, x % y);
}

void Rational::check_reduction(int& n, int& d) {
	int tmp = nod(n, d);
	n /= tmp;
	d /= tmp;
}

void Rational::sum(int& n_1, int& d_1, int& n_2, int& d_2) {
	int d_tmp = 0, n_tmp = 0;
	n_tmp = (n_1 * d_2) + (n_2 * d_1);
	d_tmp = d_1 * d_2;
	check_reduction(n_tmp, d_tmp);
	cout <<endl<< "Summary: " << n_tmp << "/" << d_tmp << endl;
}

void Rational::subration(int& n_1, int& d_1, int& n_2, int& d_2) {
	int d_tmp = 0, n_tmp = 0;
	n_tmp = (n_1 * d_2) - (n_2 * d_1);
	d_tmp = d_1 * d_2;
	check_reduction(n_tmp, d_tmp);
	cout << endl << "Subratiom: " << n_tmp << "/" << d_tmp << endl;
}

void Rational::multiplication(int& n_1, int& d_1, int& n_2, int& d_2) {
	int d_tmp = 0, n_tmp = 0;
	n_tmp = n_1 * n_2;
	d_tmp = d_1 * d_2;
	check_reduction(n_tmp, d_tmp);
	cout << endl << "Multiplication: " << n_tmp << "/" << d_tmp << endl;
}

void Rational::division(int& n_1, int& d_1, int& n_2, int& d_2) {
	int d_tmp = 0, n_tmp = 0;
	n_tmp = n_1 * d_2;
	d_tmp = d_1 * n_2;
	check_reduction(n_tmp, d_tmp);
	cout << endl << "Division: " << n_tmp << "/" << d_tmp << endl;
}

void Rational ::float_type(int& n_1, int& d_1, int& n_2, int& d_2) {
	float num_1 = 0, num_2 = 0;
	num_1 = (float)n_1 / (float)d_1;
	num_2 = (float)n_2 / (float)d_2;
	cout << endl << "Float type: " << num_1 << " " << num_2 << endl;
}

int Rational:: error_check(char* a, char* b) {
	int flag = 0;
	for (int i = 0; i < 50; i++) {
		if ((a[i] == '/') && (b[i] == '/')) {
			flag++;
		}
	}
	if (flag == 0) {
		cout << endl << "Error" << endl;
		return -1;
	}
	else
		return 0;
}

