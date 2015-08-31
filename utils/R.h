#pragma once
#include <SimpleAudioEngine.h>
#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
USING_NS_CC;
namespace R{

	class Utils{

	public :
		static void checkNetwork(const std::function<void(bool hasNetwork)> &callback);
		static void loadGameVariable();
		static void resetGameVariable();
		static void updateGameVariable();
	};

	class Constants{
	public :
		static float musicVolumn;
		static float soundVolumn;
		static bool musicEnable;
		static bool soundEnable;
	};
	enum class GameState{
		NONE
	};
	enum class Direction{
		AUTO, LEFT, RIGHT, TOP, BOTTOM, CENTER, TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT
	};
	enum class CharacterType{
		MONKEY, NONAME
	};
};


