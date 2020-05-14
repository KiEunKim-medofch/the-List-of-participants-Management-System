#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extra.h"
#include "record.h"

void group_match_node(linkedList *my_list) {
  node *p;
  int group_num=0;
  int k=1;
  printf("Enter the group number you want: ");
  scanf("%d",&group_num);
  
  FILE *fp= fopen("group_match.txt","wt");
  
  fprintf(fp,"=======================================\n");
  fprintf(fp,"========The Report Of Paricipant=======\n");
  fprintf(fp,"=======================================\n");
  for(p=my_list->head; p!=NULL; p=p->link)
  {
  	if(p->pcp.gr_num == group_num){
	    fprintf(fp,"=================No.%d==================\n",k++);
	    //name
	    fprintf(fp,"\tName : %s\n",p->pcp.name);
	    //phone_num
	    fprintf(fp,"\tPhone Number : %s\n",p->pcp.phone_num);
	    //age
	    fprintf(fp,"\tAge : %d\n",p->pcp.age);
	    //high school name
	    fprintf(fp,"\tHigh school : %s\n",p->pcp.n_highsch);
	    //group number
	    fprintf(fp,"\tGroup Number : %d\n",p->pcp.gr_num);
	    fprintf(fp,"=======================================\n");
	 }
  }
  
  fclose(fp);
}
