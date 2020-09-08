// 929. Unique Email Addresses

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,vector<string>> um;
        int count = 0;
        for(int i=0;i<emails.size();i++) {
            string email = emails[i];
            size_t found = email.find("@");
            string domain = email.substr(found+1);
            string local = email.substr(0,found);
            found = local.find("+");
            if(found!=string::npos) {
                local = local.substr(0,found);
            }
            for(int i=0;i<local.size();i++) {
                if(local[i]=='.')
                    local.erase(i,1);
            }
            
            if(um.find(domain)!=um.end()) {
                auto it= find(um[domain].begin(), um[domain].end(),local);
                if(it==um[domain].end()) {
                    um[domain].push_back(local);
                    ++count;
                }
                else {
                    continue;
                }
            }
            else {
                um[domain].push_back(local);
                ++count;
            }
        }
        return count;
    }
};