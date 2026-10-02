//Binary Search
class Solution {
public:
    int mySqrt(int x) {
    if(x==0) return 0;
    else{
        long long int low =1;
        long long int high = x/2 +1;
        long long int mid,res;
        while (low<=high){
        mid = (low+high)/2;
        if((mid*mid)<=x) 
        {low = mid+1 ;
        res=mid ;
            
        }
        else if((mid*mid)>x) high =mid-1;
        }
        return res;
    }
};
};