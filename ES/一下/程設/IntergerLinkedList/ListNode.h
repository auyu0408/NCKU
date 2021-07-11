// Fig. 20.3: ListNode.h
// Template ListNode class definition.
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 13
class ListNode 
{
   friend class List; // make List a friend
   friend class List2;
public:
   ListNode( const int & ); // constructor
   int getData() const; // return data in node
private:
   int data; // data
   ListNode *nextPtr; // next node in list
}; // end class ListNode

// constructor
ListNode::ListNode( const int &info )
   : data( info ), nextPtr( 0 ) 
{ 
   // empty body
} // end ListNode constructor

// return copy of data in node
int ListNode::getData() const 
{ 
   return data; 
} // end function getData

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
