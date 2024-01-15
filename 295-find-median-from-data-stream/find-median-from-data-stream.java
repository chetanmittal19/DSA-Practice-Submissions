class MedianFinder {
    // Method 1 [BruteForce, Sorting] add: O(nlogn), find: O(1)

    // Method 2 [Augmented BST]

    // Method 3 [heap, GFG laptop course] add: logn, find: O(1)
    PriorityQueue<Integer> s; // max heap
    PriorityQueue<Integer> g; // min heap

    public MedianFinder() {
        s = new PriorityQueue<>(Collections.reverseOrder());
        g = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        if(s.isEmpty()) {
            s.add(num);
            return;
        }

        if(s.size()>g.size()){
            if(s.peek()>num) {
                g.add(s.poll());
                s.add(num);
            } else g.add(num);
        } else {
            if(num<=s.peek()) s.add(num);
            else {
                g.add(num);
                s.add(g.poll());
            }
        }
    }
    
    public double findMedian() {
        if(s.size()>g.size()) return s.peek();
        return (double)(s.peek() + g.peek())/2.0;       
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */