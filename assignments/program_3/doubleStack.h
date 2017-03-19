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

using namespace std;

class DoubleStack{
  private:
      double *S;
      int top;
      int size;

  public:
      DoubleStack(int);
      void dPush(double);
      double dPop();
      void dPrintStack();
      bool dEmpty();
      bool dFull();
      double dCheckTop();
};
