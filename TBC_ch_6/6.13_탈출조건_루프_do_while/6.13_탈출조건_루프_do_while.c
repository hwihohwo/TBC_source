#include <stdio.h>

int main()
{
	const int password = 2233;

	int input_number = 0;

	//while (input_number != password)
	//{
	//	printf("Enter secret code : ");
	//	scanf("%d", &input_number);
	//}

	do
	{
		printf("Enter secret code : ");
		scanf("%d", &input_number);
	} 
	while (input_number != password);
	//do_while은 일단 한번은 실행하고 조건 검사를 하는것이 while과의 차이.
	printf("Good!\n");

	return 0;
}