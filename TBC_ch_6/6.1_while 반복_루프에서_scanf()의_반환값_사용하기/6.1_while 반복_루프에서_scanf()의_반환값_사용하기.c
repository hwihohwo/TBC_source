#include <stdio.h>

int main()
{
	/*My solution*/
	//int i = 0, sum = 0;
	//char quit = 0;

	//printf("Enter an integer (q to quit) : ");
	//scanf("%d", &i);

	//while (quit != 'q')
	//{ 
	//	sum = sum + i;

	//	printf("Enter next integer (q to quit) : ");
	//	scanf("%d", &i);
	//	scanf("%c", &quit);	//버퍼에 저장된 \n(line feed)를가져가다가
	//						//q입력시 저장된 q를 가져가면서 while반복을 끝냄.
	//}

	//printf("Sum = %d", sum);

	/*Professor's solution*/

	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");

	while (scanf("%d", &num) == 1)	// return value of scanf() 
									// equality operator
	{
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d\n", sum);

	return 0;
}