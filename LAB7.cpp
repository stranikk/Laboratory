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
mutex fi1;
mutex fi2;
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
    fi2.lock();
    int n=0;
    unique_lock<mutex> locker(f);
    
    w.wait(locker,[]{return ready;});
    while(n<=100){
        cout << "bbbbb" << endl;
        sleep_for(chrono::milliseconds(10));
        n++;
    }
    
    
}
void f3(){
    fi1.lock();
    fi2.lock();
    cout << "not run"<< endl;
}
void f4(){
    fi1.lock();
    fi2.lock();
    cout << "not run"<< endl;
    
}
void alarm1(){
    
    int t;
    cout << ">" ;
    cin >> t;
    sleep_for(chrono::seconds(t));
    cout << "ALARM!!! seconds:" << t << endl;
}
int main() {
    thread al(alarm1);
    al.join();
    thread b1(f2);
    thread a1(f1);
    thread a4(f3);
    thread a5(f3);
    a1.join();
    b1.join();
    a4.join();
    a5.join();
    
    return 0;
}
