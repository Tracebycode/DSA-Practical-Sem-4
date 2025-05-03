// Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of
// telephone numbers. Use linear probing and quadratic probing as collision handling
// techniques.



#include <iostream>
using namespace std;

#define TABLE_SIZE 10

class HashTable {
public:
    int table[TABLE_SIZE];
    int comparisons;

    void initialize() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
        comparisons = 0;
    }

    void insertLinear(int key) {
        int index = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            if (table[probe] == -1) {
                table[probe] = key;
                return;
            }
        }
        cout << "Hash table is full (Linear Probing)\n";
    }

    void insertQuadratic(int key) {
        int index = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i * i) % TABLE_SIZE;
            if (table[probe] == -1) {
                table[probe] = key;
                return;
            }
        }
        cout << "Hash table is full (Quadratic Probing)\n";
    }

    bool searchLinear(int key) {
        comparisons = 0;
        int index = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i) % TABLE_SIZE;
            comparisons++;
            if (table[probe] == key)
                return true;
            if (table[probe] == -1)
                return false;
        }
        return false;
    }

    bool searchQuadratic(int key) {
        comparisons = 0;
        int index = key % TABLE_SIZE;
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probe = (index + i * i) % TABLE_SIZE;
            comparisons++;
            if (table[probe] == key)
                return true;
            if (table[probe] == -1)
                return false;
        }
        return false;
    }

    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == -1)
                cout << "- ";
            else
                cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HashTable linearHT, quadraticHT;
    int key, n;
    cout << "Enter number of clients (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Please enter 10 or fewer clients.\n";
        return 0;
    }

    int phoneNumbers[10];
    cout << "Enter telephone numbers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Client " << i + 1 << ": ";
        cin >> phoneNumbers[i];
    }

    // Linear Probing Insertion
    linearHT.initialize();
    for (int i = 0; i < n; i++)
        linearHT.insertLinear(phoneNumbers[i]);

    // Quadratic Probing Insertion
    quadraticHT.initialize();
    for (int i = 0; i < n; i++)
        quadraticHT.insertQuadratic(phoneNumbers[i]);

    // Display Hash Tables
    cout << "\nLinear Probing Hash Table:\n";
    linearHT.display();
    cout << "Quadratic Probing Hash Table:\n";
    quadraticHT.display();

    // Search and compare
    cout << "\n--- Search and Comparison ---\n";
    for (int i = 0; i < n; i++) {
        linearHT.searchLinear(phoneNumbers[i]);
        int linearComp = linearHT.comparisons;

        quadraticHT.searchQuadratic(phoneNumbers[i]);
        int quadComp = quadraticHT.comparisons;

        cout << "Searching for " << phoneNumbers[i] << ":\n";
        cout << "  Linear Probing Comparisons: " << linearComp << "\n";
        cout << "  Quadratic Probing Comparisons: " << quadComp << "\n";
    }

    return 0;
}
