#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	unsigned long nb_dudes,budget,nb_hotels,nb_weeks,price,nb_rooms,i,j,temp,cur_best_price;
	while(std::cin>>nb_dudes>>budget>>nb_hotels>>nb_weeks)
	{
		cur_best_price = 500001;
		for(i=0;i<nb_hotels;i++)
		{
			std::cin>>price;
			for(j=0;j<nb_weeks;j++)
			{
			std::cin>>nb_rooms;
			if(nb_rooms>=nb_dudes && price*nb_dudes < cur_best_price)
				cur_best_price = price*nb_dudes;
			}
		}
		if(cur_best_price<=budget)
			printf("%ld\n",cur_best_price);
		else
			std::cout<<"stay home\n";
	}
}

