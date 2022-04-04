#include <stdio.h>

int main()
{
	//	Simulation of a Moving Object
	//
	//		- Speed = 1.0 m/s
	//		- dt = 1.0 s
	//		- Distance traveled during dt = Speed * dt
	//
	//		- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
	//		- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
	//		- Step 3 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
	//		- ... ...

	//Zeno's Paradox

	//	- Step 1 : 1.0 * 1.0 = 1.0, 1.0
	//	- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
	//	- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75
	//	... ...

	const double speed = 1.0;
	const unsigned repeat_max = 50;

	double time = 0.0;	//Elapsed time
	double dist_arch = 0.0;
	double dist_turtle = 1.0;
	double speed_arch = 10.0;
	double speed_turtle = 0.001;
	double dt = 0.01;
	unsigned i;

	printf("Time = %fs, Archilleus = %fm, turtle = %fm\n",
		time, dist_arch, dist_turtle);

	for (i = 0; i < repeat_max; i++)
	{
		time += dt;
		dist_arch += speed_arch * dt;
		dist_turtle += speed_turtle * dt;

		printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
			time, dt, dist_arch, dist_turtle);

		dt *= 0.5;

	}

	return 0;


}