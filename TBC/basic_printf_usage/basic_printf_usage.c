#include <stdio.h>//��ó����

int main()
{
	
	printf("The truth is ...\nI am Ironman.\n");
	// 'f'�� �پ��ִ�. �Լ��� ���� '�Է�'�� ���� '���'�� ���� �����ϸ� ����.
	// escape sequence \n �ǹ̸� ���캸�� ���� �ٲ۴ٴ� ������ �ν���.
	// ""���� ������ ���ڿ��� �ν���.
	printf("\"The truth is ... Ironman.\n\"");
	// "�� ���� �ǹ̸� ���� ���ڸ� ����ϰ� �������� �� �տ� \(�齽����)�� ���δ�.
	// print formatted �ٿ��� printf.
	int x, y, z;
	x = 1;
	y = 2;

	z = x + y;

	printf("The answer is %i.\n", z);//%i, %d �Ѵ� printf������ �Ȱ��� �۵���.
	// i�� integer, d�� decimal�� ����
	printf("%i + %i = %i", x, y, z);// ������� ����.
	printf("\a");//��½� �����(�˶�)�� ����.��, �Ҹ��� ��µ�.
	/*�ּ� ���� �ۼ��Ҷ�
	�� �����ÿ� ���� 
	Ȱ����. �ֱٿ��� ���۱ǵ��� ǥ���Ҷ� ���� �����.*/
	return 0;
}