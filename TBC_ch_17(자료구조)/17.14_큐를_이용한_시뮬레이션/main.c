#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedQueue.h"

/*
	min_per_cust = 60.0f / average_n_customers_per_hour;
	x : probabilisic number of n_queued_customers per an hour
*/

bool newcustomer_visit(double x)
{
	if (rand() * x / RAND_MAX < 1.0)
		return true;
	else
		return false;
}

Item get_customer(long arrival_time)
{
	Item cust;

	cust.processtime = rand() % 3 + 1; // 1 - 3
	cust.arrival_time = arrival_time;
	
	return cust;
}

int main()
{
	srand((unsigned int)time(0));
	Queue customers;
	Item cust, temp;
	bool serving_flag = false;
	double average_n_customers_per_hour;
	int simul_hour, lost_customers = 0, accepted_customers = 0, served_customers = 0;
	int process_min = 0;
	int sum_queue_size = 0;
	int sum_waiting_time = 0;
	InitializeQueue(&customers);
	printf("How many hours do you want to simulate?\n>>");
	int flag = scanf("%u%*c", &simul_hour);
	printf("How many customers per hour do you expect?\n>>");
	flag = scanf("%lf%*c", &average_n_customers_per_hour);
	double min_per_cust = 60.0f / average_n_customers_per_hour;
	for (int i = 1; i <= 60 * simul_hour; ++i) // cyclelimit = 60 * simul_hour
	{
		if (newcustomer_visit(min_per_cust) == true)
		{
			Item cust = get_customer(i);
			if (EnQueue(cust, &customers) == false)
			{
				printf("%d : Customer lost\n", i);
				lost_customers++;
			}
			else
			{
				printf("%d : a new customer enqueue.\n", i);
				accepted_customers++;
			}
		}
		if (serving_flag == true && process_min == customers.front->item.processtime)
		{
			DeQueue(&temp, &customers);
			serving_flag = false;
		}
		else if (QueueIsEmpty(&customers) == false && serving_flag == false)
		{
			serving_flag = true;
			printf("%d : start serving a customer for %d munutes.\n", i, customers.front->item.processtime);
			process_min = 0;
			served_customers++;
		}
		if (customers.n_items > 1 && serving_flag == true)
			sum_waiting_time += customers.n_items - 1;
		sum_queue_size += customers.n_items;
		//평균 대기시간 계산시 현재시간 - 손님의 도착시간 으로도 가능.
		if (serving_flag) process_min++;
	}
	printf("\ncustomers accepted: %d\n", accepted_customers);
	printf("  customers served: %d\n", served_customers);
	printf("              Lost: %d\n", lost_customers);
	printf("average queue size: %.2lf\n", (double)sum_queue_size / (double)(average_n_customers_per_hour * 60.0));
	if (accepted_customers != 0)
	printf(" average wait time: %.2lf\n", (double)sum_waiting_time / (double)accepted_customers);

	EmptyTheQueue(&customers);

	return 0;
}