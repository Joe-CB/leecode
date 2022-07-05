


BFS General Steps:
1. Initialize Queue with all entry points
3. While Queue is not empty
    a. for each node in the queue
    b. poll out the element(add to result)
    c. expand it, offer children to the queue in order
    d. increate level
> 每个node进出Queue一次->O(n)

