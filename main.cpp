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

    CircularNode();
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

    // Core B: Add Multiple Spaces at Once
    int addMany(int amountToAdd, string filename) {

        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open the file " << filename << endl;
            return 0;
        }

        string line;
        int added = 0;
        for (int i = 0; i < amountToAdd; i++) {
            if (length >= capacity) {
                cout << "Capacity reached at 40." << endl;
                break;
            }

            if (getline(file, line)) {
                if (!line.empty()) {
                    addSpace(line);
                    added++;
                }
            }

        }

        file.close();

        return added;
    }

    void loadSpacesFromFile(string filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open the file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
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

    cout << "=======================================" << endl;
    cout << " WELCOME TO MONOPOLY-ARMAAN SHAMSAASEF " << endl;
    cout << "=======================================" << endl;
    // 1. Create the board object
    CircularLinkedList board;

    // 2. Variable to store how many were actually added
    int rewardedItem = 0;

    // 3. Call the function (Adding 10 as per your handwritten note)
    rewardedItem = board.addMany(15, "..\\Spaces.txt");

    board.printLinkedList();

    // 4. Output the results to the console
    cout << "------------------------------------" << endl;
    cout << "Result: " << rewardedItem << " spaces successfully added." << endl;
    cout << "------------------------------------" << endl;

    // Load spaces from the provided Spaces.txt file
    board.loadSpacesFromFile("..\\Spaces.txt");

    board.addSpace("Mediterranean Avenue");
    board.addSpace("Community Chest");

    board.printLinkedList();

    return 0;
}