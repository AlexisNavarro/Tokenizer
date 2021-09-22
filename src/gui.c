#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"
#include "history.c"

#define LIMIT 100

//custom helper methods for my code
int find_space(char *ptr);
int word_start_index(char *ptr);
int word_end_index(char *ptr);


int main(){
  char c;
  char str[LIMIT];
  char *first_word;
  char *last_word;
  char *copy;
  char **tokens;
  
  int is_space = 0;
  int is_non_space = 0;
  int i = 0;
  int j = 0;
  int amount_words =0;
  int go = 1;
  char in;
  
  //while(go){
  printf("ENTER YOUR INPUT: \n");
  char *inStr = (char *)malloc(LIMIT);

  while((c = getchar()) !='\n'){
    putchar(c);
    
    is_space = space_char(c);
    is_non_space = non_space_char(c);
    
    printf("\tis white space %d\n",is_space);
    printf("\tis non-white space %d\n", is_non_space);
    
    str[i] = c; //making a string of chars
    *(inStr + i) = c; //making an allocated pointer that will be a string 
    i++; //index for the string of chars
  }//end while
  
  *(inStr +99) = '\0';
  str[i]='\0';
  printf("YOUR INPUT IS: %s\n\n",str);//print out the input as a string of characters.

  // char *ptr = str;
  char *ptr2 =inStr;

  first_word = word_start(ptr2);
  printf("The first word is: %c\n",first_word);

  last_word = word_end(ptr2);
  printf("The last word is: %c\n\n", last_word);
  amount_words = count_words(ptr2);
  printf("The amount of words is: %d\n\n", amount_words);

  copy = copy_str(ptr2,2);
  printf("The copy string is: %s\n\n", copy);
  
  //tokens = tokenize(ptr2);
  tokenize(ptr2);
  //free_tokens(tokens);
  //printf("the tokens are: %s\n", tokens);

  //history calls
  List *LL = init_history();

  add_history(LL,ptr2);
  print_history(LL);
  
  char *hist = get_history(LL, 1);
  printf("the word is: %s\n", hist);

  free_history(LL);
  printf("the list is now: %s\n", LL);

  //printf("enter n to exit \n");
  //in = getchar();

  //if(in == 'n'){
  //go = 0;
  //}
  
  //}//end while
  }//end main



int space_char(char c){
  if(c == ' ' || c == '\t'|| c =='\n')
    return 1;
  else
    return 0;
}//end space_char


int non_space_char(char c){
  //if(c != ' '|| c != '\t'|| c != '\n')
  if(c!=' ')
   return 1; //returns true
  else
    return 0; //returns false
}//end non_space_char


char *word_start(char *str){
  int i=0;
  
   for(i = 0; *(str+i) != '\0'; i++){
     if(*(str+i) != ' '){
      
       // printf("first word is %c\n", *str);
       return *(str+i);
     }
  }//end for loop
}//end word_start


char *word_end(char *str){
  int i = 0;
  
  for(i =0; *(str+i) != '\0'; i++){
      if(*(str+i+1) == '\0'){
	
	// printf("next letter is %c\n",*(str+i));
      return *(str+i);
      }//end if
  }//end for loop
}//end word_end


int count_words(char *str){
  int i; 
  int count = 1; //Assuming we will have one word atleast
  
  for(i = 0; *(str+i)!='\0';i++){
    if(*(str+i) == ' '){ //Every time there's a space then we will count the spaces and get the amount of words from there

       count++;
      }
  }//end for
  return count;
}//end count_words


char *copy_str(char *inStr, short len){
  int i=0;
  char *copy ="";

  copy = (char *)malloc(len);

  for(i = 0; i <= len; i++){
    *(copy+i) = *(inStr+i);
    //printf("the copy char is %c\n", *(copy+i));
  }
  //printf("The  final copy is %s\n", copy);

  return copy;

}//end copy_str

int word_start_index(char *str){
  int i=0;
  for(i =0; *(str +i) !='\0';i++){
    if(*(str+i) != ' '){
    return i;
   }
  }//end for loop

}//end word_start_index

int word_end_index(char *str){
  int i =0;
  for(i =0; *(str + i) != '\0'; i++){
    if(*(str + i + 1) == '\0'){
      return i;
    }//end if
  }
}//end method

int find_space(char *str){
  int i = 0;
  for(i = 0; *(str + i) != '\0'; i++){
    if(*(str +i) == ' '){
      //return *(str+i);

      return i;
    }
    
  }//end for loop
}//end entire_word


char **tokenize(char *str){
  int i = 0;
  int start = 0;
  int end;
  int space_index = 0;
  int length = 0;
  int count = 0;
  int pos = 0;
  int num_words=0;
  char *curr;
  char *ptr;
  char **tokens;

  num_words = count_words(str);
  curr = str;
  tokens = (char **)malloc(sizeof(char*)*num_words);//trying to allocate memory for the double pointer
  
  for(i= 0; *(str+i)!='\0'; i++){
    if(*(str+i) == ' '){ //this if statement will tokenize the first word once the first space is found
      
      start = word_start_index(curr);
      space_index = find_space(curr);
      length = space_index - start;
   
      ptr= copy_str(curr, length);
      //printf("the new token is: %s\n", ptr);
      *(tokens+count) = ptr;
      count++;
   }//end if

    //WIP this is supposed to tokenize whats in the middle of the string.
    //if(*(str +i) == ' ' && *(str+i+1) != ' '){
      //pos = i - length;
      //space_index = find_space(curr);
      //space_index=+1;
      //end = word_end_index(curr);
      //length = end - space_index+1;
      //printf("the len is: %d\n", end);

      //ptr = copy_str(curr+pos, length);
      //printf("the middle token is %s\n", ptr);
      //*(tokens+count) = ptr;
      //count++;
    //}//end if
    


  
    if(*(str+i+1) == '\0'){//this if statement will tokenize once it finds that the next postition is a null space.
      
      pos = i -length;// get the starting position of the index after the current space
      end = word_end_index(curr);//gets the final index of the string
      length = end - pos;
     
      
      ptr = copy_str(str+pos+1, length);
      //printf("the token on 2nd if is: %c\n", ptr);
      *(tokens+count) = ptr;
      count++;
    }//end if
   }//end for loop

  //prints the tokens, DO NOT TOUCH!
  int j = 0;
  while(*(tokens+j) != '\0'){
    printf("the tokens are: %s\n",*(tokens+j));
    j++;
  }
  
}//end tokenize


void free_tokens(char **tokens){
  free(tokens);
}//end free_tokens
