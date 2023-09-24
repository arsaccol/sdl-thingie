#pragma once

class IApplication {

public:
    virtual bool init() = 0;
    virtual void loop() = 0;

    void doQuit() {
        quit = true;
    }

    bool shouldQuit() {
        return quit;
    }

protected:
    bool quit{false};

};
