class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum1=0;
        int ind, absd=INT_MAX;
        long long int sum2=0;
        int n=nums.size();

        for(auto v:nums) sum1+=v;
        if(n==1) return 0;
        
        for(int i=0; i<n; i++){
            sum2+=nums[i];
            sum1-=nums[i];
            int av1;
            if(i!=n-1){
                av1=sum1/(n-i-1);
            }
            else{
                av1=0;
            }
            int av2=sum2/(i+1);
            int diff=abs(av1-av2);
            if(diff<absd){
                ind=i;
                absd=diff;
            }
        }
        return ind;
    }
};