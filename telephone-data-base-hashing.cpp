/*
Consider telephone book database of N clients. Make use of a hash table implementation 
to quickly look up client‘s telephone number.  Make use of two collision handling 
techniques and compare them using number of comparisons required to find a set of 
telephone numbers 
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Client structure to hold name and telephone number
struct Client {
    string name;
    string phoneNumber;
};

// HashTable class
class HashTable {
private:
    static const int TABLE_SIZE = 100; // Size of hash table
    vector<list<Client>> table; // Hash table using vector of linked lists

    // Hash function to compute index
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Constructor
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // Insert client into hash table
    void insert(const string& name, const string& phoneNumber) {
        int index = hashFunction(name);
        table[index].push_back({name, phoneNumber});
    }

    // Search for client's telephone number
    string search(const string& name) {
        int index = hashFunction(name);
        for (const auto& client : table[index]) {
            if (client.name == name) {
                return client.phoneNumber;
            }
        }
        return "Not found";
    }
};

int main() {
    HashTable table;

    // Insert some clients
    table.insert("Alice", "1234567890");
    table.insert("Bob", "9876543210");
    table.insert("Charlie", "5551234567");

    // Search for telephone numbers
    cout << "Alice's phone number: " << table.search("Alice") << endl;
    cout << "Bob's phone number: " << table.search("Bob") << endl;
    cout << "Charlie's phone number: " << table.search("Charlie") << endl;
    cout << "Dave's phone number: " << table.search("Dave") << endl; // Not found

    return 0;
}


/*
explanation
This C++ code implements a simple hash table data structure to store and retrieve telephone numbers of clients using their names. Here's a breakdown of the code:

1. **Header Inclusions**:
    - The code includes necessary header files for input/output (`iostream`), vectors (`vector`), lists (`list`), and strings (`string`).

2. **Client Structure**:
    - The `Client` structure holds the name and telephone number of a client. This structure is used to store client information in the hash table.

3. **HashTable Class**:
    - The `HashTable` class implements the hash table data structure.
    - Private members:
        - `TABLE_SIZE`: A constant integer representing the size of the hash table.
        - `table`: A vector of lists (`vector<list<Client>>`) used as the hash table. Each element of the vector represents a bucket, and each bucket stores a linked list of `Client` objects.
        - `hashFunction()`: A private method that computes the hash value (index) for a given key (client name) using a simple hashing algorithm. It sums up the ASCII values of characters in the key and takes the modulus of the result with the table size to ensure it fits within the table bounds.
    - Public members:
        - `HashTable()`: Constructor initializes the hash table by resizing the vector to the specified table size.
        - `insert()`: Inserts a new client (name and phone number) into the hash table. It computes the hash value for the name and inserts the client into the corresponding bucket (linked list).
        - `search()`: Searches for the telephone number of a client by name. It computes the hash value for the name and traverses the linked list in the corresponding bucket to find the client. If found, it returns the telephone number; otherwise, it returns "Not found".

4. **Main Function**:
    - In the `main()` function:
        - An instance of the `HashTable` class named `table` is created.
        - Some sample clients with their names and telephone numbers are inserted into the hash table using the `insert()` method.
        - Telephone numbers are then retrieved for specific clients using the `search()` method and printed to the console.

Overall, this code demonstrates a basic implementation of a hash table for storing and retrieving telephone numbers using client names. It uses separate chaining collision resolution, where collisions are handled by chaining elements in linked lists at each bucket.
*/
