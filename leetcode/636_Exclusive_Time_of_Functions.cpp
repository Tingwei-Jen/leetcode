class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> res(n, 0);
        stack<int> st;             //開始執行放進去結束拿出來 因為一次只會執行一個function
        int pre_time = 0;
        for(string log: logs){
            
            stringstream ss(log);
            string temp1, temp2, temp3;
            char split_char = ':';
            getline(ss, temp1, split_char);
            getline(ss, temp2, split_char);
            getline(ss, temp3, split_char);
            
            int id = stoi(temp1);
            string type = temp2;
            int time = stoi(temp3);
            int time_interval = time-pre_time;          //是當前stack top 的id 已經執行的時間
            
            if(!st.empty()){
                res[st.top()] += time_interval;
            }
        
            pre_time = time;                   //time 指針移動
            
            if(type=="start") 
                st.push(id);                   //新id 加進來
            else{                              //如果是end 時間要＋1           
                res[st.top()] +=1;
                st.pop();                      //結束把top id 移走stack
                pre_time++;                    //time 指針移動
            }
        } 
        return res;
    }
};
