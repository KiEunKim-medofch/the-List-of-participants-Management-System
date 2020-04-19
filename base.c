#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "record.h"
// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Participant participants[]){
	// TODO: Modify this function as you need
 
}


// Function: add_pcp()
// Input: pariticipant of the Array Participants
// Output: the information of the participant
// - take user's input and create a new record 
void register_pcp(Participant participants[]){
	// TODO: Modify this function as you need
  int num=0;
  printf("Enter the number to register participants ");
  scanf("%d",&num);
  for(int i=current_num;i<(current_num+num);i++){
    printf("Enter the information of the participants you want to add\n");
    printf("name: ");
    scanf(" %[^\n]s",participants[i].name);
    printf("\nphone_number(format XXX-XXXX-XXXX) : ");
    scanf(" %[^\n]s",participants[i].phone_num);
    printf("the name of the participant's highschool: ");
    scanf(" %[^\n]s",participants[i].n_highsch);
    printf("the number of the group to which the participants belong: ");
    scanf(" %[^\n]c",&participants[i].gr_num);
    printf("age: ");
    scanf(" %[^\n]c  ",&participants[i].age);
    current_num++;
  }
    	

}


// TODO: Add more functions to fulfill the requirements
// take filename to take data from file
    // input: pariticipants of the Array Participant, filename
    // output: none
//void ld_data(Participant participants[],char * filename){
   // char str[100];

   // int count=0;
   // FILE *fp=fopen(filename,"rt");
   // while(fgets(str,sizeof(str),fp)!=NULL){
      
    //   printf(str);
      // count++; 
   // }
   /* for(int i=0; i<count; i++){
     if(i%5==1){
        Participant * ptr = (Participant *)malloc(sizeof(Participant));
        participants[i/5].name=str[i];
      }
      else if(i%5==2){
        participants[i/5].phone_num=str[i];
      }
      else if(i%5==3){
        participants[i/5].n_highsch=str[i];
      }
      else if(i%5==4){
        participants[i/5].gr_num=str[i];
      }
      else if(i%5==0){
        participants[i/5].age=str[i];
      } 
    }*/
   // fclose(fp);
//}
 

