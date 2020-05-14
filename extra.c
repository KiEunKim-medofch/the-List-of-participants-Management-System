#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extra.h"
#include "record.h"

void advanced_search(linkedList *my_list) {
	node *p;
  	int group_num;
  	int age_up;
  	int k = 0;
  	printf("Enter the group number you want : ");
  	scanf("%d", &group_num);
  	printf("Enter more than age you want : ");
  	scanf("%d", &age_up);
  	
  	for(p=my_list->head; p!=NULL; p=p->link) {
    	if(p->pcp.gr_num == group_num && p->pcp.age >= age_up){
      		printf("=======================================\n");
      		printf("=================No.%d==================\n",++k);
      		printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    	}
    }
}