// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m ;
        for(auto ch:s) {
            m[ch]++;
        }
        string result="";
        priority_queue<pair<char, int>,vector<pair<char,int>>, compare >pq;
        
        for(auto it=m.begin();it!=m.end();it++) {
            pq.push(make_pair(it->first,it->second));
        }
        
        while(!pq.empty()) {
            pair<char,int> top=  pq.top();
            while(top.second) {
                result+=string(1,top.first);
                --top.second;
            }
            pq.pop();
        }
       return result;
    }
private:
    struct compare {
        bool operator()(pair<char,int>& p, pair<char,int>& q) {
            return p.second < q.second;
        }
    };
};