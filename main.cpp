#include <iostream>
#include <string>

using namespace std;

const int capacity = 40;

class CircularNode {
public:
    string data;
    CircularNode* next;

    explicit CircularNode(string d) : data(d), next(nullptr) {}
};

class CircularLinkedList {
private:
    CircularNode* head;
    CircularNode* tail;
    int length;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    bool addSpace(string strValue) {
        if (length >= capacity) return false;

        CircularNode* newNode = new CircularNode(strValue);

        if (head == nullptr) {
            // First node logic
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself
        } else {
            // Standard insertion
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circle
        }

        length++;
        return true; // Added missing return
    }

    void printLinkedList() {
        if (!head) return;

        CircularNode* temp = head;
        for (int i = 0; i < length; i++) { // Initialize i = 0
            cout << temp->data << " -> ";
            temp = temp->next; // Move to the next node
        }
        cout << "(Back to " << head->data << ")" << endl;
        cout << "Current List Length = " << length << endl;
    }
};

int main() {
    CircularLinkedList board;
    board.addSpace("GO");
    board.addSpace("Mediterranean Avenue");
    board.addSpace("Community Chest");

    cout << "WELCOME TO MONOPOLY" << endl;
    cout << "THIS IS ARMAAN SHAMSAASEF'S VERSION" << endl;
    cout << "GOOD LUCK" << endl;
    board.printLinkedList();


    return 0;
}