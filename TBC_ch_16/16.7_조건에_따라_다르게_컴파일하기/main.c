#include <stdio.h>

/*
	#define, #undef, #if , #ifdef, #else, #elif, #endif
*/

/*
	#undef
*/

#define LIMIT 400
//#undef LIMIT	// It's ok to undefine previously NOT defined macro.

#undef NON_DEFINED

int main()
{
	printf("%d\n", LIMIT);

	return 0;
} 