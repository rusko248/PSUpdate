//
//  pointEmitter.cpp
//  assignment2
//
//  Created by Aaron Damashek on 5/21/13.
//
//

#include "pointEmitter.h"

pointEmitter::pointEmitter(particle *pool, int emitter_id, vector3 pos, vector3 dir, vector3 dirVar, float speed, float speedVar, int totalParticles, int emitsPerFrame, int emitVar, int life, int lifeVar, GLfloat startColor[4], GLfloat startColorVar[4],GLfloat endColor[4], GLfloat endColorVar[4], vector3 force) : Emitter(pool, emitter_id, pos, dir, dirVar, speed, speedVar, totalParticles, emitsPerFrame, emitVar, life, lifeVar, startColor,  startColorVar, endColor, endColorVar, force){

}

void pointEmitter::display(){
    std::cout << "Adding " << e->particleCount << std::endl;
    for(int newP = 0; newP < (e->emitsPerFrame + e->emitVar*randDist()); newP++){
        addParticle();
    }
    glPointSize(2);
    glBegin(GL_POINTS);
    particle *curr = e->particleList;
    while(curr){
        glColor4fv(curr->color);
        glVertex3f(curr->pos.x, curr->pos.y, curr->pos.z);
        curr = curr->next;
    }
    glEnd();
}

bool pointEmitter::addParticle(){
    particle *newParticle;
    GLfloat start[4];
    GLfloat end[4];
    float speed;
    //Particle pool exists and max num particles not exceeded
    if(e != NULL && managerParticleList != NULL && e->particleCount < e->totalParticles){
        newParticle = managerParticleList;
        managerParticleList = managerParticleList->next;
        if(e->particleList != NULL){
            e->particleList->prev = newParticle;
        }
        newParticle->next = e->particleList;
        newParticle->prev = NULL;
        e->particleList = newParticle;
        
        newParticle->pos.x = e->pos.x;
        newParticle->pos.y = e->pos.y;
        newParticle->pos.z = e->pos.z;
        
        newParticle->prevPos.x = 0;
        newParticle->prevPos.y = 0;
        newParticle->prevPos.z = 0;
        
        //Calculate direction vector
        //yaw = e->yaw + (e->yawVar*randDist());
        //pitch = e->pitch + (e->pitchVar*randDist());
        //rotationToDirection(pitch, yaw, &newParticle->dir);
        newParticle->dir = e->dir + (e->dirVar*randDist());
        
        speed = e->speed + (e->speed * randDist());
        newParticle->dir.x *= speed;
        newParticle->dir.y *= speed;
        newParticle->dir.z *= speed;
        
        start[0] = e->startColor[0] + (e->startColorVar[0] * randDist());
        start[1] = e->startColor[1] + (e->startColorVar[1] * randDist());
        start[2] = e->startColor[2] + (e->startColorVar[2] * randDist());
        end[0] = e->endColor[0] + (e->endColorVar[0] * randDist());
        end[1] = e->endColor[1] + (e->endColorVar[1] * randDist());
        end[2] = e->endColor[2] + (e->endColorVar[2] * randDist());
        
        newParticle->color[0] = start[0];
        newParticle->color[1] = start[1];
        newParticle->color[2] = start[2];
        
        newParticle->life = e->life + (int)((float)e->lifeVar * randDist());
        
        newParticle->deltaColor[0] = (end[0] - start[0]) / newParticle->life;
        newParticle->deltaColor[1] = (end[1] - start[1]) / newParticle->life;
        newParticle->deltaColor[2] = (end[2] - start[2]) / newParticle->life;
        
        e->particleCount++;
        return true;
    }
    return false;
}