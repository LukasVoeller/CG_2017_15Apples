//
//  Character
//  CGXcode
//
//  Created by Philipp Lensing on 16.11.16.
//  Copyright © 2016 Philipp Lensing. All rights reserved.
//

#ifndef Tank_hpp
#define Tank_hpp

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include "Constants.h"
#include "Model.h"
#include "MovingItem.h"
#include "PhongShader.h"
#include "ConstantShader.h"

class Character : public BaseModel
{
public:
    Character();
    virtual ~Character();
    bool loadModel(const char* file, float scaling = 1.0f);
    void update(float dtime);
    virtual void draw(const BaseCamera& Cam);
	
	/** Steuerung **/
	void steer3d(float forwardBackward, float leftRight, float jump);
	
	/** Setter **/
	void setHovering(bool hover);
	void setForwardBackward(float fb);
	void setLeftRight(float lr);
	void setJump(float jmp);
	void setPosZ (float z);
	void setIsInAir(bool newIsInAir);
	void setPallet(MovingItem* p) { pallet = p;};
	void setUnderground(SceneNode* p) { standOn = p;};
	
	/** Getter ***/
	Vector getLatestPosition();
    bool getIsInAir();
    float getJumpPower();
	const AABB& getBoundingBox() const { return BoundingBox; };
	float getForwardBackward() const { return forwardBackward; };
	float getLeftRight() const { return leftRight; };
	bool getHovering() const;
	MovingItem* getPallet() const { return pallet; };
	SceneNode* getUnderground() const { return standOn; };
	AABB getScaledBoundingBox() const {return this->scaledBoundingBox; }; //this->character->getScaledBoundingBox(); };
	
	/** Debug **/
	void printLatestPosition();
protected:
	void calcBoundingBox(AABB& box);
private:
    Model* character;
	
    float leftRight = 0;
    float forwardBackward = 0;
    float jump = 0;
    float time = 0;
	float jumpPower = JUMPPOWER;
    bool isInAir = false;
    Vector position;
	
	AABB BoundingBox;
	AABB scaledBoundingBox;
	AABB movedBoundingBox;
	
	//für update und so..
	float posZ = 0;
	
	//für Hovering
	bool isHovering = false; 	// Für Palette
	
	MovingItem* pallet;
	SceneNode* standOn = NULL;
};

#endif /* Tank_hpp */
