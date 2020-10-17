//=====Author: The Arrayser=====//
//This is just a demonstration of the finite machine!
//Basic Header file: finite_machine.h
//There should be no need to change anything from the this file!
//
//I CANNOT GIVE WARRANTY, THAT THIS ALWAYS WORKS!


#define FINITE_MACHINE

#define ts terminationsymbol
#define boolean char
#define true 1
#define false 0
#define NULL ((void *)0)

char terminationsymbol = '\0';

typedef struct _Node Node;
typedef struct _Edge Edge;
typedef struct _Lang Lang;

struct _Node{
    char name[3];
    Edge *edges;
    boolean isPossibleEnd;
};
struct _Edge{
    Node *following;
    Edge *next;
    Lang *partial_alphabet;
    boolean isLast;
};
struct _Lang{
    char symbol;
    Lang *next;
};

Edge Start = {NULL, NULL, NULL, 0};

