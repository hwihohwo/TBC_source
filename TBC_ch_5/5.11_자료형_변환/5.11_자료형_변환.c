#include <stdio.h>

int main()
{
	/*promotions in assignments*/
	short s = 64;
	int i = s;		//작은 변수형을 큰 변수형에 대입은 문제생기지 않음.

	float f = 3.14f;
	double d = f;	// 위의 정수형과 마찬가지.

	/*demotion in assignments*/
	d = 1.25;
	f = 1.25;	// double과 float모두 정밀하게 표현가능해서 요류 발생하지 않음.	
	//f = 1.123;

	/*ranking of types in operations*/
	// long double > double > float, 실수가 정수보다 랭킹이 높다.
	// unsigned long long, long long
	// unsigned long, long
	// unsigned, int
	// short int, unsigned short int
	// signed char,  char, unsigned char
	//_Bool
	//Ref: Google 'Integer conversion rank'
	d = f + 1.234;
	f = f + 1.234;	//해당 expression의 값은 double이다.

	/*automatic promotion of function arguments*/
	// 1. Funcions without prototypes
	// 2. Variadic functions (ellipsis)

	/*casting operatiors*/   // 프로그래머의 의도를 명확히 표기하기 위해서는 확실하게 표기해주는게 좋음.
	d = (double)3.14f;
	i = 1.6 + 1.7;			 // i = 3
	i = (int)1.6 + (int)1.7; // i = 2

	/*more examples*/
	char c;
	f = i = c = 'A'; //65.  int와 float는 유효숫자 갯수가 다르다.
	printf("%c %d %f\n", c, i, f);
	c = c + 2;		 // 'C', 67
	i = f + 2 * c;	 // 65.0f + 2 * 67
	printf("%c %d %f\n", c, i, f); // 199
	c = 1106; // demolition, 1106 = 0b10001010010, 0b01010010 = 1106 % 256 = 82 = 'R'
	printf("%c\n", c);
	c = 83.99;
	printf("%c\n", c);

	return 0;


}