class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int n = x^y ; //XOR 
            
        bitset<32> b0(n);
        cout<<"n:"<<(b0)<<endl;
        cout<<"n>>1:"<<(b0>>1)<<endl;   //shift right 
        
        cout<<"test:"<<endl;
        cout<<(5&1)<<endl;          //0101 & 0001 --> 0001    AND!!
        cout<<(4&1)<<endl;          //0100 & 0001 --> 0000
        cout<<(3&1)<<endl;
        cout<<(2&1)<<endl;
        cout<<(1&1)<<endl;
        
        int dis = 0;
        for(int i=0;i<32;i++){
            int k = (n>>i &1);
            b0 = k;

            if(k) {   //AND GATE 1&1 = 1  最後一位 是1時
                dis++;
                cout<<"i:"<<i<<endl;
                cout<<"K: "<<b0<<endl;

            }  
        }
        return dis;
    }
};
