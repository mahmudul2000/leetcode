#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> word_map;
        for (auto word : words) {
            word_map[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&cmp)> pq(cmp);
        for (auto it : word_map) {
            pq.push({it.second, it.first});
        }
        vector<string> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};