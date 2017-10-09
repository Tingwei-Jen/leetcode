class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        //max heap: 根比葉子大
        //return usesortfunc(nums,k);
        //return quicksortmethod(nums,k);
        return heapsortmethod(nums,k);
    }
    
    //use sort func complexity : O(nlogn)
    int usesortfunc(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
    
    
    
    //quicksort: partition-exchange sort(divide and conquer method)  //O(nlogn)
    //利用基準值 將比基準值小的丟一邊 大的丟另一邊
    //對左右串列 做同樣的排序
    int quicksortmethod(vector<int> &nums, int k){
        
        int left = 0;
        int right = nums.size()-1;
        
        while(1){
            
            int pos = partition(nums, left, right);
            if(pos==k-1) return nums[pos];           //找到了
            else if (pos>k-1)                        //在k-1 的位置 在 pos 左邊
                right = pos-1;
            else
                left = pos+1;
            
        }
    }
    int partition(vector<int> &nums, int left, int right){    //最後結果 比pivot 小的放右邊 大的放左邊
        int pivot = nums[left];  
        int l = left+1;
        int r = right;
        
        while(l<=r){            
            
            if(nums[l]<pivot && nums[r]>pivot){     //小的丟右邊 大的丟左邊
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(nums[l]>=pivot) l++;                  //不換
            if(nums[r]<=pivot) r--;
        }
        swap(nums[left], nums[r]);                   //把nums[left] 塞進來
        return r;                                    //回傳pivot 值 的位置
    }
    
    
    
    
    
    //heapsort : 每個root 都比 leaf 大
    //https://www.youtube.com/watch?v=MtQL_ll5KhQ
    //https://www.youtube.com/watch?v=EuUBxM_E03E&t=24s
    //root: i
    //left child : 2i+1
    //right child : 2i+2
    //做完一次maxheap 最上面的為current heap tree的最大值
    //把last item 和最大值交換 lenth-1 繼續做 map heap 
    
    int heapsortmethod(vector<int> &nums, int k){
        
        heap_size = nums.size();
        build_max_heap(nums);
        for(int i=0; i<k; i++){
            swap(nums[0], nums[heap_size-1]);               // 將最大值放到array的最後一個位置 
            heap_size--;              
            MaxHeapify(nums, 0);                            //調整「忽略最後一個位置」的矩陣
        }
        return nums[heap_size];                             //此時heapsize = nums.size()-k     最大在最右邊 ans=從右邊數來第k個
    }
    
    void MaxHeapify(vector<int> &nums, int root_index){     //root的值 必須比left child, right child 大 
                                                                           
        int largest = root_index;
        int left_child_index = 2*root_index+1;
        int right_child_index = 2*root_index+2;
        if(left_child_index<heap_size && nums[left_child_index]>nums[largest]) largest = left_child_index;    
        if(right_child_index<heap_size && nums[right_child_index]>nums[largest]) largest = right_child_index;  
        
        if(largest != root_index){    //需要交換
            swap(nums[root_index], nums[largest]);
            MaxHeapify(nums, largest);                 //交換過後 往下檢查 看有沒有需要再做一次maxheapify
        }
    }
    void build_max_heap(vector<int> &nums){       //每一層 都做maxheapify
        for(int i=nums.size()/2-1; i>=0; i--)    // ex. num.size() = 10,  i = 4,3,2,1,0
            MaxHeapify(nums, i);
    }
    
private: 
    int heap_size;
    
};
