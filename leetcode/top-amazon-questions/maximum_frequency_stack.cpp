/*
Difficulty: Hard;
Phone Interview 

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

Constraints:
0 <= val <= 10^9
At most 2 * 10^4 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.*/

#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> freq; // val, freq
    unordered_map<int, stack<int>> m; // freq, stack de nums com aquela freq
    int maxFreq = 0;
    
    FreqStack() { }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        int val = m[maxFreq].top();
        m[maxFreq].pop();
        
        if(!m[freq[val]--].size()){
            maxFreq--;
        }  
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
