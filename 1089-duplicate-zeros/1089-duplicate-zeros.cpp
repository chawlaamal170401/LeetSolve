class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-1;){
            if(arr[i] == 0){
                for(int j=n-2; j>i-1; j--){
                    arr[j+1] = arr[j];
                }
                arr[i+1] = 0;
                i+=2;
            }
            else i+=1;
        }
    }
};