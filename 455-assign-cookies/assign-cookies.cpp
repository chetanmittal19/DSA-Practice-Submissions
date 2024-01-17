class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0, cnt=0;
        if(g.size()==0 || s.size()==0) return 0;
        while(i<g.size()) {
            int idx = binarySearch(s, g[i]);
            if(idx < s.size()) {
                cnt++;
                s.erase(s.begin()+idx);
            }
            i++;
        }
        return cnt;
    }

    int binarySearch(vector<int>&s, int target) {
        int l=0, r=s.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(s[mid]==target) return mid;
            else if(s[mid]<target) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};