/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        UndirectedGraphNode *res = BFSmethod(node);
        return res;
    }
    
    UndirectedGraphNode *BFSmethod(UndirectedGraphNode *node){
        
        //use BFS
        //In order to clone a graph, you need to have a copy of each node in the original graph
        //hashmap紀錄原本節點與複製節點關係 以及判斷是否已經visited
        //用map 方便判斷有沒有紀錄過
        
        if (node==NULL) return NULL;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hashmap;    //紀錄原本節點與複製節點間關係  <old, copy>
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        hashmap[node] = copy;                                                   //<old, copy>
        queue<UndirectedGraphNode *> q;                                         //because BFS 
        q.push(node);
        
        while(!q.empty()){
            
            UndirectedGraphNode *current =  q.front();
            q.pop();
            for(UndirectedGraphNode *neigh : current->neighbors){           //尋訪current 的鄰近node
                if(hashmap.find(neigh) == hashmap.end()){                    //如果沒有在map裡面(沒出現過) 
                    UndirectedGraphNode *neigh_copy = new UndirectedGraphNode(neigh->label);     //沒出現過 所以需要copy
                    hashmap[neigh] = neigh_copy;                            
                    q.push(neigh);
                } 
                hashmap[current]->neighbors.push_back(hashmap[neigh]);     //建立複製節點間的關係 build clone graph
            }
        }
        return copy; 
    }    
};
