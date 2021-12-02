class Solution {
public:
    Node* copyRandomList(Node* head) {
    // time complexity O(n) and space complecity is O(1)
        if(head==NULL){
           return NULL;
        }
        Node* curr=head;
        while(curr){
            
            Node* nxt=curr->next;
            Node* rand=curr->random;
            curr->next=new Node(curr->val,nxt,rand);
            curr=curr->next->next;
        }
        // updating random
        Node* nhead=head->next;
        curr=head;
        while(curr!=NULL){
            if(curr->next->random){
                curr->next->random=curr->next->random->next;
                
            }else{
                curr->next->random=NULL;
            }
            curr=curr->next->next;
        }
        // deleting extra nodes
        curr=head;
        while(curr!=NULL){
            Node* copy=curr->next;
            curr->next=copy->next;
            if(copy->next){
                copy->next=curr->next->next;
            }
            curr=curr->next;
        }
        return nhead;
    
    }
};