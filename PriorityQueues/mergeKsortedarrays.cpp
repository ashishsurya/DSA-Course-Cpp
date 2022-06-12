#include<iostream>
#include<vector>
#include<utility>

#include<queue>
using namespace std;



vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{

  // Write your code here
  	vector<int> answer;
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    
    // Insert the first element of k arrays into the priority queue
    for(int i = 0; i < input.size(); i++) {
        pq.push({input[i] -> at(0), {i, 0}});
    }
    
    // This takes O(klogk) time
    
    while(!pq.empty()) {
        pair<int, pair<int,int>> top  = pq.top();
        pq.pop();
        
        answer.push_back(top.first);
        
        int arrayIndex = top.second.first;
        int elementIndex = top.second.second;
        
        // So push the element from the same array into priority queue
        
        if(elementIndex + 1 < input[arrayIndex] -> size()) {
            pq.push({input[arrayIndex] -> at(elementIndex + 1), {arrayIndex, elementIndex + 1}});
        }
    }
    
    // This takes O(nlogK) time and O(n) space
    
    return answer;
}

int main() { 

int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
