#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <typename T>
class Node{
    private:
        T data;
        int priority;
        Node <T>* next;

    public:
        Node <T> (){
            next = nullptr;
        }

        Node <T>(T data, int priority){
            this->data = data;
            this->priority = priority;
            next = nullptr;
        }

        T& get_data(){
            return data;
        }

        const T& get_data() const{
            return data;
        }

        void set_data(T data){
            this->data = data;
        }

        Node <T>* get_next(){
            return next;
        }

        void set_next(Node <T>* next){
            this->next = next;
        }

        int get_priority(){
            return priority;
        }

        void set_priority(int priority){
            this->priority = priority;
        }
};

template <typename T>
class PriorityQueue{
    private:
        Node <T>* head;
        int length;

    public:
        PriorityQueue <T>(){
            head = nullptr;
            length = 0;
        }

        bool empty(){
            return head == nullptr;
        }

        void enqueue(T data, int priority){
            Node <T>* node = new Node <T> (data,priority);

            if (head == nullptr){
                head = node;
            }
            else if (head->get_priority() < priority){
                node->set_next(head);
                head = node;
            }
            else {
                Node <T>* temp = head;

                while (temp->get_next() != nullptr && temp->get_next()->get_priority() >= priority){
                    temp = temp->get_next();
                }

                node->set_next(temp->get_next());
                temp->set_next(node);
            }
            length++;
        }

        T peek(){
            if (empty()){
                throw out_of_range("Queue is Empty");
            }

            return head->get_data();
        }

        int size(){
            return length;
        }

        void dequeue(){
            if (head == nullptr){
                cout<<"NULL\n";
                return;
            }

            Node <T>* temp = head;

            head = head->get_next();
            delete temp;
            length--;
        }

        void traverse(){
            if (head == nullptr){
                cout<<"NULL\n";
                return;
            }

            Node <T>* temp = head;

            cout<<"Patient Queue\n\n";

            while (temp != nullptr){
                cout<<temp->get_data()<<endl;
                temp = temp->get_next();
            }
        }
};


int main(){
    PriorityQueue <string> patient;

    patient.enqueue("Headache",1);
    patient.enqueue("cough",1);
    patient.enqueue("drama",0);
    patient.enqueue("heart attack",10);

    patient.traverse();

    cout<<"Dequeue : "<<patient.peek();
    patient.dequeue();

}