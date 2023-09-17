class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mapper = new HashMap<>();

        for(String s: strs){
            char temp[] = s.toCharArray();
            Arrays.sort(temp);
            String conv = new String(temp);
            if(mapper.containsKey(conv)){
                List<String> l =  mapper.get(conv);
                l.add(s);
            }else{
                List<String> a = new ArrayList<String>();
                a.add(s);
                mapper.put(conv, a);
            }
        }

        List<List<String>> ans = new ArrayList<List<String>>();
        
        for(Map.Entry<String, List<String>> mp: mapper.entrySet()){
            List<String> value = mp.getValue();
            ans.add(value);
        }
        return ans;
    }
}