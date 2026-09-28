/*
*Leetcode Problem 75
*/
/*
*Approach-1 (Bubble Sort)
*Time Complexity - O(n^2)  [Best Case - O(n)]
*Space Complexity - O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int k=0 ; k<(nums.size()-1) ; k++){ 
         int j=0;
         for (int i=0 ; i<(nums.size()-1) ; i++){
          if(nums[i] >nums[i+1]) {
              swap(nums[i],nums[i+1]);
              j=1;
            }
         }
        if (j==0) break;
        }
    }
};

/*
*Approach-2 (Bucket Sort)
*Time Complexity - O(n)
*Space Complexity- O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a =0;
        int b =0;
        int c =0;
        for(int i=0; i < nums.size() ; i++){
            if(nums[i]==0) a++ ;
            if(nums[i]==1) b++ ;
            if(nums[i]==2) c++ ;
        }
        int i=0;
        while (i<nums.size()){
            while ( a >=1) {
                nums[i] =0;
                a-- ;
                i++ ;
            }
            while ( b >=1) {
                nums[i] =1;
                b-- ;
                i++ ;
            }
            while ( c >=1) {
                nums[i] =2;
                c-- ;
                i++ ;
            }
        }
    }
};