#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to represent each node (Book, Chapter, Section, Subsection)
struct Node {
    string label;         // Name of the node (e.g., Book title, Chapter name)
    int count;            // Number of child nodes
    vector<Node*> children;   // Vector of pointers to child nodes

    // Constructor to initialize count and children
    Node() : count(0) {}
};

// Class to manage the book tree
class BookTree {
    Node* root;  // Root node (represents the Book)

public:
    // Constructor initializes root to null
    BookTree() : root(nullptr) {}

    // Destructor to free allocated memory
    ~BookTree() {
        deleteTree(root);
    }

    // Helper function to delete the tree
    void deleteTree(Node* node) {
        if (!node) return;
        for (Node* child : node->children) {
            deleteTree(child);  // Recursively delete child nodes
        }
        delete node;  // Delete the current node
    }

    // Function to create the book structure (Book → Chapters → Sections → Subsections)
    void create() {
        root = new Node();        // Create root node
        cin.ignore();             // Clear input buffer

        cout << "Enter Book Name: ";
        getline(cin, root->label);  // Input book title

        cout << "Enter number of chapters: ";
        cin >> root->count;         // Input chapter count

        // Loop to input each chapter
        for (int i = 0; i < root->count; i++) {
            Node* chapter = new Node();  // Create chapter node
            cin.ignore();
            cout << "  Enter Chapter " << i + 1 << " name: ";
            getline(cin, chapter->label);

            cout << "  Enter number of sections: ";
            cin >> chapter->count;

            // Loop to input each section under chapter
            for (int j = 0; j < chapter->count; j++) {
                Node* section = new Node();  // Create section node
                cin.ignore();
                cout << "    Enter Section " << j + 1 << " name: ";
                getline(cin, section->label);

                cout << "    Enter number of subsections: ";
                cin >> section->count;

                // Loop to input each subsection under section
                for (int k = 0; k < section->count; k++) {
                    Node* subsection = new Node();  // Create subsection node
                    cin.ignore();
                    cout << "      Enter Subsection " << k + 1 << " name: ";
                    getline(cin, subsection->label);

                    subsection->count = 0;  // Subsections don’t have further children
                    section->children.push_back(subsection);  // Add subsection to section
                }

                chapter->children.push_back(section);  // Add section to chapter
            }

            root->children.push_back(chapter);  // Add chapter to book
        }
    }

    // Function to display the book hierarchy
    void display() {
        if (!root) {
            cout << "Book tree is empty.\n";
            return;
        }

        // Display Book name
        cout << "\nBook: " << root->label << "\n";

        // Display Chapters
        for (int i = 0; i < root->count; i++) {
            cout << "  Chapter " << i + 1 << ": " << root->children[i]->label << "\n";

            // Display Sections under each chapter
            for (int j = 0; j < root->children[i]->count; j++) {
                cout << "    Section " << j + 1 << ": " << root->children[i]->children[j]->label << "\n";

                // Display Subsections under each section
                for (int k = 0; k < root->children[i]->children[j]->count; k++) {
                    cout << "      Subsection " << k + 1 << ": " << root->children[i]->children[j]->children[k]->label << "\n";
                }
            }
        }
    }
};

int main() {
    BookTree bt;  // Create object of BookTree
    int choice;

    // Menu-driven program
    while (true) {
        cout << "\n--- Menu ---\n1. Create Book\n2. Display Book\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bt.create(); break;   // Build the book structure
            case 2: bt.display(); break;  // Display the hierarchy
            case 3: return 0;             // Exit the program
            default: cout << "Invalid choice.\n";
        }
    }
}
