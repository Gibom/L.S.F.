﻿#ifndef __LSFMain_SCENE_H__
#define __LSFMain_SCENE_H__

#include "cocos2d.h"
#include "AnimateCreate.h"
#include "..\cocos2d\external\json\rapidjson.h"
#include "..\cocos2d\external\json\document.h"
#include "..\cocos2d\external\json\stringbuffer.h"
#include "..\cocos2d\external\json\writer.h"

using namespace cocos2d;

class LSFMain : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(LSFMain);

	MenuItemImage* btn_Start;
	AnimateCreate* animCreate;
	void doPushSceneTran(Ref * pSender);
	cocos2d::TransitionScene* createTransition(int nIndex, float t, cocos2d::Scene* s);
};

#endif // __LSFMain_SCENE_H__

