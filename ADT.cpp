#include <iostream>
#include <vector>
#include <algorithm>

class SetADT {
private:
    std::vector<int> elements;

public:
    // Add an element to the set
    void add(int newElement) {
        if (std::find(elements.begin(), elements.end(), newElement) == elements.end()) {
            elements.push_back(newElement);
        }
    }

    // Remove an element from the set
    void remove(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    // Check if an element is in the set (const method)
    bool contains(int element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Return the size of the set
    int size() const {
        return elements.size();
    }

    // Iterator to loop over elements
    void iterator() const {
        for (int element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // Intersection of two sets
    SetADT intersection(const SetADT& otherSet) const {
        SetADT result;
        for (int element : elements) {
            if (otherSet.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Union of two sets
    SetADT unionSet(const SetADT& otherSet) const {
        SetADT result;
        for (int element : elements) {
            result.add(element);
        }
        for (int element : otherSet.elements) {
            result.add(element);
        }
        return result;
    }

    // Difference between two sets
    SetADT difference(const SetADT& otherSet) const {
        SetADT result;
        for (int element : elements) {
            if (!otherSet.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Check if the current set is a subset of another set
    bool subset(const SetADT& otherSet) const {
        for (int element : elements) {
            if (!otherSet.contains(element)) {
                return false;
            }
        }
        return true;
    }

    // Display the set
    void display() const {
        std::cout << "{ ";
        for (int element : elements) {
            std::cout << element << " ";
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    SetADT set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    set1.add(4);
    
    SetADT set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);
    set2.add(6);
    
    std::cout << "Set 1: ";
    set1.display();
    
    std::cout << "Set 2: ";
    set2.display();
    
    set1.add(5);
    std::cout << "Set 1 after adding 5: ";
    set1.display();
    
    set1.remove(3);
    std::cout << "Set 1 after removing 3: ";
    set1.display();
    
    std::cout << "Set 1 contains 2: " << (set1.contains(2) ? "Yes" : "No") << std::endl;
    std::cout << "Size of Set 1: " << set1.size() << std::endl;
    
    std::cout << "Iterator for Set 1: ";
    set1.iterator();
    
    // Intersection
    SetADT intersectionSet = set1.intersection(set2);
    std::cout << "Intersection: ";
    intersectionSet.display();
    
    // Union
    SetADT unionSet = set1.unionSet(set2);
    std::cout << "Union: ";
    unionSet.display();
    
    // Difference
    SetADT diffSet = set1.difference(set2);
    std::cout << "Difference (Set 1 - Set 2): ";
    diffSet.display();
    
    // Subset check
    std::cout << "Is Set 1 a subset of Set 2? " 
              << (set1.subset(set2) ? "Yes" : "No") << std::endl;
    
    return 0;
}
