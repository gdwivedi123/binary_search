class Solution {
public:
    int bounds(vector<int>& nums, int target)
    {
        int l = 0, mid, n = nums.size(), bound = -1, r = n - 1;
        while(l <= r)
        {
            mid = l + ( r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid]>= target)
            {
                bound = mid;
                r = mid - 1;
            }
        }
        if(l == n)
            return n;
        return bound;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        /*vector<int> result{-1, -1};
        if ( nums.empty())
            return result;
        int n = nums.size();
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        //vector<int> result{-1, -1};
        int u = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(l >= n || nums[l] != target)
            return result;
        else
        {
            result[0] = l;
            result[1] = u - 1;
        }
        return result;*/
        vector<int> result(2);
        result[0] = bounds(nums, target);
        result[1] = bounds(nums, target + 1) - 1;
        if(result[0] > result[1])
            return {-1, -1};
        else
            return result;
        
            
    }
};