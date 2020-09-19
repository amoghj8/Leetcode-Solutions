// 904. Fruit Into Baskets

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int j=0;
        int result = 0;
        unordered_map<int,int> um;
        for(int i=0;i<tree.size();i++) {
            um[tree[i]]++;
            while(um.size()>2) {
                int index = tree[j++];
                um[index]--;
                if(!um[index])
                    um.erase(index);
            }
            result = max(result, i-j+1);
        } 
        return result;
    }
};