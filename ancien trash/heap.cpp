#include <stdio.h>
#include <stdlib.h>


typedef struct heap Heap;

struct heap {
	int size;
	int size_max;
	int* heap;
};

void double_heap(Heap* h){
	int* new_heap = (int*) calloc(h->size_max*2,sizeof(int));
	int i;
	for(i=0;i<h->size_max;i++){
		new_heap[i] = h->heap[i];
	}
	free(h->heap);
	h->heap = new_heap;
	h->size_max *= 2;
}

void insert_heap(Heap* h,int elt){
	if(h->size==h->size_max-1)
		double_heap(h);
	
	h->size= h->size + 1;
	int i = h->size;
	int dad = h->heap[i/2];
	int temp;
	while(dad<elt && i>1){
		h->heap[i] = dad;
		i= i/2;
		dad = h->heap[i/2];
	}
	h->heap[i]=elt;
}
int lookfirst_heap(Heap* h){
	return h->heap[1];
}

int pop_heap(Heap* h){
	int i= 1;
	int max = h->heap[i];
	int elt = h->heap[h->size];
	h->size-=1;
	while(1){
		if(elt < h->heap[2*i] && (2*i) <= h->size){
			h->heap[i] = h->heap[2*i];
			i = 2*i;
		}
		else if(elt < h->heap[2*i+1] && (2*i+1) <= h->size){
			h->heap[i] = h->heap[2*i+1];
			i = 2*i+1;
		}
		else{
			break;  
		}
	}
	h->heap[i] = elt;
	return max;
}

Heap* init_heap(){
	Heap* h = (Heap*)  malloc(sizeof(Heap));
	int* heap = (int*) calloc(2,sizeof(int));
	h->size = 0;
	h->size_max = 2;
	h->heap = heap;
	return h;
}

void print_heap(Heap* h){
	int i;
	for(i=1;i <= h->size; i++)
		printf("%d ",h->heap[i]);
	printf("\n");
}

void delete_heap(Heap* h){
	free(h->heap);
	free(h);
}

int main(){
	Heap* h = init_heap();
	insert_heap(h,10);
	print_heap(h);
	insert_heap(h,12);
	print_heap(h);
	insert_heap(h,32);
	print_heap(h);
	insert_heap(h,14);
	printf("%d %d\n",h->size,h->size_max);
	print_heap(h);
	pop_heap(h);
	print_heap(h);
	delete_heap(h);
	return 0;
}
