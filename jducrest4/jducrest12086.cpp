/*******************************************************************

Le code de l'arbre de Fenwick est a 99% pompé de wikipédia 
(j'ai fait l'effort de comprendre l'algo... pas de le recopier mot pour mot)
Une fois qu'on a l'arbre bin il suffit d'appliquer et c'est gagné ;)

*******************************************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


typedef unsigned long sum_t;

// Merci wikipedia pour cette macro bien style
#define LSB(i) ((i) & -(i))

// Fen_sum: return the sum of the first i elements, 0 through i-1.
sum_t Fen_sum(sum_t const *a, unsigned int i) 
{
	sum_t sum = 0;
	while (i) {
		sum += a[i-1];
		i -= LSB(i);
	}
	return sum;
}

// Fen_add: add k to element i (and thus Fen_sum(a, j) for all j > i)
void Fen_add(sum_t *a, unsigned int size, sum_t delta, unsigned int i) 
{
	while (i < size) {
		a[i] += delta;
		i += LSB(i+1);
	}
}

// Fen_range: Returns the sum of the elements [i..j-1]
// This could be written as "Fen_sum(a, j) - Fen_sum(a, i)",
// but it is possible to do it in less time (particularly for
// small ranges) by avoiding the terms that the two sums have
// in common.
sum_t Fen_range(sum_t const *a, unsigned int i, unsigned int j)
{
	sum_t sum = 0;

	while (j > i) {
		sum += a[j-1];
		j -= LSB(j);
	}

	while (i > j) {
		sum -= a[i-1];
		i -= LSB(i);
	}
	return sum;
}

// Fen_get: Returns the value of the element at index i
// (The time is propertional to the number of trailing 1 bits
// in i.  So even numbers are fast, and i = 0xffff takes 16 steps.)
sum_t Fen_get(sum_t const *a, unsigned int i)
{
	return Fen_range(a, i, i+1);
}

// Fen_set: sets the value of the element at index i
void Fen_set(sum_t *a, unsigned int size, sum_t value, unsigned int i)
{
	Fen_add(a, size, value - Fen_get(a, i), i);
}

// It's possible to initialize a Fenwick tree using Fen_add or
// Fen_set (you can even do the latter in-place if you go backward
// through the array), but for bulk initialization, this is faster.
void Fen_init(sum_t *a, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++) {
		unsigned int j = i + LSB(i+1);
		if (j < size)
			a[j] += a[i];
	}
}


int main(void)
{
	sum_t sums[200000];
	unsigned int N;
	bool flag;
	unsigned int i;
	char c;
	sum_t val;
	unsigned int x;
	unsigned int y;
	unsigned int compteur=1;
	while(cin >> N)
	{
	if(N==0)
		break;
	
	// recuperation de l'input
	for(i=0;i<N;i++)
		cin >> sums[i];
	
	// init de l'arbre
	Fen_init(sums, N);
	
	// traitement des queries
	if (compteur != 1)
		cout << endl;
	cout << "Case " << compteur << ":" << endl;
	compteur++;
	while(1)
	{
		cin >> c;
		if(c=='M')
		{
			cin >> x >> y;
			cout << Fen_range(sums,x-1,y) << endl;
			
		}
		else if(c=='S')
		{
			cin >> x >> val;
			Fen_set(sums,	N,val,x-1); 	
		}
		else if(c=='E')
		{
			// on vide la fin du  mot END (oui j'ai pas trouvé de manière plus degueu de faire...)
			cin >> c;
			cin >> c;
			break;
		}
	}

	}
	return 0;
}
