/*
*Leetcode Problem 1051
*/
/*
*Approach - 1 : Manual Bubble Sort
*Time Complexity - O(n^2) [Best Case - O(n)]
*Space Complexity-O(n)
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        for(int k=0 ; k<(arr.size()-1) ; k++){ 
         int j=0;
         for (int i=0 ; i<(arr.size()-1) ; i++){
          if(arr[i] >arr[i+1]) {
              swap(arr[i],arr[i+1]);
              j=1;
            }
         }
        if (j==0) break;
        }
        int count =0;
        for(int k=0 ; k<arr.size(); k++){
            if(arr[k] != heights[k]) count ++;
        }
        return count;
    }
};

/*
*Approach - 2 : Using Built in libraries
*Time Complexity - O(nlogn) 
*Space Complexity-O(n)
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr = heights;
        sort(arr.begin(), arr.end());
        int count =0;
        for(int k=0 ; k<arr.size(); k++){
            if(arr[k] != heights[k]) count ++;
        }
        return count;
    }
};

