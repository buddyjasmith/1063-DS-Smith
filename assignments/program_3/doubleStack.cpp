/*********************
*@AuthorName: Buddy Smith
*@ClassName: DoubleStack
*@Methods:  DoubleStack(int)
*           dPush(double)
*           dPop()
*           dPrintStack()
*           dEmpty()
*           dFull()
*           dCheckTop()
*@Data:     double *S
*           int top
*           int size
*@Date:     3/19/2017
*/

#include <iostream>
#include "doubleStack.h"

using namespace std;



      DoubleStack::DoubleStack(int s){
        size = s;
        top = -1;
        S = new double[size];
      }

      void DoubleStack::dPush(double x){
        if(!dFull()){
            S[++top] = x;
        }else{
            cout<<"Stack Overflow!"<<endl;
        }
      }

      double DoubleStack::dPop(){
        if(!dEmpty())
          return S[top--];
        else
          return -1;
      }

      void DoubleStack::dPrintStack(){
        for(int i=top;i>=0;i--){
          cout<<S[i]<<" ";
        }
        cout<<endl;
      }

      bool DoubleStack::dEmpty(){
        return top == -1;
      }

      bool DoubleStack::dFull(){
        return top == size-1;
      }

      double DoubleStack::dCheckTop(){
        double temp = S[top];
        return temp;
      }


