        /*int index=0;
        
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[index];        //把nums2 放入nums1中 然後再開始排序
            index++;
        }
        
        
        //使用泡沫排序法重新排序
        for(int j = 0 ; j < nums1.size()- 1 ; j++){
            for(int k = j + 1 ; k < nums1.size() ; k++){
                if(nums1[j] > nums1[k]){
                    int temp = nums1[j];
                    nums1[j] = nums1[k];
                    nums1[k] = temp;
            }
        }*/
        
        
        int count = m+n-1;   //陣列有值的最後一個 然後比大小 大的放進A 然後 指針向前移動
        int i = m-1;
        int j = n-1;           
        
        //cout--  ： 計算時 用count 算完 count-1
        //nums1 跑完 直接將nums2 放到前面
        //nums2 跑完 結束 前面依然是num1原先的數字
        
        
        while(j>=0){
            cout<<j<<endl;
            nums1[count--] = i>=0 && nums1[i]>nums2[j]? nums1[i--]:nums2[j--]; 
            cout<<j<<endl;
        }
