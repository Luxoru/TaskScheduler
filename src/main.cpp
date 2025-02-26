#include <iostream>
#include "manager/TaskManager.h"
#include "util/Log.h"

int main() {

    const TaskManager taskManager;


    ThreadManager *thread_manager = taskManager.getThreadManager();

    bool created = true;
    int numCreated = 0;

    while (created) {
        created = thread_manager->createThread();
        numCreated++;
    }

    LOG("Created {} threads!", numCreated)

    taskManager.addTask([]() {
        LOG("WAITING 1 second");

        std::this_thread::sleep_for(std::chrono::seconds(1));

        LOG("SLEPT FOR 1 SECOND");
    });

    taskManager.addTask([]() {
            LOG("DORIME")
        });



    taskManager.addTask([]() {
        LOG("Hello, World!")
    });





    taskManager.addTask([]() {
        LOG("HIHI")
    });




    std::this_thread::sleep_for(std::chrono::milliseconds(1000));





    return 0;
}
