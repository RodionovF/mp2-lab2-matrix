#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> v(15);
	TMatrix<int> b(v);

	EXPECT_EQ(v, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(15);
	TMatrix<int> b(v);
	b[1][3] = 4;
	EXPECT_NE(v[1][3], 4);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(16);
	EXPECT_EQ(16, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[2][3] = 3;
	EXPECT_EQ(m[2][3], 3);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(7);
	ASSERT_ANY_THROW(m[1][-2] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(16);
	ASSERT_ANY_THROW(m[17][5] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(10);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(15);
	TMatrix<int> m(15);
	m[1][2] = 3;
	ASSERT_NO_THROW(v = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size = 15;
	TMatrix<int> v(size);
	TMatrix<int> b(size+1);
	v = b;
	EXPECT_EQ(v, b);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(11);
	TMatrix<int> m(4);
	m[1][2] = 16;
	ASSERT_NO_THROW(v = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{

	TMatrix<int> v(18);
	TMatrix<int> m(18);
	v[1][14] = 16;
	m[1][14] = 16;
	EXPECT_EQ(v, m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(9);

	EXPECT_EQ(v, v);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(9);
	TMatrix<int> m(19);
	EXPECT_NE(v, m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(11);
	TMatrix<int> m(11);
	
	ASSERT_NO_THROW(TMatrix<int> p(v + m));
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(13);
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(TMatrix<int> p(v + m));
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(16);
	TMatrix<int> m(16);

	ASSERT_NO_THROW(TMatrix<int> p(v - m));
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(23);
	TMatrix<int> m(15);

	ASSERT_ANY_THROW(TMatrix<int> p(v - m));
}

