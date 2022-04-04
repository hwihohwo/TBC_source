#include <stdio.h>

int main()
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (y/n)\n",
			count);

		int c = getchar();

		if (c == 'n')
			break;

		else if (c == 'y')
		{
			count++;
		}
		else
		{
			printf("Please input y or n\n");
		}

		while (getchar() != '\n')
			continue; 
		//입력받은 문자들중 첫문자 빼고 모두 buffer에서 지움.
	}

	return 0;
}