#include <stdio.h>
#include <stdlib.h>

/*
	ABCDEF ....
	Current position 0 and read -> A
	Current position 1 and read -> B
	...
*/

int main()
{
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_END */

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* fsetpos(), fgetpos() */
	//file이 어마어마하게 클 경우.

	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);		//returns 0 ok. fseek과 유사
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	fgetpos(fp, &pt);		//returns 0 ok  ftell과 유사
	printf("%lld\n", pt);	//NOTE: not meant to be read directly
	// fpos_t의 format specifier는 의도적으로 지정되어있지 않음. 예제는 보여주기 위해서 강제로 출력한것.
	return 0;
}