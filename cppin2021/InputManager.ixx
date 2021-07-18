export module InputManager;

import <string>;
import <unordered_map>;
import <vector>;
import <functional>;

export class InputManager {
public:
    enum class EventType {
        MOUSE,
        KEYBOARD,
        GAMEPAD
    };

    using EventCallback = std::function<bool(std::string)>;

    void RegisterCallback(EventType type, EventCallback cb);
    void Dispatch(EventType type, std::string msg);

private:
    std::unordered_map<EventType, std::vector<EventCallback>> _callbacks{};
};