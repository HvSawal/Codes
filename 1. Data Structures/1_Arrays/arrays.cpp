#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printArray(int* array, int len){
    for(int i = 0; i < len; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void printVector(vector<int> array){
    for(int i = 0; i < array.size(); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    /*Learning to Implement Arrays in different ways
    *1. Static Implementaion
    *2. Dynamic Implementation (STL)
    */

    //Static Implementation
    //=======================================================================================
    int static_1[5]; //This initializes an empty array of size 5
    len = sizeof(static_1)/sizeof(static_1[0]);
    for(int i = 0; i < len; i++) static_1[i]=i;
    printArray(static_1,len);

    int static_2[] = {1, 2, 3, 4, 5}; //Creates an array of size 5 with the given values
    len = sizeof(static_2)/sizeof(static_2[0]);
    printArray(static_2,len);
    //=======================================================================================

    //Dynamic Implementation (STL)
    //=======================================================================================
    vector<int> dynamic_array;  //This initializes an empty array of size 5
    for(int i=0;i<10;i++){
        dynamic_array.push_back(i);     //push_back is used to insert values at the end of the vector.
    }
    printVector(dynamic_array);

    //=======================================================================================

    return 0;
}