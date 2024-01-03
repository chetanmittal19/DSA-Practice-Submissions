class StockSpanner {

    Stack<Pair> st;
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        int val = 1;
        while(!st.isEmpty() && st.peek().price<=price) {
            val+= st.peek().span;
            st.pop();
        }
        st.push(new Pair(price, val));
        return val;
    }

    class Pair {
        int price, span;
        Pair(int price, int span){
            this.price = price;
            this.span = span;
        }
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */