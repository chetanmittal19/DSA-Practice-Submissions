class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // vector<int> freq(26, 0);
        // for(auto ch: tasks) freq[ch-'A']++;
        // sort(tasks.begin(), tasks.end(), greater<int>());
        // int idealSlots = (freq[0]-1)*n;
        // for(int i=1; i<freq.size(); i++) idealSlots-= min(freq[0]-1, freq[i]);
        // return tasks.size() + max(0, idealSlots);

        vector<int>hash(26,0);
        for(char c:tasks)hash[c-'A']++;
        sort(hash.begin(),hash.end(),greater<int>());
        int slots=hash[0]-1;
        int idle=slots*n;
        for(int i=1;i<hash.size();i++)
        {
            idle-=min(slots,hash[i]);
        }
        return tasks.size()+max(0,idle);
    }
};