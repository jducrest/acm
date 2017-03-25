#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* file = fopen("res.txt","w+");
	long N=1,M=1,temp1,temp2,temp3;
	int i,j;
	long calls_start[10000];
	long calls_end[10000];
	long range_start[100];
	long range_end[100];
	long range_count[100];
	while(!(N==0 && M==0)){
	temp3  = scanf("%ld %ld",&N,&M);

	for(i=0;i<N;i++){
		temp3 = scanf("%ld %ld %ld %ld",&temp1,&temp2,calls_start+i,calls_end+i);
		calls_end[i]+=calls_start[i];
	}
	for(i=0;i<M;i++){
		temp3 = scanf("%ld %ld",range_start+i,range_end+i);
		range_end[i]+=range_start[i];
	}

	for(j=0;j<M;j++)
		range_count[j] = 0;

	for(i=0;i<N;i++)
	{
		if(calls_start[i] != calls_end[i])
		for(j=0;j<M;j++)
		{
			if(calls_end[i]<=range_start[j])
				continue;
			if(calls_start[i]>=range_end[j])
				continue;
			range_count[j]++;
		}
	}

	for(j=0;j<M;j++)
		printf("%ld\n",range_count[j]);

	}
}
