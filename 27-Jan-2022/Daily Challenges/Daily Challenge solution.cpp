#include <bits/stdc++.h>

using namespace std;

int minimumAverage(vector<vector<int>> customers) {    
    
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> waiting;
    
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cust;

    for(int i=0; i<customers.size(); i++) {
        cust.push({customers[i][0], customers[i][1]});
    }   
    
    int curr_time = 0;
    int waiting_time = 0;
    
    while(waiting.size() || cust.size()) {
        if(!waiting.size()) {
            curr_time = cust.top().first + cust.top().second;
            waiting_time += cust.top().second;
            cust.pop();
        } else {
            curr_time += waiting.top().first;
            waiting_time += (curr_time - waiting.top().second);
            waiting.pop();
        }
        
        while(cust.size() && cust.top().first < curr_time) {
            waiting.push({cust.top().second, cust.top().first});
            cust.pop();
        }    
    }
    
    return (waiting_time/customers.size());
    
}


int main() {
    
    int n;
    cin>>n;
    
    vector<vector<int>> customers(n);
    
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        customers[i].push_back(temp);
        cin>>temp;
        customers[i].push_back(temp);
    }
    
    cout<<minimumAverage(customers);
    
}