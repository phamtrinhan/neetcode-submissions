class MinStack {
    long min;
    stack<long> stack;

public:
    MinStack() {}
    void push(int val) {
        if (stack.empty()) {
            stack.push(0);
            min = val;
            return;
        }
        long diff = (long)val - min;
        stack.push(diff);
        if (diff < 0) {
            min = val;
        }
    }

    void pop() {
        if (stack.empty()) return;
        long diff = stack.top();
        stack.pop();
        if (diff < 0) {
            min = min - diff;
        }
    }

    int top() {
        if (stack.empty()) return -1;
        long diff = stack.top();
        if (diff <= 0) {
            return (int)min;
        }
        return (int)(min + diff);
    }
    int getMin() {
        return (int)min;
    }
};