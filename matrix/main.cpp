#include <iostream>
#include "matrix.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{	
	srand(time(NULL));

	matrix m1(1, 4);
	m1.set();

	matrix m2(1, 4);
	m2.set();

	float** example = new float* { new float[4]{1,2,3,4} };
	matrix m3(1, 4, example);



	cout << "Matrix 1:\n" << m1 << endl;
	cout << "Matrix 2:\n" << m2 << endl;
	cout << "Matrix 2:\n" << m3 << endl;


	try
	{
		cout << "Result:" << endl << m1 + m2 << endl;
	}
	catch (const std::exception&)
	{
		cout << endl << "Matrices must be the same size for this operation" << endl;
	}
	
	
	system("pause");

	return 0;
}