#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "record.h"
// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
/*void print_all_records(Participant participants[]){
	// TODO: Modify this function as you need
 
}*/

void create_pcp(linkedList *my_list,Participant *pcp,int *number_to_add)
{
  char flat;
  
  //Participant* kpcp;
  while(flat!='Q'){

     printf("Choose input methods or option to quit (K-keyboard, D-data file, Q-quit) ");
     scanf(" %c",&flat);
  
     if(flat == 'K')
     {
        add_pcp_from_k(pcp);
        (*number_to_add)++;
        create_new_node(my_list, pcp);
     }
      
    else if (flat == 'D')
     {
        add_pcp_from_d(my_list,pcp);
        (*number_to_add)++;
        //create_new_node(my_list, pcp);
        
     }
    
     else if (flat == 'Q')
     {
       break;
     }

     else{
       printf("You enetered the invalid option.");
       continue;
     }

    
        
  }

  //return (*number_to_add);

}

void add_pcp_from_k(Participant *pcp)
{ 
  char buffer[20];

  printf("create a new pcp data from a keyboard\n");
  printf("Enter the name \n(c.p. name format; if name is Kim You Jin, Enter like this->Kim_You_Jin) : ");
  scanf("%s",buffer);
  strncpy(pcp->name,buffer,sizeof(buffer));
  printf("Enter the phone number : ");
  scanf("%s",buffer);
  strncpy(pcp->phone_num,buffer,sizeof(buffer));
  printf("Enter the age : ");
  scanf("%d",&pcp->age);
  printf("Enter the name of high school : ");
  scanf("%s", buffer);
  strncpy(pcp->n_highsch,buffer,sizeof(buffer));
  printf("Enter the number of group : ");
  scanf(" %d",&pcp->gr_num);

  printf("The below infromaiton is added!\n");
  printf("%s\n%s\n%d\n%s\n%d\n",pcp->name,pcp->phone_num,pcp->age,pcp->n_highsch,pcp->gr_num);
  
   
}

void add_pcp_from_d(linkedList *my_list,Participant* pcp)
{
  char filename[10];
  char buffer[20];
  int i=0;
  printf("Enter the file name : ");
  scanf("%s",filename);

  FILE * fp= fopen(filename,"rt");
  if(fp==NULL){
    puts("Fail to open the file!");
  }

  else{

    while(!feof(fp)){
    
      fscanf(fp,"%s\n%s\n%d\n%s\n%d",pcp->name,pcp->phone_num,&pcp->age,pcp->n_highsch,&pcp->gr_num);
    
      i++;
    }
    
    printf("The below infromaiton is added!\n");
    printf("%s\n%s\n%d\n%s\n%d\n",pcp->name,pcp->phone_num,pcp->age,pcp->n_highsch,pcp->gr_num);

    create_new_node(my_list, pcp);
    fclose(fp);
  }
  
}

void create_new_node(linkedList *my_list,Participant *tpcp)
{
  node *new_node = (node *)malloc(sizeof(node));
  new_node->pcp = *tpcp;
  new_node->link=NULL;

  if(my_list->head == NULL && my_list->tail == NULL)
      my_list->head = my_list->tail = new_node;
  else
  {
    my_list->tail->link = new_node;
    my_list -> tail = new_node;
  }
}





void print_nodes(linkedList *my_list)
{
  char flat;
  char buffer;
  int o=0;
    printf("A- It prints out all participants,\n");
    printf("B- It only prints out the participant of the name you entered\n");
    printf("C- It only prints out the participant of the phone number you enetered\n");
    printf("D- It only prints out the participants of the age you entered\n"); 
    printf("E- It only prints out the participants of the name for high school you entered\n");
    printf("F- It only prints out the participant of the group number you enetered\n");
    printf("Q - if you want to quit, enter Q.\n");

  while(flat!='Q'){
    if(o>0){
       buffer =getchar();
    }
   
    printf("Choose the print condition you want : ");

    scanf("%c",&flat);

     if(flat == 'A')
     {
       print_all_nodes(my_list);
     }
     else if(flat == 'B')
     {
       print_name_nodes(my_list); 
     }
     else if(flat == 'C')
     {
        print_phone_num_nodes(my_list);
     }
       
     else if(flat == 'D')
     {
        print_age_nodes(my_list);
     }
        
     else if(flat == 'E')
     {
        print_school_nodes(my_list);
     }
        
     else if(flat == 'F')
     {
        print_group_num_nodes(my_list);
     }
        
     else if(flat == 'Q')
     {
        break;
     }
        
     else{
       printf("You enetered the invalid option.");
       continue;
     }
       
        
        
  }


}

