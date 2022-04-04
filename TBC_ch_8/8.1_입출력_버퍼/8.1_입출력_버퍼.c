#include <stdio.h>
#include <conio.h>//Windows, _getch(), _getche()
							 //버퍼를 사용하지 않는 함수.
int main()
{
	char c;

	while ((c = _getch()) != '.') 
		putchar(c);

	return 0;
}
