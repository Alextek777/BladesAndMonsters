#include "cMapVillage.h"
#include "cDynamics/creatures/orc.h"

cMap_Village::cMap_Village(olc::PixelGameEngine* gfx) : cMap(gfx)
{
	Create("maps/village.lvl", Assets::get().GetSprite("village"), "village");
}


bool cMap_Village::PopulateDynamics(vector<cDynamic*> &vecDyns) {
	// Add Teleporters
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 200, 200));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 240, 200));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 200, 240));
	vecDyns.push_back(new cDynamic_Object("TreeAutumn", 280, 240));
    vecDyns.push_back(new cDynamic_Object("TreeAutumn", 100, 100));


    vecDyns.push_back(new cDynamic_Creature_Orc("orc", 300, 300));


	// // Add Items
	// vecDyns.push_back(new cDynamic_Item(10, 10, RPG_Assets::get().GetItem("Small Health")));
	// vecDyns.push_back(new cDynamic_Item(12, 10, RPG_Assets::get().GetItem("Health Boost")));

	// for (int i = 0; i < 3; i++)
	// {
	// 	cDynamic* g1 = new cDynamic_Creature_Skelly();
	// 	vecDyns.push_back(g1);
	// 	g1->px = rand() % 10 + 5.0f;
	// 	g1->py = rand() % 10 + 5.0f;
	// }

	return true;
}

bool cMap_Village::DrawStaticMap(float ox, float oy) {
	gfx->SetDrawTarget(backgroundLayer);

    // TODO: move this func to utils
    auto ToScreen = [&](int x, int y)
    {			
        return olc::vi2d
        {
            (vOrigin.x * vTileSize.x) + (x - y) * (vTileSize.x / 2),
            (vOrigin.y * vTileSize.y) + (x + y) * (vTileSize.y / 2)
        };
    };

	gfx->Clear(olc::WHITE);
	gfx->SetPixelMode(olc::Pixel::MASK);

    // TODO: refactor this crap, move drawing in parent class and change type switching on load Assets::GetSprite() function 
    // (0,0) is at top, defined by vOrigin, so draw from top to bottom
    // to ensure tiles closest to camera are drawn last
    for (int y = 0; y < nHeight; y++)
    {
        for (int x = 0; x < nWidth; x++)
        {
            // Convert cell coordinate to world space
            olc::vi2d vWorld = ToScreen(x, y);
            olc::vi2d source_pos;
            olc::vi2d source_size;
            
            switch(GetIndex(x, y))
            {
            case 0:
                // Invisble Tile
                source_pos.x = 1 * vTileSize.x;
                source_pos.y = 0;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y;
                break;
            case 1:
                // Visible Tile
                source_pos.x = 2 * vTileSize.x;
                source_pos.y = 0;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y;
                break;
            case 2:
                // Tree
                vWorld.y = vWorld.y - vTileSize.y;
                source_pos.x = 0 * vTileSize.x;
                source_pos.y = 1 * vTileSize.y;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y * 2;
                break;
            case 3:
                // Spooky Tree
                vWorld.y = vWorld.y - vTileSize.y;
                source_pos.x = 1 * vTileSize.x;
                source_pos.y = 1 * vTileSize.y;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y * 2;
                break;
            case 4:
                // Beach
                vWorld.y = vWorld.y - vTileSize.y;
                source_pos.x = 2 * vTileSize.x;
                source_pos.y = 1 * vTileSize.y;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y * 2;
                break;
            case 5:
                // Water
                vWorld.y = vWorld.y - vTileSize.y;
                source_pos.x = 3 * vTileSize.x;
                source_pos.y = 1 * vTileSize.y;
                source_size.x = vTileSize.x;
                source_size.y = vTileSize.y * 2;
                break;
            }


            vWorld.x -= ox;
            vWorld.y -= oy;

            // TODO: refactor -> draw only visible tiles
            if (vWorld.y > gfx->ScreenHeight() || vWorld.x > gfx->ScreenWidth()) {
                break;
            }

            gfx->DrawPartialSprite(vWorld, Assets::get().GetSprite(sName), source_pos, source_size);
        }
    }

	gfx->SetPixelMode(olc::Pixel::NORMAL);
	gfx->EnableLayer(backgroundLayer, true);
	gfx->SetDrawTarget(nullptr);

	return true;
}