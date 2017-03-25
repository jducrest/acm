#include <iostream>
#include <stdio.h>


int main(){
	char s[200];
	char quotes[2] =  {'`','\''};
	int nb_read=1;
	int quote_started = 0;
	int i = 0;
	while(fgets(s,200,stdin)!=NULL){
		i=0;
		while(s[i]!='\0')
		{
			if(s[i]=='\"')
			{
				printf("%c%c",quotes[quote_started],quotes[quote_started]);
				quote_started = 1-quote_started;
			}
			else
				printf("%c",s[i]);
			i++;
		}
	}	

}

