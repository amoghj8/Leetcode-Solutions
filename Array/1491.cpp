class Solution {
public:
    double average(vector<int>& salary) {
        int total=0;
        salary.erase(max_element(salary.begin(),salary.end()));
        salary.erase(min_element(salary.begin(),salary.end()));
        for_each(salary.begin(), salary.end(), [&total](int a) {
            total+=a;
        });
        return (double)total/salary.size();
    }
};