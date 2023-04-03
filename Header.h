#pragma once
class Rational {
private:
	int n_1, n_2;
	int d_1, d_2;

public:
	
	int error_check(char* a, char* b);
	void Functions();
	void set(char a[], char b[]);
	void get();
	int make_numerator(char a[]);
	int make_denominator(char a[]);
	int nod(int x, int y);
	void check_reduction(int& n, int& d); // ����������
	void sum(int& n_1, int& d_1, int& n_2, int& d_2); // ��������
	void subration(int& n_1, int& d_1, int& n_2, int& d_2); // ���������
	void multiplication(int& n_1, int& d_1, int& n_2, int& d_2); // ���������
	void division(int& n_1, int& d_1, int& n_2, int& d_2); // �������
	void float_type(int& n_1, int& d_1, int& n_2, int& d_2); //float type
	
};
