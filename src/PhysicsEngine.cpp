#include "../headers/PhysicsEngine.h"



Physics* Physics::instance_engine = nullptr;


Physics* Physics::getInstance(float gravity) {
	
	if (instance_engine == nullptr) {
		instance_engine = new Physics;
		instance_engine->m_gravity = gravity;
		instance_engine->m_window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Simulation");
	}

	return instance_engine;

}


void Physics::run() {


	sf::Clock clock;


	while (m_window.isOpen()) {

		sf::Time time = clock.restart();
		float dt = time.asSeconds();


		sf::Event event;
		while (m_window.pollEvent(event)) { //main cycle

			if (event.type == sf::Event::Closed) {
				m_window.close();
				}
			}
			//phsycis

			collision();
			
			gravityUpdate(dt);

			for (size_t i = 0; i < circles.size(); i++) {
				circles[i]->update(dt);
			}

			//draw

			m_window.clear();

			render();

			m_window.display();
		

	}

}

void crashBalls(Circle& circle1, Circle& circle2) {
	vec2 x1 = circle1.getPosition();
	vec2 x2 = circle2.getPosition();

	vec2 v1 = circle1.getVelocity();
	vec2 v2 = circle2.getVelocity();

	float m1 = circle1.getMass();
	float m2 = circle2.getMass();

	vec2 v1_new = v1 - (x1 - x2) * (2 * m2 / (m1 + m2) * dotProd(v1 - v2, x1 - x2) / (length(x1 - x2) * length(x1 - x2)));
	vec2 v2_new = v2 - (x2 - x1) * (2 * m1 / (m1 + m2) * dotProd(v2 - v1, x2 - x1) / (length(x2 - x1) * length(x2 - x1)));

	circle1.setVelocity(v1_new.get());
	circle2.setVelocity(v2_new.get());
}

bool checkBallsCollision(const Circle& c1,const Circle& c2)
{
	float r1 = c1.getRadius();
	float r2 = c2.getRadius();
	

	if (length(c1.getPosition() - c2.getPosition()) < r1 + r2) {
		return true;
	}

	return false;
}


void separateBalls(Circle& c1, Circle& c2);
void separateWalls(Circle& c1, vec2 normal, float diff);

//check all collisions
void Physics::collision()
{
	//collisions with each other
	for (size_t i = 0; i < circles.size(); i++) {

		for (size_t j = i+1; j < circles.size(); j++) {

			if (circles[i]->getCollisionIndicate() && circles[j]->getCollisionIndicate() && 
				checkBallsCollision(*circles[i], *circles[j]))
			{
				crashBalls(*circles[i], *circles[j]);
				separateBalls(*circles[i], *circles[j]);
			}

		}

	}
	//boundary collisions

	if (boundaryCollisionHandle) {

		for (auto& c : circles) {
			boundaryCollision(*c);
			
		}


	}

}



void Physics::render() {

	for (size_t i = 0; i < circles.size(); i++)
	{
		circles[i]->draw(m_window);
	}


}


void Physics::addCircle(Circle& c) {
	circles.push_back(std::make_unique<Circle>(c));
}


void Physics::gravityUpdate(float dt)
{
	for (size_t i = 0; i < circles.size(); i++) {
		if(circles[i]->getGravityIndicate())
			gravity(*circles[i], dt);
	}
}


void Physics::gravity(Circle &c, float dt)
{
	float vx = c.getVelocity().get().x;
	float vy = c.getVelocity().get().y;

	vy += m_gravity * dt;

	c.setVelocity({ vx, vy });
}


float Physics::getGravity() {
	return m_gravity;
}

void Physics::setGravity(float g) {
	m_gravity = g;
}



void Physics::boundaryCollision(Circle& c) {

	float r = c.getRadius();

	if (c.getPosition().get().x + r > ScreenWidth ) {
		float diff = c.getPosition().get().x + r - ScreenWidth;

		separateWalls(c, {-1, 0}, diff);
		c.setVelocity({ -c.getVelocity().get().x, c.getVelocity().get().y });
	}

	if (c.getPosition().get().x - r < 0) {
		float diff = -(c.getPosition().get().x - r);

		separateWalls(c, {1, 0}, diff);
		c.setVelocity({ -c.getVelocity().get().x, c.getVelocity().get().y });
	}

	if (c.getPosition().get().y + r > ScreenHeight) {
		float diff = c.getPosition().get().y + r - ScreenHeight;

		separateWalls(c, {0, -1}, diff);
		c.setVelocity({ c.getVelocity().get().x, -c.getVelocity().get().y });

	}
	if (c.getPosition().get().y - r < 0) {
		float diff = -(c.getPosition().get().y - r);

		separateWalls(c, { 0, 1 }, diff);
		c.setVelocity({ c.getVelocity().get().x, -c.getVelocity().get().y });

	}


}


void Physics::boundaryCollisionOn(bool handle) {
	boundaryCollisionHandle = handle;
}



void separateBalls(Circle& c1, Circle& c2) {

	float angle = atan2f(c1.getPosition().get().y - c2.getPosition().get().y, 
						 c1.getPosition().get().x - c2.getPosition().get().x);


	float diffDist = c1.getRadius() + c2.getRadius() - length(c1.getPosition() - c2.getPosition());

	diffDist *= 0.5;

	vec2 dir = { cos(angle), sin(angle) };
	vec2 delta1 = c1.getPosition() + dir *diffDist;
	vec2 delta2 = c2.getPosition() + dir * diffDist;

	c1.setPosition(delta1);
	c2.setPosition(delta2);
	

}


void separateWalls(Circle& c1, vec2 normal, float diff) {

	diff *= 0.5;

	vec2 delta = c1.getPosition() + normal * diff;

	c1.setPosition(delta);

}

