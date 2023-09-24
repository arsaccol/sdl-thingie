#include <cstdio>
#include "./App.h"


int main(int argc, char** argv) {

    printf("C++ 久しぶり\n");

    App app = App{};

    app.init();
    app.loop();
    app.close();


    return 0;
}

