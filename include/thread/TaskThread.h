#pragma once
#include <memory>
#include <stack>
#include <thread>

#include "task/Task.h"

/**
 * @class TaskThread TaskThread.h
 * @brief Represents a thread which can run tasks
 * @author Luxoru
 */
class TaskThread {

    const int threadID;
    bool running = false;
    bool stopped = false;
    std::thread thread;

    std::deque<Task> tasksToComplete;

public:
    /**
     * Constructor of TaskThread
     * @param threadID ID of thread
     */
    explicit TaskThread(int threadID);

    TaskThread(TaskThread&& other) = delete;

    TaskThread& operator=(TaskThread&&) = delete;

    ~TaskThread();

    /**
     * Pushes task to thread queue ready to be executed
     * @param task Task to be pushed
     * @return has task been pushed
     */
    bool pushTask(Task&& task);

    /**
     * Starts thread
     */
    void start();

    /**
     * Stops thread
     */
    void stop();

    /**
     * Gets size of @ref tasksToComplete
     * @return number of tasks waiting to be completed
     */
    [[nodiscard]] int getNumberOfTasksToComplete() const;

    /**
     * Returns whether the thread is still running
     * @return isRunning
     */
    [[nodiscard]] bool isRunning() const;

    /**
     * Returns whether the thread has stopped
     * @return isStopped
     */
    [[nodiscard]] bool isStopped() const;

    /**
     * Returns the threadID
     * @return threadID
     */
    [[nodiscard]] int getThreadID() const;

    /**
     * Returns the thread
     * @return thread
     */
    std::thread& getThread();

private:
    /**
     * Run method for thread
     */
    void run();

};
