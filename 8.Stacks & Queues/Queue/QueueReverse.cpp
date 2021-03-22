void reverseQueue(queue<int> &input) {
    int ele = input.front();
    input.pop();
    reverseQueueRec(input, ele);
    return;    
}

void reverseQueueRec(queue<int>& q, int ele)
{
    // Base Case
    if (q.empty())
    {
        q.push(ele);
        return;
    }
    
    // Recurison
    int nextEle = q.front();
    q.pop();
    reverseQueueRec(q, nextEle);
    
    // Computation
    q.push(ele);  
    
    return;
}