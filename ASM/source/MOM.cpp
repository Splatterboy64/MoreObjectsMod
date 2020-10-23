#include "DeleteFile.h"
#include "SM64DS_2.h"
#include "GalaxyShrinkingPlatform.h"
#include "SilverCoin.h"
#include "InvisibleWall.h"
#include "Berry.h"
#include "YoshiRide.h"
#include "ObjectLightingModifier.h"
#include "BlankObject.h"
#include "GoombaColored.h"

namespace {

	//Object IDs.
	constexpr short int BASE_OBJECT_ID = 								0x0200;
	constexpr short int GALAXY_SHRINKING_PLATFORM_ID = 					BASE_OBJECT_ID;
	constexpr short int SILVER_COIN_ID = 								BASE_OBJECT_ID + 1;
	constexpr short int INVISIBLE_WALL_ID = 							BASE_OBJECT_ID + 2;
	constexpr short int BERRY_ID = 										BASE_OBJECT_ID + 3;
	constexpr short int YOSHI_RIDE_ID = 								BASE_OBJECT_ID + 4;
	constexpr short int OBJECT_LIGHTING_MODIFIER_ID = 					BASE_OBJECT_ID + 5;
	constexpr short int TWO_DEE_LEVEL_ID = 								BASE_OBJECT_ID + 6;
	constexpr short int TWO_DEE_CAMERA_LIMITER = 						BASE_OBJECT_ID + 7;
	constexpr short int COLORED_GOOMBA_SMALL = 							BASE_OBJECT_ID + 8;
	constexpr short int COLORED_GOOMBA =	 							BASE_OBJECT_ID + 9;
	constexpr short int COLORED_GOOMBA_LARGE = 							BASE_OBJECT_ID + 10;
	//constexpr short int CONDITIONAL_CUTSCENE_LOADER_ID = 0x0165;

	//Assets.
	constexpr short int GALAXY_SHRINKING_PLATFORM_FRAME_MODEL_ID = 		0x0000;
	constexpr short int GALAXY_SHRINKING_PLATFORM_MODEL_ID = 			0x0001;
	constexpr short int GALAXY_SHRINKING_PLATFORM_COLLISION_ID = 		0x0002;

	constexpr short int SILVER_COIN_MODEL_ID = 							0x0003;

	constexpr short int INVISIBLE_WALL_COLLISION_ID = 					0x0005;

	constexpr short int BERRY_MODEL_ID = 								0x0006;
	constexpr short int BERRY_STEM_MODEL_ID = 							0x0007;

	constexpr short int YOSHI_RIDE_ANIM_ID =							0x0008;

	constexpr short int COLORED_GOOMBA_MODEL_ID = 						0x0009;
	constexpr short int COLORED_GOOMBA_ANIM_ID = 						0x000A;

	//Modify the object and actor tables.
	void modTable(short int val, unsigned newFunc)
	{
		OBJ_TO_ACTOR_ID_TABLE[val] = val;
		ACTOR_SPAWN_TABLE[val] = newFunc;
	}

}

//Initialize the objects.
void init()
{

	//Shrinking platforms.
	modTable(GALAXY_SHRINKING_PLATFORM_ID, (unsigned)&GalaxyShrinkingPlatform::spawnData);
	GalaxyShrinkingPlatform::modelFile.Construct(GALAXY_SHRINKING_PLATFORM_MODEL_ID);
    GalaxyShrinkingPlatform::clsnFile .Construct(GALAXY_SHRINKING_PLATFORM_COLLISION_ID);
    GalaxyShrinkingPlatform::frameModelFile.Construct(GALAXY_SHRINKING_PLATFORM_FRAME_MODEL_ID);

    //Silver coins.
	modTable(SILVER_COIN_ID, (unsigned)&SilverCoin::spawnData);
	SilverCoin::modelFile.Construct(SILVER_COIN_MODEL_ID);

	//Invisible walls.
	modTable(INVISIBLE_WALL_ID, (unsigned)&InvisibleWall::spawnData);
	InvisibleWall::clsnFile.Construct(INVISIBLE_WALL_COLLISION_ID);

	//Berries.
	modTable(BERRY_ID, (unsigned)&Berry::spawnData);
	Berry::modelFile.Construct(BERRY_MODEL_ID);
	Berry::stemFile.Construct(BERRY_STEM_MODEL_ID);

	//Rideable yoshis.
	modTable(YOSHI_RIDE_ID, (unsigned)&YoshiRide::spawnData);
	YoshiRide::ridingAnim.Construct(YOSHI_RIDE_ANIM_ID);

	//Object lighting modifier.
	modTable(OBJECT_LIGHTING_MODIFIER_ID, (unsigned)&ObjectLightingModifier::spawnData);

	//2D level.
	modTable(TWO_DEE_LEVEL_ID, (unsigned)&BlankObject::spawnData);
	modTable(TWO_DEE_CAMERA_LIMITER, (unsigned)&BlankObject::spawnData);

	//Colored goombas.
	modTable(COLORED_GOOMBA_SMALL, (unsigned)&Goomba::spawnDataSmall);
	modTable(COLORED_GOOMBA, (unsigned)&Goomba::spawnDataNormal);
	modTable(COLORED_GOOMBA_LARGE, (unsigned)&Goomba::spawnDataBig);
	Goomba::modelFile.Construct(COLORED_GOOMBA_MODEL_ID);
	Goomba::texSeqFile.Construct(COLORED_GOOMBA_ANIM_ID);
	Goomba::animFiles[0].Construct(0x0388);
	Goomba::animFiles[1].Construct(0x0389);
	Goomba::animFiles[2].Construct(0x038a);
	Goomba::animFiles[3].Construct(0x038b);
	Goomba::animFiles[4].Construct(0x038c);
	Goomba::animFiles[5].Construct(0x038d);

}