class Solution {
    public boolean isPossibleDivide(int[] hand, int w) {
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

        // Method 2 [HashMap, PriorityQueue] O(N + NlogN + NlogN), O(2N)
        // This method is similar to method 1, but it is more manual. Other languages like c++ does not contain remove method, so we can use this manual approach.
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