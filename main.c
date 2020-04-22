#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"



// function prototypes
void input_handler(char input[], linkedList *my_list,Participant* pcp,int * number_to_add);
void show_menu();

// main function
int main(){

	Participant pcp;
  linkedList *my_list = (linkedList *)malloc(sizeof(linkedList));
  my_list->head = NULL;
  my_list->tail = NULL;
  int number_to_add=0;
  int i=0;
  char c;
	char user_input[2] = "";
	while(strcmp(user_input, "99") != 0){
    if(i>0){
      c=getchar();
    }
    
		show_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 2, stdin);
		input_handler(user_input,my_list, &pcp,&number_to_add);
    i++;
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], linkedList *my_list,Participant* pcp,int * number_to_add){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		create_pcp(my_list,pcp,number_to_add);
  else if(!strcmp(input, "2"))
    print_nodes(my_list);	
  else if(!strcmp(input, "3"))
		export_entire_data_in_report(my_list);
	else if(!strcmp(input, "4"))
		read_entire_data_from_file(my_list);
  else if(!strcmp(input, "5"))
		write_entire_data_to_file(my_list);
  else if(!strcmp(input, "6"))
		find_node_to_update(my_list);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)*/
	//else
//		printf("Unknown menu: %s \n\n", input);
}



// Function: show_menu()
// Input: none
// Output: none
// - prints out the main menu
void show_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" In G-IMPACT of Handong, the List of participants Management System(LMS) \n");
	printf("******************************\n");
	printf(" 1. create a new participants\n");
	printf(" 2. Print participants in the way you want\n");
	printf(" 3. Export the entire data in a report\n");
	printf(" 4. Read the entire data from the file you want\n");
  printf(" 5. Write the entire data to the file you want\n");
  printf(" 6. Update the data of the participant you want\n");
  printf(" 99. Quit");
}
