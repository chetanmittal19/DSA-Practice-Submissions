class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(auto ch: tasks) freq[ch-'A']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int idealSlots = (freq[0]-1)*n;
        for(int i=1; i<freq.size(); i++) idealSlots-= min(freq[0]-1, freq[i]);
        return tasks.size() + max(0, idealSlots);
    }
};