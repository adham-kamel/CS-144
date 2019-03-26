#include "SortedLinkedList.h"
#include <string>
#include <iomanip>

/***** Complete this class. *****/

SortedLinkedList::SortedLinkedList() {
	head = nullptr;
	length = 0;
}

void SortedLinkedList::insert(Node *node) {
	/*
	 if (head != nullptr) {
	 printf("Node: (%d,%d), Head: (%d,%d)\n", node->getRow(), node->getCol(),head->getRow(), head->getCol());
	 printf("Head > Node: %d\n\n\n\n", *head > *node);
	 }
	 */
	if (head == nullptr || *head > *node) {
		node->next = head;
		head = node;
		length++;
	} else {
		Node *current = head;
		while (current->next != nullptr && *node > *current->next) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
		length++;
	}
}



ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
   Node* previous = list.head;
   Node* current;
   int new_row = 0, printed = 0, current_position = 0;

   if (previous != nullptr && previous->getRow() > 0)
   {
      for (int i = 0; i < previous->getRow(); i++)
         outs << endl;
   }

   outs << setw(previous->getCol()) << *previous;

   if (previous->getName() == "")
      current_position = previous->getCol();
   else
      current_position = previous->getCol() + previous->getName().length() + 1 + previous->getState().length();

   current = previous->next;

   while (current != nullptr)
   {
      if ( current->getRow() > previous->getRow() ) //To check every node if it can be printed in the same line or in a new line
      {
         new_row = 1;
         for (int i = 0; i < (current->getRow() - previous->getRow()); i++)
            outs << endl;
      }
      if (new_row == 0)
      {
         if ( current->getCol() > current_position ) //To check if the current node position overlaps an already printed node
         {
            outs << setw(current->getCol() - current_position) << *current;
            printed = 1;
         }

         if ( printed == 1 ) //Update the current cursor position only if the current node was printed
         {
            if ( current->getName() == "" ) //Check if the node is a boundary
            {
               current_position = current->getCol(); //current cursor position is after printing #
               printed = 0;
            }
            else //Check if the node is a city
            {
               //current cursor position is after printing *+name+SPACE+state
               current_position = current->getCol() + current->getName().length() + 1 +  current->getState().length();
               printed = 0;
            }
         }
      }
      else
      {
         outs << setw(current->getCol()) << *current;

         if (current->getName() == "")
            current_position = current->getCol();
         else
            current_position = current->getCol() + current->getName().length() + 1 + current->getState().length();
         new_row = 0;
      }

      previous = current;
      current = current->next;
   }

   //Clean-up the program before it terminates by explicitly deleting the Node object that was created using the keyword new
   //All other objects will be automatically deleted as and when they go out-of-scope
   current = list.head;
   while (current != nullptr)
   {
      current->~Node();
      current = current->next;
   }
   return outs;
}

//ostream& operator <<(ostream& outs, const SortedLinkedList& list) {
//	Node *current = list.head;
//	while (current != nullptr) {
//		if (!current->getName().empty()){
//			outs << current->getName() << "," << current->getState() << ",";
//		}
//		outs << current->getRow() << "," << current->getCol() << endl;
//		current = current->next;
//	}
//	return outs;
//}

