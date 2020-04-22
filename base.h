#ifndef _BASE_H_
#define _BASE_H_
#include <stdlib.h>
#include "record.h"

// function prototypes
//void print_all_records(Participant[]);
//void register_pcp(Participant participants[]);
//void ld_data(Participant participants[],char * filename);
void create_pcp(linkedList *my_list,Participant* pcp, int* number_to_add);
void add_pcp_from_k(Participant* pcp);
void add_pcp_from_d(linkedList *my_list,Participant* pcp);
void create_new_node(linkedList *my_list,Participant* tpcp);
void print_all_nodes(linkedList *my_list);
void print_name_nodes(linkedList *my_list);
void print_phone_num_nodes(linkedList *my_list);
void print_age_nodes(linkedList *my_list);
void print_school_nodes(linkedList *my_list);
void print_group_num_nodes(linkedList *my_list);
void print_nodes(linkedList *my_list);
void export_entire_data_in_report(linkedList *my_list);
void read_entire_data_from_file(linkedList *my_list);
void write_entire_data_to_file(linkedList *my_list);
void find_node_to_update(linkedList *my_list);
void update_the_node(linkedList *my_list, Participant *pcp);
void print_update_data(Participant *pcp);




#endif
