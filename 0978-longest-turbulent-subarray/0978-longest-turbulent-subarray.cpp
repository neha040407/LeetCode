class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int length = 1;
        int maxlength = 1;

        if(n == 1){
            return length;
        }

        for(int end = 1 ; end < n ; end++){
            if(end % 2 == 0 && arr[end] > arr[end-1]){
                length++;
                maxlength = max(length,maxlength);;
            }
            else if(end % 2 != 0 && arr[end] < arr[end - 1]){
                length++;
                maxlength = max(length,maxlength);;
            }
            else{
                length = 1;
            }
        }

        length = 1;


        for(int end = 1 ; end < n ; end++){
            if(end % 2 == 0 && arr[end] < arr[end-1]){
                length++;
                maxlength = max(length,maxlength);;
            }
            else if(end % 2 != 0 && arr[end] > arr[end - 1]){
                length++;
                maxlength = max(length,maxlength);;
            }
            else{
                length = 1;
            }
        }

        return maxlength;
    }
};