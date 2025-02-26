#pragma once

#include <functional>

/**
 * @class Task Task.h
 * @brief Stores a Task info ready to be executed by the @ref ThreadManager
 */
class Task {

  const int taskID;
  const std::function<void()> callback;
  bool running = false;
  bool cancelled = false;

public:
  /**
   * Constructor for task object
   * @param taskID taskID set for task
   * @param task task callback which will be executed
   */
  Task(const int taskID, const std::function<void()>& task) :
      taskID(taskID), callback(task) {};

  Task(const Task& other) :
      taskID(other.taskID), callback(other.callback) {}


  /**
   * Returns the Identifier for this task
   * @return task ID
   */
  [[nodiscard]] int getTaskID() const;

  /**
   * Returns whether the task is running
   * @return isRunning?
   */
  [[nodiscard]] bool isRunning() const;

  /**
   * Returns whether this task is cancelled?
   * @return isCancelled?
   */
  [[nodiscard]] bool isCancelled() const;

  /**
   * Runs the callback provided in @ref callback
   */
  void run() const;

};

