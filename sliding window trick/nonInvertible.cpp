int opr(int a, int b){
    return (a|b); // can be changed for other operations like max, min, gcd, lcm etc
}
struct AggStack {
    // Each element is stored as (value, current_min)
    stack<pair<int, int>> st;
    
    // Push a new number; compute the new min.
    void push(int x) {
        int cur = st.empty() ? x : opr(st.top().second,x);
        st.push({x, cur});
    }
    
    // Pop the top element.
    void pop() {
        st.pop();
    }
    
    // Return the current minimum.
    int agg() const {
        return st.top().second;
    }
};
struct AggQueue {
    AggStack in, out;
    
    // Push a new number into the queue.
    void push(int x) {
        in.push(x);
    }
    
    // Pop the oldest number.
    void pop() {
        if (out.st.empty()) {
            while (!in.st.empty()) {
                int v = in.st.top().first;
                in.pop();
                out.push(v);
            }
        }
        out.pop();
    }
    
    // Query the current minimum.
    int query() const {
        if (in.st.empty()) return out.agg();
        if (out.st.empty()) return in.agg();
        return opr(in.agg(),out.agg());
    }
};
void solve() {
    int n, k; cin >> n >> k;
    int x, a, b , c; cin >> x >>a >> b >> c;
    vector<int>v(n);
    v[0] = x;
    for(int i =1; i<n; i++){
        v[i] = (v[i-1]*a+b) % c;
    }

    AggQueue mq;
    for (int i = 0; i < k; i++) {
        mq.push(v[i]);
    }
    int ans = mq.query();
    for(int i = k; i<n; i++){
        mq.pop();
        mq.push(v[i]);
        ans ^= mq.query();
    }
    cout << ans << "\n";

}