void print_all_nodes(linkedList *my_list)
{
  node *p = my_list->head;
  int k = 0;
  printf("All prints out the list of participants\n");
  while(p!=NULL)
  {
    printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
   p=p->link;
  }
}


void print_name_nodes(linkedList *my_list)
{

   node *p;
   char yw[20];
   int k = 0;
   printf("Enter the name of the participant you want: ");
   scanf("%s",yw);
  
   for(p=my_list->head; p!=NULL; p=p->link)
   {
    if(!strncmp(p->pcp.name,yw,sizeof(yw)))
    {
      printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }

   }
  
}
void print_phone_num_nodes(linkedList *my_list)
{
   node *p;
   char yw[20];
   int k = 0;
   printf("Enter the phone number of the participant you want: ");
   scanf("%s",yw);

   for(p=my_list->head; p!=NULL; p=p->link)
   {
    if(!strncmp(p->pcp.phone_num,yw,sizeof(yw)))
    {
      printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }

   }
 
}


void print_age_nodes(linkedList *my_list)
{
   node *p;
   int num_yw=0;
   int k = 0;
   printf("Enter the age of the participant you want: ");
   scanf("%d",&num_yw);

   for(p=my_list->head; p!=NULL; p=p->link)
   {
    if(p->pcp.age == num_yw){
      printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }

   }

  

}


void print_school_nodes(linkedList *my_list)
{
   node *p;
   char yw[20];
   int k = 0;
   printf("Enter the school name of the participant you want: ");
   scanf("%s",yw);

   for(p=my_list->head; p!=NULL; p=p->link)
   {
    if(!strncmp(p->pcp.n_highsch,yw,sizeof(yw)))
    {
      printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }

   }
}


void print_group_num_nodes(linkedList *my_list)
{
  node *p;
  int num_yw=0;
  int k=0;
  printf("Enter the group number you want: ");
  scanf("%d",&num_yw);

  for(p=my_list->head; p!=NULL; p=p->link)
  {  
    if(p->pcp.gr_num == num_yw){
      printf("=======================================\n");
      printf("=================No.%d==================\n",++k);
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }
      
    

  }
}

void export_entire_data_in_report(linkedList *my_list)
{

  char filename[20];
  node *p;
  int k=1;

  printf("We will export the entire data in a report format.\n");
  printf("Please keep the below rule of naming the file.\n");
  printf("1. Files should be named consistently.\n");
  printf("2. Use capitals and underscores instead of periods or spaces or slashes.\n");
  printf("3. Avoid special characters or spaces in a file name.\n");

  printf("Enter the file name you want to make : ");
  scanf("%s",filename);

  FILE *fp= fopen(filename,"wt");
  
  fprintf(fp,"=======================================\n");
  fprintf(fp,"========The Report Of Paricipant=======\n");
  fprintf(fp,"=======================================\n");
  for(p=my_list->head; p!=NULL; p=p->link)
  {
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
  
  fclose(fp);

}

void read_entire_data_from_file(linkedList *my_list)
{
  char filename[25];
  Participant buffer_pcp;
  printf("We will read the entire data in the list of participants from the file you want.\n");

  printf("Enter the file name you want to read : ");
  scanf("%s",filename);
  FILE * fp= fopen(filename,"rt");

  if(fp==NULL){
    printf("Fail to read the file!");
  }

  while(!feof(fp)){

    fscanf(fp,"%s\n%s\n%d\n%s\n%d\n",buffer_pcp.name,buffer_pcp.phone_num,&buffer_pcp.age,buffer_pcp.n_highsch,&buffer_pcp.gr_num);

    printf("%s\n%s\n%d\n%s\n%d\n",buffer_pcp.name,buffer_pcp.phone_num,buffer_pcp.age,buffer_pcp.n_highsch,buffer_pcp.gr_num);
    
  
  }
  
  fclose(fp);
    
}


void write_entire_data_to_file(linkedList *my_list)
{
  char filename[25];
  node *p;
  
  printf("We will write the entire data in the list of participants.\n");
  
  printf("Please keep the below rule of naming the file.\n");
  printf("1. Files should be named consistently.\n");
  printf("2. Use capitals and underscores instead of periods or spaces or slashes.\n");
  printf("3. Avoid special characters or spaces in a file name.\n");
  printf("Enter the file name you want to make : ");
  scanf("%s",filename);
  FILE * fp= fopen(filename,"wt");

  for(p=my_list->head; p!=NULL; p=p->link)
  {
    
    fprintf(fp,"%s\n%s\n%d\n%s\n%d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    

  }
  
  fclose(fp);

}

void find_node_to_update(linkedList *my_list)
{
  char tname[20];
  node *p;
  printf("We will update the speific information of the participants you want.\n");
  printf("Enter the name of participant you want to update the specific information without space. replace space with '_'.: ");
  scanf("%s",tname);
  getchar();
  for(p=my_list->head; p!=NULL;p=p->link){
    if(!strncmp(p->pcp.name,tname,sizeof(tname)))
    {
      update_the_node(my_list,&p->pcp);
      //printf(" Update! Check the below data : )\n");
     // printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",p->pcp.name,p->pcp.phone_num,p->pcp.age,p->pcp.n_highsch,p->pcp.gr_num);
    }
  }


}

void update_the_node(linkedList *my_list,Participant *pcp)
{
   char flat;
   char tname[20];
   char buffer[20];
   int buffer_num;
  

       
       while(flat!='Q')
       {
         printf("A- Update the name\n");
         printf("B- Update the phone number\n");
         printf("C- Update the age\n");
         printf("D- Update the name of high school\n");
         printf("E- Update the number of group\n");
         printf("Q- Quit\n");
        
    
         printf("Enter the option you want: ");
         scanf("%c",&flat);
         
         if(flat=='A'){
           printf("Enter the new name to update without space. Replace space with '_' : ");
           scanf("%s",buffer);
           getchar();
           strcpy(pcp->name, buffer);
           print_update_data(pcp);
         }

         else if(flat=='B'){
           printf("Enter the new phone number to update and keep the format=XXX-XXXX-XXXX : ");
           scanf("%s",buffer);
           getchar();
           strcpy(pcp->phone_num,buffer);
           print_update_data(pcp);
         }

         else if(flat=='C'){
           printf("Enter the new age to update");
           scanf("%d",&buffer_num);
           getchar();
           pcp->age = buffer_num;
           print_update_data(pcp);
         }

         else if(flat=='D'){
           printf("Enter the new name of the high school without space. Replace space with '_'.");
           scanf("%s",buffer);
           getchar();
           strcpy(pcp->n_highsch,buffer);
           print_update_data(pcp);
         }
           
         else if(flat=='E'){
           printf("Enter the new group number to update");
           scanf("%d",&buffer_num);
           getchar();
           pcp->gr_num = buffer_num;
           print_update_data(pcp);
         }

         else if(flat=='Q'){
           break;
         }
     
        }
         
       
     
   
   

}

void print_update_data(Participant *pcp)
{
  printf(" Update! Check the below data : )\n");
      printf("\tName : %s\n\tPhone_number : %s\n\tAge :  %d\n\tHigh School : %s\n\tGroup Number : %d\n",pcp->name,pcp->phone_num,pcp->age,pcp->n_highsch,pcp->gr_num);
}
