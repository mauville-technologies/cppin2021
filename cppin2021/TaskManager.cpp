module;
#define EXIT_THREAD -1
#define PRINT_BANANAS 1
#define PRINT_ABUNCHOFNUMBERS 2

module TaskManager;

import <format>;
import <iostream>;

TaskManager::~TaskManager() {
    shutdown();
}

void TaskManager::Start() {
    std::cout << "Task Manager starting!\n";

    if (_commandThread.joinable()) {
        std::cout << "Task Manager already running!\n";
        return;
    }

    _commandQueue.clear();
    _commandThread = std::thread(&TaskManager::run, this);
}

void TaskManager::QueueCommand(Command command) {
    if (!_running) {
        std::cout << "TaskManager is shut down! Please call Start() again to begin queueing!\n";
        return;
    }
    std::cout << std::format("Queuing command {}!\n", command);
    _commandQueue.push_back(command);
}

void TaskManager::run() {
    std::cout << "Thread starting!\n";

    _running = true;
    while (_running) {
        if (_commandQueue.size() == 0) continue;

        executeCommand(_commandQueue.front());
        _commandQueue.pop_front();
    }

    std::cout << "Thread shutting down!\n";
}

void TaskManager::executeCommand(Command command) {
    switch (command) {
    case EXIT_THREAD:
        shutdown();
        break;
    case PRINT_BANANAS:
        std::cout << "BANANAS\n";
        break;
    case PRINT_ABUNCHOFNUMBERS:
        for (int i = 0; i < 10000; i++) {
            std::cout << i << std::endl;
        }
    }
}

void TaskManager::shutdown() {
    if (_commandThread.joinable()) {
        _running = false;
        _commandThread.detach();
    }
}