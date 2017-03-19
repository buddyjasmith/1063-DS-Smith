
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "doubleStack.h"

using namespace std;

class Calculator{
    private:
        string infix;         //store the expression supplied by user
        int size;             // size + 2 of expression
        Queue *postFix;       // Pointer to char queue 
        Stack *Staq;          // Pointer to char Stack
        DoubleStack *dStack;  // Pointer to double Stack
        
/*****************************************************************************************
* @FunctionName: isOperator  //Private
* @Description:
*     Determines if a character is an operator used in mathematical expressions.
* @Params:
*    char x;
* @Returns:
*    true or false
*/      
bool isOperator(char x);

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
int AssignSig(char x);

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
double performOperation(char x, double x1, double y1);

    public:
    
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

Calculator (string);

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
void Evaluate();
/*****************************************************************************************
* @FunctionName: printPost
* @Description:
*     functions calls the print methods of the Queue and Stack used to store the expression.
* @Params:
*  none
* @Returns:
*    void
*/
void printPost();

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
double retValue();

};
