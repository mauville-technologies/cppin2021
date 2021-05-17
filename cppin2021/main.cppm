import helloworld;

int main() {

    HelloWorld();
    
    HelloWorldStruct my_struct{ 1 };
    HelloWorldClass my_class{ 2 };

    HelloWorldNS::Init();
    HelloWorldNS::Shutdown();
    return 0;
}