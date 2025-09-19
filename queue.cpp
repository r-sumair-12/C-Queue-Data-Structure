#include <iostream>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
        Node <T>* next;

    public:
        Node <T> (){
            next = nullptr;
        }

        Node <T>(T data){
            this->data = data;
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
};


template <typename T>
class Queue{
    private:
        Node <T>* front;
        Node <T>* rear;
        int length;

    public:
        Queue <T> (){
            rear = front = nullptr;
            length = 0;
        }

        bool empty(){
            return rear == nullptr;
        }

        void enqueue(T data){
            Node <T>* node = new Node <T>(data);

            if (rear == nullptr){
                rear = front = node;
            }
            else {
                rear->set_next(node);
                rear = node;
            }
            length++;
        }

        void dequeue(){
            if (empty()){
                cout<<"NULL"<<endl;
                return;
            }

            Node <T>* temp = front;
            front = front->get_next();

            if (front == nullptr){
                rear = nullptr;
            }

            delete temp;
            length--;
        }

        T peek(){
            if (empty()){
                throw out_of_range("Queue is empty");
            }

            return front->get_data();
        }

        int size(){
            return length;
        }

        void traverse(){
            if (empty()){
                cout<<"NULL"<<endl;
                return;
            }

            Node <T>* temp = front;

            while (temp != nullptr){
                cout<<temp->get_data()<<" ";
                temp = temp->get_next();
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    Queue <int> numbers;

    for (int i=0; i<20; i++){
        numbers.enqueue(i+1);
    }

    cout<<"Size of Queue : "<<numbers.size()<<endl;
    cout<<"Processing Dequeue : \n";
    for (int i=0; i<20; i++){
        cout<<numbers.peek()<<"\n";
        numbers.dequeue();
    }

    cout<<"Dequeue Completed!\n";
    cout<<"Size of Queue is : "<<numbers.size()<<endl;
}