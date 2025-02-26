#pragma once
#include <vector>
#include "thread/TaskThread.h"

class ThreadManager {

    const int maxThreadPoolSize;
    std::vector<std::unique_ptr<TaskThread>> threadPool;

public:

    explicit ThreadManager(int maxThreadPoolSize);

    ~ThreadManager();

    bool createThread();

    bool pushTask(Task&& task) const;

    [[nodiscard]] const std::vector<std::unique_ptr<TaskThread>>& getThreads() const;


};

