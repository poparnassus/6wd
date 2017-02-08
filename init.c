#include "prototype.h"

void init_structure(ecran *ecran, Input *input, menu_bas *menu_bas, menu_gauche *menu_gauche, menu_droit *menu_droit, menu_haut *menu_haut, camera *camera)
{
    //Tableau
    //int tableauMD1[10];

    int margeh = 10, margew = 10; //Marge boutton time, chrono, chronoapp
    int boutton_cotew = 100 , boutton_coteh = 40 ;
    int touche= 40; //// Boutton A B X Y dimmension

    /*
    //Option
    option->Roption.x = 0;
    option->Roption.y = 0;
    option->Roption.w = 0;
    option->Roption.h = 0;*/

    //ZOZOR
    ecran->zozor.x = WINDOW_W /2;
    ecran->zozor.y = WINDOW_H /2;
    ecran->zozor.w = DimZozor ;
    ecran->zozor.h = DimZozor;

    //structure ecran
    ecran->screen1 = NULL;
    ecran->renderer1 = NULL;
    ecran->SimageFond_1 = NULL;
    ecran->TimageFond_1= NULL;
    ecran->Rscreen.x = 0;
    ecran->Rscreen.y = 0;
    ecran->Rscreen.w = WINDOW_W - (ecran->Rscreen.x*2);
    ecran->Rscreen.h =  WINDOW_H;

    //Camera
    camera->Rpcamera.x = 0 ;
    camera->Rpcamera.y = 0 ;
    int dimh = CAMERA_H, dimw = CAMERA_H * (16/9)  ;
    camera->Rcamera.x = (WINDOW_W - dimw)/2  ;
    camera->Rcamera.y = (WINDOW_H - dimh) ;
    camera->Rcamera.w = dimw;
    camera->Rcamera.h = dimh;
    camera->Rchronocam.x=camera->Rcamera.x;
    camera->Rchronocam.y=camera->Rcamera.y;
    camera->Rchronocam.w=100;
    camera->Rchronocam.h=camera->Rchronocam.w * (16/9);
    camera->Rchronocambis.x=camera->Rchronocam.x +margew;
    camera->Rchronocambis.y=camera->Rchronocam.y +margeh;
    camera->Rchronocambis.w=camera->Rchronocam.w - (margew*2);
    camera->Rchronocambis.h=(camera->Rchronocambis.w * (16/9)) - margeh *2;

    //structure input (joystique)
    input->joystick = SDL_JoystickOpen(0);
    input->quitter = 0;
    input->mode_pilotage = 0;
    input->sourisX = 0;
    input->sourisY = 0;
    input->sourisBG = 0;
    input->sourisBD = 0;
    input->JGXX[10] = 0;
    input->JGYY[10] = 0;
    input->JDXX[10] = 0;
    input->JDYY[10] = 0;
    input->JGX_Max = 24767 ; // A redefinir avec la calibration
    input->JGY_Max = 24767 ;
    input->JDX_Max = 24767 ;
    input->JDY_Max = 24767 ;
    input->PRoueG=0 ;
    input->PRoueD=0 ;
    input->PRoueGx[10]=0 ;
    input->PRoueDx[10]=0 ;
    input->JGX_Mx = 0 ; // A redefinir avec la calibration
    input->JGY_Mx = 0 ;
    input->JDX_Mx = 0 ;
    input->JDY_Mx = 0 ;
    input->JGX = 0; //position tableau = 0
    input->JGY = 0; //position tableau = 1
    input->JDX = 0; //position tableau = 2
    input->JDY = 0; //position tableau = 3
    input->BOUTTON_A = 0; //position tableau = 4 - 0 Pour Boutton Relacher
    input->BOUTTON_B = 0;//position tableau = 5
    input->BOUTTON_Y = 0;//position tableau = 6
    input->BOUTTON_X = 0;//position tableau = 7
    input->BOUTTON_LB = 0; //position tableau = 8 boutton Gauche
    input->BOUTTON_RB = 0; //position tableau = 9 boutton droite
    input->BOUTTON_START = 0;//position tableau = 10
    input->BOUTTON_BACK = 0; //position tableau = 11
    //Zone morte
    input->DEADZONE_P = 8000;
    input->DEADZONE_N = -8000;

    // Boutton A B X Y
    //BOUTTON Y
    menu_bas->RbouttonY.x =(WINDOW_W/2)-(touche/2) ; //centre du rectangle 1
    menu_bas->RbouttonY.y = WINDOW_H - (touche * 3);
    menu_bas->RbouttonY.w = touche;
    menu_bas->RbouttonY.h = touche;
    //BOUTTO A
    menu_bas->RbouttonA.x = menu_bas->RbouttonY.x;
    menu_bas->RbouttonA.y = menu_bas->RbouttonY.y + touche*2;
    menu_bas->RbouttonA.w = touche;
    menu_bas->RbouttonA.h = touche;
    //BOUTTON B
    menu_bas->RbouttonB.x = menu_bas->RbouttonY.x + touche;
    menu_bas->RbouttonB.y = menu_bas->RbouttonY.y + touche;
    menu_bas->RbouttonB.w = touche;
    menu_bas->RbouttonB.h = touche;
    //BOUTTON X
    menu_bas->RbouttonX.x = menu_bas->RbouttonY.x - touche;
    menu_bas->RbouttonX.y = menu_bas->RbouttonY.y + touche;
    menu_bas->RbouttonX.w = touche;
    menu_bas->RbouttonX.h = touche;
    //Carré du milieu
    menu_bas->RbouttonMID.x = menu_bas->RbouttonY.x;
    menu_bas->RbouttonMID.y = menu_bas->RbouttonY.y + touche;
    menu_bas->RbouttonMID.w = touche;
    menu_bas->RbouttonMID.h = touche;
    //Position par rapport a la touche X
    //int marge=10;
    menu_bas->RJoy1.w = menu_bas->RbouttonMID.w+menu_bas->RbouttonA.w+menu_bas->RbouttonY.w;
    menu_bas->RJoy1.h = menu_bas->RbouttonMID.h+menu_bas->RbouttonA.h+menu_bas->RbouttonY.h;
    menu_bas->RJoy1.x =camera->Rcamera.x - menu_bas->RJoy1.w;
    menu_bas->RJoy1.y = WINDOW_H - menu_bas->RJoy1.h;
        menu_bas->RJoy11.w =menu_bas->RJoy1.w;
        menu_bas->RJoy11.h =menu_bas->RJoy1.h/3;
        menu_bas->RJoy11.x =menu_bas->RJoy1.x;
        menu_bas->RJoy11.y =menu_bas->RJoy1.y;
        menu_bas->RJoy12.w =menu_bas->RJoy11.w;
        menu_bas->RJoy12.h =menu_bas->RJoy11.h;
        menu_bas->RJoy12.x =menu_bas->RJoy11.x ;
        menu_bas->RJoy12.y =menu_bas->RJoy11.y + menu_bas->RJoy12.h;
        menu_bas->RJoy13.w =menu_bas->RJoy12.w;
        menu_bas->RJoy13.h =menu_bas->RJoy12.h;
        menu_bas->RJoy13.x =menu_bas->RJoy12.x ;
        menu_bas->RJoy13.y =menu_bas->RJoy12.y + menu_bas->RJoy13.h;
    //Position par rapport a la touche B
    menu_bas->RJoy2.w = menu_bas->RbouttonMID.w+menu_bas->RbouttonA.w+menu_bas->RbouttonY.w;
    menu_bas->RJoy2.h = menu_bas->RbouttonMID.h+menu_bas->RbouttonA.h+menu_bas->RbouttonY.h;
    menu_bas->RJoy2.x = camera->Rcamera.x +  camera->Rcamera.w  ;
    menu_bas->RJoy2.y = WINDOW_H - menu_bas->RJoy2.h  ;
        menu_bas->RJoy21.w =menu_bas->RJoy2.w;
        menu_bas->RJoy21.h =menu_bas->RJoy2.h/3;
        menu_bas->RJoy21.x =menu_bas->RJoy2.x;
        menu_bas->RJoy21.y =menu_bas->RJoy2.y;
        menu_bas->RJoy22.w =menu_bas->RJoy21.w;
        menu_bas->RJoy22.h =menu_bas->RJoy21.h;
        menu_bas->RJoy22.x =menu_bas->RJoy21.x;
        menu_bas->RJoy22.y =menu_bas->RJoy21.y + menu_bas->RJoy22.h;
        menu_bas->RJoy23.w =menu_bas->RJoy22.w;
        menu_bas->RJoy23.h =menu_bas->RJoy22.h;
        menu_bas->RJoy23.x =menu_bas->RJoy22.x;
        menu_bas->RJoy23.y =menu_bas->RJoy22.y + menu_bas->RJoy23.h;
    menu_bas->Rproueg.x=menu_bas->RJoy11.x;
    menu_bas->Rproueg.y=menu_bas->RJoy11.y ;
    menu_bas->Rproueg.w=menu_bas->RJoy11.w;
    menu_bas->Rproueg.h=menu_bas->RJoy11.h;
    menu_bas->Rproued.x=menu_bas->RJoy21.x;
    menu_bas->Rproued.y=menu_bas->RJoy21.y;
    menu_bas->Rproued.w=menu_bas->RJoy21.w;
    menu_bas->Rproued.h=menu_bas->RJoy21.h;

    //Menu_gauche
    //Bouttons colonne gauche - 6 bouttons

    menu_gauche->wifi = 7;

    menu_gauche->Rcase1.x = 0;
    menu_gauche->Rcase1.y = 0;
    menu_gauche->Rcase1.w = 100 ;
    menu_gauche->Rcase1.h = menu_gauche->Rcase1.w * (16/9);
    menu_gauche->Rtime.x = menu_gauche->Rcase1.x + margew;
    menu_gauche->Rtime.y = menu_gauche->Rcase1.y + margeh;
    menu_gauche->Rtime.w = menu_gauche->Rcase1.w - (margew *2);
    menu_gauche->Rtime.h = (menu_gauche->Rtime.w * (16/9)) - (margeh *2);

    menu_gauche->Rchronoapp.x=menu_gauche->Rcase1.x + menu_gauche->Rcase1.w +10 ;
    menu_gauche->Rchronoapp.y = menu_gauche->Rcase1.y ;
    menu_gauche->Rchronoapp.w= menu_gauche->Rcase1.w;
    menu_gauche->Rchronoapp.h= menu_gauche->Rchronoapp.w * (16/9);
    menu_gauche->Rchrono.x= menu_gauche->Rchronoapp.x + margew;
    menu_gauche->Rchrono.y= menu_gauche->Rchronoapp.y + margeh;
    menu_gauche->Rchrono.w= menu_gauche->Rchronoapp.w - (margew *2);
    menu_gauche->Rchrono.h= menu_gauche->Rchrono.w *(16/9)- (margew *2);

    menu_gauche->Rcase2.x = menu_gauche->Rcase1.x;
    menu_gauche->Rcase2.y = menu_gauche->Rcase1.y + menu_gauche->Rcase1.h;
    menu_gauche->Rcase2.w = boutton_cotew ;
    menu_gauche->Rcase2.h = boutton_coteh;
    menu_gauche->Rcase3.x = menu_gauche->Rcase2.x;
    menu_gauche->Rcase3.y = menu_gauche->Rcase2.y + boutton_coteh;
    menu_gauche->Rcase3.w = boutton_cotew ;
    menu_gauche->Rcase3.h = boutton_coteh;
    menu_gauche->Rcase4.x = menu_gauche->Rcase3.x;
    menu_gauche->Rcase4.y = menu_gauche->Rcase3.y + boutton_coteh;
    menu_gauche->Rcase4.w = boutton_cotew ;
    menu_gauche->Rcase4.h = boutton_coteh;
    menu_gauche->Rcase5.x = menu_gauche->Rcase4.x;
    menu_gauche->Rcase5.y = menu_gauche->Rcase4.y + boutton_coteh;
    menu_gauche->Rcase5.w = boutton_cotew ;
    menu_gauche->Rcase5.h = boutton_coteh;
    menu_gauche->Rcase6.x = menu_gauche->Rcase5.x;
    menu_gauche->Rcase6.y = menu_gauche->Rcase5.y + boutton_coteh;
    menu_gauche->Rcase6.w = boutton_cotew ;
    menu_gauche->Rcase6.h = boutton_coteh;



    //Menu_haut
    menu_haut->statueCAM = 0 ;
    menu_haut->RVjoystick.x = WINDOW_W -  (boutton_cotew*2);
    menu_haut->RVjoystick.y =0;
    menu_haut->RVjoystick.w = boutton_cotew;
    menu_haut->RVjoystick.h =boutton_coteh  ;
    SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); // blanc
    SDL_RenderFillRect(ecran->renderer1,&menu_haut->RVjoystick);
    menu_haut->RstatueCAM.x = menu_haut->RVjoystick.x +  boutton_cotew;
    menu_haut->RstatueCAM.y = menu_haut->RVjoystick.y  ;
    menu_haut->RstatueCAM.w = boutton_cotew;
    menu_haut->RstatueCAM.h = boutton_coteh ;
    /**/


    //menu_droit
    menu_droit->lumiere = 0;
    menu_droit->RVlumiere.x = WINDOW_W - (boutton_cotew);;
    menu_droit->RVlumiere.y = (menu_haut->RVjoystick.y + menu_haut->RVjoystick.h) + boutton_coteh;
    menu_droit->RVlumiere.w = boutton_cotew;
    menu_droit->RVlumiere.h = boutton_coteh;


}


