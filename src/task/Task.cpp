#include "task/Task.h"




int Task::getTaskID() const{
  return taskID;

}

bool Task::isRunning() const{
  return running;
}

bool Task::isCancelled() const{
  return cancelled;
}


void Task::run() const{
  callback();
}

