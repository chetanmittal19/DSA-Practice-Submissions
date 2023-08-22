class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();
        while (columnNumber != 0) {
            int rem = columnNumber % 26;
            ans.append(getChar(rem));
            columnNumber /= 26;
            columnNumber = (rem == 0 ? columnNumber - 1 : columnNumber);
        }
        return ans.reverse().toString();
    }
    
    private String getChar(int num) {
        int base = 64;
        if (num == 0) {
            return "Z";
        }
        return String.valueOf((char)(base + num));
    }
}