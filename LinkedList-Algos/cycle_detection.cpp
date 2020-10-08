// following function return node where cycle begins if present else it return NULL

 ListNode *detectCycle(ListNode *head) {

        if(head==NULL || head->next==NULL) 
            return NULL;


        ListNode *slow=head,*fast=head;
        do
        {
            if(fast->next==NULL || fast->next->next==NULL) 
                return NULL;
            fast=fast->next->next;
            slow=slow->next;
        }while(slow!=fast);
        
        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
        
    }