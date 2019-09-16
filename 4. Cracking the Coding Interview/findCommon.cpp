#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(int a, vector<int> B){

    int low = 0;
    int high = B.size()-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(a == B[mid]){
            return 1;
        }
        else if(a<B[mid]){
            high = mid-1;
        }
        else if(a>B[mid]){
            low = mid+1;
        }
    }
    return 0;
}

//Time: N^2
//Space: 1
int findCommon(vector<int> A, vector<int> B){

    int count = 0;
    int n = A.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i]==B[j]) count++;
        }
    }

    return count;
}

//Time: N*logN
//Space: 1
int findCommon2(vector<int> A, vector<int> B){

    int count = 0;
    int n = A.size();

    for(int i=0;i<n;i++){
        count+=binary_search(A[i],B);
    }
    return count;
}

//Time: N
//Space: N
int findCommon3(vector<int> A, vector<int> B){

    int count = 0;
    int n = A.size();

    return count;
}

//Time: N
//Space: 1
int main(){

    vector<int> A = {};
    vector<int> B = {};

    int count = findCommon(A,B);

    cout<<count<<endl;
    return 0;    

}