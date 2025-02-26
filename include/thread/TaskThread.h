#pragma once
#include <memory>
#include <stack>
#include <thread>

#include "../Task/Task.h"

class TaskThread {

    const int threadID;
    bool running = false;
    bool stopped = false;
    std::thread thread;

    std::deque<Task> tasksToComplete;

public:

    explicit TaskThread(int threadID);
    TaskThread(TaskThread&& other) = delete; ;
    TaskThread& operator=(TaskThread&&) = delete;
    ~TaskThread();

    bool pushTask(Task&& task);

    void start();

    void stop();

    int getNumberOfTasksToComplete() const;

    [[nodiscard]] bool isRunning() const;

    [[nodiscard]] bool isStopped() const;

    [[nodiscard]] int getThreadID() const;

    std::thread& getThread();

private:

    void run();


};
