#include <stdio.h>
#include <stdlib.h>
#include "GLL.h"
int intcmp(void* a,void* b){
    return *((int*)a)-*((int*)b);
}
void processing_function(void* a){
    printf("%d\n",*((int*)a));
}
int main(int argc,char const *argv[])
{
    GLL list=newGLL(sizeof(int));
    int k=3,i=1,j;
    insertGLL(&list,(void*)&i,sizeof(int));
    insertOGLL(&list,(void*)&k,sizeof(int),&intcmp);//both insertion methods used together for demonstation
    j=*((int*)getPosGLL(&list,0));
    printf("%d\n",j);
    j=*((int*)getDataGLL(&list,(void*)&i,&intcmp));
    printf("%d\n",j);
    j=*((int*)getODataGLL(&list,(void*)&k,&intcmp));
    printf("%d\n",j);
    printf("Processing GLL\n");
    processGLL(&list,&processing_function);
    delPosGLL(&list,0);
    printf("Processing GLL\n");
    processGLL(&list,&processing_function);
    destroyGLL(&list);
     printf("Processing GLL\n");
    processGLL(&list,&processing_function);
}