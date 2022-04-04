#include <stdio.h>

int main()
{
	// type qualifiers: const, volatile, ...

	const double PI = 3.14159;
	//PI = 2.14159;

	const int arr[5] = { 1, 2, 3, 4, 5 };
	//arr[1] = 123;

	const double arr2[3] = { 1.0, 2.0, 3.0 };
	//arr2[0] = 100.0;

	const double* const pd = arr2;
	//앞의 const는 포인터가 가리키는 주소의 객체를 못바꾸게 함.
	//뒤의 const는 포인터가 저장하는 주소자체를 바꾸지 못하게 한다.
	//*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
	//pd[2] = 1024.0;	// arr2[2] = 1024.0;

	printf("%f %f", pd[2], arr2[2]);

	//pd++;// allowed

	printf("%f %f", pd[2], arr2[2]);

	return 0;
}