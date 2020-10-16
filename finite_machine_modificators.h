//=====Author: The Arrayser=====//
//This is just a demonstration of the finite machine!
//Use this file (finite_machine_modificators.h) to describe the machine!
//
//Demonstration of: p.41/2a) - doubble b at the end!
//
//There should be no need to change anything from the other files!
//
//I CANNOT GIVE WARRANTY, THAT THIS ALWAYS WORKS!

#ifndef FINITE_MACHINE
#include "E:\sdl engine test\finite_machine.h"
#endif


char alphabet[] = {"ab"};

Node Z1;
Node Z2;
Node Z3;

Lang pos1 = {'a', NULL};
Lang pos2 = {'b', NULL};

Edge Z1b = {&Z2,NULL, &pos2, true};
Edge Z1a = {&Z1,&Z1b ,&pos1, false};

Edge Z2b ={&Z3,NULL, &pos2, true};
Edge Z2a ={&Z1,&Z2b, &pos1, false};

Edge Z3b ={&Z3,NULL, &pos2, true};
Edge Z3a ={&Z1,&Z3b, &pos1, false};


void Initialization(){
    Start.following = &Z1;

    Z3 = (Node){"Z3",&Z3a ,true};
    Z2= (Node) {"Z2", &Z2a, false};
    Z1 = (Node){"Z1", &Z1a, false};

    
}