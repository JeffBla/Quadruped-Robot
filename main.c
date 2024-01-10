#include <pic18f4520.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

#include "setting_hardaware/include/motion.h"
#include "setting_hardaware/include/setting.h"
#include "setting_hardaware/include/config.h"

// command example: #21P2500T5000\r\n

void main() {
    SYSTEM_Initialize();

    int walk_state = 0;
    
    while(1) {
        if(isWalk){
            Motion_Walk(walk_state);
            walk_state = (walk_state + 1) % 6;
        } 
        else if(!isAdc){
            Motion_WalkInit();
            walk_state = 0;
        }
    }
    
    /*while (1) {
        if(isWalk){
            Motion_Walk(walk_state);
            walk_state = (walk_state + 1) % 4;
        }else{
            Motion_Stand();
            walk_state = 0;
        }
    }*/
    return;
}
