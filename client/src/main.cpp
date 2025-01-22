#define OLC_PGE_APPLICATION
#include <engine/engine.h>

int main()
{
    AnimatedGame game;
    if (game.Construct(256, 240, 4, 4))
        game.Start();
    return 0;
}
