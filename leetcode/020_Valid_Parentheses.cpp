class Solution {
public:
    bool isValid(string s) {
        
        int a = 0;
        int b = 0;
        int c = 0;
        
        stack<char> parentheses;
        
        for (int i=0; i<s.size();i++){
            
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                parentheses.push(s[i]);
            else {
                
                if (parentheses.empty())                               //沒有左括號
                    return false;
                
                if(s[i] == ')' && parentheses.top() != '(')            //出現右小括號前 最top 一定是左小括號 否則為false
                    return false;
                
                if(s[i] == ']' && parentheses.top() != '[')
                     return false;
                
                if(s[i] == '}' && parentheses.top() != '{')    
                    return false;    
                     
                parentheses.pop();                                     //代表 出現右小括號前 最top 是左小括號 拿掉最上面括號
 
            }        
        }
        
        return parentheses.empty();
        
        
    }
};
