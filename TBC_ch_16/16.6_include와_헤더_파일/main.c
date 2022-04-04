#include <stdio.h> // 컴파일러가 위치를 알고있는 헤더파일(ex. 표준 라이브러리들)
#include "my_functions.h"
#include "my_structures.h"
#include "my_macros.h" // path
//#include "C:\Users\82109\source\repos\TBC_ch_16\16.6_include와_헤더_파일\my_headers\my_macros.h"
// 가능은 함.
// 보통 표준 라이브러리나 오픈소스등의 라이브러리를 사용만 하면 <>
// 직접만든 라이브러리는 ""로 보통 사용.


extern int status;

int main()
{
	printf("PI = %f\n", PI);

	printf("%p %d\n", &status, status);

	print_status();

	printf("%d\n", multiply(51, 2));

	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);

	print_address();

	patient_info james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };

	return 0;
}