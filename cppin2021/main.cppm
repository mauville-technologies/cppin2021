
import vector3;
import InputManager;
import TaskManager;

import <iostream>;
import <string>;
import <format>;

void vectorStuff() {
    Vector3 vec1{
        .x = 1,
        .y = 2,
        .z = 3
    };

    Vector3 vec2{
        .x = 3,
        .y = 2,
        .z = 1
    };

    // test output operator
    std::cout << vec1 << std::endl;

    // test addition / subtraction
    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;

    // test scalar multiplication and division
    std::cout << vec1 * 2 << std::endl;
    std::cout << vec1 / 2 << std::endl;
    std::cout << 3 * vec1 << std::endl;

    // test comparison operators
    std::cout << bool(vec1 == vec2) << std::endl;
    std::cout << bool(vec1 > vec2) << std::endl;
    std::cout << bool(vec1 <= vec2) << std::endl;
    std::cout << bool(vec1 != (2 * vec2)) << std::endl;
}


struct Game {
    void Init() {
        _inputManager.RegisterCallback(InputManager::EventType::MOUSE,
            [this](std::string message) -> bool {
            handleMouseEvent(message);
            return false;
        });

        // Registers handleMouseEvent with inputManager;
        _inputManager.RegisterCallback(InputManager::EventType::MOUSE,
            std::bind(&Game::handleMouseEvent, this, std::placeholders::_1));
    }

    void Run() {
        _inputManager.Dispatch(InputManager::EventType::MOUSE, "Bound message");

        _running = true;
        _taskManager.Start();

        while (_running) {
            Command command{ 0 };

            std::cout << "Give me a command! (must be an integer!)\n";
            std::cin >> command;

            switch (command) {
            case -98:
                // restart task manager
                _taskManager.Start();
                break;
            case -99:
                _running = false;
                break;
            default:
                _taskManager.QueueCommand(command);
            }
        }

        std::cout << "Game Loop Ended\n";
    }

    bool handleMouseEvent(std::string message) {
        std::cout << std::format("The message: {}\n", message);
        return true;
    }

private:
    InputManager _inputManager{};
    TaskManager _taskManager{};

    bool _running{ false };
};

void handleMouseEvent(std::string message) {
    std::cout << std::format("The message: {}\n", message);
}

template <typename T>
bool IsEqual(T num1, T num2, auto callback) {
    return callback(num1, num2);
}

int main() {
    Game g{};
    g.Init();
    g.Run();

    return 0;
}

#undef bool
