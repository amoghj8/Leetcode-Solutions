class Solution {
public:
    struct stringComp {
        bool operator()(const pair<string,int>&a, const pair<string,int> &b) {
            if(a.second==b.second) {
                return a.first.compare(b.first)>0;
            }
            else {
                return a.second<b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto word:words) {
            m[word]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>, stringComp> pq;
        for(auto it=m.begin();it!=m.end();it++) {
            pq.push(make_pair(it->first,it->second));
        }
        vector<string> result;
        for(int i=0;i<k;i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};
