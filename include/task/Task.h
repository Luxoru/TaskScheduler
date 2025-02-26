#pragma once

#include <functional>


class Task {

  const int taskID;
  const std::function<void()> callback;
  bool running = false;
  bool cancelled = false;

public:

  Task(const int taskID, const std::function<void()>& task) :
      taskID(taskID), callback(task) {};

  Task(const Task& other) :
      taskID(other.taskID), callback(other.callback) {}

  int getTaskID() const;

  bool isRunning() const;

  bool isCancelled() const;

  void run() const;



};

