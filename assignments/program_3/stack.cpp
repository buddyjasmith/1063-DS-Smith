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
#include "stack.h"

using namespace std;


  Stack::Stack(int s){
    size = s;
    top = -1;
    S = new char[size];
  }
  void Stack::push(char x){
    if(!full()){
      S[++top] = x;
    }else{
      cout<<"Stack Overflow!"<<endl;
    }
  }
  char Stack::pop(){
    if(!Empty())
      return S[top--];
    else
      return -1;
  }
  void Stack::printStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  bool Stack::Empty(){
    return top == -1;
  }
  bool Stack::full(){
    return top == size-1;
  }
char Stack::checkTop(){
    char temp = S[top];
    return temp;
}
