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
#include "finite_machine.h"
#endif


char alphabet[] = {"ab"};

Node Z1;
Node Z2;
Node Z3;
Node Z4;
Node Z5;
Node Z6;
Node Z7;
Node Z8;
Node Z9;
Node Z10;

Lang at = {'@', NULL};
Lang point = {'.', NULL};
Lang minus = {'-', NULL};

Lang alp26 = {'z', NULL};
Lang alp25 = {'y', &alp26};
Lang alp24 = {'x', &alp25};
Lang alp23 = {'w', &alp24};
Lang alp22 = {'v', &alp23};
Lang alp21 = {'u', &alp22};
Lang alp20 = {'t', &alp21};
Lang alp19 = {'s', &alp20};
Lang alp18 = {'r', &alp19};
Lang alp17 = {'q', &alp18};
Lang alp16 = {'p', &alp17};
Lang alp15 = {'o', &alp16};
Lang alp14 = {'n', &alp15};
Lang alp13 = {'m', &alp14};
Lang alp12 = {'l', &alp13};
Lang alp11 = {'k', &alp12};
Lang alp10 = {'j', &alp11};
Lang alp9 = {'i', &alp10};
Lang alp8 = {'h', &alp9};
Lang alp7 = {'g', &alp8};
Lang alp6 = {'f', &alp7};
Lang alp5 = {'e', &alp6};
Lang alp4 = {'d', &alp5};
Lang alp3 = {'c', &alp4};
Lang alp2 = {'b', &alp3};
Lang alp1 = {'a', &alp2};

Lang let9 = {'9', &alp1};
Lang let8 = {'8', &let9};
Lang let7 = {'7', &let8};
Lang let6 = {'6', &let7};
Lang let5 = {'5', &let6};
Lang let4 = {'4', &let5};
Lang let3 = {'3', &let4};
Lang let2 = {'2', &let3};
Lang let1 = {'1', &let2};
Lang let0 = {'0', &let1};

Lang signs4 = {'_', &let0};
Lang signs3 = {'.', &signs4};
Lang signs2 = {'-', &signs3};
Lang signs1 = {'!', &signs2};


Edge Z1a = {&Z2, NULL, &signs1, true};

Edge Z2b = {&Z3, NULL, &at, true};
Edge Z2a = {&Z2, &Z2b, &signs1, false};

Edge Z3a = {&Z4, NULL, &let0, false};

Edge Z4b = {&Z5, NULL, &let0, false};
Edge Z4a = {&Z4, &Z4b, &minus, false};

Edge Z5c = {&Z4, NULL, &minus, false};
Edge Z5b = {&Z6, &Z5c, &point, false};
Edge Z5a = {&Z5, &Z5b, &let0, false};

Edge Z6a = {&Z7, NULL, &alp1, false};

Edge Z7a = {&Z8, NULL, &alp1, false};

Edge Z8a = {&Z9, NULL, &alp1, false};

Edge Z9a = {&Z10, NULL,&alp1, false};

//Edge Z10a ={&Z1, NULL, &alp1, false};

void Initialization(){
    Start.following = &Z1;

    Z10 = (Node){"Za", NULL, true};
    Z9 = (Node){"Z9", &Z9a, true};
    Z8 = (Node){"Z8", &Z8a, true};
    Z7 = (Node){"Z7", &Z7a, false};
    Z6 = (Node){"Z6", &Z6a, false};
    Z5 = (Node){"Z5", &Z5a, false};
    Z4 = (Node){"Z4", &Z4a, false};
    Z3 = (Node){"Z3", &Z3a, false};
    Z2 = (Node){"Z2", &Z2a, false};
    Z1 = (Node){"Z1", &Z1a, false};

    
}