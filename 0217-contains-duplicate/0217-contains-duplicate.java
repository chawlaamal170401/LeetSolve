class Solution {
    public boolean containsDuplicate(int[] nums) {
        boolean ans = false;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(Integer x: nums){
            Integer freq = mp.get(x);
            if(freq == null) freq = 0;
            mp.put(x, freq + 1);
            if(freq + 1 == 2){
                ans = true;
                break;
            }
        }

        return ans;
    }
}