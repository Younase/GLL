#include "GLL.h"
#include <stdlib.h>
GLL newGLL(int size){///////////////////////COMPLETE   (NO INT IN NEWGLL)
	GLL l;
	l.first=NULL;
	l.size=0;
	return l;
}
int insertGLL(GLL* l,void* d,int size){
	node* n=(node*)malloc(size);
	n->data=d;
	n->next=l->first;
	l->first=n;
	l->size++;
	return 0;
}

void* insertOGLL(GLL* l,void* d,int size,int (*cmp)(void*,void*)){
	// node *np,*n1,*n=(node*)malloc(size);
	// n->data=d;
	// node* n1=*l;
	// np=n1;
	// while((*cmp)(d,n1->data)<0&&n1->next){
	// 	np=n1;
	// 	n1=n1->next;
	// }
	// n->next=n1;
	// *l=n;
	node *np=l->first,*n=l->first;
	if(n==NULL||(*cmp)(n->data,d)>0){
		//printf("sdsd\n");
		insertGLL(l,d,size);
		return 0;
	}
	//n=n->next;
	while(n && (*cmp)(n->data,d)<0){
		np=n;
		n=n->next;
	}
	if(n && (*cmp)(n->data,d)==0)
		return (n->data);

	node* no=(node*)malloc(size);
	no->data=d;
	no->next=n;
	np->next=no;
	l->size++;
	return 0;
	//insertGLL(&(np->next),d,size);
}

void destroyGLL(GLL* l){
	while(l->first){

		delPosGLL(l,0);
	}
}
void delPosGLL(GLL* l,int pos){
	node *n1,*n=l->first;
	if(!n)
		return NULL;
	if(pos==0)
		l->first=n->next;
	else{
		while(pos!=0){
			if(n==NULL)
				return NULL;
			n1=n;
			n=n->next;
			--pos;
		}
		n1->next=n->next;
	}
	free(n);
	// for(int i=0;i<pos;i++){
	// 	if(n==NULL)
	// 		return NULL;
	// 	n1=n;
	// 	n=n->next;
	// }
	// n1->next=n->next;
	//free(n);
}
void* getPosGLL(GLL* l,int pos){
	node* n=l->first;
	if(!n)
		return NULL;
	for(int i=0;i<pos;i++){
		if(n->next==NULL)
			return NULL;
		n=n->next;
	}
	return n->data;
}
void* getDataGLL(GLL* l,void* d,int (*cmp)(void*,void*)){
	node *n=l->first;
	while(n!=NULL){
		if((*cmp)(d,n->data)==0)
			return n->data;
		n=n->next;
	}
	return NULL;
	//////////////////////////////////////////return
}


void* getODataGLL(GLL* l,void* d,int (*cmp)(void*,void*)){
	node *n=l->first;
	while(n!=NULL && (*cmp)(d,n->data)>0)
		n=n->next;

	if(n!=NULL && (*cmp)(d,n->data)==0)
		return n->data;
	return NULL;
}


void processGLL(GLL* l,void (*f)(void*)){
	node* n=l->first;
	if(!n)
		return;
	while(n){
		(*f)(n->data);
		n=n->next;
	}

}