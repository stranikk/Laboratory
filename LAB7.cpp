#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace this_thread;
condition_variable w;
mutex f;
void f1(){
    int n=0;
    while(n<=10){
        f.lock();
        for (int i=0; i<4; i++){
        cout << "aaaaa";
        sleep_for(chrono::milliseconds(10));
        }
        f.unlock();
        n++;
    }

}
void f2(){
    int n=0;
    while(n<=100){
        f.lock();
        for (int i=0;i<4;i++){
        cout << "bbbbb";
        sleep_for(chrono::milliseconds(10));
        }
        f.unlock();
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
