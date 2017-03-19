/**
* @ProgramName: Program_3
* @Author: Buddy Smith
* @Description:
*     This program reads in an expression and calculates the indicated
*     operation.  Digits must be between 0 and 9.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 17 03 2017
*/

#include <iostream>
#include <string>
#include "calculator.h"
#include <iomanip>

using namespace std;

int main()
{
    string infix1 = "1+2+3",
           infix2 = "2*3*(4+2)",
           infix3 = "9+4+9/2",
           infix4="(3*3)/(4*2)+9",
           infix5="7-3+2/4";

    Calculator calc1(infix1);
    Calculator calc2(infix2);
    Calculator calc3(infix3);
    Calculator calc4(infix4);
    Calculator calc5(infix5);

    calc1.Evaluate();
    calc2.Evaluate();
    calc3.Evaluate();
    calc4.Evaluate();
    calc5.Evaluate();
    //value = calc.retValue();
    cout << fixed << setprecision(1) << endl;

    cout << infix1 << " = " ;
    cout << calc1.retValue()<< endl;
    cout << infix2 << " = " ;
    cout << calc2.retValue() << endl;
    cout << infix3 << " = " ;
    cout << calc3.retValue() << endl;
    cout << infix4 << " = " ;
    cout << calc4.retValue() << endl;
    cout << infix5 << " = " ;
    cout << calc5.retValue() << endl;
    return 0;
}
