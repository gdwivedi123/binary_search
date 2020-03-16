class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Find the pivot.
        bool flag = false;
        int l = 0, n = nums.size(),  pivot, r = n - 1, mid;
        if(l > r)
            return -1;
        while( l < r)
        {
            mid = l + ( r - l) / 2;
            if(nums[mid] < nums[0])
                r = mid ;
            else if(((nums[mid] > nums[0]) || (nums[mid] == nums[0]))&& nums[mid] < nums[mid + 1])
                l = mid + 1;
            else if(((nums[mid] == nums[0]) || (nums[mid] > nums[0])) && ( nums[mid] > nums[mid + 1]))
                    {
                        flag = true;
                        pivot = mid;
                        break;
                    }
        }
        if(!flag)
            pivot = l;
        if(nums[pivot] == target)
            return pivot;
        else if(nums[0] > target)
        {
            l = pivot + 1; 
            r = n - 1;
            while(l < r)
            {
                mid = l + ( r - l) / 2;
                if(nums[mid] > target)
                    r = mid;
                else if(nums[mid] < target)
                    l = mid + 1;
                else
                    return mid;
            }
            return (l == r && nums[l] == target) ? l : -1;
        }
        else
        {
            l = 0; 
            r = pivot - 1;
            while(l < r)
            {
                mid = l + ( r - l) / 2;
                if(nums[mid] > target)
                    r = mid;
                else if(nums[mid] < target)
                    l = mid + 1;
                else 
                    return mid;
            }
            return (l == r && nums[l] == target) ? l : -1;
        }
        
        
    }
};