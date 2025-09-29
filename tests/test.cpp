#include "PhysicsEngine.h"



static void test_engine(){



    Physics* instance = Physics::getInstance(1000);

    Circle c1({100.f, 100.f}, 10, 100, 0.5);
    c1.setVelocity({10,10});
    c1.activateGravity(true);
    c1.activateCollision(true);

    Circle c2({100.f, 200.f}, 20, 200, 0.8);
    c2.activateGravity(true);
    c2.activateCollision(true);


    instance->addCircle(c1);
    instance->addCircle(c2);

    instance->boundaryCollisionTurn(true);

    instance->run();


}

