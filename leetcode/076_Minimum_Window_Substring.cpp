class Solution {
public:
    string minWindow(string s, string t) {
             
        //我们最开始先扫描一遍T，把对应的字符及其出现的次数存到哈希表中。
        //然后开始遍历S，遇到T中的字符，就把对应的哈希表中的value减一，直到包含了T中的所有的字符，纪录一个字串并更新最小字串值。
        //将子窗口的左边界向右移，略掉不在T中的字符，如果某个在T中的字符出现的次数大于哈希表中的value，则也可以跳过该字符。
        
       if (t.size() > s.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = s.size() + 1;
        int tm[256] = {0}, sm[256] = {0};
        for (int i = 0; i < t.size(); ++i) ++tm[t[i]];
        for (int right = 0; right < s.size(); ++right) {
            if (tm[s[right]] != 0) {
                ++sm[s[right]];
                if (sm[s[right]] <= tm[s[right]]) ++count;
                while (count == t.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = s.substr(left, minLen);
                    }
                    if (tm[s[left]] != 0) {
                        --sm[s[left]];
                        if (sm[s[left]] < tm[s[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
        
        /*if(s.empty() || t.empty()) return "";
 
        vector<int> sArr(128);                     //用來記錄 string s 的 substring 的狀況 //隨時會更新
        vector<int> tArr(128);                     //256 已經包含了全部字符 (ASC)
        for(int i=0;i<t.size();i++){                  //tArr 用來記錄 string t 裡面的字符是什麼且重複了幾次  //initial 之後不會變
            tArr[t[i]]++;                             //之後拿來跟 sArr比對
        }
        
        int left = findNextStrIndex(0, s, tArr);      //left initial
        if (left == s.size()) return "";              //no char in s match t
        int right = left;                             //right initial
        int matchcount=0;                             //如果matchcount 等於 t 裡面字符數量 代表 找到substring    
        string res;
        
        while(right<s.size()){
            
            int rightChar = s[right];                //現在右指針指到的字元
            if(sArr[rightChar] < tArr[rightChar])
                matchcount++;                        //找到一個應該包含卻還沒包含在substring 的字符
            sArr[rightChar] ++;
            
            while(left<s.size() && matchcount==t.size()){       //找到了符合題目的substring
                
                if(res.empty() || res.size()> (right-left+1)){
                    res = s.substr(left, (right-left+1));
                }                                               //找到後開始移動左指針 
                
                int leftChar = s[left];
                if(sArr[leftChar] <= tArr[leftChar]){           //左指針往右後 substring 包含t 裡面的字符 如果比較少
                    matchcount--;
                }
                sArr[leftChar]--;
                left = findNextStrIndex(left+1, s, tArr);
            }
            right = findNextStrIndex(right+1, s, tArr);        //matchcount 小於t的大小後 右指針開始往右移動
        }
        
        
        return res;
    }
    
    int findNextStrIndex(int start, string s, vector<int> tArr){
        
        while(start<s.size()){         //從start 開始向右跑
            
            char c = s[start];         //如果s裡面有包含 t裡的字符 回傳start的位置
            if(tArr[c] !=0)            //substring 一定從t裡面有的字符 開始算
                return start;
            start++;
        }   
        return start;
    }*/
};
