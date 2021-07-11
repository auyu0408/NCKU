// Exercise 20.8 Solution: List2.h
// List2 class template definition
// Enhances List by adding insertInOrder.
#ifndef LIST2_H
#define LIST2_H

#include "ListNode.h"
#include "List.h"

class List2 : public List
{
public:
   void insertInOrder( const int);
   int deletefound( int );
}; // end class List2

// insert a node in order
void List2::insertInOrder( const int value )
{
   if (this-> isEmpty() ) // list is empty
   {
      ListNode *newPtr = this->getNewNode( value );
	  this->firstPtr = this->lastPtr = newPtr;
   } // end if
   else // list is not empty
   {
      if ((this->firstPtr)->getData() > value ) // value is the smallest
         this->insertAtFront( value );
      else if ( (this->lastPtr)->getData() < value ) // value is the largest
       this-> insertAtBack( value );
      else 
      {
         ListNode *currentPtr = firstPtr->nextPtr;
         ListNode *previousPtr = firstPtr;
         ListNode *newPtr = getNewNode( value );

         while ( currentPtr != lastPtr && currentPtr->getData() < value )
         {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
         } // end while

         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } // end else
   } // end else
} // end function insertInOrder

int List2::deletefound( int value)
{
   ListNode *previousPtr, *currentPtr, *tempPtr;

      previousPtr = NULL;
      currentPtr = firstPtr;
      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      }
   if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         delete tempPtr;
         return value;
      }
   else return -1;                                                        
}
#endif

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
