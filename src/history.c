   
#include <stdio.h>
#include <stdlib.h>
#include "history.h"


int main(){
List *list = init_history();

add_history(list, "hello");
add_history(list, "world");
add_history(list, "are you good");

print_history(list);

  //char *hist = get_history(list, 1);
  //printf("the word is: %s\n", hist);

  //free_history(list);
  //printf("the list is: %s\n", list); 
}//end main

List *init_history(){
  List *list = NULL;
  list = malloc(sizeof(List)*1);

  Item *item = NULL;
  item = malloc(sizeof(Item)*1);

  //declaring the variables for our list and item structure.
  list -> root = item;
  item -> id = 0;
  item -> str ="";
  item -> next = NULL;
  return list;

}//end init_history

void add_history(List *list, char *str){
  Item *temp_list = list->root; //making a copy of of current item in the root so we don't lose it
  int node_pos = 0;

  //NEED THIS STATEMENT IF NOT THE ZERO NODE WILL NOT BE POPULATED!!!
  if(temp_list->id == 0){ //if we have nothing in our list then we populate the first node
      
    temp_list->str = str;
    temp_list->id = node_pos+1;
    return; //need to return the root cause if not we will repeat the root twice in our output. Also we exit since we successfully added the first item.

  }else{


    while(temp_list->next != NULL){//just to count and traverse the nodes that we have in the list.
      temp_list = temp_list->next;
      node_pos++;
    }//end while

    node_pos = node_pos + 2;// identify the next position in our list
  
    temp_list->next = malloc(sizeof(Item));//allocate memory for the next node in the list.
    
    temp_list->next->str=str; //add the next str in the next node.
    temp_list->next->id = node_pos;//add the next value of id.
    temp_list->next->next = NULL;//make the next-next node null, but in this case it would be the last position.
  
    }//end if
}//end add_history


void print_history(List *list){
  Item *temp_list = list->root;//keep our head safe
  
  while(temp_list != NULL){
    printf("the id is: %d and the word is: %s \n", temp_list->id, temp_list->str);
    temp_list = temp_list->next;// point to the next item in our list
    
  }//end while
  
}//end print_history

char *get_history(List *list, int id){
  Item *temp_list = list->root;

  while(temp_list != NULL){
    if(temp_list->id == id){//if the id in our current position is the same as the id we want then we return the str in that position.
      return temp_list->str;
    }
    temp_list = temp_list->next;
  }

  return NULL; //return NULL if the id doesn't exist.
}//end get_history


void free_history(List *list){
  free(list);
}//end free_history
