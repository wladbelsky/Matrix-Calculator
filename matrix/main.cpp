#include <iostream>
#include "matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	
	srand(time(NULL));
	matrix m1(3,4);
	m1.rnd(0, 10);
	matrix m2(4,1);
	m2.rnd(0, 10);
	cout << "Matrix 1:\n" << m1 << endl;
	cout << "Matrix 2:\n" << m2 << endl;
	matrix m3 = m1 * m2;
	cout << m1 * m2 << endl;
	m3.get();
	//cout << "m1 + m2 = \n" << m1 + m2 << endl;
	//cout << "m1 - m2 = \n" << m1 - m2 << endl;
	//cout << "m1 * m2 = \n" << m1 * m2 << endl;
	//cout << "Matrix 1:" << endl;
	//matrix m(3, 3);
	//m.rnd(0, 10);
	//cout << m;
	////m.get();
	//cout << "Determinant of Matrix 1: " << m.getDet() << endl;
	//m.algExt().getFloat();
	//cout << endl;
	//m.reversed().getFloat();
	//m *= m.reversed();
	//cout << endl;
	//m.getFloat();
	//cout << endl;
	//
	//cout << "Matrix 2:" << endl;
	//matrix x(4, 4);
	//x.rnd(0, 10);
	//x.get();
	//cout << "Determinant of Matrix 2: " << x.getDet() << endl;
	//x.algExt().getFloat();
	//cout << endl;
	//x.reversed().getFloat();
	//x *= x.reversed();
	//cout << endl;
	//x.get();
	system("pause");

	return 0;
}