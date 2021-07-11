// Fig. 20.5: Fig20_05.cpp
// List class test program.
#include <iostream>
#include <string>
#include "List.h" // List class definition
#include "List2.h"
using namespace std;

// display program instructions to user

void instructions( void )
{ 
   cout << "Enter your choice:\n"
        <<  "   1 to insert an element into the list in order.\n"
        <<  "   2 to delete an specified element from the list.\n"
        <<  "   3 to insert at beginning of list\n" 
        <<  "   4 to insert at end of list\n" 
        <<  "   5 to delete from beginning of list\n" 
        <<  "   6 to delete from end of list\n" 
        <<  "   0 to end.\n" ;
}

// function to test a List

void testList( List2 &listObject, const string &typeName )
{
   cout << "Testing a List of " << typeName << " values\n";

   instructions(); // display instructions

   int choice; // store user choice
   int value; // store input value

   do // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
        case 1:
            cout << "Enter " << typeName << " to be inserted inorder: ";
            cin >> value;
            listObject.insertInOrder( value );
            listObject.print();
            break;
         case 2: 
            cout << "Enter " << typeName << " to be deleted: ";
            cin >> value;

            if ( listObject.deleteFound( value ) != -1) { 
                cout << value << "deleted.\n" ;
                listObject.print();
               }
            else
                cout << value <<"not found or list is empty\n\n";
            break;
         case 3: // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 4: // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 5: // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 6: // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
      } // end switch
   } while ( choice !=0 ); // end do...while

   cout << "End list test\n\n";
} // end function testList

int main()
{
   // test List of int values
   List2 integerList;
   testList( integerList, "integer" ); 
} // end main

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
