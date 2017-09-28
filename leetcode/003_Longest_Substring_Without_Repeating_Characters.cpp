class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //思路: 從頭尋訪 沒遇過就放到hash table裡 方便下次尋找 then count +1
        //      遇過就跳過
        //  錯！！！ 是substring 不是subsequence
        
        /*map<char, int> hash;
        map<char, int>::iterator iter;
        
        int count = 0;
        
        //one dimention
        for (int i=0; i<s.size();i++){
            
            iter = hash.find(s[i]);    
            if(iter != hash.end()){           //found
                //nothing
            }  else {
                hash[s[i]] = i;
                count++;
            }     
        }
        
        return count;*/
        
        
        //思路: 從頭尋訪 沒遇過 就開始計算長度 直到遇過相同字符 移動指針 指到前一個重複的字符
        //      紀錄長度 不斷更新 

        
        map<char, int> hash;
        map<char, int>::iterator it;
        
        int maxlength = 0;
        int start = -1;                               //substring 的最左邊 的前一個

        for(int i=0;i<s.size();i++){
            
            it = hash.find(s.at(i));                   //檢查重複
            if(it != hash.end()){                      //找到重複
                
                start = max(start, it->second);        //移動指針 指到前一個重複的地方  ex. abcadf 遇到a 指針從 -1 -->0
                                                       // ex. abcb 遇到b 重複 指針從 -1 ---> 1
            }
            hash[s.at(i)] = i;                         //加入新字符
            maxlength = max(maxlength, i-start);       //更新長度
            
        }
        
        
        return maxlength;        
        
    }
};
