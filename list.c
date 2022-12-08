// list/list.c
//
// Implementation for linked list.
//
// <Traven Reese>

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
 }

node_t *node_alloc() { 
  node_t *node = (node_t*)malloc(sizeof(node_t));
  node->next = NULL;
  return node;
 }

//node free
void node_free(node_t *n) {
  free(n);
}

void list_free(list_t *l) {
  node_t *tmp;
  node_t *next;
  // if (l == NULL)
  //   return;
  tmp = l->head;
  while (tmp != NULL) 
  {
    next = tmp->next;          
    free(tmp);
    tmp = next;
    }
  free(l->head);
  l->head = NULL;
}


  //Prints the list in some format.
void list_print(list_t *l) {
  node_t *curr = l->head;
  if (curr != NULL) {
    while (curr != NULL) {
      printf("%d ",  curr->value);
      curr = curr->next;
    }
  }
}


//Returns the length of the list. 
int list_length(list_t *l) {
  node_t *temp = l->head;
  int count = 0;

  while (temp != NULL) {
    count += 1;
    temp = temp->next;
  }
  printf("%d", count);
  return count;
}


//Methods for adding to the list.
void list_add_to_back(list_t *l, elem value) {
  node_t* new_node = node_alloc();
  if (l->head == NULL) {
    new_node->value = value;
    l->head = new_node;
  } 
  else {
    node_t *temp = l->head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    if (temp->next == NULL) {
        new_node->value = value;
        temp->next = new_node;
      }
  }
}

void list_add_to_front(list_t *l, elem value){
  node_t* new_node = node_alloc();

  if (l->head == NULL){
    new_node->value = value;
    l->head = new_node;
    } 

  else {
    new_node->value = value;            
    node_t* temp = l->head;             
    l->head = new_node;                 
    new_node->next = temp;              
    }
  }

// adds to end of list if out of bounds CHECK THIS ONE
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *temp = l->head;
  node_t *new_node = node_alloc();
  new_node->value = value;
  int count = 0;
  if(index == 0){
    list_add_to_front(l,value);
    
  }
  else{
    while(temp != NULL){
      if (count + 1 == index){
        new_node->next = temp->next;
        temp->next = new_node;
        break;

      } 
      else{
        count += 1;
        temp = temp->next;
      }
    }
  }
  if (count < index){
    list_add_to_back(l, value);
  }

}

elem list_remove_from_front(list_t *l) { 
  if (l->head == NULL) {
    printf("Empty list");
    } 
  else {
    node_t *curr = l->head;

    
    curr = curr->next;
    l->head = curr;
      }
  }


elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) {
    printf("Empty list");
  } 
  else {
    node_t *temp = l->head->next;
    node_t *prev = l->head;
    while (temp->next != NULL) {
      temp = temp->next;
      prev = prev->next;
    }
    if (temp->next == NULL){
        prev->next = NULL;
      } 
  }
}

elem list_remove_at_index(list_t *l, int index){
  node_t *curr = l->head;
  node_t *prev = node_alloc();

  if (l->head == NULL) {
    printf("Empty list");//098765432
    return -1;
  } 
  
  int count = 0;
  if(index == 0){
    list_remove_from_front(l);
  }
  else{
    while(count != index){
      prev = curr;
      curr = curr->next;
      count +=1;
    }
    node_t *rest_list = curr->next;
    prev->next = rest_list;
  }
  return -1; 
  }

//Checks to see if the given element exists in the list.
bool list_is_in(list_t *l, elem value) 
 { 
  node_t *curr = l->head;

  if (l->head == NULL) {
    printf("Empty list");//098765
    return false;
  } 

  while(curr){
    if(curr->value == value){
      printf("true");
      return true;
    }
    else{
      curr = curr->next;
    }
  }
  printf("false");
  return false; 
  }

//Returns the element at the given index, or -1 if empty or out of bounds 
elem list_get_elem_at(list_t *l, int index) {
  node_t *temp = l->head;

  if (l->head == NULL) {
    printf("%d", -1);
    //printf("Empty list");//-0987654567iuy
    return -1;
  } 

  int count = 0;
  int final_value = 0;
  
  while (temp != NULL) {
    if (count == index) {
      printf("%d", temp->value);
      return temp->value;
    } 
    else {

      temp = temp->next;
      count += 1;
      
    }
    
    
  }
  printf("%d", -1);
  return -1;
}
//Returns the index at which the given element appears, or -1 if not found
int list_get_index_of(list_t *l, elem value) {
  node_t* current = l->head;

  if (l->head == NULL) {
    printf("%d", -1);
    //printf("Empty list");//098yfcvbnb
    return -1;
  } 

  int count = 0;

  while (current){
    if (current->value == value){
      printf("%d", count);
      return count;
  }
    else {
      current = current->next;
      count += 1;
    }
  }

  printf("%d", -1);
  return -1;
  
  //return 0;
  }
