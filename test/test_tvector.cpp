#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
		TVector<int> v(10);
		TVector<int> b(v);

		EXPECT_EQ(v, b);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> b(v);
	b[4] = 3;

	EXPECT_NE(v[4],3);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(10,2);
	
	ASSERT_ANY_THROW(v[-2] = 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(15);

	ASSERT_ANY_THROW(v[17] = 3);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(17);
	TVector<int> b(17);
	b[1] = 1;

	ASSERT_NO_THROW(v = b);
}

TEST(TVector, assign_operator_change_vector_size)
{
	const int size = 10;
    TVector<int> v(size);
    TVector<int> b(size+1);

	v = b;
	EXPECT_EQ(v, b);
}

TEST(TVector, can_assign_vectors_of_different_size)
{

	TVector<int> v(3);
	TVector<int> b(13);
	
	ASSERT_NO_THROW(v = b);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(13);
	TVector<int> b(13);
	EXPECT_EQ(v, b);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	
	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(10);
	TVector<int> b(9);
	EXPECT_NE(v,b);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(15);
	v[3] = 4;
	int a = 10;
	TVector<int> b(v + a);
	EXPECT_EQ( b[3] , 14);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(7);
	v[2] = 8;
	int a = 2;
	TVector<int> b(v - a);
	EXPECT_EQ(b[2], 6);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(11);
	v[10] =16 ;
	int a = 3;
	TVector<int> b(v * a);
	EXPECT_EQ(b[10], 48);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(7);
	TVector<int> k(7);
	ASSERT_NO_THROW(TVector<int> a(v + k));
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(7);
	TVector<int> k(8);
	
	ASSERT_ANY_THROW(TVector<int> a(v + k));
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{

	TVector<int> v(5);
	TVector<int> k(5);
	ASSERT_NO_THROW(TVector<int> a(v - k));
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(14);
	TVector<int> k(3);

	ASSERT_ANY_THROW(TVector<int> a(v - k));
 
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(16);
	TVector<int> k(16);
	ASSERT_NO_THROW(TVector<int> a(v * k));
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(4);
	TVector<int> k(12);

	ASSERT_ANY_THROW(TVector<int> a(v * k));
}

