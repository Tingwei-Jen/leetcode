class Solution {
public:
    string addBinary(string a, string b) {          //"11":3, "1":1,  "11"+"1" = 4 = "100"
        
        string res = "";
        
        int carry = 0;
        int sum;
        int i = a.size()-1;
        int j = b.size()-1;
        
        while(i>=0 || j>=0){
            
            sum = 0;
            
            if(j>=0){
                sum += b[j]-'0';
                j--;
            }
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            
            sum += carry;
            
            int low = sum%2;
            carry = sum/2;
            
            res = to_string(low)+res;
        }
        
        return carry? '1'+res: res;
    }
};
