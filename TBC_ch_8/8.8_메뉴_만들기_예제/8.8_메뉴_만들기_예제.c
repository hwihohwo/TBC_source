#include <stdio.h>

int main()
{
	char c;
	int count;

	while (1)
	{
		printf("Enter the letter of your choice:\n");
		printf("a. avengers\tb. beep\n");
		printf("c. count\tq. quit\n");


		c = getchar();

		if (c == 'q')
			break;

		switch (c)
		{
		case 'a':
		
			printf("Avengers assemble!\n");
			break;
		
		case 'b':
		
			printf("\a\n");
			break;
		
		case 'c':
			printf("Enter an integer : \n");
			while (scanf("%d", &count) != 1)
			{
				while ((c = getchar()) != '\n')
					putchar(c);
				printf(" is not an integer.\nPlease try again.");
			}

			for (int i = 1; i <= count; i++)
				printf("%d\n", i);
			break;
		
		default:
			printf("Wrong input. Please input a, b, c, q\n");
		}
		while ((c = getchar()) != '\n')
			continue;
	}
	return 0;
}
