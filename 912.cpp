#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // priority queue using nums
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) pq.push(num);
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};