#include <stdio.h>
#include <inttypes.h>

int main()
{
	/*multiple inputs with bland separators*/
	//int i;
	//float f;
	//char str[30];
	//scanf("%d %f %s", &i, &f, str); //Note % is absent in front of str
	//printf("%d %f %s\n", i, f, str);

	/*character*/
	//char c;
	//scanf("%c", &c);		// try blank. 문자로 입력받을때는 빈칸도 문자로 입력받음.
	//printf("%i\n", c);	// blank is 32

	/*Unsigned as signed*/
	//unsigned i;
	//scanf("%i", &i);		// try nagative number
	//printf("%i\n", i);

	/*Unsigned as unsigned*/
	//unsigned i2;
	//scanf("%u", &i2);		// try nagative number
	//printf("%u\n", i2);

	/*floating point numbers*/
	//	l for double for %f, %e, %E, %g
	//double d = 0.0;
	//scanf("%lf", &d);	// lf, try E notation.(scientific notation)
	////printf와는 다르게 double은 lf로만 받을 수 있음.
	//printf("%f\n", d);	// f

	/*Width*/
	//char str[30];
	//scanf("%5s", str);	//width
	//printf("%s\n", str);

	/*h modifier*/
	//char i;
	//scanf("%hhd", &i);	// try large numbers
	//printf("%i\n", i);

	/*integer with characters*/
	//int i;
	//scanf("%i", &i);		//try '123ab', '123a456'. 문자를 만나면 읽어들이기를 끝냄.
	//printf("%i\n", i);

	/*j modifier*/
	/*intmax_t i;
	scanf("%ji", &i);
	printf("%ji", i);*/

	/*Regular characters*/
	//int a, b;
	//scanf("%d,%d", &a, &b);	// try blank separator only
	///*scanf("%d ,%d", &a, &b);
	//scanf("%d, %d", &a, &b);
	//scanf("%d , %d", &a, &b);
	//scanf("%d-%d", &a, &b);
	//scanf("%dA%d", &a, &b);*/
	//printf("%d %d\n", a, b);

	/*char receives blank*/
	//int a, b;
	//char c;
	//scanf("%d%c%d", &a, &c, &b);	// try 123 456 (blank)
	//printf("%d|%c|%d", a, c, b);	// | is separator

	// sentences?, getchar(), fgets(), etc.

	/*return vlaue of scanf()*/
	/*int a, b;
	int i = scanf("%d%d", &a, &b);
	printf("%d", i);*/

	///* *modifier for printf()*/
	//int i = 123;
	//int width = 5;				// from script fole, scanf, etc.
	//printf("Input width : ");
	//scanf("%d", &width);
	//printf("%*d\n", width, i);	// width를 더 유연하게 사용할 수 있다.

	/* *modifier for scanf()*/
	int i;
	scanf("%*d%*d%d", &i);			//scanf에서 *는 입력은 받지만 무시해버림. 
	printf("Your third input = %d", i);

	return 0;
}