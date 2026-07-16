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

void test_print_empty_list(void)
{
	list_t *head = NULL;
	int count = 0;

	count = print_list(head);

	TEST_ASSERT_EQUAL_INT(0, count);
}

void test_print_non_empty_list(void)
{
	list_t *head = NULL;
	int count = 0;

	add_node(&head, "key:1", "value:1");
	add_node(&head, "key:2", "value:2");

	count = print_list(head);

	TEST_ASSERT_EQUAL_INT(2, count);
}

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
