#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#define WINDOW_W 1600
#define WINDOW_H 900
#define CAMERA_W 900
#define CAMERA_H 900

#define DimZozor 25

time_t now, chrono, chronoapp;

struct tm *tm_now;
char xtime [sizeof "HH:MM:SS"];

struct tm *tm_chrono;
char xchronocam [sizeof "HH:MM:SS"];

struct tm *tm_chronoapp;
char xchronoapp [sizeof "HH:MM:SS"];


double cam_seconds, app_seconds;
double heure;

/*
//Option
typedef struct option option;
struct option
{
    SDL_Rect Roption;
    SDL_Surface *Soption;
    SDL_Texture *Toption;

};
*/

//Structure des fenetres
typedef struct ecran ecran;
struct ecran
{
    SDL_Window *screen1;
    SDL_Renderer *renderer1;
    SDL_Rect Rscreen;

    SDL_Surface *SimageFond_1;
    SDL_Texture *TimageFond_1;

    TTF_Font *police;
    SDL_Color couleurNoire;
    SDL_Color couleurRouge;
    SDL_Color couleurBlanche;

    SDL_Rect zozor;
    SDL_Surface *Szozor;
    SDL_Texture *Tzozor;
};

//Structure qui gere les evenements joystick, clavier
typedef struct Input Input;
struct Input
{
    //Variable
    int quitter ;
    //Mode de pilotage
    int mode_pilotage;

    //Position souris
    int sourisRelX;
    int sourisRelY;
    int sourisX;
    int sourisY;
    int sourisBG;
    int sourisBD;

    //Evenement joystick
    SDL_Joystick* joystick;
    //Correspondance de JGX, JGY , JDX, JDY en %
    int JGX_Mx ;
    int JGY_Mx ;
    int JDX_Mx ;
    int JDY_Mx ;
    //Variable pour affichage données
    char JGXX[10];
    char JGYY[10];
    char JDXX[10];
    char JDYY[10];

    int JGX_Max ; //calibration
    int JGY_Max ; //calibration
    int JDX_Max ; //calibration
    int JDY_Max ; //calibration

    int PRoueG ;
    int PRoueD ;
    char PRoueGx[10] ;
    char PRoueDx[10] ;


    int JGX ; //1
    int JGY ; //2
    int JDX ; //3
    int JDY ; //4
    int BOUTTON_A; //5- 0 Pour Boutton Relacher
    int BOUTTON_B ;//6
    int BOUTTON_Y ;//7
    int BOUTTON_X ;//8
    int BOUTTON_LB ; //9 boutton Gauche
    int BOUTTON_RB ; //10 boutton droite
    int BOUTTON_START ;//11
    int BOUTTON_BACK ; //12
    //Zone morte
    int DEADZONE_N ;
    int DEADZONE_P;
};


typedef struct menu_bas menu_bas;
struct menu_bas
{
    SDL_Rect RbouttonMID, RbouttonA, RbouttonY, RbouttonX, RbouttonB, RJoy1 , RJoy11, RJoy12, RJoy13, RJoy2, RJoy21, RJoy22, RJoy23;
    SDL_Surface *SbouttonA, *SbouttonY, *SbouttonX , *SbouttonB, *SJoy1, *SJoy11, *SJoy12, *SJoy13, *SJoy2, *SJoy21, *SJoy22, *SJoy23;
    SDL_Texture *TbouttonA, *TbouttonY, *TbouttonX , *TbouttonB, *TJoy1, *TJoy11, *TJoy12, *TJoy13, *TJoy2, *TJoy21, *TJoy22, *TJoy23;

    SDL_Rect Rproued,Rproueg;
    SDL_Surface *Sproued,*Sproueg;
    SDL_Texture *Tproued,*Tproueg;
};

typedef struct menu_gauche menu_gauche;
struct menu_gauche
{
    int wifi ;
    SDL_Rect  Rcase2, Rcase3, Rcase4, Rcase5, Rcase6;
    SDL_Surface *Scase2, *Scase3, *Scase4, *Scase5, *Scase6;
    SDL_Texture *Tcase2, *Tcase3, *Tcase4, *Tcase5, *Tcase6;

    //Image wifi
    SDL_Surface *Swifi ;
    SDL_Texture *Twifi ;

    //TIME
    SDL_Rect Rtime, Rcase1;
    SDL_Surface *Stime, *Scase1;
    SDL_Texture *Ttime, *Tcase1;

    //chrono
    SDL_Rect Rchronoapp, Rchrono;
    SDL_Surface *Schronoapp, *Schrono;
    SDL_Texture *Tchronoapp, * Tchrono;

};

typedef struct menu_droit menu_droit;
struct menu_droit
{
    SDL_Rect RVlumiere;
    SDL_Surface *SVlumiere;
    SDL_Texture *TVlumiere;
    int lumiere ;
};

typedef struct menu_haut menu_haut;
struct menu_haut
{
    //Voyant joystick on/off
    SDL_Rect RVjoystick;
    SDL_Surface *SVjoystick;
    SDL_Texture *TVjoystick;

    //Voyant joystick on/off
    SDL_Rect RstatueCAM;
    SDL_Surface *SstatueCAM;
    SDL_Texture *TstatueCAM;
    int statueCAM;
/**/


};

typedef struct camera camera;
struct camera
{
    SDL_Surface *SimageFondCam;
    SDL_Texture *TimageFondCam;

    SDL_Rect Rcamera;
    SDL_Rect Rpcamera;
    SDL_Surface *Scamera;
    SDL_Texture *Tcamera;

    SDL_Rect Rchronocam, Rchronocambis;
    SDL_Surface *Schoronocam, *Schoronocambis;
    SDL_Texture *Tchronocam, *Tchronocambis;
};

void print_data( Input *input, menu_droit *menu_droit, menu_gauche *menu_gauche);

void init_structure(ecran *ecran, Input *input, menu_bas *menu_bas, menu_gauche *menu_gauche, menu_droit *menu_droit, menu_haut *menu_haut, camera *camera);
void initialisation(const char *titre,Input *input, ecran *ecran);

void send_data_pilotage (Input *input);

void updateEvent( Input *input, ecran *ecran, menu_gauche *menu_gauche);
void pilotage(Input *input, ecran *ecran, menu_droit *menu_droit, menu_haut *menu_haut, menu_gauche *menu_gauche, menu_bas *menu_bas);
void chargement_image(Input *input, ecran *ecran,menu_droit *menu_droit, menu_haut *menu_haut, menu_gauche *menu_gauche, menu_bas *menu_bas, camera *camera);
void camera_camera(camera *camera, menu_haut *menu_haut);

void cleanup(Input *input,ecran *ecran, menu_bas *menu_bas, menu_gauche *menu_gauche, menu_droit *menu_droit, menu_haut *menu_haut, camera *camera);
