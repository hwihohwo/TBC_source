#include <stdio.h>
#include <stdlib.h>

/*
	rand(), srand(), malloc(), free(), ...
*/

void goodbye(void)
{
	printf("Goodbye\n");
}

void thankyou(void)
{
	printf("Thankyou\n");
}

int main()
{
	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou); // 내부적으로 함수 포인터의 목록을 가지고 있다.

	while (getchar() != '\n') {};

	printf("Goodbye message ?\n");
	if (getchar() == 'y')
		atexit(goodbye);

	/*
		exit(0);
	*/

	/*
		qsort();
	*/

	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdnoreturn.h>
//
//// causes undefined behavior if i <= 0
//// exits if i > 0
//_Noreturn void stop_now(int i) // or _Noreturn void stop_now(int i)
//{
//	if (i > 0) exit(i);
//	exit(i);
//}
//
//int main()
//{
//	puts("Preparing to stop...");
//	stop_now(0);
//	puts("This code is never executed.");
//
//	return 0;
//}
