class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int ans[] = new int[k];
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0;

        for(int x: nums){
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>(){
            public int compare(Integer a, Integer b){
                return Integer.compare(mp.get(a), mp.get(b));
            }
        });

        for(int itr: mp.keySet()){
            pq.add(itr);
            if(pq.size() > k) pq.poll();
        }

        while(!pq.isEmpty()){
            ans[i++] = pq.poll();
        }

        return ans;
    }
}