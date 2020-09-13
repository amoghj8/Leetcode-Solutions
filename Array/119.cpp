// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(!rowIndex)
            return {1};
        else if(rowIndex==1)
            return {1,1};
        int totalElements = ((rowIndex+1)*(rowIndex+2))/2;
        vector<int> result(totalElements,0);
        result[0]=1;
        result[1]=1;
        result[2]=1;
        int index=3;
        vector<int> temp;
        for(int row=2;row<=rowIndex;row++) {
            int ele = row;
            for(int i=0;i<=ele;i++) {
                if(!i || (i==ele)) {
                   result[index]=1;
                    index++;
                    continue;
                }
                result[index] = result[index-row] + result[index-row-1];
                index++;
            }
        }
        for(int i=totalElements-rowIndex-1;i<totalElements;i++) {
            temp.push_back(result[i]);
        }
        return temp;
        
    }
};