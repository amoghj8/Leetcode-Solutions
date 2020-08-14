// 350. Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> result;
        bool firstVector = nums1.size()<=nums2.size() ? true : false;
        
        if(firstVector) {
            for(auto num:nums1) {
                m[num]++;
            }
            for(int i=0;i<nums2.size();i++) {
                map<int,int>::iterator it; 
                it=m.find(nums2[i]);
                if(it==m.end() || !it->second) {
                    continue;
                }
                else {
                    result.push_back(nums2[i]);
                    m[nums2[i]]--;
                }
            }
        }
        else {
            for(auto num:nums2) {
                m[num]++;
            }
            for(int i=0;i<nums1.size();i++) {
                map<int,int>::iterator it; 
                it=m.find(nums1[i]);
                if(it==m.end() || !it->second) {
                    continue;
                }
                else {
                    result.push_back(nums1[i]);
                    m[nums1[i]]--;
                }
            }
        }
        return result;
    }
};