#pragma once

class matrix
{
	float **matx;
public:
	unsigned short int rows;	//Stroki
	unsigned short int columns;	//Kolonki

	//constructors
	matrix();
	matrix(int,int);
	~matrix();
	matrix(const matrix &);
	matrix(int, int, float**);

	//operators overload
	matrix operator+(const matrix &);
	matrix operator+=(const matrix &);
	matrix operator-(const matrix &);
	matrix operator-=(const matrix &);
	matrix operator=(const matrix &);


	matrix operator*(const int &);		//int operators
	matrix operator*=(const int &);
	matrix operator*(const float &);		//float operators
	matrix operator*=(const float &);	
	matrix operator*(const matrix &);		
	matrix operator*=(const matrix &);

	friend matrix operator*(int, const matrix &); //out of class overload!
	friend matrix operator*(float, const matrix &); //float variant
	friend std::ostream& operator<<(std::ostream &, const matrix &);
	//funcs
	void set();
	float& set(int, int);
	void get();
	void getFloat();
	float get(int, int) const;
	void rnd(int, int);
	matrix getMinor(int, int);
	int getDet();
	matrix transposed();
	matrix algExt();
	matrix reversed();
	float findMax();
	float findMin();
};
