class Solution {
    public String reorganizeString(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i=0; i<s.length(); i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
        }

        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue()-a.getValue());
        for(Map.Entry<Character, Integer> m: map.entrySet()) pq.add(m);
        StringBuilder ans = new StringBuilder();
        Map.Entry<Character, Integer> block = pq.poll();
        ans.append(block.getKey());
        block.setValue(block.getValue()-1);

        while(pq.size()>0){
            Map.Entry<Character, Integer> temp = pq.poll();
            ans.append(temp.getKey());
            temp.setValue(temp.getValue()-1);
            if(block.getValue()>0) pq.add(block);
            block = temp;
        }
        if(block.getValue()>0) return "";
        return ans.toString();
    }
}