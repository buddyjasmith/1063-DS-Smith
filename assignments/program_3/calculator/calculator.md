```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "calculator.h"



using namespace std;
/*****************************************************************************************
* @ConstructorName: Calculator
* @Description:
*     Removes all spaces from within the string, sets up pointers to stack, doubleStack,
*     and Queue classes.  A right parentheses is appended to the string passed to the function
*     A left parentheses is pushed to the stack.
* @Params:
*    string x
* @Returns:
*    none, constructor
*/

Calculator::Calculator(string x){
    x.erase(remove_if(x.begin(), x.end(), ::isspace), x.end());
    infix = x;
    infix.append(")");
    size = infix.length()+1;
    postFix = new Queue(size);
    Staq = new Stack(size);
    dStack = new DoubleStack(size);
    Staq->push('(');

}
/*****************************************************************************************
* @FunctionName: Evaluate
* @Description:
*   1.	Push a left parenthesis ‘(‘ onto the stack;
*   2.	Append a right parenthesis ‘)’ to the end of infix.
*   3.	While the stack is not empty, read infix from left to right and do the following:
*        a. If the current character in infix is a white space, simply ignore it.
*        b. If the current character in infix is a digit, copy it to the next element of postfix.
*        c. If the current character in infix is a left parenthesis, push it onto the stack.
*        d. If the current character in infix is an operator,
*           • Pop operators (if there are any) at the top of the stack while they have equal or higher
*             precedence than the current operator, and insert the popped operators in postfix.
*           • Push the current character in infix onto the stack.
*       e. If the current character in infix is a right parenthesis,
*           • Pop operators from the top of the stack and insert them in postfix until a left parenthesis
*             is at the top of the stack.
*           • Pop (and discard) the left parenthesis from the stack.
* @Params:
*   none
* @Returns:
*    void
*/
void Calculator::Evaluate(){
    int i = 0;
    char temp;
    //int  weight;       //signi1
    while(!Staq->Empty()){
        temp = infix[i];
        if(isdigit(temp)){
            postFix->qPush(infix[i]);
        }else
            if(temp == '('){
                Staq->push(infix[i]);
        }else
            if(isOperator(temp)){
                    while(!Staq->Empty() && AssignSig(Staq->checkTop()) >= AssignSig(temp)){
                        postFix->qPush(Staq->checkTop());
                        Staq->pop();
                    }
                    Staq->push(temp);

        }else
            if(temp == ')'){
                while(Staq->checkTop() != '(' ){
                    postFix->qPush(Staq->checkTop());
                    Staq->pop();
                }
                Staq->pop();
            }
        i++;

    }
}
/*****************************************************************************************
* @FunctionName: printPost
* @Description:
*     functions calls the print methods of the Queue and Stack used to store the expression.
* @Params:
*  none
* @Returns:
*    void
*/
void Calculator::printPost(){
        cout << "Now Printing Stack: " ;
        Staq->printStack();
        cout << "\nNow Printing PostFix: ";
        postFix->qPrint();
        cout << endl;


}
/*****************************************************************************************
* @FunctionName: isOperator
* @Description:
*     Determines if a character is an operator used in mathematical expressions.
* @Params:
*    char x;
* @Returns:
*    true or false
*/
bool Calculator::isOperator( char x ){
    return(x == '+' || x == '-'|| x == '*' || x == '%' || x=='/' || x =='^' );

}
/*****************************************************************************************
* @FunctionName: AssignSig
* @Description:
*     Determines the mathematical significance for the character value representing
*     an an expressions operator.
* @Params:
*     char x
* @Returns:
*    int
*/
int Calculator::AssignSig(char x){
    int sig = 0;
    switch(x){
    case '+':
    case '-':
        sig = 1;
        break;
    case '*':
    case '/':
    case '%':
        sig = 2;
        break;
    case '^':
        sig = 3;
        break;
    default: sig = 0;
    }
    return sig;
}
/*****************************************************************************************
* @FunctionName: retValue
* @Description:
*     program calculates the post fix expression pushed into Queue.  Expression must be
*     converted and pushed into Queue before attempting to run
* @Params:
*    none
* @Returns:
*    double
*/
double Calculator::retValue(){
    char temp;
    int intVal;
    double intX,
           intY,
           accumulation = 0.0;
    double  staqAdd = 0.0;
    while(!postFix->qEmpty()){
        temp = postFix->qPop();


        if(isdigit(temp)){
            intVal = temp - '0';
            dStack->dPush((double)intVal);
        }
        else
        if(isOperator(temp)){
            intX = dStack->dPop();
            intY = dStack->dPop();
            accumulation = performOperation(temp, intX, intY);
            dStack->dPush(accumulation);
        }

    }
    while(!dStack->dEmpty()){
        staqAdd += dStack->dPop();
    }
   return staqAdd;
}
/*****************************************************************************************
* @FunctionName: performOperation
* @Description:
*     Based on the char passed, a calculation is performed y1 operation x1
* @Params:
*    char x:   operation used
*    double x1: value to use in operation
*    double y1: value to use in operation
* @Returns:
*    double
*/
double Calculator::performOperation(char x, double x1, double y1){
    double value = 0.0;
    switch (x){
    case '+':
        value = y1 + x1;
        break;
    case '-':
        value = y1-x1;
        break;
    case '*':
        value = y1 * x1;
        break;
    case '/':
        value = y1/x1;
        break;
    case '%':
        value =  ((int)y1 % (int)x1);
        break;
    case '^':
        value =  pow(y1,x1);
        break;
    }
    return value;
}
```
