#pragma once
#include <vector>
#include "../Task/Task.h"
#include "../thread/manager/ThreadManager.h"

class TaskManager {

  std::unique_ptr<ThreadManager> threadManager;



public:


  TaskManager();



  void addTask(const std::function<void()>& task) const;

  [[nodiscard]] ThreadManager* getThreadManager() const;

};

