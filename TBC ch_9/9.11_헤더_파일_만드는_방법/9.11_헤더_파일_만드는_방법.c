//#include <stdio.h>
//My_print_functions.h에 stdio.h에 include되어있기때문에
//따로 해주지 않아도 됨.
#include "My_print_functions.h"
#include <stdio.h>

int main()
{
	print_hello();
	print_hi();
	print_hello();
	print_hi();
	print_str("No one lives forever.");
	print_str("Valar morghulis");

	printf("Hello!");

	return 0;
}

//새로운 filter를 만들어서 코드들 정리할 수 있다.
//실제로 폴더가 생기는 것은 아님.