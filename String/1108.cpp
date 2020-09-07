// 1108. Defanging an IP Address

class Solution {
public:
    string defangIPaddr(string address) {
        size_t pos = address.find(".");
        while(pos!=string::npos) {
            address.replace(pos,1,"[.]");
            pos = address.find(".",pos+2);
        }
        return address;
    }
};