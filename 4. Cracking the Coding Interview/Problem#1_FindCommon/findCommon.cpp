#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

    unordered_map<int, int> map;

    for(int i=0;i<n;i++){
        map[A[i]]++;
    }
    for(int i=0;i<n;i++){
        if(map.find(B[i]) != map.end()){
            count++;
        }
    }
    return count;
}

//Time: N
//Space: 1
int findCommon4(vector<int> A, vector<int> B){

    int count = 0;
    int n = A.size();
    int l=0,r=0;
    while(l<n){
        if(A[l]==B[r]){
            count++; 
            l++;
            r++;
        }
        else if(A[l]>B[r]){
            r++;
        }
        else if(A[l]<B[r]){
            l++;
        }
    }
    return count;
}



int main(){

    vector<int> A = {13, 27, 35, 40, 49, 55, 59};
    vector<int> B = {17, 35, 39, 40, 55, 58, 60};

    int count = findCommon(A,B);

    cout<<count<<endl;
    return 0;    

}