#define OLC_PGE_APPLICATION
#include "engine/engine.h"

int main()
{
    Engine game;
    if (game.Construct(680, 420, 4, 4, true))
        game.Start();
    return 0;
}