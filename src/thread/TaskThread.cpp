#include "thread/TaskThread.h"

#include <iostream>
#include <thread>

TaskThread::TaskThread(const int threadID) :
    threadID(threadID) {
    start();
}

TaskThread::~TaskThread() {
    if (thread.joinable()) {
        thread.join();
    }
}

bool TaskThread::pushTask(Task&& task){
    tasksToComplete.emplace_back(std::move(task));
    return true;
}

void TaskThread::start() {
    running = true;
    thread = std::thread(&TaskThread::run, this);
}

int TaskThread::getNumberOfTasksToComplete() const {
    return tasksToComplete.size();
}

void TaskThread::run() {
    while (running) {

        if (tasksToComplete.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            continue;
        }

        const auto task = tasksToComplete.front();

        tasksToComplete.pop_front();

        try {
            task.run();

        }catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    stopped = true;
}

void TaskThread::stop() {
    running = false;
}

bool TaskThread::isRunning() const {
    return running;
}

bool TaskThread::isStopped() const {
    return stopped;
}

int TaskThread::getThreadID() const {
    return threadID;
}

std::thread& TaskThread::getThread() {
    return thread;
}


