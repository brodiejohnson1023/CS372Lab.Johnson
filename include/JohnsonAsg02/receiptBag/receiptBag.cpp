// receiptBag.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief A bag (multiset) that assigns a unique receipt to each inserted item.
 *
 * @tparam T Type of items stored.
 *
 * Features:
 *  - Items are stored in a vector.
 *  - Each item gets a unique receipt ID.
 *  - Items can be removed using their receipt.
 */
template <typename T>
class ReceiptBag {
    vector<T> items;       // Stores all items
    vector<int> receipts;  // Stores matching receipt IDs
    int nextID = 1;        // Next available receipt ID

public:
    /**
     * @brief Insert an item and return its receipt ID.
     * @param val The item to insert.
     * @return Unique receipt ID for this item.
     */
    int insert(const T& val) {
        items.push_back(val);
        receipts.push_back(nextID);
        return nextID++;
    }

    /**
     * @brief Remove an item by receipt ID.
     * @param receipt The receipt ID of the item to remove.
     * @param out Reference to store the removed item.
     * @return true if the item was found and removed, false otherwise.
     */
    bool remove(int receipt, T& out) {
        for (size_t i = 0; i < receipts.size(); i++) {
            if (receipts[i] == receipt) {
                out = items[i];
                items.erase(items.begin() + i);
                receipts.erase(receipts.begin() + i);
                return true;
            }
        }
        return false;
    }

    /// Get the number of items currently in the bag.
    size_t size() const { return items.size(); }
};

int main() {
    ReceiptBag<string> bag;

    // Insert two items
    int r1 = bag.insert("apple");
    int r2 = bag.insert("banana");

    cout << "Inserted receipts: " << r1 << ", " << r2 << endl;

    // Remove an item using receipt
    string item;
    if (bag.remove(r1, item)) {
        cout << "Removed item with receipt " << r1 << ": " << item << endl;
    }
    else {
        cout << "Receipt not found.\n";
    }

    return 0;
}

