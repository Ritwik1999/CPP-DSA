void reverse(stack<int> &input, stack<int> &extra) {
	if(extra.empty())
    {
        return;
    }
    
    int ele = extra.top();
    extra.pop();
    
    reverse(input, extra);
    
    input.push(ele);
    return;
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    while(!input.empty())
    {
        int ele = input.top();
        input.pop();
        extra.push(ele);
    }
    
    reverse(input, extra);
}