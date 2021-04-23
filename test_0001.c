#include <unity.h>

#include <stdio.h>
#include "calculator.h"

#define epsilon 0.001

void test_valid_addition(void)
{
	/* I am assuming there is a difference between positive and negative values */

	/* Two positive arguments */
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 3.0, calculate(1.0, 2.0, '+'));

	/* Two negative arguments */
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -5.0, calculate(-3.0, -2.0, '+'));
    
	/* First argument negative and output negative or positive */
	TEST_ASSERT_FLOAT_WITHIN(epsilon, -1.0, calculate(-3.0, 2.0, '+'));
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 1.0, calculate(-3.0, 4.0, '+'));
	
	/* Second argument negative and output negative or poitive*/
    TEST_ASSERT_FLOAT_WITHIN(epsilon, 2.0, calculate(3.0, -1.0, '+'));
    TEST_ASSERT_FLOAT_WITHIN(epsilon, -1.0, calculate(3.0, -4.0, '+'));
}

void test_invalid_addition(void)
{
	TEST_ASSERT_FLOAT_IS_NAN(calculate(NAN, 4, '+'));
	TEST_ASSERT_FLOAT_IS_NAN(calculate(2, NAN, '+'));

	TEST_ASSERT_FLOAT_IS_INF(calculate(INFINITY, 1, '+'));
	TEST_ASSERT_FLOAT_IS_INF(calculate(1, INFINITY, '+'));
}

void test_invalid_operator(void)
{
	TEST_ASSERT_FLOAT_IS_NAN(calculate(1, 3, 'a'));
}

void test_invalid_division(void)
{
	TEST_ASSERT_FLOAT_IS_INF(calculate(3, 0, '/'));
	TEST_ASSERT_FLOAT_IS_NEG_INF(calculate(-3, 0, '/'));
}

void setUp(void)
{
}

void tearDown(void)
{
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_valid_addition);
	RUN_TEST(test_invalid_addition);
	RUN_TEST(test_invalid_operator);
	RUN_TEST(test_invalid_division);

    return UNITY_END();
}
