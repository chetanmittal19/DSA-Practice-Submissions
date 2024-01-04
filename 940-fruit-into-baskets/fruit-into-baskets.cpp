class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // For question understanding - Tech adora by nivedita
        // Explanation: find the length of longest subarray which contains only 2 type of fruits
        // int n = fruits.size();
        // unordered_set<int> s;
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         s.insert(fruits[j]);
        //         if(s.size()<=2) ans = max(ans, j-i+1);
        //         else {
        //             s.clear(); // removes all elements from stack
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // Method 2 [HashMap]
        unordered_map<int, int> map;
        int n = fruits.size();
        int ans = 0, l = 0;
        for(int r=0; r<n; r++){
            map[fruits[r]]++;
            while(map.size()>2){
                map[fruits[l]]--;
                if(map[fruits[l]]==0) map.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};