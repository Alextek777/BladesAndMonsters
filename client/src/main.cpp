#define OLC_PGE_APPLICATION
#include "engine/engine.h"

e_GameMode GAMEMODE = RELEASE;

int main()
{
    Engine game;
    if (game.Construct(680, 382, 4, 4, false))
        game.Start();
    return 0;
}