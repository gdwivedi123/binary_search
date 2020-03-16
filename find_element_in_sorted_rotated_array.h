class Solution {
public:
    int search_element(vector<int>& nums, int l, int r, int target)
    {
        int mid;
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
    int search(vector<int>& nums, int target) {
        //Find the pivot.
        
        int l = 0, n = nums.size(),  pivot, r = n - 1, mid;
        if(n == 0)
            return -1;
        if(n == 1)
            return nums[0] == target ? 0 : -1;
        /*
        1. Finding the largest element then dividing the array into two halves.
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
        }*/
        //2. Find the minimum  element then divide the array into two halves.
        while(l < r)
        {
            mid = l + ( r - l) / 2;
            if(nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }   
        pivot = l;
        
        /*
        when using 1.
        if(!flag)
            pivot = l;*/
        if(nums[pivot] == target)
            return pivot;
        if(target > nums[n - 1])
            return search_element(nums, 0, pivot - 1, target);
        else
            return search_element(nums, pivot + 1, n - 1, target);
            
    }
};
