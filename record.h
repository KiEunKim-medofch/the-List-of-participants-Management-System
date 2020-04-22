#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct participant{

	// TODO: define your own structure type here
  char name[30]; // the name of the participant
  char phone_num[20]; // the phone number of the participant
  int age; // the age of the participant
  char n_highsch[30]; // the name of the particiapant’s highschool
  int gr_num;// the number of the group to which the participants belong

} Participant;


typedef struct node
{
  Participant pcp;
  struct node * link;

}node;

typedef struct linkedList
{
  node *head, *tail;

}linkedList;

#endif

