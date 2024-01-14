class Solution {
    public boolean isNStraightHand(int[] hand, int n) {
        if(hand.length%n!=0) return false;

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i: hand) pq.add(i);

        while(!pq.isEmpty()) {
            int smallest = pq.poll();
            for(int i=1; i<n; i++){
                if(pq.remove(smallest+i)) continue;
                else return false;
            }
        }
        return true;
    }
}