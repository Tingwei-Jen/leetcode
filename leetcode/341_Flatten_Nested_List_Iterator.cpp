/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        //http://blog.leanote.com/post/westcode/5a37f0ce727c
        //在constructor 把list從後面放到stack裡面
        //ex. [1,[4,[6]]]  --> stack[0] = 1, stack[1] = [4,[6]];
        //放在 hasNext 里面我们就看当前的 top 是不是数字，如果是数字我们直接 return true 就可以了，
        //如果不是数字那么我们再开始把 top 的这个 list 给展开，展開放入stack展开到什么程度呢？ 
        //并不是一次性把整个 stack 的 list 都展开，而且展开到找到下一个数字为止。
        
        for(int i=nestedList.size()-1;i>=0;i--){
            st.push(nestedList[i]);
        }   
    }

    int next() {       
        int res =  st.top().getInteger();
        st.pop();
        return res;
    }

    bool hasNext() {
        
        while(!st.empty()){
            NestedInteger cur = st.top();
            if(cur.isInteger())
                return true;            
            else {
                st.pop();
                vector<NestedInteger> &temp = cur.getList();    //展開 放入stack
                for(int i=temp.size()-1; i>=0;i--)
                    st.push(temp[i]);            
            }
        }
        return false;
    }
    
private:
    stack<NestedInteger> st;

};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
