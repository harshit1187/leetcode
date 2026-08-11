class Solution {
public:
    bool checkvalid(const vector<int>& nums, int k, int mid) {
        int paircount = 1;
        int i = 0;
        long long c = mid;
        while(i<nums.size()){
            mid -= nums[i];
            if (mid < 0) {
                mid = c;
                paircount++;
                i--;
            }
            i++;
        }
        if(paircount<=k)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        long long maxt = INT_MIN;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxt <= nums[i])
                maxt = nums[i];
            sum += nums[i];
        }
        long long low = maxt;
        long long high = sum;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if(checkvalid(nums,k,mid)==true)
                high=mid;
            else
                low=mid+1;
        }
        return high;
    }
};