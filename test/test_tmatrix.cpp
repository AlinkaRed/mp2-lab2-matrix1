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
	TMatrix<int> v(3);
	TMatrix<int> v1(v);
	int s = v == v1;
	EXPECT_EQ(s, 1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(v);
	EXPECT_EQ(3, v.GetSize());
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][0] = 4;

	EXPECT_EQ(4, v[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[-9][1] = 4);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[1000002] = 4);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	ASSERT_NO_THROW(v = v);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(4);
	ASSERT_NO_THROW(v = v1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(5);
	v1 = v;
	EXPECT_EQ(4, v1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(4);
	TMatrix<int> v1(5);
	ASSERT_NO_THROW(v = v1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) {
			v1[i][j] = i;
			v[i][j] = i;
		}
	}
	int s = v == v1;
	EXPECT_EQ(s, 1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v(3);
	int s = v == v;
	EXPECT_EQ(s, 1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(4);
	int s = v == v1;
	EXPECT_EQ(s, 0);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(3);
	TMatrix<int> v2(3);
	TMatrix<int> v3(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) {
			v1[i][j] = i + 3;
			v[i][j] = i;
			v2[i][j] = i + i + 3;
		}
	}
	v3 = v1 + v;
	int s = v2 == v3;
	EXPECT_EQ(s, 1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(4);
	TMatrix<int> v3(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) {
			v1[i] = i + 3;
			v[i] = i;
		}
	}
	ASSERT_ANY_THROW(v3 = v1 + v);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(3);
	TMatrix<int> v2(3);
	TMatrix<int> v3(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) {
			v1[i][j] = i + 3;
			v[i][j] = i;
			v2[i][j] = 3;
		}
	}
	v3 = v1 - v;
	int s = v2 == v3;
	EXPECT_EQ(s, 1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> v(3);
	TMatrix<int> v1(4);
	TMatrix<int> v3(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++) {
			v1[i] = i + 3;
			v[i] = i;
		}
	}
	ASSERT_ANY_THROW(v3 = v1 - v);
}

