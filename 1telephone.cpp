#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10; // Hash table size (can adjust as needed)

class HashEntry {
public:
    long long telephone;
    string name;
    bool isOccupied;

    HashEntry() {
        telephone = 0;
        name = "";
        isOccupied = false;
    }
};

class HashTableLinear {
    HashEntry table[SIZE];

public:
    int insert(string name, long long tele) {
        int key = tele % SIZE;
        int comparisons = 1;

        for (int i = 0; i < SIZE; i++) {
            int idx = (key + i) % SIZE;
            if (!table[idx].isOccupied) {
                table[idx].telephone = tele;
                table[idx].name = name;
                table[idx].isOccupied = true;
                return comparisons;
            }
            comparisons++;
        }
        cout << "Hash table (Linear) is full.\n";
        return comparisons;
    }

    int search(long long tele) {
        int key = tele % SIZE;
        int comparisons = 1;

        for (int i = 0; i < SIZE; i++) {
            int idx = (key + i) % SIZE;

            if (!table[idx].isOccupied)
                return comparisons;

            if (table[idx].telephone == tele) {
                cout << "[Linear] Found: " << table[idx].name << " - " << table[idx].telephone << endl;
                return comparisons;
            }
            comparisons++;
        }

        cout << "[Linear] Telephone not found.\n";
        return comparisons;
    }
};

class HashTableQuadratic {
    HashEntry table[SIZE];

public:
    int insert(string name, long long tele) {
        int key = tele % SIZE;
        int comparisons = 1;

        for (int i = 0; i < SIZE; i++) {
            int idx = (key + i * i) % SIZE;

            if (!table[idx].isOccupied) {
                table[idx].telephone = tele;
                table[idx].name = name;
                table[idx].isOccupied = true;
                return comparisons;
            }
            comparisons++;
        }
        cout << "Hash table (Quadratic) is full.\n";
        return comparisons;
    }

    int search(long long tele) {
        int key = tele % SIZE;
        int comparisons = 1;

        for (int i = 0; i < SIZE; i++) {
            int idx = (key + i * i) % SIZE;

            if (!table[idx].isOccupied)
                return comparisons;

            if (table[idx].telephone == tele) {
                cout << "[Quadratic] Found: " << table[idx].name << " - " << table[idx].telephone << endl;
                return comparisons;
            }
            comparisons++;
        }

        cout << "[Quadratic] Telephone not found.\n";
        return comparisons;
    }
};

// --------- Main Program ------------
int main() {
    HashTableLinear linear;
    HashTableQuadratic quadratic;

    int choice;
    string name;
    long long tele;

    while (true) {
        cout << "\n---- Telephone Book ----\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter 10-digit telephone number: ";
            cin >> tele;

            if (tele < 1000000000 || tele > 9999999999) {
                cout << "Invalid telephone number.\n";
                break;
            }

            linear.insert(name, tele);
            quadratic.insert(name, tele);
            cout << "Record inserted in both tables.\n";
            break;

        case 2:
            cout << "Enter telephone number to search: ";
            cin >> tele;

            if (tele < 1000000000 || tele > 9999999999) {
                cout << "Invalid telephone number.\n";
                break;
            }

            int compLinear, compQuadratic;
            compLinear = linear.search(tele);
            compQuadratic = quadratic.search(tele);

            cout << "Comparisons in Linear Probing: " << compLinear << endl;
            cout << "Comparisons in Quadratic Probing: " << compQuadratic << endl;
            break;

        case 3:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
