#include "pch.h"
#include "../matrix/matrix.cpp"

TEST(matrix_addition, same_size)
{
	float** manual_input1 = new float* { new float[4]{1,2,3,4} };
	matrix m1(1, 4, manual_input1);

	float** manual_input2 = new float* { new float[4]{4,3,2,1} };
	matrix m2(1, 4, manual_input2);

	auto test_res = m1 + m2;

	float** example = new float* { new float[4]{5,5,5,5} };
	matrix ref_result(1, 4, example);
	


	ASSERT_EQ(ref_result, test_res);
}

TEST(matrix_addition, incompatible_size)
{
	//Arrange
	matrix m1(3, 4);
	m1.rnd(0, 10);
	matrix m2(1, 4);
	m2.rnd(0, 10);

	//Act


	//Assert
	ASSERT_THROW(m1 + m2, invalid_argument);
}
