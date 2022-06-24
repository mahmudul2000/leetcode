#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        int tem_num = num;
        priority_queue<int> opq, epq;
        stack<int> fn;
        while(num) {
            int d = num % 10;
            if (d % 2 == 0) epq.push(d * -1);
            else opq.push(d * -1);
            num /= 10;
        }
        while(tem_num) {
            int d = tem_num % 10;
            if (d % 2 == 0) {
                fn.push(epq.top());
                epq.pop();
            } else {
                fn.push(opq.top());
                opq.pop();
            }
            tem_num /= 10;
        }
        while(!fn.empty()) {
            num = num * 10 + fn.top() * -1;
            fn.pop();
        }
        return num;
    }
};

int main() {
    Solution s;
    int num = 123475;
    int ans = s.largestInteger(num);
    cout << ans << endl;
    return 0;
}