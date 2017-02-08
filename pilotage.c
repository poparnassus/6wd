#include "prototype.h"

//Mode de pilotage
void pilotage(Input *input,ecran *ecran , menu_droit *menu_droit, menu_haut *menu_haut, menu_gauche *menu_gauche, menu_bas *menu_bas)
{
    //Fonction Temps
    now = time (NULL);
    tm_now = localtime (&now);
    strftime (xtime, sizeof xtime, "%H:%M:%S", tm_now);
    sprintf(xtime, "%s",xtime);

    //Chrono application
    app_seconds = difftime(now,chronoapp);
    sprintf(xchronoapp, "%.f",app_seconds);

    if (input->mode_pilotage == 1)
    {

        ecran->zozor.x = input->sourisX  ;
        ecran->zozor.y = input->sourisY ;
        static int test_lumiere = 0;
        static int test_camera = 0;

        if (input->BOUTTON_RB == 0)
        {
            test_camera = 0;
        }
        else if (input->BOUTTON_RB == 1 && ! test_camera)
        {
            test_camera = 1;
            if (menu_haut->statueCAM == 0)
            {
                menu_haut->statueCAM = 1;
                test_camera = 1;
            }
            else if (menu_haut->statueCAM == 1)
            {
                menu_haut->statueCAM = 0;
                test_camera = 1;
            }
        }
        //PARTIE JOYSTICK
        if((input->JGY_Mx == 0) && (input->JDX_Mx == 0)) //mise à zero
        {
            input->PRoueG = 0;
            input->PRoueD = 0;
        }
        if((input->JGY_Mx == 0) && (input->JDX_Mx < 0)) //Rotation Gauche Sans Avance ni reculer
        {
            input->PRoueG = input->JDX_Mx;
            input->PRoueD = -input->JDX_Mx;
        }
        else if ((input->JGY_Mx == 0) && (input->JDX_Mx > 0))//Rotation Droite Sans Avance ni reculer
        {
            input->PRoueG = input->JDX_Mx;
            input->PRoueD = -input->JDX_Mx;
        }
        if((input->JGY_Mx > 0) && (input->JDX_Mx == 0)) // avancer
        {
            input->PRoueG = input->JGY_Mx;
            input->PRoueD = input->JGY_Mx;
        }
        else if ((input->JGY_Mx < 0)&&(input->JDX_Mx == 0))
        {
            input->PRoueG = input->JGY_Mx;
            input->PRoueD = input->JGY_Mx;
        }

        //Avancer + rotatioin
        if((input->JGY_Mx > 0)&&(input->JDX_Mx < 0)) // tourner a gauche
        {
            input->PRoueG = input->JGY_Mx + input->JDX_Mx;
            input->PRoueD = input->JGY_Mx;
        }
        else if ((input->JGY_Mx > 0)&& (input->JDX_Mx > 0)) //tourner a droite
        {
            input->PRoueG = input->JGY_Mx ;
            input->PRoueD = input->JGY_Mx - (input->JDX_Mx);
        }

        //reculer + rotation
        if ((input->JGY_Mx < 0) && (input->JDX_Mx < 0)) // tourner a gauche
        {
            input->PRoueG = input->JGY_Mx - input->JDX_Mx;
            input->PRoueD = input->JGY_Mx;
        }
        else if ((input->JGY_Mx < 0) &&(input->JDX_Mx > 0)) //tourner a droite
        {
            input->PRoueG = input->JGY_Mx ;
            input->PRoueD = input->JGY_Mx +  (input->JDX_Mx);
        }

        if(menu_haut->statueCAM == 1)
        {
            cam_seconds = difftime (now,chrono);
            sprintf(xchronocam, "%.f",cam_seconds);

            if (input->BOUTTON_A == 0)
            {
                test_lumiere = 0;
            }
            else if (input->BOUTTON_A == 1 && ! test_lumiere)
            {
                test_lumiere = 1;
                if (menu_droit->lumiere == 0)
                {
                    menu_droit->lumiere = 1;
                    test_lumiere = 1;
                }
                else if(menu_droit->lumiere == 1)
                {
                    menu_droit->lumiere = 0;
                    test_lumiere = 1;
                }
            }
        }
        else
        {
            heure = cam_seconds / 3600;
            cam_seconds = 0;
            //DEpart Chrono
            chrono = time(NULL);
            tm_chrono = localtime (&chrono);
        }
    }

    //WIFI Definition de la variable menu_gauche->wifi
{
/*
    if(input->JGX_Mx < 0  )
    {
        if((input->JGX_Mx >= -89) && (input->JGX_Mx <= -100))
        {
            menu_gauche->wifi = 8;
        }
        else if ((input->JGX_Mx <= -78) && (input->JGX_Mx > -89))
        {
            menu_gauche->wifi = 7;
        }
        else if ((input->JGX_Mx <= -67) && (input->JGX_Mx>  -78))
        {
            menu_gauche->wifi = 6;
        }
        else if ((input->JGX_Mx <= -56) && (input->JGX_Mx>  -67))
        {
            menu_gauche->wifi = 5;
        }
        else if
            cam_seconds = difftime (now,chrono);
            sprintf(xchronocam, "%.f",cam_seconds);
((input->JGX_Mx <= -45) && (input->JGX_Mx>  -56))
        {
            menu_gauche->wifi = 4;
        }
        else if ((input->JGX_Mx <= -34) && (input->JGX_Mx>  -45))
        {
            menu_gauche->wifi = 3;
        }
        else if ((input->JGX_Mx <= -23) && (input->JGX_Mx>  -34))
        {
            menu_gauche->wifi = 2;
        }
        else if ((input->JGX_Mx <= -12) && (input->JGX_Mx>  -23))
        {
            menu_gauche->wifi = 1;
        }
        else if ((input->JGX_Mx <= -2) && (input->JGX_Mx>  -12))
        {
            menu_gauche->wifi = 0;
        }
        else
        {
            menu_gauche->wifi = 0;
        }
   }
*/
}
    //Gestion souris
    //Gestion des bouttons de l'interface
    if( (input->sourisX >= menu_gauche->Rcase2.x) && (input->sourisX<= (menu_gauche->Rcase2.x + menu_gauche->Rcase2.w)) && (input->sourisY >= menu_gauche->Rcase2.y ) && (input->sourisY <= (menu_gauche->Rcase2.y + menu_gauche->Rcase2.h)))
    {
        if(input->sourisBG == 1)
        {
            input->quitter = 1; //Quitter le programme
        }
    }


/*
    //Position
    if (input->mode_pilotage == 1)
    {
        if( (ecran->zozor.x > ecran->Rscreen.x) && (ecran->zozor.x < (ecran->Rscreen.x + WINDOW_W)) && (ecran->zozor.y > ecran->Rscreen.y ) && (ecran->zozor.y < (ecran->Rscreen.y + WINDOW_H)))
        {
            int zozorx = 10;
            int zozory = 10;

            if(input->JDX > 0)
            {
                ecran->zozor.x = ecran->zozor.x + zozorx ;
            }
            if(input->JDX < 0)
            {
                ecran->zozor.x = ecran->zozor.x - zozorx ;
            }
            if(input->JDY > 0)
            {
                ecran->zozor.y =ecran->zozor.y - zozory ;
            }
            if (input->JDY < 0)
            {
                ecran->zozor.y =ecran->zozor.y + zozory ;
            }
        }
        else if ( (ecran->zozor.x < ecran->Rscreen.x) && (ecran->zozor.x > (ecran->Rscreen.x + WINDOW_W)) && (ecran->zozor.y < ecran->Rscreen.y ) && (ecran->zozor.y > (ecran->Rscreen.y + WINDOW_H)))
        {
            ecran->zozor.x = WINDOW_W/2 ;
            ecran->zozor.y = WINDOW_H /2 ;
        }
    }*/

}
