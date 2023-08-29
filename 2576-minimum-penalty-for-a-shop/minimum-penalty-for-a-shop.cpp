class Solution {
public:
    int bestClosingTime(string customers) {
        //Method 1 [PrefixSum] O(3N) = O(N), O(2N) = O(N)
        int n = customers.size();
        vector<int> prefixN(n+1, 0); //prefixN[i] is number of N before the ith hour
        vector<int> suffixN(n+1, 0); //suffixN[i] is number of Y after the ith hour

        // at 0th hour, number of N before 0th hour is 0 => prefixN[0] = 0;
        // at Nth hour, number of Y after Nth hour is 0 => suffixN[N] = 0;
        // prefixN will be calculated from start and suffixN will be from N
        // for string "YYNY", prefixN[] = {0, 0, 0, 1, 1}, suffixN[] = {3, 2, 1, 1, 0}
        for(int i=0; i<n; i++) prefixN[i+1] = prefixN[i] + (customers[i]=='N');
        for(int i=n-1; i>=0; i--) suffixN[i] = suffixN[i+1] + (customers[i]=='Y');

        int minPenalty = INT_MAX;
        int minPenaltyHour = 0;
        for(int i=0; i<=n; i++){
            if(prefixN[i] + suffixN[i]<minPenalty){
                minPenalty = prefixN[i] + suffixN[i];
                minPenaltyHour = i;
            }
        }
        return minPenaltyHour;

        
        // Method 2 [Iterative, Prakhar Aggarwal -> 8min] O(2N) = O(N), O(1)
        // int minPenalty = INT_MAX;
        // int minPenaltyHour = 0;
        // int totalOpen = 0;
        // for(auto s: customers) if(s=='Y') totalOpen++;
        // int currOpen = 0, currClosed = 0;
        
        // // Penalty at ith hour is calculated as the number of times there was no customer previously(currClosed) + number of customers which came after the shop closed at ith hour(totalOpen - currOpen) 
        // for(int i=0; i<=customers.size(); i++){
        //     int penalty = currClosed + (totalOpen-currOpen);
        //     if(penalty<minPenalty){
        //         minPenalty=penalty;
        //         minPenaltyHour = i;
        //     }
        //     if(i==customers.size()) break;

        //     if(customers[i]=='Y') currOpen++;
        //     else currClosed++;
        // }
        // return minPenaltyHour;
    }
};