class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i=0;
        while(i<n){
            int lineLength = words[i].size();
            int j = i+1;

            while(j<n && lineLength + words[j].size() + (j-i) <= maxWidth){
                lineLength+=words[j].size();
                j++;
            }

            int numWords = j-i;
            string line = words[i];
            if(numWords==1 || j==n){
                for(int k=i+1; k<j; k++){
                    line+= ' ' + words[k];
                }
                line+= string(maxWidth-line.size(), ' ');
            } else {
                int numSpaces = maxWidth - lineLength;
                int spaceBetweenWords = numSpaces/(numWords-1);
                int extraSpaces = numSpaces%(numWords-1);
                for(int k=i+1; k<j; k++){
                    line+= string(spaceBetweenWords, ' ');
                    if(extraSpaces>0){
                        line+=' ';
                        extraSpaces--;
                    }
                    line+= words[k];
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};