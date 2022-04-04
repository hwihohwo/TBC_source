#include <stdio.h>

/*
	Function call has overhead
	- set up the call, pass arguments, jump to the function code, and return.

	inline function specifier
	- Suggests inline replacements.

	Inline funcions should be short.
	A function with internal linkage can be made inline. (GCC, clang)
	You can't take its address.
*/

inline int foo()
{
	return 5;
}

// Driver code
int main()
{
	int ret;

	// inline function call
	ret = foo();	// 내가 직접했을때 release모드에서만 inline이 작동함. 버전에 의한 차이..?

	printf("Output is: %d\n", ret);
	return 0;
}