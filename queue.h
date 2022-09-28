#include <bits/stdc++.h>
using namespace std;

class Queue{
    int size = 0;
    int front = 0;
    int rear = -1;
    int* arr_queue = new int[size];

    bool empty(){
        return (rear == -1);
    }

    bool full(){
        return (rear == size-1);
    }

    bool found(int item){
        bool find_item = false;
        for (int i = front; i <= rear; ++i) {
            if (arr_queue[i] == item){
                find_item = true;
                break;
            }
        }
        return find_item;
    }

public:
    Queue(int n){
        size = n;
    }

    void enqueue(int item){
        if (!full()) {
            rear++;
            arr_queue[rear] = item;
        }else{
            cout << "Can't enqueue, Queue is full";
        }
    }

    void create(int num){
        if (num <= size){
            for (int i = 0; i < num; ++i) {
                int item;
                cout << "Enter item " << i+1 << " : ";
                cin >> item;
                enqueue(item);
            }
        }else{
            cout << "The numbers of items is more than size of Queue";
        }
    }

    void dequeue(){
        if(empty()){
            cout << "Can't dequeue, Queue is empty." << endl;
        }else{
            for (int i = 0; i < rear; ++i) {
                arr_queue[i] = arr_queue[i+1];
            }
            rear--;
        }
    }

    void get_size(){
            cout << "The size of queue is : " << size << endl;
    }

    void get_length(){
            cout << "The length of queue is : " << rear+1 << endl;
    }

    void get_front(){
        if(empty())
            cout << "No front, Queue is empty." << endl;
        else
            cout << "The front is ==> " << arr_queue[0] << endl;
    }

    void get_rear(){
        if(empty())
            cout << "No rear, Queue is empty." << endl;
        else
            cout << "The rear is ==> " << arr_queue[rear] << endl;
    }

    void search(int item) {
        if (empty()) {
            cout << "No " << item << " isn't found, " <<"Queue is empty" << endl;
        }else if(found(item)){
            cout << "Yes " << item << " is found" << endl;
        }else {
            cout << "No " << item << " isn't found, " <<"item don't in it" << endl;
        }
    }

    void is_empty(){
        string s = empty() ? "Queue is empty" : "Queue isn't empty";
        cout << s << endl;
    }

    void join(Queue q){
        int* old_arr = arr_queue;
        size += q.size;
        int* new_arr = new int[size];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = old_arr[i];
        }
        delete[] old_arr;
        arr_queue = new_arr;
        for (int i = 0; i <= q.rear; ++i) {
            enqueue(q.arr_queue[i]);
        }
    }

    void reverse(){
        int* old_arr = arr_queue;
        int* new_arr = new int[size];
        int n = rear;
        for (int i = 0; i <= rear; ++i) {
            new_arr[i] = old_arr[n];
            n--;
        }
        delete[] old_arr;
        arr_queue = new_arr;
    }

    void display(){
        if(!empty()){
            cout << "The Queue is ==> ";
            for (int i = 0; i < rear; ++i) {
                cout << arr_queue[i] << " ";
            }
            cout << arr_queue[rear];
            cout << endl;
        }else{
            cout << "Can't display, Queue is empty" << endl;
        }
    }

    void clear(){
        if (empty()){
            cout << "Can't clear, Queue is empty" << endl;
        }else{
            while (!empty()){
                dequeue();
            }
        }
    }
};
