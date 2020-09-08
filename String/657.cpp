// 657. Robot Return to Origin

class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        
        for(int i=0;i<moves.size();i++) {
            helper(moves[i],p);
        }
        return !p.first && !p.second;
    }
private:
    void helper(char move, pair<int,int> &p) {
        switch(move) {
            case 'R': ++p.first;
                        break;
            case 'L': --p.first;
                        break;
            case 'U': ++p.second;
                        break;
            case 'D': --p.second;
                        break;
        }
    }
};