#include <stdio.h>
#include <string.h>	// strcmp (HINT!)
#include <stdbool.h>// C99

enum spectrum {red, orange, yellow, green, blue};
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

#define LEN 30

int main()
{
	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;

	while (1)
	{
		printf("Input a color name (empty line to quit):\n>>");

		int flag = scanf("%[^\n]%*c", choice);

		if (flag == 0)
		break;

		for (color = red; color <= blue; ++color)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found == true;
				break;
			}
		}

		if (color_is_found)
		{
			switch (color)
			{
			case red:
				printf("Red wine\n");
				break;
			case orange:
				printf("Orange sparkling\n");
				break;
			case yellow:
				printf("Yellow banana\n");
				break;
			case green:
				printf("Green leaf\n");
				break;
			case blue:
				printf("Blue mountain\n");
				break;
			}
		}
		else
			printf("Please try different color %s.\n", choice);

		color_is_found = false;
	}

	printf("Good bye!");

	return 0;
}