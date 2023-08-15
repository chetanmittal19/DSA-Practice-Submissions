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
        if(head==NULL) return head;
        unordered_map<Node*, Node*> map;
        Node *curr = head;
        while(curr!=NULL){
            map[curr] = new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        Node *cloneHead=map[curr];
        while(curr!=NULL){
            Node *cloneNode = map[curr];
            cloneNode->next = map[curr->next];
            cloneNode->random = map[curr->random];
            curr=curr->next;
        }
        return cloneHead;

    }
};