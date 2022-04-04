#include <stdio.h>

int main()
{
	/*continue*/
	//for (int i = 0; i < 10; ++i)
	//{
	//	if (i == 5)
	//		continue;	//뒷 부분을 실행하지 않고 ++i로 바로 들어감.

	//	printf("%d ", i);

	//	//if (i != 5)
	//	//	printf("%d ", i);
	//}

	/*break*/
	//for (int i = 0; i < 10; ++i)
	//{
	//	if (i == 5)
	//		break;	//break를 포함하는 첫번째 loop를 탈출한다.

	//	printf("%d ", i);
	//}

	/*while and continue*/
	//int count = 0;
	//while (count < 5)
	//{
	//	int c = getchar();
	//	if (c == 'a')
	//		continue;
	//	putchar(c);
	//	count++;
	//}

	/*for and continue*/
	//for (int count = 0; count < 10; ++count)
	//{
	//	int c = getchar();
	//	if (c == 'a')
	//		continue;
	//	putchar(c);
	//}

	/*continue as a placeholder*/
	//특별한 기능없이 공간을 표기해주는것.
	//while (getchar() != '\n')
	//	continue;

	//char c;
	//while ((c = getchar()) != '\n')
	//{
	//	if (c == 'a')
	//		continue;
	//	putchar(c);

	//	//if (c != 'a')
	//	//	putchar(c);

	//}

	/*break*/

	//char c;
	//while ((c = getchar()) != '.')
	//{
	//	putchar(c);
	//}

	//while (1)
	//{
	//	char c = getchar();

	//	if (c == '.')
	//		break;

	//	putchar(c);
	//}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
				break;

			printf("(%d %d)", i, j);
		}

		printf("\n");
	}

	return 0;
}