#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


BStree bstree_ini(int size) {
	//Dynamically alocate memory for bstree
	BStree bstree = (BStree) (malloc(sizeof(BStree_struct)));
	//dynamically allocate memory for node array
	(*bstree).tree_nodes = (Node *) (malloc(sizeof(Node)*size+1));
	//dynamically allocate memory for unsigned char array
	(*bstree).is_free = (unsigned char *) (malloc(sizeof(unsigned char)*size+1));

	//initialize all value of is_free to '1'
	for(int i=0; i<size+1;i++) {
		((*bstree).is_free)[i] = '1';
	}

	//sets the size
	(*bstree).size = size;

	return bstree;

}

//k indicates the position in the node array
int k = 1;
void bstree_insert(BStree bst, Key *key, int data) {


	if(k>(*bst).size) {


		printf("Insertion error: index out of bounds\n");
	
		printf("Hint: you might want to use a larger bst\n");
		return;//exit
	}
	//If the node is free
	if((*bst).is_free[k]=='1') {
		//Make the node NOT free
		(*bst).is_free[k]='0';
		//Put the key and data into the node
		(*bst).tree_nodes[k].key = key;
		(*bst).tree_nodes[k].data = data;
		//reset the position variable k back to 1
		k = 1;

		//
	}
	//If the key to be stored is less than the current key
	else if(key_comp(*(((*bst).tree_nodes)[k]).key,*key)>0) {
		//Go to the left child and call insert recursively
		k = k*2;
		bstree_insert(bst, key, data);


	}
	
	//If the key to be stored is greater than the current key
	else if(key_comp(*(((*bst).tree_nodes)[k]).key,*key)<0) {
		//Go to the right child and call insert recursively
		k = k*2 +1;
		bstree_insert(bst, key, data);
	}
}




//j indicates the position in the array
int j = 1;
void bstree_traversal(BStree bst) {
	//If out of bounds, do nothing
	if(j>(*bst).size) {
		return;
	}
	//If the node is empty, do nothing
	else if((*bst).is_free[j]=='1') {
			return;
	}
	else {
		//Traverse left node
		if((*bst).is_free[j*2]!='1') {

			j = j*2;
			bstree_traversal(bst);
			j = j/2;
		}

		//Traverse root node
		print_node((*bst).tree_nodes[j]);

		//Traverse right node
		if((*bst).is_free[j*2+1]!='1') {

			j=j*2+1;
			bstree_traversal(bst);
			j=(j-1)/2;
		}
	}
}


int main() {
	BStree bst2;

	int size;
	printf("Enter the size of your bst: ");
	scanf("%d",&size);
	printf("Enter triples to insert into bst\n");
	printf("Enter EOF character to end input\n");
	bst2 = bstree_ini(size);


	//Name to insert in key of node of  bst
	char name[50];
	//ID to insert in key of node of bst
	int  id;
	//data to insert in node of bst
	int  data;

	//Checks if end of file has been reached
	char eof = getchar();


	//Stop running at end of file
	while(eof!=EOF) {
		//Push back first char
		ungetc(eof, stdin);
		//Get information as a triple
		scanf("%s %d %d", name, &id, &data);
		//Insert int to bst
		bstree_insert(bst2,key_construct(name,id),data);
		//Get next char to go to next line
		eof = getchar();
	}

	//print tree inorder traversal
	bstree_traversal(bst2);

}
