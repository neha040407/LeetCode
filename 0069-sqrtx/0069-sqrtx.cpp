class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        long long mid;

        if(x == 0 || x == 1){
            return x;
        }

        while(start <= end){
            mid = (start + end)/2;

            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return end;
    }
};