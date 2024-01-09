#ifndef CONFIG
#define CONFIG

#define NUM_LEG 4

#define RFLEG 0
#define RBLEG 1
#define LFLEG 2
#define LBLEG 3

#define UPSER 0
#define MIDSER 1
#define DOWNSER 2

#define angle_up_big 90
#define angle_up_small 30
#define angle_mid_long 35
#define angle_mid_short 45
#define angle_down_long 75
#define angle_down_short 45
#define angle_mid_long_lift 65
#define angle_mid_short_lift 75 
#define angle_down_long_lift 45 
#define angle_down_short_lift 15 

#define delaytime 1000

int ServoId[NUM_LEG][3] = {{1, 5, 9}, {3, 7, 11}, {32, 28, 24}, {30, 26, 22}};
int ServoErr[NUM_LEG][3] = {{-110, -80, -105}, {-30, -80, -120}, {-22, -85, -100}, {-89, -60, -110}};
int ServoDirAdj[NUM_LEG][3] = {{1, -1, 1}, {-1, 1, -1}, {-1, 1, -1}, {1, -1, 1}};

#endif