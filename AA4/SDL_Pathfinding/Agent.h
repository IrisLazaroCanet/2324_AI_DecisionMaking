#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Path.h"
#include "Vector2D.h"
#include "utils.h"

class Agent
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {};
	};

	class DecisionMakingAlgorithm
	{
	public:
		DecisionMakingAlgorithm() {};
		~DecisionMakingAlgorithm() {};
		virtual void Update(Agent* agent, float dtime) {};

	};

private:
	// Steering behaviors
	SteeringBehavior *steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;
	std::vector<Agent*> neighbors;
	float cohesionRadius;
	float separationRadius;
	float alignmentRadius;

	// Pathfinding
	Path path;
	int currentTargetIndex;

	// Decision making
	DecisionMakingAlgorithm* brain;
	
	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();

	void addNeighbor(Agent* neighbor) { neighbors.push_back(neighbor); }
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	SteeringBehavior* getBehavior() const { return steering_behaviour; }
	const std::vector<Agent*>& getNeighbors() const { return neighbors; }
	float getSeparationRadius() const { return separationRadius; }
	float getAlignmentRadius() const { return alignmentRadius; }
	float getOrientation() const { return (float)(atan2(velocity.y, velocity.x) * RAD2DEG); }
	float getCohesionRadius() const { return cohesionRadius; }
	
	void addPathPoint(Vector2D point);
	void setCurrentTargetIndex(int idx);
	int getCurrentTargetIndex();
	int getPathSize();
	Vector2D getPathPoint(int idx);
	void clearPath();

	void setBrain(DecisionMakingAlgorithm* brain);
	DecisionMakingAlgorithm* getBrain() { return brain; }
	
	virtual void update(float dtime, SDL_Event *event);
	void draw();
	
	bool loadSpriteTexture(char* filename, int num_frames=1);
	
	//Agent Decision Making
	//Agent has a Gun Equipped logic
	bool agentHasGunEquipped;
	bool getGun()
	{
		return agentHasGunEquipped; 
	}
	void setGun(const bool& gunIsEquipped) 
	{
		agentHasGunEquipped = gunIsEquipped;
	}
};
