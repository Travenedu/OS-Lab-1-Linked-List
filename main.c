#include <stdio.h>
#include "list.c"


int main() 
{
  elem val;

  printf("Write your Tests for your linked list implementation\n");
  
  list_t *mylist = list_alloc();
  //tests

  //build list
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 15);
  list_add_to_back(mylist, 30);
  list_add_to_back(mylist, 40);
  list_add_to_back(mylist, 50);

  //Make linked list
  //print list
  printf("Original List: ");
  list_print(mylist);

  //Returns the length of the list
  printf("\nThe length of the list(5):");
  list_length(mylist);

  //adds items to index of list
  printf("\nadds items to index of list: ");
  printf("\nCorrect: 20 33 15 30 40 50");
  list_add_at_index(mylist, 33, 1);

  list_print(mylist);
    
  //Delete items from front of list
  printf("\nList after Deleting items from front of list: ");
  list_remove_from_front(mylist);

  list_print(mylist);

  //Delete items from end of list
  printf("\nList after Deleting items from end of list: ");
  list_remove_from_back(mylist);

  list_print(mylist);

  //Delete items from index of list
  printf("\nList after Deleting items from index 2 of list: ");
  list_remove_at_index(mylist, 2);

    list_print(mylist);

  //Check to see if item is in a list
  printf("\nCheck to see if item is in list(True): ");
  list_is_in(mylist, 40);
  
  //Returns the element at the given index but return -1 because its not there
  printf("\nCheck to see if item is in list(False): ");
  list_get_elem_at(mylist, 1);

  //Returns the index at which the given element appears, or -1 if not found 
  printf("\nReturns the index at which the given element appears: ");
  list_get_index_of(mylist, 10);

  //Returns the index at which the given element appears, or -1 if not found 
  printf("\nReturns the index at which the given element appears(False): ");
  list_get_index_of(mylist, 55);
  
return 0;
}
