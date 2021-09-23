
#include "List.h"

/* Programmer: Arturo Lopez
 * Date: 5/14/2019
 * CISC 187
 * Assignment 7
*/
/* Name: ~List()
 * parameters: none
 * The destructor will clear out the memory
 * of nodes in the linked list along with the
 * head pointer.
 */
List::~List()
{
	Node* ptr = head;
	Node* temp;
	 while(ptr != NULL){
	 	temp = ptr;
	 	ptr = ptr->next;
	 	delete temp; // release the memory pointed to by temp
	 }
}
/* Name: append
 * parameters: char letter
 * returns: none
 * This function will append a node to the
 * linked list, but the letter has to be
 * a capital letter.
 */
void List::append(char letter)
{
	Node *newNode; //point to a new node
	Node *temp;//will traverse the Linked List

	cout << "append node " << endl;
	newNode = new Node;
	newNode->let = letter;
	newNode->next = nullptr;
	if(!isupper(letter))
	{
		cout << "Letter should be capitalized. Program exiting!" << endl;
		exit(EXIT_FAILURE);
	}
	if(head == nullptr)
	{
		head = newNode;
	}
	else
	{
		temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
/* Name: insert
 * parameters: char letter
 * returns: int
 * This function will insert a node to the
 * linked list in a specific position chosen
 * by the user, but the letter has to be
 * a capital letter. Will return the position
 * the node was inserted into otherwise -1 if not found.
 */

int List::insert(char letter)
{
     Node *newNode; //point to a new node
     Node *curr;//will traverse the Linked List
     Node* prev = nullptr;
     int index = 0;
     int choice;
     int size;
     curr = head;
     cout << "Please enter the place to add the new node" << endl;
     cin >> choice;
     //create the new node
		 if(!isupper(letter))
	 	{
	 		cout << "Letter should be capitalized. Program exiting!" << endl;
	 		exit(EXIT_FAILURE);
	 	}
     newNode = new Node;
     newNode->let = letter;
     newNode->next = nullptr;

	//check if list is empty
	 if(head == nullptr)
	 	head = newNode;
	 //insert the new node in the first position
     if(choice == 0)
     {
      curr = head;
      head = newNode;
      head->next = curr;
      return choice;
     }
     else
     {
      while(curr && (index < choice))
      {
       index++;
       prev = curr;

       curr = curr->next;

       }
       prev->next = newNode;
       newNode->next = curr;
       return index;
      }
      return -1;
}
/* Name: search
 * parameters: char letter
 * returns: index
 * This function will search for a node in the
 * linked list in a specific position chosen
 * by the user. If the letter is found the index
 * will be returned. Otherwise -1 will be returned
 * if not found.
 */


int List::search(char letter)
{
	if(!isupper(letter))
	{
		cout << "Letter should be capitalized. Program exiting!" << endl;
		exit(EXIT_FAILURE);
	}
	Node* curr;
	curr = head;
	int index = 0;

	cout << "search " << endl;
	//if list is empty
	if(head == nullptr)
		return -1;
	while(curr != nullptr)
	{
	 if(curr->let == letter)
 	{
  		index++;
  		return index;
 	}

 	index++;
 	//move current to next node
 	curr = curr->next;
	}
	return -1;
}

/* Name: deleteNode
 * parameters: none
 * returns: index
 * This function will delete a node in the
 * linked list in a specific position chosen
 * by the user. If the letter is deleted the index
 * will be returned. Otherwise -1 will be returned
 * if not found.
 */

int List::deleteNode()
{
    Node *curr;//will traverse the Linked List
    Node* prev = nullptr;
   // Node* after = nullptr;
    int index = 0;

    int choice = 0;

    curr = head;
    //check if list is empty
    if(head == nullptr)
    	return -1;
    cout << "delete " << endl;

    cout << "Please enter the place to delete the node" << endl;

     cin >> choice;

 	//if the choice is the first element
     if(choice == 0)
     {
      head = curr->next;

      curr = nullptr;
      return choice;
      }
      else
      {
      index++;
      prev = curr;

      curr = curr->next;

	  // will traverse the list until we reach the end
      while(curr)
      {
      if(index == choice)
       {

        if (curr->next != nullptr)
        {
          prev->next = curr->next;
          curr->next = nullptr;
        }
        else
        {
          prev->next = nullptr;
          curr = nullptr;

          break;
         }
       }
        prev = curr;
        curr = curr->next;
        index++;
       }
        return index;
        }
       return -1;
}
/* Name: print
 * parameters: none
 * returns: none
 * This function will print the linked list.
 * Will traverse the linked list from beginning to end.
 */

void List::print() const
{
	Node *temp;

	temp = head;

	cout << "Printing list " << endl;
	//will traverse until it reaches the end
	while(temp != nullptr)
	{
		cout << temp->let << endl;
		temp = temp->next;
	}
	temp = nullptr;

}

/* Name: reverse
 * parameters: none
 * returns: none
 * This function will reverse the
 * linked list. Where the head will
 * point to the last element of the list.
 */

void List::reverse()
{

  	 Node* curr;

   	 Node* prev = nullptr;

  	 Node* after = nullptr;
	cout << "reverse " << endl;
   	 curr = head;

     while (curr)
     {

     //Store the next node
      after = curr->next;
     //Reverse the current node's pointer
      curr->next = prev;

     //Move pointers one position ahead;
      prev = curr;

      curr = after;
     }
     head = prev;
}
/* Name: countNodes
 * parameters: List* node
 * returns: int number of nodes
 * This function will return the
 * total number of nodes within the List.
 * Otherwise if there are no elements then 0
 * will be returned.
 */
		int List::countNodes(Node *node) const
		{
			if(node != nullptr)
			{
				return 1+countNodes(node->next);
			}
			else
				return 0;
		}

		/* Name: findMaxNode
		 * parameters: List *node
		 * returns: largest char
		 * This function will return the largest
		 * character within the List. If the list is
		 * empty then the program will close. Otherwise
		 * the largest character will be returned
		 */
		char List::findMaxNode(Node *node) const
		{
			//will check that list empty
			if(node == nullptr)
			{
				cout << "List is empty, program closing!" << endl;
				exit(EXIT_FAILURE);
			}
			char largest = node->let;

			char curr;
			//will check if there is only one element
			if(node->next == nullptr)
				return largest;
			else{
				curr = findMaxNode(node->next);
			}
			if(largest > curr)
				return largest;
			else
				return curr;

		}
