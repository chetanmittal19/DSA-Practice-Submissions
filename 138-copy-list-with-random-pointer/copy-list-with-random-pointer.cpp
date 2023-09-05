/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Method 1 [HashMap] O(2N)=O(N), O(N)
        // if(head==NULL) return head;
        // unordered_map<Node*, Node*> map;
        // Node *curr = head;
        // while(curr!=NULL){
        //     map[curr] = new Node(curr->val);
        //     curr=curr->next;
        // }
        // curr=head;
        // Node *cloneHead=map[curr];
        // while(curr!=NULL){
        //     Node *cloneNode = map[curr];
        //     cloneNode->next = map[curr->next];
        //     cloneNode->random = map[curr->random];
        //     curr=curr->next;
        // }
        // return cloneHead;

        //Method 2 O(3N)=O(N), O(1)
        if(head==NULL) return head;
        Node *curr = head;
        while(curr!=NULL){
            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr=newNode->next;
        }

        curr = head;
        while(curr!=NULL){
            if(curr->random!=NULL) curr->next->random = curr->random->next;
            curr=curr->next->next;
        }

        curr=head;
        Node *clonedHead = curr->next;
        Node *clonedTail = clonedHead;
        while(curr->next->next!=NULL){
            curr->next = curr->next->next;
            curr=curr->next;
            clonedTail->next = clonedTail->next->next;
            clonedTail = clonedTail->next;
        }
        curr->next = NULL;
        return clonedHead;
    }
};