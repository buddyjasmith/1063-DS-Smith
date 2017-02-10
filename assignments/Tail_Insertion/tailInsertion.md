```cpp
/**
* @ProgramName: Program-2
* @Author: Buddy Smith
* @Description:
*    This program creates an instance of the class List, and creates an ordered list.
*    using the methods of the class List.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 08 02 2017
*/

#include <iostream>
#include <cstdlib>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

/**
 *  @ClassName: List
 *  @Description:
 *             Class creates a linked list with a Head Pointer and Tail pointer.
 *             Values can be inserted ordered, from the front, or rear of the list.
 *             Known data values of the list can be deleted specifically.
 *  @PublicMethods:
 *             void FrontSert()
 *             void EndSert()
 *             void OrderedSert()
 *             void PrintList()
 *             Bool DeleteNode()
 *  @Private:  Node *Head
 *             Node *Tail
 *
*/

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
      Tail = NULL;
    }
    /**
    * @FunctionName: FrontSert
    * @Description:
    *     Function inserts value into the first node of a linked list.
    *     The Head pointer points to the first value of the list. A tail will
    *     be used to point to the last node of the list.
    * @Params:
    *    int x--Value passed to the function to be inserted in the first node
    * @Returns:
    *    void
    */
    void FrontSert(int x){

      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;

      if(Head){             // head is not null
        Temp->Next = Head;  // temp.next points to head
      }
      Head = Temp;
      Node *Temp2 = Head;
      while(Temp2->Next != NULL){
            Temp2 = Temp2->Next;
      }
      Tail = Temp2;


    }
    /**
    * @FunctionName: EndSert
    * @Description:
    *      Creates a new node with the value x passed into the function.
    *      The new node is inserted into end of the linked list. Tail is
    *      repainted to this value.
    * @Params:
    *    int x-- value passed to the function to represent the value of the
    *            node being inserted in the end point.
    * @Returns:
    *    void
    */

    void EndSert(int x){

        Node *Temp = new Node;      // Temp is pointing to new node created for x
        Temp->Data = x;             // Temp.data assigned x value
        Temp->Next = NULL;          // Temp.next points to NULL
        if(Head == NULL){
            FrontSert(x);
        }
        else{
            Node *Temp2 = Tail;
            Temp2->Next= Temp;
            Tail = Temp;
        }
    }
    /**
    * @FunctionName: OrderedSert
    * @Description:
    *     Creates a temporary node with the value given. The node traverses
    *     the list and compares the values.  The nude is inserted depending
    *     on numerical order.
    * @Params:
    *    int x-- Data value passed to function.  A new node is created with
    *    this value.
    * @Returns:
    *    void
    */

    void OrderedSert(int x){
      // Memorize the three lines of new node allocation
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;

      // If there is NOT a head, point head to the new node
      if(!Head){
        Head = Temp;
      }else{
        //if x is less than head node, we essentially do a FrontSert
        if(x < Head->Data){
          Temp->Next = Head;
          Head = Temp;
        }else{
          // We need to set up a list traversal to find the proper insertion point of our data
          Node *Curr = Head;
          Node *Prev = Head;

          // Memorize the loop that traverses our list and find our proper insertion point.
          while(Curr && x > Curr->Data){
            Prev = Curr;
            Curr = Curr->Next;
          }

          //These two lines do the actual linking in of the new node.
          Prev->Next = Temp;
          Temp->Next = Curr;
        }
      }
    }
    //Not Done
    /**
* @FunctionName: PrintList
* @Description:
*     Prints the value of linked list
* @Params:
*    none
* @Returns:
*    void
*/
    void PrintList(){

      if(!Head){                    // If head is empty, display message
        cout<<"Empty"<<endl;
        return;
      }else{

        Node *Temp = Head;          // Create Temporary to traverse list
        while(Temp != NULL){        // Traverse til Null
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;        // increment list
        }
        cout << endl;
      }
    }

    /**
    * @FunctionName: DeleteNode
    * @Description:
    *     The value passed to the function is checked against the linked list,
    *     if a duplicate is found within the list, the item is removed.
    * @Params:
    *     int key-- value passed to function to be deleted.
    * @Returns:
    *    void
    */

     bool DeleteNode(int key){
      // set up a traversal to find key
      Node *Curr = Head;        // Curr points to Head
      Node *Prev = Head;        // Prev points to Head

      // assume key not found
      bool success = false;

      // Check to see if key is the front of the list since we have to handle it slightly
      // different. Different list configurations could clean this code up.
      if(Head->Data == key){
        success = true;
        Head = Head->Next;
        delete Curr;
      }
      else{
        // Key is not at head of the list, so lets traverse to find it.
        while(Curr && key != Curr->Data){
          Prev = Curr;
          Curr = Curr->Next;
        }

        // If Curr is not off the end of the list AND we found the key
        if(Curr && Curr->Data == key){
          success = true;
          Prev->Next = Curr->Next;

          delete Curr;
        }
      }
     return success;
    }

};


/**
* @ProgramName: Program-2
* @Author: Buddy Smith
* @Description:
*    This program calls an object list, and creates an ordered list.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 08 02 2017
*/
int main() {
   srand(97097807);
   List L;
   for(int i=0;i<10;i++){
      L.FrontSert(rand()%100);
    }
   L.PrintList();
   L.EndSert(25);
   L.PrintList();
   L.DeleteNode(24) ? (cout << "Successfully Deleted" << endl) : (cout << "Unsucessful Deletion" << endl);
   L.PrintList();

    return 0;
}

```
