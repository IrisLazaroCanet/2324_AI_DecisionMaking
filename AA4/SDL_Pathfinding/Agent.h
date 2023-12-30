#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Path.h"
#include "Vector2D.h"
#include "utils.h"
#include <array>

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

	/////////////ADDED
	float _velocityTransitionTimer;
	float _velocityTransitionDuration;
	float _startVelocity;
	float _startForce;

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
	



	////////////////////////////////////////////////////////ADDED

	void toggleHasGun() { setHasGun(!_hasGun); }
	bool hasGun() { return _hasGun; }
	void setHasGun(const bool& hasGun) {
		_hasGun = hasGun;
		_hasGun ? SetRedForward() : SetGreenForward();
	}

	void SetRedForward() { _forwardColor = &_redColor; }
	void SetYellowForward() { _forwardColor = &_yellowColor; }
	void SetGreenForward() { _forwardColor = &_greenColor; }

	bool _hasGun;
	float default_max_velocity;
	float default_max_force;

	float flee_max_velocity = 210.0f;
	float flee_max_force = 170.0f;

	float chase_max_velocity = 180.0f;
	float chase_max_force = 150.0f;

	float wander_max_velocity = 90.0f;
	float wander_max_force = 150.0f;

	float wanderAngle = 0.0f;
	float wanderOffset = 200.0f;
	float wanderRadius = 20.0f;
	float wanderMaxChange = 0.9f;

	bool _drawForward = false;
	std::array<const int, 3>* _forwardColor;
	std::array<const int, 3> _redColor;
	std::array<const int, 3> _greenColor;
	std::array<const int, 3> _yellowColor;



	//DMA
	float _velocityTransitionTimer;
	float _velocityTransitionDuration;

	float _startVelocity;
	float _startForce;


	void setDMA(DecisionMakingAlgorithm* decisionMakingAlgorithm)
	{

	}

	virtual Agent* getEnemy() const { return nullptr; }
	virtual float getSightDistance() const { return 0.0f; }
	virtual bool isEnemyInSight() { return false; }

	float getLoseDistance() const { return getSightDistance() + 50.0f; }
	virtual bool hasLostEnemySight() { return false; }

	float GetVelocityTransitionDuration() const
	{
		return _velocityTransitionDuration;
	}

	float GetVelocityTransitionTimer() const
	{
		return _velocityTransitionTimer;
	}
	void AddVelocityTransitionTimer(const float& amount)
	{
		_velocityTransitionTimer += amount;

		if (_velocityTransitionTimer > _velocityTransitionDuration)
			_velocityTransitionTimer = _velocityTransitionDuration;
	}
	void ResetVelocityTransitionTimer()
	{
		_velocityTransitionTimer = 0.0f;
	}

	void SetStartVelocityAndForce(const float& startVelocity, const float& startForce)
	{
		_startVelocity = startVelocity;
		_startForce = startForce;
	}
	void UpdateVelocityAndForce(const float& timeAmount, const float& endVelocity, const float& endForce) 
	{
		AddVelocityTransitionTimer(timeAmount);

		float t = GetVelocityTransitionTimer() / GetVelocityTransitionDuration();
		float velocity = ((1.0f - t) * _startVelocity) + (t * endVelocity);
		float force = ((1.0f - t) * _startForce) + (t * endForce);

		setMaxVelocityAndForce(velocity, force);
	}

	void setMaxVelocityAndForce(const float& maxVelocity, const float& maxForce)
	{
		max_velocity = maxVelocity;
		max_force = maxForce;
	}
};
