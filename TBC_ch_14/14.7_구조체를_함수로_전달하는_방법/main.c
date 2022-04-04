#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

double sum(const struct fortune *my_fortune);

int main()
{
	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		//sum(&my_fortune.bank_saving, &my_fortune.fund_invest));
		sum(&my_fortune)
	);

	return 0;
}

double sum(const struct fortune *my_fortune)	//일반변수로 선언하면 다른 변수가 되니까 object를 복사해서 이 변수에 넣음.
// 이 경우 메모리를 한자리 더 차지하게 되고 무엇보다 data양이 많을 경우 복사에 시간이 많이 걸리게 됨. 그래서 포인터로 많이 쓴다.
{
	return my_fortune->bank_saving + my_fortune->fund_invest;
}