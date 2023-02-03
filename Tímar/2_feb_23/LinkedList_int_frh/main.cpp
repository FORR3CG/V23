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

        void setjaRadad(int data) {
            Node* ny_gogn = new Node(data);
            if(!this->head) {
                this->head = ny_gogn;
            } else {
                if(this->head->data > data) {
                    ny_gogn->next = this->head;
                    this->head = ny_gogn;
                } else {
                    Node* current = this->head;
                    Node* prev = this->head;
                    while(current && current->data <= data) {
                        prev = current;
                        current = current->next;
                    }
                    if(current) {
                        ny_gogn->next = current;
                        prev->next = ny_gogn;
                    } else {
                        prev->next = ny_gogn;
                    }
                }
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

        // eyða síðastu nóðunni og skila gögnunum úr henni
        int saekjaAftast() {
            if(!this->head) {
                return -1;
            }
            if(this->head->next == nullptr) { // if(!this->head->next)
                // return this->saekjaFremsta();
                int skilagildi = this->head->data;
                delete this->head;
                this->head = nullptr;
                return skilagildi;
            } else {
                Node* current = this->head;
                Node* prev = this->head;
                while(current->next) { //while(current->next != nullptr)
                    prev = current;
                    current = current->next;
                }
                int skilagildi = current->data;
                delete current;
                prev->next = nullptr;
                return skilagildi;
            }

        }

        int saekjaNoduMedGognumNr(int id) {
            if(!this->head) {
                return -1;
            }
            if(this->head->data == id) {
                return this->saekjaFremsta();
            } else {
                Node* current = this->head;
                Node* prev = this->head;
                while(current && current->data != id) {
              //while(current != nullptr && current->data != id)          
                    prev = current;
                    current = current->next;
                }
                if(current) { // if(current != nullptr)
                    int skilagildi = current->data;
                    prev->next = current->next;
                    delete current;
                    return skilagildi;
                }
                return -1;
            }
        }

        void prentaEinn(int id) {
            Node* current = this->head;
            while(current) {
                if(current->data == id) {
                    cout << current->data << endl;
                    return;
                }
                current = current ->next;
            }
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
    listi.setjaRadad(50);
    listi.setjaRadad(30);
    listi.setjaRadad(10);
    listi.setjaRadad(40);
    listi.setjaRadad(20);
    
    listi.prenta();

    return 0;
}