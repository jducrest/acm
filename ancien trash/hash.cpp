#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash {
	char key[75];
	int value;
};

typedef struct hash Hash;


unsigned int apply_hash(char* elt)
{
    unsigned int h = 0;
    
    int i=0;
    while(elt[i]!='\0')
    {
        h += elt[i];
        h += (h << 10);
        h ^= (h >> 6);
	i++;
    }

    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);

    return h;
}

int find_hash(char*elt,Hash* h,int size)
{
	unsigned int hash_value = apply_hash(elt)%size;
	int i,j;
	for(i=hash_value;i<size;i++)
		if(strcmp(h[i].key,elt)==0){
			return i;
		}
		else if(h[i].key[0]=='\0'){
			for(j=0;j<75;j++)
				h[i].key[j] = elt[j];
			return i;
		}

	for(i=0;i<hash_value;i++)
		if(strcmp(h[i].key,elt)==0){
			return i;
		}
		else if(h[i].key[0]=='\0'){
			for(j=0;j<75;j++)
				h[i].key[j] = elt[j];
			return i;
		}


	return -1;
}

void print_hash(Hash* h, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%s %d\n",h[i].key,h[i].value); 
	}
}

void beauty_print_hash(Hash* h, int size)
{
	int i,j,k,flag;
	for(i=0;i<size;i++)
	{
		flag = -1;
		for(j=0;j<size;j++)
		{
		 	if(h[j].key[0] != '\0')
			{
				if(flag==-1)
					flag=j;
				else if(strcmp(h[j].key,h[flag].key)<0)
				{
					flag=j;
				}
					
			}
		}
		if(flag==-1)
			return;
		
		printf("%s %d\n",h[flag].key,h[flag].value);
		h[flag].key[0]='\0';

	}
}

Hash* init_hash(int size)
{
	Hash* h  = (Hash*) malloc(sizeof(Hash)*size);
	int i;
	for(i=0;i<size;i++){
		h->value = 0;
		h->key[0]='\0';
	}
	return h;
}

int main(){
	Hash* h = init_hash(2000);
	int ind;
	int i,nb_femmes;
	char pays[75],prenom[75],nom[75];
	scanf("%d",&nb_femmes);
	for(i=0;i<nb_femmes;i++)
	{
		scanf("%s %s %s",pays,prenom,nom);
		ind = find_hash(pays,h,2000);
		h[ind].value++;

	}
	beauty_print_hash(h,2000);	
	free(h);
	return 0;
}
