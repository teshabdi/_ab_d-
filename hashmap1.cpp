
#include <iostream>
#include <list>

class MyHashMap {
private:
    // Create a structure to hold key-value pairs
    struct KeyValuePair {
        int key;
        int value;
    };

    // Array of linked lists to handle collisions using separate chaining
    std::list<KeyValuePair>* hashMap;
    int capacity;

public:
    MyHashMap() {
        // Initialize the hashmap with an empty map
        capacity = 10000;
        hashMap = new std::list<KeyValuePair>[capacity];
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    void put(int key, int value) {
        int index = hashFunc(key);

        // Check if key already exists, if yes, update the value
        for (auto& kv : hashMap[index]) {
            if (kv.key == key) {
                kv.value = value;
                return;
            }
        }

        // Key doesn't exist, add a new key-value pair
        hashMap[index].push_back({ key, value });
    }

    int get(int key) {
        int index = hashFunc(key);

        // Search for the key in the linked list at the computed index
        for (auto& kv : hashMap[index]) {
            if (kv.key == key) {
                return kv.value;
            }
        }

        // Key not found
        return -1;
    }

    void remove(int key) {
        int index = hashFunc(key);

        // Find and remove the key-value pair if it exists
        for (auto it = hashMap[index].begin(); it != hashMap[index].end(); ++it) {
            if (it->key == key) {
                hashMap[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    MyHashMap hashmap;

    hashmap.put(1, 10);
    hashmap.put(2, 20);
    hashmap.put(3, 30);

    std::cout << "Value for key 1: " << hashmap.get(1) << std::endl; // Output: 10
    std::cout << "Value for key 2: " << hashmap.get(2) << std::endl; // Output: 20

    hashmap.remove(1);

    std::cout << "Value for key 1 after removal: " << hashmap.get(1) << std::endl; // Output: -1

    return 0;
}


