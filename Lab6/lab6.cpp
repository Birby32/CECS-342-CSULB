#include <string>
#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

// The function we want to execute on the new thread.
void lookup1(int value){
    for(int i = 0; i < 250 ;i++){
        if(i == value)
            cout <<"Found in thread 1: "<<i<<endl;
    }
    // cout << "Finsihed Thread 1 \n";
}

void lookup2(int value){
    for(int i = 250; i < 500 ;i++){
        if(i == value)
            cout <<"Found in thread 2: "<< i<<endl;
    }
    // cout << "Finsihed Thread 2 \n";
}

void lookup3(int value){
    for(int i = 500; i < 750 ;i++){
        if(i == value)
            cout <<"Found in thread 3: "<< i<<endl;
    }
    // cout << "Finsihed Thread 3 \n";
}

void lookup4(int value){
    for(int i = 750; i < 1000 ;i++){
        if(i == value)
            cout <<"Found in thread 4: "<< i<<endl;
    }
    // cout << "Finsihed Thread 4 \n";
}
int main()
{
    srand(time(NULL));
    int number = rand() % 1000;
    cout << "RANDOM_NUMBER ="<<number<<endl; 

    thread t1(lookup1,number);
    thread t2(lookup2, number);
    thread t3(lookup3, number);
    thread t4(lookup4, number);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}