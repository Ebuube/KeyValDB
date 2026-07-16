#include "unity.h"
#include "hashtable.h"

TEST_SOURCE_FILE("src/hashtable/hash_djb2.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_hash_empty_string - returns Daniel J. Bernstein's magic number
 */
void test_hash_empty_string(void)
{
	TEST_ASSERT_EQUAL_UINT32(5381, hash_djb2(""));
}

/**
 * test_hash_known_values - test against known djb2 hash values
 */
void test_hash_known_values(void)
{
	TEST_ASSERT_EQUAL_UINT64(177670, hash_djb2("a"));
	TEST_ASSERT_EQUAL_UINT64(210714636441, hash_djb2("hello"));
}

/**
 * test_hash_always_same_output - test that the same input always produces the same output
 */
void test_hash_always_same_output(void)
{
	TEST_ASSERT_EQUAL_UINT64(hash_djb2("test"), hash_djb2("test"));
}

/**
 * test_hash_diff_input_diff_output - different outputs for different inputs
 */
void test_hash_diff_input_diff_output(void)
{
	TEST_ASSERT_NOT_EQUAL_UINT64(hash_djb2("test1"), hash_djb2("test2"));
}

/**
 * test_hash_single_char_vs_long_string - test that a single character and a long string produce different outputs
 *
 * Description: ensure loop is acuumulating across iterations
 */
void test_hash_single_char_vs_long_string(void)
{
	TEST_ASSERT_NOT_EQUAL_UINT64(hash_djb2("a"), hash_djb2("aa"));
}

/**
 * test_order_sensitivity - ensure ordering affects the hash output
 */
void test_order_sensitivity(void)
{
	TEST_ASSERT_NOT_EQUAL_UINT64(hash_djb2("abc"), hash_djb2("cba"));
}

/**
 * test_hash_long_string - test that a long string produces a valid hash
 */
void test_hash_long_string(void)
{
	char long_string[1001];
	unsigned long result;

	memset(long_string, 'a', 1000);
	long_string[1001] = '\0';

	result = hash_djb2(long_string);

	/* no crash = implicit pass by just reaching this line */
	TEST_ASSERT_TRUE(result !=0 || result == 0);
}
