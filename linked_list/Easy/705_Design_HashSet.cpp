struct ListNode {
    int val;
    ListNode* next;
    ListNode(int key = 0) : val(key), next(nullptr) {}
};

class MyHashSet {
public:
    ListNode* head;

    MyHashSet() {
        head = new ListNode(-1); // dummy head
    }

    void add(int key) {
        if (contains(key)) return; // avoid duplicates
        ListNode* newNode = new ListNode(key);
        newNode->next = head->next;
        head->next = newNode;
    }

    void remove(int key) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            if (curr->val == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(int key) {
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};
