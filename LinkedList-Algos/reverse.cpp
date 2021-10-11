// Following function is used to reverse the Linked list given its head

ListNode* reverse_list(ListNode* head)
{
    ListNode dummy(-1); //creating dummy node to deal with edge cases
    dummy.next = head;

    ListNode *curr = head; 

    while(curr)
    {
        ListNode *next_node = curr->next;  // used for incrementing curr pointer

        curr->next = dummy.next; // curr next to point head of list

        dummy.next = curr; // curr becomes head

        curr = next_node;  //incrementing curr
    }

    if(head) //if head exist then it will become tail in reverse list thus making it NULL else it will be self pointing
    head->next = NULL;

    return dummy.next; //dummy.next holds our new head
}