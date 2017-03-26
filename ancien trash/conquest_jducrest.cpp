#include <stdio.h>
#include <string.h>

typedef struct lovers_by_country lbc;
struct lovers_by_country 
{
	char country[100] = "";
	int nb_lovers=0;
}

int main(){
	char country[100],name[100];
	lbc my_lovers[2000]; 
	int hash,i;
	scanf("%d",&i);
	while(scanf("%s %s",country,name)
	{
		hash=0;
		i=0;
		while(country[i]!='\0')
		{
			hash+=(int) country[i];	
		}
		hash = hash%2000;
		if(strcmp(my_lovers[hash].country,"")==0) //c'est la première fois qu'on arrive sur ce hachage
		{

		}
		else if(strcmp(my_lovers[hash].country,country)==0) //on est bien au bon endroit
		{

		}
		else //collision
		{
			
		}
	}
}

