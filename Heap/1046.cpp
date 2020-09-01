// 1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto weight:stones) {
            pq.push(weight);
        }
        while(pq.size()>1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        return pq.top();
    }
};