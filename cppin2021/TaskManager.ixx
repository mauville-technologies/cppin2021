export module TaskManager;

import <thread>;
import <deque>;

export using Command = int;

export struct TaskManager {
public:
    TaskManager() = default;
    ~TaskManager();

    void Start();
    void QueueCommand(Command);
private:
    void run();
    void executeCommand(Command);
    void shutdown();
private:
    std::thread _commandThread;
    std::deque<Command> _commandQueue{};
    bool _running{ false };
};

