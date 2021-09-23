#ifndef LIST_H
#define LIST_H

/* Programmer: Arturo Lopez
 * Date: 5/14/2019
 * CISC 187
 * Assignment 7
*/

#include <iostream>
using namespace std;
/*
 * List.h declares functions that will be used by
 * main in order to manipulate a linked list.
 */
class List
{
	private:
		struct Node
		{
			int index;
			char let;
			struct Node *next;
		};
		Node *head;
		int countNodes(Node *) const;
	public:
	    //constructor
		List(): head(nullptr){}
		//destructor
		~List();

		void append(char letter);
		int insert(char letter);
		int deleteNode();
		void reverse();
		void print() const;
		int search(char letter);
		/* Name: numNodes
		 * parameters: none
		 * returns: none
		 * This function will call the function
		 * countNodes that will count the total
		 * number of nodes.
		 */
		void numNodes()
		{
			 cout << " The number of nodes is " << countNodes(head) << endl;
		}
		/* Name: maxNode
		 * parameters: none
		 * returns: none
		 * This function will call the function
		 * findMaxNode that will display the
		 * largest element in the list.
		 */
		void maxNode()
		{
		 	cout << "The largest element in the list is "<< findMaxNode(head) << endl;
		}

		char findMaxNode(Node *) const;
};
#endif
