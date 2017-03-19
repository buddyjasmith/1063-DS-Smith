/*********************
*@AuthorName: Buddy Smith
*@DataStructures_1063
*@ClassName: Stack
*@Methods:  Stack(int)
*           Push(char)
*           Pop()
*           PrintStack()
*           Empty()
*           Full()
*           CheckTop()
*@Data:     char *S
*           int top
*           int size
*@Date:     3/19/2017
*/
#include <iostream>

using namespace std;

class Stack{
  private:
      char *S;
      int top;
      int size;

  public:
      Stack(int);
      void push(char);
      char pop();
      void printStack();
      bool Empty();
      bool full();
      char checkTop();
};
