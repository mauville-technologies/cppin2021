module InputManager;

import <iostream>;

void InputManager::RegisterCallback(EventType type, EventCallback cb) {
    _callbacks[type].push_back(cb);
}


void InputManager::Dispatch(EventType type, std::string msg) {
    for (auto cb : _callbacks[type]) {
        // if cb returns true, the message has been handled and should not propagate further
        if (cb(msg)) return;
    }
}
