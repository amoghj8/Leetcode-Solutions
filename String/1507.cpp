// 1507. Reformat Date

class Solution {
public:
    string reformatDate(string date) {
        istringstream ss(date);
        string word,result;
        int index=0;
        while(ss>>word) {
            if(!index) {
                size_t found = word.find("th");
                if(found==string::npos) {
                    found = word.find("st");
                    if(found==string::npos) {
                        found = word.find("nd");
                        if(found==string::npos) {
                            found = word.find("rd");
                        }
                    }
                }
                    
                if(found==1)
                    result+="0";
                result += word.substr(0,found);
                index++;
            }
            else if(index==1) {
                result.insert(0,monthHelper(word)+"-");
                index++;
            }
            else {
                word+="-";
                result.insert(0,word);
            }
        }
        return result;
    }
private:
    string monthHelper(string month) {
        
                if (month=="Jan")
                    return "01";
                else if (month== "Feb")
                    return "02";
                else if (month=="Mar")
                    return "03";
                else if (month=="Apr")
                    return "04";
                else if (month=="May")
                    return "05";
                else if (month=="Jun")
                    return "06";
                else if (month=="Jul")
                    return "07";
                else if (month=="Aug")
                    return "08";
                else if (month=="Sep")
                    return "09";
                else if (month=="Oct")
                    return "10";
                else if (month=="Nov")
                    return "11";
                else return "12";
    }
};