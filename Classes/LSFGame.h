#ifndef __LSFGame_SCENE_H__
#define __LSFGame_SCENE_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"
#include <GLES-Render.h>
#include "vrope-x\vrope.h"
#include "ContactListener.h"
#include "AnimateCreate.h"
#include "WaterNode.h"
using namespace cocos2d;

class LSFGame : public cocos2d::LayerColor , public AnimateCreate

{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(LSFGame);

	//Box2D----------------------------------------------------------------------------
	bool createBox2dWorld(bool debug);
	SpriteBatchNode* ropeSpriteSheet;
	~LSFGame();

	b2Body *groundBody;
	void tick(float dt);
	
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

	//낚시
	b2Body* addNewSpriteAt(Vec2 point);
	b2Body* addNewSpriteAtWater(Vec2 point);
	void createRope(b2Body* bodyA, b2Vec2 anchorA, b2Body* bodyB, b2Vec2 anchorB, float32 sag);
	std::vector<VRope*>* ropes;
	void ropeTick(float dt);
	void ropeTouch(float dt);
	Vec2 touchRope;

	//충돌처리
	bool checkLineIntersection(Vec2 v1, Vec2 v2, Vec2 v3, Vec2 v4);
	b2Body* createRopeTipBody();
	ContactListener* myContactListener;
	
	//날씨
	WaterNode* water;
	int weatherCount;
	



	


	Texture2D* texture;
	b2World* _world;
	GLESDebugDraw* m_debugDraw;

	//Box2D----------------------------------------------------------------------------

	//환경구성
	//Animation
	AnimateCreate* animCreate;

	//World
	Size winSize;
	Sprite* back;
	Sprite* ship;
	Sprite* fisherman;
	Sprite* inventory;
	Sprite* craftUsel;
	Sprite* craftSel;
	Sprite* craft;
	Sprite* rainDrop;
	Sprite* snowDrop;
	LayerColor* invenLayer;
	MenuItemImage* btn_inventory;
	Menu* inventoryMenu;
	b2Body* water1;
	b2Body* water2;
	b2Body* water3;
	//World - Flow
	b2Body* addNewSpriteFlow(Vec2 point, Size size, b2BodyType bodytype, const char* spriteName, int type);
	b2WheelJoint* m_spring1;
	b2WheelJoint* m_spring2;
	b2WheelJoint* m_spring3;
	b2WheelJoint* m_spring4;
	b2WheelJoint* m_spring5;
	b2WheelJoint* m_spring6;

	b2WheelJointDef flowJd1;
	b2WheelJointDef flowJd2;
	b2WheelJointDef flowJd3;
	b2WheelJointDef flowJd4;
	b2WheelJointDef flowJd5;
	b2WheelJointDef flowJd6;
	b2Body *flowBody0;
	b2Body *flowBody1;
	b2Body *flowBody2;
	b2Body *flowBody3;
	b2Body *flowBody4;
	b2Body *flowBody5;
	b2Body *flowBody6;
	b2Body *flowBody7;
	b2Body *flowBody8;

	b2Vec2 axis;

	//상태변화  WeatherStatus - Normal(1), Windy(2), Snowy(3), Rainny(4), ThunderStorm(5)
	int statusCheck(const std::string & kindof);
	int ShipStat;



	bool playerIsFlying = false;
	float playerVelocity = 0;
	RepeatForever* rainRep;
	//Ship
	SpriteFrameCache* ShipFrameCache;
	RepeatForever* shipRep;
	


	//카운트
	int btnCount;
	int cbtnCount;
	int waterCount;
	bool ropeTickCount;
	bool ropeTouchCount;
	
	bool craftSwitch;
	bool modeSwitch;
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);

	//Inventory Scene transition
	void doPushInventory(Ref * pSender);
	cocos2d::TransitionScene* createTransition(int nIndex, float t, cocos2d::Scene* s);

protected:
	void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCommand;
};

#endif // __LSFGame_SCENE_H__
