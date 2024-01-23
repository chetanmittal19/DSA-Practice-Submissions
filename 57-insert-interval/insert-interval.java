class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // Method 1 [Greedy] O(n + nlogn + 2n), O(n)
        // int [][] merged = new int[intervals.length+1][];
        // int c = 0;
        // for (int[] i : intervals) merged[c++] = i;
        // merged[intervals.length] = newInterval;
        // Arrays.sort(merged , (a,b) -> Integer.compare(a[0], b[0]));
        // List<int []> l1 = new ArrayList<>();
        // for(int[] arr : merged) {
        //     if(l1.size() == 0) l1.add(arr);
        //     else{
        //         int[] prevArr = l1.get(l1.size()-1);
        //         if(arr[0] <= prevArr[1]) prevArr[1] = Math.max(prevArr[1] , arr[1]);
        //         else l1.add(arr);
        //     }
        // }
        // return l1.toArray(new int[l1.size()][]);

        List<int[]> result = new ArrayList<>();
        int i = 0;
        // Add intervals before newInterval
        while (i < intervals.length && intervals[i][1] < newInterval[0]) {
            result.add(intervals[i]);
            i++;
        }
        // Merge overlapping intervals with newInterval
        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.add(newInterval);
        // Add intervals after newInterval
        while (i < intervals.length) {
            result.add(intervals[i]);
            i++;
        }
        return result.toArray(new int[result.size()][]);
    }
}