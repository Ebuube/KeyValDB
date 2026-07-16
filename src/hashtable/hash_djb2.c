#include "hashtable.h"

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
