
static unsigned int seed = 0;
//�ش� ���Ͽ�����, �� �� �Լ������� ������ �� �ֵ��� ����.
//�� �� ��ü���⿡�� �߿��ϰ� ���Ǵ� ����

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