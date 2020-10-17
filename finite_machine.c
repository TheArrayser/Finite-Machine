//=====Author: The Arrayser=====//
//This is just a demonstration of the finite machine!
//This is the main project file (finite_machine.c)
//There should be no need to change anything from the this file!
//
//I CANNOT GIVE WARRANTY, THAT THIS ALWAYS WORKS!


#include <stdio.h>

#include "finite_machine.h"
#include "finite_machine_modificators.h"

unsigned int possibleInputLength = 50; //Propably you might want to

void InitializeMembers();
Node *doesEdgeListContainLetter(char, Edge *);

int main(){
    InitializeMembers();
    
    char input[possibleInputLength];
    printf("Type in a word to check if it works with the machine! Press [Enter], once you want to check your word!\n");
    printf("You can at maximum type %u characters\n", possibleInputLength);
    printf("The alphabet is \"%s\" with a length of %i\n", alphabet, sizeof(alphabet)-1);
    printf("Your word: ");
    scanf("%s", input);
    printf("The input = %s\n", input);
    /*for(int i= 0; i<possibleInputLength; i++){
        if(input[i]!='\0'){
            for(int a = 0; a < sizeof(alphabet-1); a++){
                if(input[i]==(alphabet[a])){
                    goto cc;
                }else{
                    continue;
                }
                break;
            }
        }else{
            break;
        }
        goto end1;
        break;
        cc:
        continue;
    }
    printf("your word passed stage 1\n");*/
    
    
    Node *tempnode = Start.following;
    Edge *tempedges = Start.following->edges;

    for(int k = 0; k < possibleInputLength; k++){
        char charForComparison = input[k];
        if((charForComparison=='\0')||(k==possibleInputLength-1)){
            if(tempnode->isPossibleEnd){
                goto finish;
            }else{
                goto Error;
            }

        }
        if(tempedges == NULL){
            goto Error;
        }
        Node *moretempnode =doesEdgeListContainLetter(charForComparison, tempedges);
        if(moretempnode!=NULL){
            tempnode = moretempnode;
            tempedges = tempnode->edges;
            continue;
        }else{
            //printf("yeah, still not compatible!\n");
            goto Error;
            return 0;
        }
        break;
    }

    Error:
    printf("Unfortunatly, the word did NOT pass the finite machine!\n");
    return 0;

    finish:
    printf("Concrats! The word passed the finite machine!\n");
    return 0;

    end1:
    printf("The word you chose is not compatible with the machine\n");
}

boolean doesEdgeContainLetter(char, Edge *);

Node *doesEdgeListContainLetter(char cmpchar ,Edge *testEdgelist){
        Edge *tempedge = testEdgelist;
        while(tempedge->next != NULL){
            if(doesEdgeContainLetter(cmpchar, tempedge)){
                return tempedge->following;
            }else{
                tempedge = tempedge->next;
            }
        }
            
        if(doesEdgeContainLetter(cmpchar, tempedge)){
            return tempedge->following;
        }else{
            tempedge = tempedge->next;
        }
        return NULL;
}

boolean doesEdgeContainLetter(char cmpchar, Edge *testEdge){
        Lang *templang = testEdge->partial_alphabet;

        while((templang->next) != NULL){
            if(templang->symbol=='\0'){
                printf("Error #2: unexpected null found!\n");
            }
            if(templang->symbol==cmpchar){
                return true;
            }
            templang = templang->next;
        }
        if(templang->symbol=='\0'){
                printf("Error #3: unexpected null found!\n");
            }
        if(templang->symbol==cmpchar){
            return true;
        }
    return false;
}

void InitializeMembers(){
    Initialization();
}