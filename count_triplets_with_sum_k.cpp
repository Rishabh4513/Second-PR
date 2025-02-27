/*

Traverse the doubly linked list from left to right. 
For each current node during the traversal, 
initailze two pointers first = pointer to the node 
next to the current node and last = pointer to the
last node of the list. 
Now, count pairs in the list from first to last pointer 
that sum up to value (x – current node’s data). 
Add this count to the total_count of triplets. 
Pointer to the last node can be found only once in the beginning.

*/

int countPairs(struct Node* first, struct Node* second, int value) 
{ 
    int count = 0; 
  
    // The loop terminates when either of two pointers 
    // become NULL, or they cross each other (second->next 
    // == first), or they become same (first == second) 
    while (first != NULL && second != NULL &&  
           first != second && second->next != first) { 
  
        // pair found 
        if ((first->data + second->data) == value) { 
  
            // increment count 
            count++; 
  
            // move first in forward direction 
            first = first->next; 
  
            // move second in backward direction 
            second = second->prev; 
        } 
  
        // if sum is greater than 'value' 
        // move second in backward direction 
        else if ((first->data + second->data) > value) 
            second = second->prev; 
  
        // else move first in forward direction 
        else
            first = first->next; 
    } 
  
    // required count of pairs 
    return count; 
} 
  
// function to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
int countTriplets(struct Node* head, int x) 
{ 
    // if list is empty 
    if (head == NULL) 
        return 0; 
  
    struct Node* current, *first, *last; 
    int count = 0; 
  
    // get pointer to the last node of 
    // the doubly linked list 
    last = head; 
    while (last->next != NULL) 
        last = last->next; 
  
    // traversing the doubly linked list 
    for (current = head; current != NULL; current = current->next) { 
  
        // for each current node 
        first = current->next; 
  
        // count pairs with sum(x - current->data) in the range 
        // first to last and add it to the 'count' of triplets 
        count += countPairs(first, last, x - current->data); 
    } 
  
    // required count of triplets 
    return count; 
} 