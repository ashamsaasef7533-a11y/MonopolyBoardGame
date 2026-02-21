#include <iostream>
#include <fstream>
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

    // Destructor to clean up memory and prevent leaks
    ~CircularLinkedList() {
        if (head == nullptr) return;

        CircularNode* current = head;
        for (int i = 0; i < length; i++) {
            CircularNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    bool addSpace(string strValue) {
        if (length >= capacity) {
            cerr << "Error: Reached Maximum Capacity of 40" << endl;
            return false;
        }

        CircularNode* newNode = new CircularNode(strValue);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Make it circular immediately
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Close the circle
        }

        length++;
        return true;
    }

    void loadSpacesFromFile(string filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open the file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            // Check for non-empty lines to avoid adding blank spaces to the board
            if (!line.empty()) {
                addSpace(line);
            }
        }

        file.close();
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout << "The board is empty." << endl;
            return;
        }

        CircularNode* temp = head;
        for (int i = 0; i < length; i++) {
            cout << "[" << i + 1 << "] " << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    CircularLinkedList board;

    // Load spaces from the provided Spaces.txt file
    board.loadSpacesFromFile("C:\\CS210\\MonopolyBoardGame\\Spaces.txt");

    board.addSpace("Mediterranean Avenue");
    board.addSpace("Community Chest");

    cout << "=======================================" << endl;
    cout << " WELCOME TO MONOPOLY-ARMAAN SHAMSAASEF " << endl;
    cout << "=======================================" << endl;

    board.printLinkedList();

    return 0;
}