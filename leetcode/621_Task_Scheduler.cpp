class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //http://www.cnblogs.com/grandyang/p/7098764.html
        //相同任務之前要隔n個間隔
        //ex. n=2 --> AB_A   _: idle (閒置)
        
        //先統計次數 找出出現最多次的
        vector<int> count(26,0);
        for(char task: tasks){
            count[task-'A'] +=1;
        }
        //然後排序 由小到大 從大的遍歷回來
        sort(count.begin(), count.end());
        
        int i=25;
        while(i>=0 && count[i]==count[25]) --i;     //找出 相同次數字符   ex. count[23] = 4, count[24] = 4, count[25] = 4
                                                    //i = 25-3;
        int NumOfGroup = count[25]-1;   //出現最多次的次數-1
        int SizeOfGroup = n+1;          //每組的大小
        
        int len = tasks.size();
        
        return max(len, NumOfGroup*SizeOfGroup+(25-i));  //25-i 最后加上的字母个数为出现次数最多的任务 有可能有很多字符次數最多   
    }
};
