#include "manager/TaskManager.h"



static int currentTaskID = 0;




TaskManager::TaskManager() {
    threadManager = std::make_unique<ThreadManager>(2);
}



void TaskManager::addTask(const std::function<void()>& taskToRun) const {

    Task task(currentTaskID, taskToRun);


    currentTaskID++;

    threadManager->pushTask(std::move(task));



}


ThreadManager* TaskManager::getThreadManager() const{
    return threadManager.get();
}


