```cpp
/**
  * @Homework: Homework-3
  * @Author: Buddy Smith
  * @Description: 
  *     This function is used to print circular based arrays.  If the array is empty, 
  *     "Queue is empty", will be returned to the user.  The function will print the 
  *      Que FIFO.
  * @Course: 1063 Data Structures
  * @Semester: Spring 2017
  * @Date: 28 02 2017
  */
  void Print(){
    int Index = Front;                         // tmep holder for front value


    if(Empty()){                               // True if NumItems = 0
        cout << "Que is empty!\n";
    } 
    else
      if(Rear <= Index || Full()){                        // Check if Front is greater or equal than Rear
     // Iterate from Front to ArraySize
        for(int i = Index; i <ArraySize; i++)
            cout << Q[i]<<" ";
     // Iterate from 0 to Rear
        for(int j = 0; j < Rear; j++)
            cout << Q[j]<< " ";
    }
    else{                                   // Default: Head is less than Rear
        for(int i = Index; i < Rear; i++){
            cout << Q[i] << " ";
        }
    }
    cout<<endl;
    cout << "Front: " << Front << " Rear: " << Rear << endl;
  }

```
