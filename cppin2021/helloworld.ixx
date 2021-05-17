export module helloworld;

// imports 
import <iostream>;

/***
        INTERFACE
*/

// public
export void HelloWorld();

export struct HelloWorldStruct {
    int worldNum;
};

export class HelloWorldClass {
public:
    int worldNum;
};

namespace HelloWorldNS {
    export void Init() {
        std::cout << "Init" << std::endl;
    }

    void update() {
        std::cout << "Update" << std::endl;
    }

    export void Shutdown() {
        std::cout << "Shutdown" << std::endl;
    }
}

//private
void helloWorldImpl();


/***
        IMPLEMENTATION
*/

// public
void HelloWorld() {
    helloWorldImpl();
}

// private
void helloWorldImpl() {
    std::cout << "Hello, World!" << std::endl;
    HelloWorldNS::update();
}