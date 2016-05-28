#include <iostream>
#include <chrono>
#include <condition_variable>
#include <thread>
#include <mutex>

using namespace std;
using namespace this_thread;
bool ready = false;
condition_variable w;
mutex f;
void f1(){
    int n=0;
    unique_lock<mutex> locker(f);
        for (int i=0; i<10; i++){
            cout << "aaaaa" << endl;
        sleep_for(chrono::milliseconds(10));
        }
    ready = true;
    locker.unlock();
    w.notify_one();
    
    while(n<=10){
        cout << "aaaaa" << endl;
        sleep_for(chrono::milliseconds(10));
        n++;
    }
}

void f2(){
    int n=0;
    unique_lock<mutex> locker(f);
    
    w.wait(locker,[]{return ready;});
    while(n<=100){
        cout << "bbbbb" << endl;
        sleep_for(chrono::milliseconds(10));
        n++;
    }
    
    
}

int main() {
    
    thread b1(f2);
    thread a1(f1);
    
    a1.join();
    b1.join();
    
    return 0;
}
