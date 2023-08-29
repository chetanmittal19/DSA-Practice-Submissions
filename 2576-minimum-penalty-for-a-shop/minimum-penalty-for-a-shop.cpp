class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = INT_MAX;
        int minPenaltyHour = 0;

        int totalOpen = 0;
        for(auto s: customers) if(s=='Y') totalOpen++;

        int currOpen = 0, currClosed = 0;
        for(int i=0; i<=customers.size(); i++){
            int penalty = currClosed + (totalOpen-currOpen);
            if(penalty<minPenalty){
                minPenalty=penalty;
                minPenaltyHour = i;
            }
            if(i==customers.size()) break;

            if(customers[i]=='Y') currOpen++;
            else currClosed++;
        }
        return minPenaltyHour;
    }
};