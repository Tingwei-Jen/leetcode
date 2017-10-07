class Solution {
public:
    string simplifyPath(string path) {
        
        if(path.size()<=1) return path;
        string temp;
        stack<string> st;
        stringstream ss(path);
        
        while(getline(ss, temp, '/')){      //temp = "a" "." "b" ".." ....
            
            if(temp=="" || temp==".") continue;
            if(temp==".." && !st.empty())           //回上一層
                st.pop();
            else if (temp!="..") 
                st.push(temp);
        } 
        
        string res = "";
        if(st.empty()) return "/";
        
        while(!st.empty()){               //st: [a,b,c,d..]
            res = "/"+ st.top() + res;          //res: /a/b/c/d..
            st.pop();
        }
        return res;
    }
};
