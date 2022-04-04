#include <stdio.h>
#define LEN 20

struct names {			// A structure
	char given[LEN];	// first name
	char family[LEN];	// last name
};

struct reservation {	// Another structure
	struct names guest;	// a nested structure
	struct names host;	// one more nested structure
	char food[LEN];
	char place[LEN];

	//time
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main()
{
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
	printf("I would like to serve you %s.\n", res.food);
	printf("Please visit the %s on %d/%d/%d at %d:%d\n", res.place, res.day, res.month, res.year, res.hours, res.minutes);
	printf("Sincerely,\n");
	printf("%s %s\n", res.host.given, res.host.family);

	return 0;
}