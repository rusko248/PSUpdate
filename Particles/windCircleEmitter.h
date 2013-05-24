//
//  windCircleEmitter.h
//  Particles
//
//  Created by Aaron Damashek on 5/23/13.
//
//

#ifndef __Particles__windCircleEmitter__
#define __Particles__windCircleEmitter__

#include <iostream>
#include "circleEmitter.h"
#include "math.h"

class windCircleEmitter : public circleEmitter
{
public:
    windCircleEmitter(float r, particle *pool, int emitter_id, vector3 pos, vector3 dir, vector3 dirVar, float speed, float speedVar, int totalParticles, int emitsPerFrame, int emitVar, int life, int lifeVar, GLfloat startColor[4], GLfloat startColorVar[4],GLfloat endColor[4], GLfloat endColorVar[4], vector3 force);
    void display();
    
private:
    
};
#endif /* defined(__Particles__windCircleEmitter__) */
