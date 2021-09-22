Project 1: Tokenizer
Instructions:
You should document your tokenizer in this file.

This file is written in the refreshingly simple markdown text formatting language.

To learn about text formatting using markdown, we encourage you to examine

../README.md
the online Markdown Guide.
Main:
In the main method of my gui.c file I will be declaring all the variables such as int, char , char*, and some additional arrays which were used for testing at the time this was made. In the main method I called...

space_char
non_space_char
word_start
word_end
count_words
copy_str
tokenize
free_tokens
then from the history.c file I would call on these methods...

init_history
add_history
get_history
free_history
space_char and non_space_char methods:
In the space_char method I was assigned to find if there was a space in the character input and to say that if it is a space(' ') then I return True (1 in this case), if not I return False(0 in this case).

The non_space_char method is essentially the same method only that if the current char that you have is not a space then you return True, since thats what we're looking for, also we return false if the char is a space.

word_start and word_end methods:
The purpose of the word start method is to find the first char in our string, so to achieve that I needed to traverse the pointer data type that holds our collection of chars and get the letter at the first index. In this case if the first char we find is not a space then we return the value in the pointer index.

In word_end I had to get the opposite result of word_start, so what I mean is that I needed to get the last non space char in the pointer. So what I did, was to traverse the pointer until we find that the NEXT INDEX is equals to '\0'. The reason why I want to know when the next index is that, is because '\0' will always be located after the last character. Once I found that I return the value in the pointer index before that.

count_words method:
For this method I just wanted to be able to count the amount of words we had in out pointer. So what I did I would traverse the pointer and when I encounter a space then a counter would increase. But after I finished counting I would add 1 to the counter. So if I had "hello world" I would return 2 for 2 words instead.

copy_str method:
For this method I would need to copy a pointer into a new pointer and decide how many chars I want to copy based on the integer input. The way I did this was to allocate memory on a copy pointer based on the amount of chars we want and having the same data type. Doing so I wanted to traverse the original pointer by the length that we were give. So if we had an input of 3 with the word "hello world" then we would copy "hel" and return the copy pointer.

tokenize method:
For this method I will be using many of the methods from before including some helper methods which are...

word_start_index
word_end_index
find_space_index
copy_str
count_words
To begin, in this method im supposed to return a double pointer which will tokenize the single pointer. which the output if we used "hello world" should return...

tokens[0] = "hello"
tokens[1] = "world"
So in my program there were many ways I went about it until I found the best way for me. So what I did was that I needed to first allocate new memory for the double pointer by using the count_words method to get the current size of the single pointer. Also to be safe I copied the entire single pointer into another to not lose it in such a big and complex method.

After thats done, now its time to tokenize, so to do this first we traverse the single pointer and if we find a space char then we would do this. we would get the integer value of where the first char is at by using word_start_index (does the same process as word_start but returns the int position of the index), then we will get the integer value where the space was found by using find_space. Now we do some simple math to determine the length of our word which that length would be passed into the copy_str method along with the single pointer.

When we copy the string then we would containe it in another single pointer, which we would later use a count to work as the individual index for our double pointer. When using the double pointer at the current count we will store the copy ptr we had and then increase our count(index).

Now we need the rest of the strings, so to do thhis if we reach the next index that is '\0' then we will do more calculations. So to start I need to get the position of the current so we subtract the index by the length and then find the position of the last char using word_end_index. We then update the length by subtracting both values and send the length to the copy_str along with the index we want to start in our pointer. After we do the same as before and store the copy in the double pointer.

free_tokens method:
For this piece of code, I needed to free all the tokens allocated in the double pointer. so what I did was essentially use the free command which will de-allocate all of our tokens making it unuseable for the future.

History File:
For the history file I would depend on using a Linked List which my knowledge of it depends on my CS3 and arch course. But to begin we will depend on these methods...

init_history
add_history
print_history
get_history
free_history
init_history method:
The purpose of this method is to essentially work as our constructor, so what we have to do to begin is to create an empty list then allocate space for it by its object data type, which the same would apply for item which is a different type than the list.

Now with that done we need to declare our variables. So the list at the root (head) will store the item. The item's id(node position) will be declared as zero. The items string will be declared as an empty string for now. Then the next item node will be NULL since we have yet to store anything inside of it. Now the constructor is fully functional and we can make our Linked list.

add_history method:
In this method we want to add a collection of data into our linked list, so to do so based on programming principles, we always save our linked list's head in a copy of it so we don't lose the original. After we want to make an integer that will work as our id(position) for our nodes.

To start creating our linked list I first wanted to check if our list was empty, so to do that I wanted to check the id of the node and if it was equals to zero then we would have to populate its string and index which the first id will be 1 instead of zero due to me not wanting to override our first item every time we called the method.I tried to check if our root was null but since we needed to populate the nodes,I wasn't allowed access to it since its a different type (tried to replicate list.head == NULL in java to c).

After we populated the first position, I then made a while loop to traverse the Linked list until we found the next node that was Null. If the next node was not null, then we would shift to the next node and increment our node_pos. When we find the next node that is null then we proceed out the loop and succesfully traversed to the last node we have.

outside the loop we would increment our current node_pos by 1 and then allocate new memory for 1 new node in the next position. With an empty node allocated we store our str inside the next node then the new position in it which would represent it as our id. We have now made it possible to add an item in our list, however we still need to declare the position after our next as null since we require the while loop to traverse our list.

print_history method:
For this method all I had to do was to print the entire content of each node which inlcudes the id and the str only. To start off, make a copy of the head to keep it safe then traverse the list until we get to the Null node. Each time we traverse we print the id and the str then shift on to the next node available.

get_history method:
This method whats us to return the node that is in a specific index so if I had "hello world" and the index given to me is 1 then I would return hello since I start at 1. As always keep the head safe and traverse the list till we reach a null position, in the loop we want to compare id's so if our current id is the same as the one given to us then we return the str. If not then we shift to the next node to check if we have one of the same id. If the id given to us does not exist in the list then we return NULL.

free_history method:
Its almost the same as free tokens, but here we are trying to deallocate our existing list which will not be usable anymore. So what I did was to use the free command once more.
