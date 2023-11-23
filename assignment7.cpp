#include <iostream>
#include <thread>

using namespace std;

mutex coutMutex;

// function to be executed in thread 2
void countdown(int arg) {

    unique_lock <mutex> lock(coutMutex);
    cout << "Counting down" << endl;
    lock.unlock();

    for (int i = 20; i >= 0 ; --i)
    {
        unique_lock <mutex> lock(coutMutex);
        cout << "Thread " << arg << " is running, iteration " << i << endl;
        lock.unlock();
    }
}

// Function to be executed in the thread 1
void countup(int arg) {

    unique_lock <mutex> lock(coutMutex);
    cout << "Counting up" << endl;
    lock.unlock();

    for (int i = 0; i <= 20; ++i) {
        unique_lock <mutex> lock(coutMutex);
        cout << "Thread " << arg << " is running, iteration " << i << endl;
        lock.unlock();
    }

    cout << endl;
}

int main() {
    // Creating threads
    thread thread1 (countup,1);  // Thread with argument
    thread thread2 (countdown,2);

    // Wait for threads to finish
    thread1.join();
    thread2.join();

    cout << "Main function is done." << endl;

    return 0;
}