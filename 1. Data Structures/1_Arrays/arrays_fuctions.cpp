#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(vector<int> array){
    for(int i = 0; i < array.size(); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> dynamic_array;  //This initializes an empty array of size 5
    for(int i=0;i<10;i++){
        dynamic_array.push_back(i);     //push_back is used to insert values at the end of the vector.
    }//running time of push_back is anortized to O(1) as it appends to the end of vector, in simple terms
    cout<<"Vector size: "<<dynamic_array.size()<<endl;
    printVector(dynamic_array);
}