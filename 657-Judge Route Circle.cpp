class Solution {
public:
    bool judgeCircle(string moves) {
        
        int a = 0;
        int b = 0;
        
        for(int i=0;i<moves.size();i++){
            
            if(moves[i]=='U')
                a++;
            else if (moves[i]=='D')
                a--;
            else if (moves[i]=='L')
                b++;
            else if (moves[i]=='R')
                b--;
        }
        
        /*if (a==0 && b==0)
            return true;
        else 
            return false;*/
        
        return a==0 && b==0;
    }        
    
};
