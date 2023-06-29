#include <iostream>

template<typename Item_Type>
class Single_Linked_List {
private:
    //struct that holds data and next Node
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };


    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    //Adds item to the front of the linked list
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item);
        new_node->next = head;
        head = new_node;

        if (tail == nullptr) {
            tail = head;
        }

        num_items++;
    }

    //Adds item to the back of the linked list
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);

        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        num_items++;
    }

    //Removes element from the front of the linked list
    void pop_front() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr) {
                tail = nullptr;
            }

            num_items--;
        }
    }

    //Removes element from the back of the linked list
    void pop_back() {
        if (tail != nullptr) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }

            num_items--;
        }
    }

    //Returns the front element of the array
    Item_Type front() const {
        if (head != nullptr) {
            return head->data;
        }
        throw std::out_of_range("List is empty");
    }

    //Returns the back element of the array
    Item_Type back() const {
        if (tail != nullptr) {
            return tail->data;
        }
        throw std::out_of_range("List is empty");
    }

    //Checks to see if the linked list is empty
    bool empty() const {
        return num_items == 0;
    }

    //Inserts an element into the linked list at a certain index
    void insert(size_t index, const Item_Type& item) {
        if (index >= num_items) {
            push_back(item);
        } else if (index == 0) {
            push_front(item);
        } else {
            Node* new_node = new Node(item);
            Node* current = head;
            size_t current_index = 0;

            while (current_index < index - 1) {
                current = current->next;
                current_index++;
            }

            new_node->next = current->next;
            current->next = new_node;

            num_items++;
        }
    }

    //Removes an element given an index
    bool remove(size_t index) {
        if (index >= num_items) {
            return false;
        }

        if (index == 0) {
            pop_front();
        } else {
            Node* current = head;
            size_t current_index = 0;

            while (current_index < index - 1) {
                current = current->next;
                current_index++;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;

            if (current->next == nullptr) {
                tail = current;
            }

            num_items--;
        }

        return true;
    }

    //Returns an index given an item to find it in the linked list
    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;

        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }

            current = current->next;
            index++;
        }

        return num_items;  // Item not found, return size of the list
    }

    //Size of linked list
    size_t size() const {
        return num_items;
    }

    //Returns data given an index
    Item_Type at(size_t index) const {
        if (index >= num_items) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }
};

int main() {
    Single_Linked_List<int> list;

    // Push elements to the front
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    

    // Push elements to the back
    list.push_back(4);
    list.push_back(5);

    // Print the elements
    std::cout << "List elements: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Front: " << list.front() << std::endl << "Back: " << list.back() << std::endl;
    // Remove an element at index 2
    list.remove(2);

    // Insert an element at index 1
    list.insert(1, 6);

    // Print the updated list
    std::cout << "Updated list elements: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;

    // Find the position of element 5
    size_t index = list.find(5);
    if (index < list.size()) {
        std::cout << "Element 5 found at position " << index << std::endl;
    } else {
        std::cout << "Element 5 not found in the list" << std::endl;
    }

    std::string empty = (list.empty() == 0) ? "false" : "true";
    std::cout << "Is Empty: " << empty << std::endl;
    

    return 0;
}

