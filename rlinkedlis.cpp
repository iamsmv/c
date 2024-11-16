Reversing a linked list can also be approached progressively, from brute force to optimized methods. Here's a step-by-step guide:

---

### **1. Brute Force Approach (Using Extra Space)**  
Copy the elements to a stack (or another container) and reconstruct the list in reverse order.

```cpp
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedListBruteForce(Node* head) {
    stack<int> s;
    Node* temp = head;

    // Push all elements into the stack
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }

    // Reconstruct the linked list in reverse order
    temp = head;
    while (temp) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}

// Helper Functions
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedListBruteForce(head);
    cout << "Reversed (Brute Force): ";
    printList(head);

    return 0;
}
```
**Time Complexity**: \(O(n)\)  
**Space Complexity**: \(O(n)\) (due to the stack).

---

### **2. Iterative In-Place Reversal (Optimized Approach)**  
Reverse the pointers of the list iteratively without using extra space.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedListIterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next; // Save next node
        curr->next = prev; // Reverse the link
        prev = curr;       // Move prev forward
        curr = next;       // Move curr forward
    }
    return prev; // New head of the list
}

// Helper Functions
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedListIterative(head);
    cout << "Reversed (Iterative): ";
    printList(head);

    return 0;
}
```
**Time Complexity**: \(O(n)\)  
**Space Complexity**: \(O(1)\)

---

### **3. Recursive In-Place Reversal**
Reverse the pointers of the list recursively.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedListRecursive(Node* head) {
    if (!head || !head->next) {
        return head; // Base case: empty list or single node
    }

    Node* rest = reverseLinkedListRecursive(head->next); // Reverse the rest
    head->next->next = head; // Point next node's next to current node
    head->next = nullptr;    // Set current node's next to null
    return rest; // New head of the reversed list
}

// Helper Functions
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = reverseLinkedListRecursive(head);
    cout << "Reversed (Recursive): ";
    printList(head);

    return 0;
}
```
**Time Complexity**: \(O(n)\)  
**Space Complexity**: \(O(n)\) (due to recursive stack calls).

---

### **Comparison**
| Approach             | Time Complexity | Space Complexity | Notes                          |
|----------------------|-----------------|------------------|--------------------------------|
| Brute Force (Stack)  | \(O(n)\)        | \(O(n)\)         | Extra memory used for stack.   |
| Iterative In-Place   | \(O(n)\)        | \(O(1)\)         | Best memory efficiency.        |
| Recursive In-Place   | \(O(n)\)        | \(O(n)\)         | Elegant but uses recursion.    |

The **Iterative In-Place** approach is the most efficient for practical purposes.
