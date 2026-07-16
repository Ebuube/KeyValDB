#include "unity.h"
#include "lists.h"

TEST_SOURCE_FILE("src/linked_list/print_list.c")
TEST_SOURCE_FILE("src/linked_list/add_node.c")

/* Called before each test */
void setUp(void)
{
}

/* Called after each test */
void tearDown(void)
{
}

/**
 * test_print_empty_list - Test print empty list returns 0
 */
void test_print_empty_list(void)
{
	list_t *head = NULL;
	int count = 0;

	count = print_list(head);

	TEST_ASSERT_EQUAL_INT(0, count);
}

/*
 * test_print_single_node - Test print single node returns 1
 */
void test_print_single_node(void)
{
	list_t *head = NULL;

	add_node(&head, "key:1", "value:1");

	TEST_ASSERT_EQUAL_INT(1, print_list(head));
}

/**
 * test_print_non_empty_list - Test print non-empty list returns correct count
 */
void test_print_non_empty_list(void)
{
	list_t *head = NULL;
	int count = 2;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");


	TEST_ASSERT_EQUAL_INT(count, print_list(head));
}

/**
 * test_print_very_long_list - Test print list of about 100 nodes returns correct count
 */
void test_print_very_long_list(void)
{
	list_t *head = NULL;
	char key[8], value[8];
	int count = 100, i = 0;

	for (i = 0; i < count; i++)
	{
		sprintf(key, "key:%d", i);
		sprintf(value, "value:%d", i);
		add_node(&head, key, value);
	}

	TEST_ASSERT_EQUAL_INT(count, print_list(head));
}
