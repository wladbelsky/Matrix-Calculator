#include <iostream>
#include "matrix.h"
#include <cstdlib>
#include <cmath>
#include <stdexcept>

using namespace std;

matrix::matrix()
{
	cout << "rows: ";
	cin >> rows;
	cout << "columns: ";
	cin >> columns;

	matx = new float *[rows];
	for(int i = 0; i < rows; i++)
		matx[i] = new float[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matx[i][j] = 0;
}

matrix::matrix(int r, int c)
{
	rows = r;
	columns = c;

	matx = new float *[rows];
	for(int i = 0; i < rows; i++)
		matx[i] = new float[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matx[i][j] = 0;
}

matrix::~matrix()
{
	for(int i = 0; i < rows; i++)
		delete[] matx[i];
	delete[] matx;
}

matrix::matrix(const matrix &x)
{
	rows = x.rows;
	columns = x.columns;

	matx = new float *[rows];
	for(int i = 0; i < rows; i++)
		matx[i] = new float[columns];	

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			set(i,j) = x.get(i,j);
}

matrix::matrix(int r, int c, float** arr)
{
	rows = r;
	columns = c;

	matx = new float* [rows];
	for (int i = 0; i < rows; i++)
		matx[i] = new float[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			set(i, j) = arr[i][j];
}

//operator overload
matrix matrix::operator+(const matrix &x)
{
	matrix tmp(rows, columns);
	

	if(x.rows == rows && x.columns == columns)
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				tmp.set(i,j) = get(i,j) + x.get(i,j);	
	else
		throw invalid_argument("incompatible size");

	return tmp;
}


matrix matrix::operator+=(const matrix &x)
{

	if(x.rows == rows && x.columns == columns)
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				set(i,j) += x.get(i,j);	

	return *this;
}


bool operator==(const matrix& x, const matrix& y)
{

	if (x.rows == y.rows && x.columns == y.columns)
	{
		for (int i = 0; i < y.rows; i++)
			for (int j = 0; j < y.columns; j++)
				if (!(y.get(i, j) == x.get(i, j)))
					return false;
	}
	else
		return false;

	return true;
}


matrix matrix::operator-(const matrix &x)
{
	matrix tmp(rows, columns);

	if(x.rows == rows && x.columns == columns)
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				tmp.set(i,j) = get(i,j) - x.get(i,j);
	else
		throw runtime_error("incompatible size");

	return tmp;
}

matrix matrix::operator-=(const matrix &x)
{
	matrix tmp(rows, columns);

	if(x.rows == rows && x.columns == columns)
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				set(i,j) -= x.get(i,j);				

	return *this;
}

matrix matrix::operator=(const matrix &x) 
{
	rows = x.rows;
	columns = x.columns;

	matx = new float *[rows];
	for(int i = 0; i < rows; i++)
		matx[i] = new float[columns];	

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			set(i,j) = x.get(i,j);

	return *this;
}

matrix matrix::operator*(const int &x)
{
	matrix tmp(rows, columns);

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			tmp.set(i,j) = get(i,j) * x;
	return tmp;
}

matrix matrix::operator*(const float &x)
{
	matrix tmp(rows, columns);

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			tmp.set(i,j) = get(i,j) * x;
	return tmp;
}


//Implement overload outside the class
matrix operator*(int num, const matrix &x)
{
	matrix tmp(x.rows, x.columns);

	for(int i = 0; i < x.rows; i++)
		for(int j = 0; j < x.columns; j++)
			tmp.set(i,j) = x.get(i,j) * num;
	return tmp;
}

//float variant
matrix operator*(float num, const matrix &x)
{
	matrix tmp(x.rows, x.columns);

	for(int i = 0; i < x.rows; i++)
		for(int j = 0; j < x.columns; j++)
			tmp.set(i,j) = x.get(i,j) * num;
	return tmp;
}

matrix matrix::operator*(const matrix &x)
{
	matrix tmp(rows, x.columns);	

	if (x.rows == columns)
	{
		for(int resRow = 0; resRow < rows; resRow++)
			for(int resCol = 0; resCol < x.columns; resCol++)
				for (int col = 0; col < x.rows; col++)
				{
					tmp.set(resRow, resCol) += get(resRow, col) * x.get(col, resCol);
				}
	}		
	return tmp;
}

matrix matrix::operator*=(const int &x)
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			set(i,j) *= x;
	return *this;
}

matrix matrix::operator*=(const float &x)
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			set(i,j) *= x;
	return *this;
}

matrix matrix::operator*=(const matrix &x)
{
	matrix tmp(rows, x.columns);
		
	if (x.rows == columns)
	{
		for(int resRow = 0; resRow < rows; resRow++)
			for(int resCol = 0; resCol < x.columns; resCol++)
				for(int col = 0; col < x.rows; col++)
					tmp.set(resRow, resCol) += get(resRow, col) * x.get(col, resCol);
	}

	*this = tmp;

	return *this;
}

//cout
ostream& operator<<(ostream &os, const matrix &x)
{
	for(int i = 0; i < x.rows; i++)
	{
		for(int j = 0; j < x.columns; j++)
		{
			os.width(7);
			os.precision(2);
			os << x.get(i, j) << "|";
			
		}
		os << endl;
	}
	return os;
}

//setters&getters
void matrix::set()
{
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			cin >> matx[i][j];
}

float& matrix::set(int i, int j)
{
	return matx[i][j];
}

void matrix::get()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout.width(7);
			cout << round(matx[i][j]) << "|";
		}
		cout << endl;
	}
}

void matrix::getFloat()
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			cout.width(7);
			cout.precision(2);
			cout << fixed << matx[i][j] << "|";
		}
		cout << endl;
	}
}

float matrix::get(int i, int j) const
{
	return matx[i][j];
}

void matrix::rnd(int min, int max)
{
	max++;
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			set(i,j) = (rand() % (max - min)) + min;

}

matrix matrix::getMinor(int row, int col)
{
	matrix tmp(rows - 1, columns - 1);
	int imin, jmin;
	imin = 0;
	jmin = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++){ 
			if (i != row && j != col){
				tmp.set(imin, jmin) = get(i,j);
				jmin++;
			}
		}
		jmin = 0;
		if (i != row)
			imin++;		
	}

	return tmp;

}

int matrix::getDet()
{
	int det = 0;
	int k = 1;

	if(columns == rows)
	{
		if(rows == 1)
			det = get(0,0);
		if(rows == 2)
			det = (get(0,0) * get(1,1)) - (get(1,0) * get(0,1));
		if(rows >= 3)
		{
			matrix tmp(0,0);
			for (int i = 0; i < rows; i++)
			{
				tmp = getMinor(i, 0);
				det += k * get(i, 0) * tmp.getDet();
				k = -k;
			}
		}
	}

	return det;
}

matrix matrix::transposed()
{
	matrix tmp(columns, rows);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			tmp.set(j,i) = get(i,j);

	return tmp;
}

matrix matrix::algExt()
{
	matrix tmp(columns, rows);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
		{
			matrix minor = transposed().getMinor(i,j);
			if(minor.getDet())
				tmp.set(i,j) = pow(-1, i + j) * minor.getDet();
		}
	return tmp;
}

matrix matrix::reversed()
{
	matrix tmp = algExt();
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			tmp.set(i,j) = tmp.get(i,j)/getDet();

	return tmp;
}

float matrix::findMax()
{
	float max = get(0,0);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			if(get(i,j) < max)
				max = get(i,j);
	return max;
}

float matrix::findMin()
{
	float min = get(0,0);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < columns; j++)
			if(get(i,j) > min)
				min = get(i,j);
	return min;
}