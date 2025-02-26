#pragma once
#include "task/Task.h"
#include "thread/manager/ThreadManager.h"

/**
 * @class TaskManager TaskManager.h
 * @brief Interface for dealing with tasks
 */
class TaskManager {

  std::unique_ptr<ThreadManager> threadManager;

public:

  TaskManager();

  /**
   * Adds task ready to be executed by the threadManager
   * @param task callback function passed in as parameter, to be called when task is ran
   * @see ThreadManager
   */
  void addTask(const std::function<void()>& task) const;

  /**
   * Used to fetch pointer of the threadmanager
   * @return pointer to the thread manager
   * @see ThreadManager
   */
  [[nodiscard]] ThreadManager* getThreadManager() const;

};

