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
#include "queue.h"


using namespace std;

Queue::Queue(int size){
    ArraySize = size;
    Q= new char[ArraySize];
    Front = Rear = NumItems = 0;
}
char Queue::qPop(){
    int Temp = Q[Front++];
    NumItems--;
    return Temp;
}
void Queue::qPush(char x){
    Q[Rear++] = x;
    NumItems++;
}
bool Queue::qEmpty(){
    return(NumItems == 0);
}
bool Queue::qFull(){
    return(NumItems==ArraySize);
}
void Queue::qPrint(){
    for(int index = 0; index < NumItems; index++){
        cout<<Q[index] << " ";
    }
    cout << endl;
}

