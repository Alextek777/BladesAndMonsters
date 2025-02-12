
#include "cAssets.h"
#include "cMaps/maps/cMapVillage.h"
#include <boost/filesystem.hpp>
#include <iostream>

Assets::Assets()
{
}


Assets::~Assets()
{
}

void Assets::LoadAnimations() {
	// Characters
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::EAST, "animations/creatures/witty/walking/east.png", 8, 20);
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::WEST, "animations/creatures/witty/walking/west.png", 8, 20);
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::NORTH, "animations/creatures/witty/walking/north.png", 4, 20);
	m_animationHandler.load("witty", e_GraphicsState::WALKING, e_FactionDirection::SOUTH, "animations/creatures/witty/walking/south.png", 4, 20);

	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::EAST, "animations/creatures/witty/standing/east.png", 6, 20);
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::WEST, "animations/creatures/witty/standing/west.png", 6, 20);
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::NORTH, "animations/creatures/witty/standing/east.png", 6, 20);
	m_animationHandler.load("witty", e_GraphicsState::STANDING, e_FactionDirection::SOUTH, "animations/creatures/witty/standing/west.png", 6, 20);

	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::EAST, "animations/creatures/witty/attacking/east.png", 6, 30, 28);
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::WEST, "animations/creatures/witty/attacking/west.png", 6, 30, 28);
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::NORTH, "animations/creatures/witty/attacking/east.png", 6, 30, 28);
	m_animationHandler.load("witty", e_GraphicsState::ATTACKING, e_FactionDirection::SOUTH, "animations/creatures/witty/attacking/west.png", 6, 30, 28);


	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::EAST, "animations/creatures/orc/walking/east.png", 8, 100);
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::WEST, "animations/creatures/orc/walking/west.png", 8, 100);
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::NORTH, "animations/creatures/orc/walking/east.png", 8, 100);
	m_animationHandler.load("orc", e_GraphicsState::WALKING, e_FactionDirection::SOUTH, "animations/creatures/orc/walking/west.png", 8, 100);

	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::EAST, "animations/creatures/orc/standing/east.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::WEST, "animations/creatures/orc/standing/west.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::NORTH, "animations/creatures/orc/standing/east.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::STANDING, e_FactionDirection::SOUTH, "animations/creatures/orc/standing/west.png", 6, 100);

	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::EAST, "animations/creatures/orc/attacking/east.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::WEST, "animations/creatures/orc/attacking/west.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::NORTH, "animations/creatures/orc/attacking/east.png", 6, 100);
	m_animationHandler.load("orc", e_GraphicsState::ATTACKING, e_FactionDirection::SOUTH, "animations/creatures/orc/attacking/west.png", 6, 100);


	// Trees
	m_animationHandler.load("TreeAutumn", e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, "animations/trees/autumn/default.png", 16, 64);

	// Clouds
	// m_animationHandler.load("cloud", e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, "animations/clouds/default.png", 4, 40);
	m_animationHandler.load("cloud", e_GraphicsState::DEFAULT_GS, e_FactionDirection::DEFAULT_FD, "animations/clouds/SunnyDayCloud/default.png", 8, 40, 120);
}

void Assets::LoadSprites()
{
	string spriteDirPath = "sprites";
    boost::filesystem::path dirPath(spriteDirPath);

    if (!boost::filesystem::exists(dirPath) || !boost::filesystem::is_directory(dirPath)) {
        std::cerr << "Directory does not exist or is not a directory!\n";
        return;
    }

    for (const auto& entry : boost::filesystem::directory_iterator(dirPath)) {

		if (!boost::filesystem::is_regular_file(entry.path())) continue;

		string spriteIndex = entry.path().stem().string();
		int idx;
		try {
			size_t pos;
			idx = std::stoi(spriteIndex, &pos);
			if (spriteIndex.size() != pos) {
				std::cerr << "sprite name is not an index: " << spriteIndex << "\n";
				continue;
			}

			if (m_mapDecal.find(idx) != m_mapDecal.end()) {
				std::cerr << "Sprite with index [" << idx << "] already loaded\n";
				continue;
			}

			olc::Sprite *s = new olc::Sprite(spriteDirPath + "/" + entry.path().filename().string());
			m_mapSprite[idx] = s;
			m_mapDecal[idx] = new olc::Decal(s);	
		} catch(...) {
			std::cerr << "sprite name is not an index: " << spriteIndex << "\n";
			continue;
		}
    }
}

void Assets::LoadMaps(olc::PixelGameEngine* gfx)
{
    auto load = [&](cMap* m)
	{
		m_mapMaps[m->sName] = m;
	};

	load(new cMap_Village(gfx));
}
