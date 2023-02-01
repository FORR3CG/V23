#include <iostream>

using namespace std;

struct Node {
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() {
            this->head = nullptr;
        }

        void setjaFremst(int data) {
            Node* ny_gogn = new Node(data);
            if(this->head == nullptr) { // listinn er tómur
                this->head = ny_gogn;
            } else { // listinn er ekki tómur
                ny_gogn->next = this->head;
                this->head = ny_gogn;
            }
        }

        void setjaAftast(int data) {
            Node* ny_gogn = new Node(data);
            if(!this->head) { // if(this->head == nullptr) {
                this->head = ny_gogn;
            } else {
                Node* current = this->head;
                while(current->next) { // while(current->next != nullptr)
                    current = current->next;
                }
                current->next = ny_gogn;
            }
        }

        int saekjaFremsta() {
            if(this->head == nullptr) {
                return -1;
            }
            Node* new_head = this->head->next;
            int skilagildi = this->head->data;
            delete this->head;
            this->head = new_head;
            return skilagildi;
        }

        void prenta() {
            Node* current = this->head;
            while(current != nullptr) {
                cout << current->data << " - ";
                current = current->next;
            }
            cout << endl;
        }

        ~LinkedList() {
            while(this->head != nullptr) { // while(this->head) {
                Node* new_head = this->head->next;
                delete this->head;
                this->head = new_head;
            }
        }
};

int main() {
    LinkedList listi;
    listi.setjaAftast(10);
    listi.setjaAftast(20);
    listi.setjaAftast(30);
    listi.setjaAftast(40);
    //listi.prenta();

    return 0;
}