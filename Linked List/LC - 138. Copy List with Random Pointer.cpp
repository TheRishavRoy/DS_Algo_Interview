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
        unordered_map<Node*, Node*> deepCopy;
        Node* traverse=head;
        //first iterate through the list.
        //For each node, 
        //create a deep copy of each node and hash it with it. 
        //Store it in the hashmap deepCopy.
        while(traverse!=nullptr)
        {
            Node* newNode=new Node(traverse->val);
            deepCopy[traverse]=newNode;
            traverse=traverse->next;
        }
        //again iterate through the given list
        //second iteration is store the pointer next and random
        traverse=head;
        while(traverse!=nullptr)
        {
            Node* node=deepCopy[traverse];//take node value from hash map itself
            node->next=(traverse->next)?deepCopy[traverse->next]:nullptr;//because deepCopy[tarverse] is the cur node 
            node->random=(traverse->random)?deepCopy[traverse->random]:NULL;//traverse->next is the next node in the original list.
            //traverse->random is the random node in the original list.
            traverse=traverse->next;
        }
        return deepCopy[head];//return start of hashmap deepCopy
    }
};
