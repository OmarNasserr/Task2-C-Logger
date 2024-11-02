using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>
#include <chrono>


class Logger {
public:
    // constructor takes file path and init the file
    Logger(const string& filePath) : filePath(filePath) {
        logFile.open(filePath, ios::app);
        if (!logFile.is_open()) {
            cerr << "Failed to open log file: " << filePath << endl;
        }
    }

    // destructor to make sure file is to be closed
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // locks the mutex to ensure thread-safe access to the file.
    // lock_guard automatically unlocks the mutex when it goes out of scope, preventing potential deadlocks.
    void log(const string& message) {
        lock_guard<std::mutex> lock(mutex);
        if (logFile.is_open()) {
            logFile << message << endl;
        } else {
            cerr << "Log file is not open. Message: " << message << endl;
        }
    }

private:
    string filePath;
    ofstream logFile;
    std::mutex mutex;
};

void logMessages(Logger& logger, const string& message, int count) {
    for (int i = 1; i < count+1; ++i) {
        logger.log(message + " -> " + to_string(i));
        // delay is introduced to avoid running the function in a tight loop,
        // logging messages as fast as the system allows leading to increased CPU usage.
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main() {
    Logger logger("log.txt");

    thread t1(logMessages, ref(logger), "Thread 1", 5);
    thread t2(logMessages, ref(logger), "Thread 2", 5);
    thread t3(logMessages, ref(logger), "Thread 3", 5);

    t1.join();
    t2.join();
    t3.join();

    cout << "Logging completed. Check log.txt for the logs." << endl;
    return 0;
}
