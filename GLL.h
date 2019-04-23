#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

typedef struct node{
	void* data;
	struct node* next;	
}node;

typedef struct GLL{
	node* first;
	int size;
} GLL;


#endif