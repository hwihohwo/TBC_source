
static unsigned int seed = 0;
//해당 파일에서만, 즉 두 함수에서만 접근할 수 있도록 선언.
//이 후 객체지향에서 중요하게 사용되는 개념

void my_srand(unsigned int input)
{
	seed = input;
}

int my_rand()
{
	seed = seed * 1103515245 + 1234;
	seed = (unsigned int)(seed / 65546) % 32768;

	return (int)seed;
}