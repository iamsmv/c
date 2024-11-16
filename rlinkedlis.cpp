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
