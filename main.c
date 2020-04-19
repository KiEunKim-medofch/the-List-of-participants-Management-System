#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char input[], Participant[]);
void show_menu();

// main function
int main(){

	Participant participants[MAX_RECORDS];
  
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		show_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		input_handler(user_input, participants);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Participant participants[]){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		register_pcp(participants);
//	else if(!strcmp(input, "2"))
   //	print_all_records(participants);	
//	else if(!strcmp(input, "3"))
		//ld_data(participants,"pcp.txt");
	/*else if(!strcmp(input, "4"))
		display_stats(records);	
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
	printf(" 1. register a new participants\n");
	printf(" 2. Print all participants\n");
	printf(" 3. Load a new data file\n");
	printf(" 4. Export data file in report format\n");
}
