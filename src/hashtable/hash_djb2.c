#include "hashtable.h"

/**
 * hash_djb2 - compute hash using Dnaiel J. Bernstein's algorithm
 * @str: string to hash
 *
 * Description: does not fail when str is upto 1000 chars long
 * order affects hash value
 * Return: hash value
 */
unsigned long hash_djb2(const char *str)
{
	unsigned long hash = 5381;	/* Daniel J. Bernstein's magic number */
	int c;

	while ((c = *str++))
	{
		/**
		 * Same as (hash * 33) + c but easier for CPU
		 * because bit-shift is easier than full multiplication instruction
		 */
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}
