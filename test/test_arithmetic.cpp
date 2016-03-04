#include <gtest.h>
#include "arithmetic.h"
TEST(TArithmetic, check_brackets_return_false_if_extra_opening)
{
	char s[] = "5+3*((a+b)";
	EXPECT_EQ(0, CheckBrackets(s));
}
TEST(TArithmetic, check_brackets_return_false_if_extra_closing)
{
	char s[] = "5+3*(a+b))";
	EXPECT_EQ(0, CheckBrackets(s));
}
TEST(TArithmetic, check_brackets_return_false_if_first_closing)
{
	char s[] = "5+3*)(a+b)";
	EXPECT_EQ(0, CheckBrackets(s));
}
TEST(TArithmetic, check_operations_return_false_if_expr_starts_with_it)
{
	char s[] = "+5+3*(a+b)";
	EXPECT_EQ(0, CheckOperations(s));
}
TEST(TArithmetic, check_operations_return_false_if_expr_ends_with_it)
{
	char s[] = "5+3*(a+b)-";
	EXPECT_EQ(0, CheckOperations(s));
}
TEST(TArithmetic, check_operations_return_false_if_they_stand_together)
{
	char s[] = "5+3*(a+-b)";
	EXPECT_EQ(0, CheckOperationsStandTogether(s));
}
TEST(TArithmetic, check_operands_return_false_if_they_stand_together)
{
	char s[] = "5+3*(a+cb)";
	EXPECT_EQ(0, CheckOperandsStandTogether(s));
}
TEST(TArithmetic, check_operands_return_false_if_they_stand_after_brackets)
{
	char s[] = "5+3*(a+b)c";
	EXPECT_EQ(0, CheckOperandBracketStandTogether(s));
}
TEST(TArithmetic, check_operands_return_false_if_they_stand_before_brackets)
{
	char s[] = "5+3*c(a+b)";
	EXPECT_EQ(0, CheckOperandBracketStandTogether(s));
}
TEST(TArithmetic, Partition_Into_Tokens)
{
	char s[] = "3.2+c-d";
	PartitionIntoTokens(s);
}
TEST(TArithmetic, priority)
{
	char s = '+';
	EXPECT_EQ(2, Priority(s));
}
TEST(TArithmetic, To_Polish)
{
	char s[] = "32 + c - d";
	ToPolish(s);
}
TEST(TArithmetic, Polish_Result)
{
	char s[] = "a b -";
	PolishFindResult(s);
}

