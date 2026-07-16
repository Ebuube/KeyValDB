#include "unity.h"
#include "hashtable.h"

TEST_SOURCE_FILE("src/hashtable/ht_init.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_ht_init_custom_size - test that ht_init initializes a hash table with a custom size
 */
void test_ht_init_custom_size(void)
{
	hash_table_t *ht = ht_init(100);

	TEST_ASSERT_NOT_NULL(ht);
	TEST_ASSERT_NOT_NULL(ht->buckets);
	TEST_ASSERT_EQUAL_INT(100, ht->size);
}

/**
 * test_ht_every_bucket_null - test that ht_init initializes every bucket to NULL
 */
void test_ht_every_bucket_null(void)
{
	hash_table_t *ht = NULL;
	size_t i;

	ht = ht_init(10);

	TEST_ASSERT_NOT_NULL(ht);

	for (i = 0; i < ht->size; i++)
	{
		TEST_ASSERT_NULL(ht->buckets[i]);
	}
}

/**
 * test_ht_init_with_defult_size - test that ht_init initializes a hash table with the default size when size is 0
 */
void test_ht_init_with_default_size(void)
{
	hash_table_t *ht = NULL;

	ht = ht_init(0);

	TEST_ASSERT_NOT_NULL(ht);
	TEST_ASSERT_NOT_NULL(ht->buckets);
	TEST_ASSERT_EQUAL_INT(HT_DEFAULT_SIZE, ht->size);
}

/**
 * test_ht_tables_dont_share_memory - test that two hash tables initialized with ht_init do not share memory
 */
void test_ht_tables_dont_share_memory(void)
{
	hash_table_t *ht1 = NULL, *ht2 = NULL;

	ht1 = ht_init(10);
	ht2 = ht_init(10);

	TEST_ASSERT_NOT_NULL(ht1);
	TEST_ASSERT_NOT_NULL(ht2);

	TEST_ASSERT_TRUE(ht1 != ht2);
	TEST_ASSERT_TRUE(ht1->buckets != ht2->buckets);
}
