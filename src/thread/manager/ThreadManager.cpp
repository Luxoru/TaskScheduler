
#include "thread/manager/ThreadManager.h"

#include <cmath>
#include <iostream>
#include <algorithm>

static int currentThreadID = 0;

ThreadManager::ThreadManager(const int maxThreadPoolSize) : maxThreadPoolSize(maxThreadPoolSize) {

}

ThreadManager::~ThreadManager() {

    while (std::ranges::any_of(threadPool, []( auto& thread) {
        return thread->getNumberOfTasksToComplete() > 0;
    })){}

    for (const auto& thread : threadPool) {
        thread->stop();
    }

    while (std::ranges::any_of(threadPool, []( auto& thread) {
        return !thread->isStopped();
    }));
}

bool ThreadManager::createThread() {

    if (threadPool.size() >= maxThreadPoolSize) return false;

    try {
        threadPool.emplace_back(std::make_unique<TaskThread>(currentThreadID));
        currentThreadID++;
    }catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return true;
}


bool ThreadManager::pushTask(Task&& task) const {

    const size_t randomIndex = rand() % threadPool.size();

    const auto& thread = threadPool[randomIndex];

    thread->pushTask(std::move(task));

    return true;
}


const std::vector<std::unique_ptr<TaskThread>>& ThreadManager::getThreads() const {
    return threadPool;
}





