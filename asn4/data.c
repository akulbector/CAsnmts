#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

//Creates a key
Key *key_construct(char *in_name, int in_id) {



	//Dynamically allocate memory for key	
	Key *k= (Key *) malloc(sizeof(Key));
	//Assigns the id of the key to in_id
	(*k).id = in_id;
	//duplicate name
	(*k).name = strdup(in_name);
	return k;

}


//Compares the names of two keys,
//if they are identical then it compares the id of the keys
int key_comp(Key key1, Key key2) {
	//Compares the strings
	int result  = strcmp(key1.name, key2.name);
	//Uses this if the strings are identical
	int res2 = key1.id - key2.id;
	
	//If the strings are not the same, return the first result
	if(result < 0) {
		return result;

	} else if(result > 0) {
		return result;

	} else{
		//if the strings are the same, return the second result
		return res2;
	}


}

//prints a key
void print_key(Key *key) {
	//prints char array
	printf("Key= (name: ");
	fputs(((char *)((*key).name)),stdout);
	//prints id
	printf(", ID: %d), ",(*key).id);

}

//prints a node
void print_node(Node node) {
	printf("Node= (");
	//prints key
	print_key(node.key);
	//prints data
	printf("data:%d)\n",node.data);

}

