class CustomStack {
    int size;
    vector<int> stack;
public:
    CustomStack(int maxSize) {
        stack = vector<int>();
        size = maxSize;
    }
    
    void push(int x) {
        if (stack.size() != size) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.size() == 0) return -1;
        int result = stack[stack.size() - 1];
        stack.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)stack.size()); i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */