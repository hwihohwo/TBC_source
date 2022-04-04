#include <stdio.h>
/*
	Linkage

	Variables with block scope, function scope, or function prototype scope
	- No linkage

	File scope variables
	- External or internal linkage
*/

// translation unit

int el;				// file scope with external linkage (global variable)
static int il;		// file scope with internal linkage
//다른 파일에서 사용할 수 없다.
void testLinkage();	//prototype으로 선언하는 것도 linking하는 구조.

int main()
{
	el = 1024;

	testLinkage();

	printf("%d\n", el);

	return 0;
}
