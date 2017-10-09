class Solution {
public:
    int maximumSwap(int num) {
        
        //http://www.cnblogs.com/grandyang/p/7583875.html

        //return method1(num);
        return method2(num);
        
    }
    int method1(int num){
        //轉換成string 就不用 %10 /10 一個一個找
        string str = to_string(num);
        
        //bobble sort
        int n = str.size();  //位數
        int res = num;
        for(int i=0;i<n;i++){    //第i格 跟後面每一格都swap 比較大小
            for(int j=i+1; j<n; j++){
                swap(str[i], str[j]);
                res = max(res, stoi(str));
                swap(str[i], str[j]);           //換回來不然會影響下次的swap
            }
        }
        return res;        
    }
    
    
    int method2(int num){
        
        //從低位出發遍歷因為我們希望能跟較低位的數字對換 這樣置換後的數字最大
        string str = to_string(num);
        string back = str;
        
        for(int i=back.size()-2;i>=0;--i){
            back[i] = max(back[i],back[i+1]);     //從後面開始找最大值  ex. 1893 ---> back: 9993 ,9>1, 從1893 後面找9
        }
        
        for(int i=0;i<str.size();i++){            //從前面開始比較 str 與 back的大小 如果back 比較大 代表可以置換
                                                  //然後從 str 後面開始找 back 比較大的那個數 進行置換
            if(str[i] == back[i]) continue;
            else{                                   //back的數比較大
                for(int j=str.size()-1;j>=i;j--){   //從後面找back 較大的數
                    if(str[j]==back[i]){            //找到了
                        swap(str[i], str[j]);
                        return stoi(str);
                    }                    
                }   
            }
        }
        return stoi(str);                            //不用對調 已經是最大
    }
};
