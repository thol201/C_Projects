#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int ammount = 1000;
	int* sort_tab1[10000];
	int* sort_tab2[10000];
	int* sort_tab3[10000];
	int* sort_tab4[10000];
	int i,j;
	double tmp_avg[4] = { 0,0,0,0 }, tmp_avg2[4] = { 0,0,0,0 };
	int min_tmp[4] = { INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX }, min_tmp2[4] = { INT_MAX ,INT_MAX ,INT_MAX ,INT_MAX };
	int max_tmp[4] = {0,0,0,0}, max_tmp2[4] = {0,0,0,0}, *tmp = calloc(8,sizeof(int));
	for (i = 0; i < ammount; i++)
	{
		prepTab(sort_tab1,10000);
		memcpy(sort_tab2, sort_tab1, sizeof(int) * 10000);
		memcpy(sort_tab3, sort_tab1, sizeof(int) * 10000);
		memcpy(sort_tab4, sort_tab1, sizeof(int) * 10000);
		sort_bubble(sort_tab1, 10000,&tmp[0],&tmp[1]);
		sort_insert(sort_tab2, 10000,&tmp[2],&tmp[3]);
		sort_shell(sort_tab3, 10000,&tmp[4],&tmp[5]);
		quicksort(sort_tab4, 0, 9999,&tmp[6],&tmp[7]);


		for (j = 0; j < 8; j+=2)
		{
			if (min_tmp[j / 2] > tmp[j])
				min_tmp[j / 2] = tmp[j];
			if (min_tmp2[j / 2] > tmp[j+1])
				min_tmp2[j / 2] = tmp[j+1];
			if (max_tmp[j / 2] < tmp[j])
				max_tmp[j / 2] = tmp[j];
			if (max_tmp2[j / 2] < tmp[j + 1])
				max_tmp2[j / 2] = tmp[j + 1];
			tmp_avg[j / 2] += tmp[j];
			tmp_avg2[j / 2] += tmp[j+1];
			tmp[j] = 0;
			tmp[j+1] = 0;
		}
			
	}

	printf("Bubble sort\n min comp %d\n max comp %d\n min sets %d\n max sets %d\n avg comp %f\n avg sets %f\n", min_tmp[0], max_tmp[0], min_tmp2[0], max_tmp2[0], tmp_avg[0]/ ammount, tmp_avg2[0]/ ammount);
	printf("Insert sort\n min comp %d\n max comp %d\n min sets %d\n max sets %d\n avg comp %f\n avg sets %f\n", min_tmp[1], max_tmp[1], min_tmp2[1], max_tmp2[1], tmp_avg[1]/ ammount, tmp_avg2[1]/ ammount);
	printf("Shell sort\n min comp %d\n max comp %d\n min sets %d\n max sets %d\n avg comp %f\n avg sets %f\n", min_tmp[2], max_tmp[2], min_tmp2[2], max_tmp2[2], tmp_avg[2]/ ammount, tmp_avg2[2]/ ammount);
	printf("Quick sort\n min comp %d\n max comp %d\n min sets %d\n max sets %d\n avg comp %f\n avg sets %f\n", min_tmp[3], max_tmp[3], min_tmp2[3], max_tmp2[3], tmp_avg[3]/ ammount, tmp_avg2[3]/ ammount);


	return 0;
}