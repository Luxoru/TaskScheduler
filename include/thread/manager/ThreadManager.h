#pragma once
#include <vector>
#include "thread/TaskThread.h"

/**
 * @class ThreadManager ThreadManager.h
 * @brief Used to manage threads and push tasks to threads
 * @author Luxoru
 */
class ThreadManager {

    const int maxThreadPoolSize;
    std::vector<std::unique_ptr<TaskThread>> threadPool;

public:
    /**
     * Constructor for @ref ThreadManager
     * @param maxThreadPoolSize max amount of threads that can be created
     */
    explicit ThreadManager(int maxThreadPoolSize);

    ~ThreadManager();

    /**
     * Creates a thread if @ref threadPool size is lower than @ref maxThreadPoolSize
     * @return has thread been created
     */
    bool createThread();

    /**
     * Pushes a task to a random thread for the thread to execute
     * @param task Task to push to a thread
     * @return has task been pushed
     */
    bool pushTask(Task&& task) const;

    /**
     * Returns all threads in a pointer
     * @return pointer to all threads
     */
    [[nodiscard]] const std::vector<std::unique_ptr<TaskThread>>& getThreads() const;


};

