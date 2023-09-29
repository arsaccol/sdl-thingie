#include <SDL2/SDL.h>

#include "./math/Vector2.h"

class FrameBuffer {

public:
    static inline math::Vector2 NDCtoScreenSpace(double x, double y) {


    }
    
private:
    int width;
    int height;

    Uint32* pixels;

}
