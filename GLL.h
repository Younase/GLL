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

GLL newGLL(int size);
////////insert
////Oinsert        //////////ordered insert function pointer in args
//void insertGLL(GLL* l,void* d);
void destroyGLL(GLL* l);
void* getPosGLL(GLL* l,int pos);
void delPosGLL(GLL* l,int pos);
void* getDataGLL(GLL* l,void* d,int (*cmp)(void*,void*));
int insertGLL(GLL* l,void* d,int size);
void* insertOGLL(GLL* l,void* d,int size,int (*cmp)(void*,void*));/////////////no redundency of data
void* getDataGLL(GLL* l,void* d,int (*cmp)(void*,void*));
void* getODataGLL(GLL* l,void* d,int (*cmp)(void*,void*));
void processGLL(GLL* l,void (*f)(void*));
#endif