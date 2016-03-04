#include "stack.h"
#include <gtest.h>


TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> s(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s(10);

	ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, can_put_elem)
{
	TStack<int> s(10);

	ASSERT_NO_THROW(s.Put(1));
}
TEST(TStack, cant_put_elem_if_stack_is_full) {
	TStack<int> s(10);
	for (int i = 0; i < 10; i++)
	{
		s.Put(i);
	}
	ASSERT_ANY_THROW(s.Put(1));
}
TEST(TStack, cant_get_elem_if_stack_is_empty) 
{
	TStack<int> s(10);

	ASSERT_ANY_THROW(s.GetTopElem());
}
TEST(TStack, can_get_elem)
{
	TStack<int> s(10);
	s.Put(1);
	EXPECT_EQ(1, s.GetDelTopElem());
}
TEST(TStack, can_get_and_not_delete_elem)
{
	TStack<int> s(10);
	s.Put(1);
	EXPECT_EQ(1, s.GetTopElem());
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> s(10);
	s.Put(1);
	TStack<int> s1(s);

	EXPECT_EQ(s, s1);
}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> s(10);
	s.Put(1);
	TStack<int> s1(s);
	s.Put(2);
	EXPECT_NE(s, s1);
}

TEST(TStack, assigned_stacks_are_equal)
{
	TStack<int> s(5), s1(5);
	s.Put(1);
	s.Put(2);
	s1 = s;
	EXPECT_EQ(s, s1);
}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(5);
	s.Put(1);
	s.Put(2);
	s = s;
	EXPECT_EQ(2, s.GetDelTopElem());
	EXPECT_EQ(1, s.GetDelTopElem());
}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s(5);
	s.Put(1);
	s.Put(2);
	TStack<int> s1 = s;
	EXPECT_EQ(2, s1.GetDelTopElem());
	EXPECT_EQ(1, s1.GetDelTopElem());
}
//TEST(TStack, can_assign_stacks_of_different_size)
//{
//	TStack<int> s(5), s1(7);
//	s1 = s;
//
//	EXPECT_EQ(s, s1);
//}
TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> s1(10), s2(10);
	s1.Put(1);
	s2 = s1;
	EXPECT_EQ(s1, s2);
}
TEST(TStack, compare_stack_with_itself_return_true)
{
	TStack<int> s(10);
	s.Put(1);
	EXPECT_EQ(s, s);
}
TEST(TStack, stacks_with_different_size_are_not_equal)
{
	TStack<int> s1(5), s2(2);
	EXPECT_NE(s1, s2);
}
TEST(TStack, different_stacks_not_equal)
{
	TStack<int> s1(10), s2(10);
	s1.Put(1);
	s2.Put(2);
	EXPECT_NE(s1, s2);
}