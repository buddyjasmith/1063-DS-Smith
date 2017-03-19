/*********************
*@AuthorName: Buddy Smith
*@DataStructures_1063
*@ClassName: Queue
*@Methods:  Queue(int)
*           qPush(char)
*           qPop()
*           qPrint()
*           qEmpty()
*           qFull()
*@Data:     char *Q
*           int Front
*           int Rear
*           int NumItems
*@Date:     3/19/2017
*/
#include <iostream>

using namespace std;

class Queue{
    private:
        int ArraySize;
        char *Q;
        int Front;
        int Rear;
        int NumItems;
    public:
        Queue(int);
        void qPush(char);
        char qPop();
        bool qEmpty();
        bool qFull();
        void qPrint();
};
