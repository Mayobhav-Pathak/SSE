/*
 *Problem: Maximum Gap (Leetcode Problem -164)
  */
 /*
 *Approach-1 : Normal 
 *Time Complexity:O(nlogn)
 *Space Complexity: O(1) auxilliary ( or O(logn) stack frames in sort)
   */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
            return 0;
        int n = nums.size()-1;
        int res=0 ;
        for(int i=0; i< n ; i++){
            res = max(res, nums[i + 1] - nums[i]);
        }
        return res;
    }
};

/*
 *Approach-2 : Bucket Sort ( Pigeonhole principle)
 *Time Complexity:O(n)
 *Space Complexity: O(n) 
   */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int min_val = nums[0];
        int max_val = nums[0];
        for (int x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }

        if (min_val == max_val) return 0;
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        for (int x : nums) {
            int idx = (x - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], x);
            bucket_max[idx] = max(bucket_max[idx], x);
        }
        int res = 0;
        int prev_max = min_val;

        for (int i = 0; i < bucket_count; ++i) {
            if (bucket_min[i] == INT_MAX) continue;
            res = max(res, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
        }

        return res;
    }
};
