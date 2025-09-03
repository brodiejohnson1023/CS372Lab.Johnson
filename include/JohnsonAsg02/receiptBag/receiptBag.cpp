// receiptBag.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class ReceiptBag {
    vector<T> items;
    vector<int> receipts;
    int nextID = 1;
public:
    int insert(const T& val) {
        items.push_back(val);
        receipts.push_back(nextID);
        return nextID++;
    }
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
};

int main() {
    ReceiptBag<string> bag;
    int r1 = bag.insert("apple");
    int r2 = bag.insert("banana");
    cout << "Inserted receipts: " << r1 << ", " << r2 << endl;

    string item;
    if (bag.remove(r1, item))
        cout << "Removed receipt " << r1 << ": " << item << endl;
    else
        cout << "Receipt not found.\n";
    return 0;
}
