#include <iostream>
#include <algorithm>

using namespace std;


void reverseArray(int P[], int Q) {
    // USING INBUILT METHOD
    // reverse(P, P+Q);
    
    // IMPLEMENTING IT
    for(int i=0; i<=(Q-1)/2; i++) {
        int temp = P[i];
        P[i] = P[Q-1-i];
        P[Q-1-i] = temp;
    }
}


void printArray(int P[], int Q) {
    for(int i=0; i<Q; i++) {
        cout<<P[i]<<"\n";
    }
}


int main() {
    int Q;
    cin>>Q;
    
    int P[Q];
    
    for(int i=0; i<Q; i++) {
        cin>>P[i];
    }
    
    reverseArray(P, Q);
    printArray(P, Q);
}