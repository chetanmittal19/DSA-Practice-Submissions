class Solution {
    public boolean isNStraightHand(int[] hand, int w) {
        // Method 1 [PriorityQueue] O(2*NlogN), O(N)
        // if(hand.length % w != 0) return false;
        // PriorityQueue<Integer> pq = new PriorityQueue<>();
        // for(int i: hand) pq.add(i);
        // while(!pq.isEmpty()) {
        //     int smallest = pq.poll();
        //     for(int i=1; i<w; i++){
        //         if(pq.remove(smallest+i)) continue; 
        //         else return false;
        //     }
        // }
        // return true;

        if(hand.length % w != 0) return false;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Map<Integer, Integer> map = new HashMap<>();
        for(int value: hand) map.put(value, map.getOrDefault(value, 0)+1);
        for(int key: map.keySet()) pq.add(key); // adding only unique keys to pq
        while(!pq.isEmpty()) {
            int first = pq.peek();
            for(int i = first; i<first+w; i++) {
                if(!map.containsKey(i)) return false;
                int count = map.get(i);
                
                // Occurances about to become 0 - > So remove
                if(count==1){
                    map.remove(i);
                    pq.poll();
                } else map.put(i, count-1);
            }
        }
        return true;
    }
}