void initialisation(const char *titre,Input *input, ecran *ecran)
{
    if (SDL_Init( SDL_INIT_VIDEO |SDL_INIT_JOYSTICK) != 0)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger la librairie SDL2.0.",NULL);
        EXIT_FAILURE;
    }
    else
    {
        //Creation de la fenetre
        ecran->screen1 = SDL_CreateWindow(titre,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_W,WINDOW_H,SDL_WINDOW_SHOWN);
        //Creation du renderer
        ecran->renderer1 = SDL_CreateRenderer( ecran->screen1,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if ( ecran->screen1 == NULL ||  ecran->renderer1 == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible d'initialiser la fenetre ou/et d'afficher le rendu.",NULL);

        }

        //Verifie si un joystixk est connecter
        if (SDL_NumJoysticks() < 1)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Pas de joystick connecter.",NULL);
            EXIT_FAILURE;
        }
        else
        {
            SDL_JoystickEventState(SDL_ENABLE);
            input->joystick = SDL_JoystickOpen(0);
        }

    }

    //Initialisation TTf_font
    if(TTF_Init() != 0)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: impossible de charger la SDL2_TTF_Init..",NULL);
        EXIT_FAILURE;
    }
     else
    {
        ecran->police = TTF_OpenFont("Caslon.ttf",18) ;
        if(ecran->police == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger la police Calson.",NULL);
            EXIT_FAILURE;
        }
        else
        {
        ecran->couleurNoire.a = 0;
        ecran->couleurNoire.b = 0;
        ecran->couleurNoire.g = 0;
        ecran->couleurNoire.r = 0;
        ecran->couleurRouge.a = 0;
        ecran->couleurRouge.b = 0;
        ecran->couleurRouge.g = 0;
        ecran->couleurRouge.r = 255;
        ecran->couleurBlanche.a = 255;
        ecran->couleurBlanche.b = 255;
        ecran->couleurBlanche.g = 255;
        ecran->couleurBlanche.r = 255;
        }
    }

}

