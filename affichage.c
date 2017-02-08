#include "prototype.h"
void print_data(Input *input, menu_droit *menu_droit, menu_gauche *menu_gauche)
{
    //Mise en tableau des valeurs a transmettre au buggy
    int tableauMD1[10]= {input->mode_pilotage,input->JGX_Mx,input->JGY_Mx,input->JDX_Mx,input->JDY_Mx,menu_droit->lumiere,input->BOUTTON_B,input->BOUTTON_Y,input->BOUTTON_X,menu_gauche->wifi};

    printf("Heure: %s\n\n",xtime);
    printf("heure: %f \n\n",heure);

    int i;
    for(i=0; i < 10; i++)
    {
        printf("= %d \n",tableauMD1[i]);
    }
    printf("Roue gauche: %d\n\n",input->PRoueG);
    printf("Roue droite: %d\n\n",input->PRoueD);
    system("cls");
}

void chargement_image(Input *input, ecran *ecran, menu_droit *menu_droit, menu_haut *menu_haut, menu_gauche *menu_gauche, menu_bas *menu_bas, camera *camera)
{
    int w = 20 , h = 20;
    SDL_RenderClear(ecran->renderer1);
    SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); //BLANC

    ecran->SimageFond_1 = SDL_LoadBMP("./image/fond3.bmp");
    if (ecran->SimageFond_1 == NULL)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image fond1.",NULL);
    }
    else
    {
        //Affichage image de fond
        ecran->TimageFond_1 = SDL_CreateTextureFromSurface(ecran->renderer1,ecran->SimageFond_1);
        SDL_RenderCopy(ecran->renderer1,ecran->TimageFond_1 ,NULL,NULL);
    }
        menu_gauche->Scase1 = SDL_LoadBMP("./image/time.bmp");
        if (menu_gauche->Scase1 == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image fond1.",NULL);
        }
        else
        {
            menu_gauche->Tcase1 = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Scase1);
            SDL_RenderCopy(ecran->renderer1,menu_gauche->Tcase1 ,NULL,&menu_gauche->Rcase1);
            SDL_RenderCopy(ecran->renderer1,menu_gauche->Tcase1 ,NULL,&menu_gauche->Rchronoapp);

        //Affichage temps
        menu_gauche->Stime = TTF_RenderText_Blended(ecran->police, xtime ,ecran->couleurRouge);
        menu_gauche->Ttime = SDL_CreateTextureFromSurface(ecran->renderer1, menu_gauche->Stime);
        SDL_QueryTexture(menu_gauche->Ttime, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_gauche->Ttime, NULL, &menu_gauche->Rtime);

        //Chrono application
        menu_gauche->Schronoapp = TTF_RenderText_Blended(ecran->police, xchronoapp ,ecran->couleurRouge);
        menu_gauche->Tchronoapp = SDL_CreateTextureFromSurface(ecran->renderer1, menu_gauche->Schronoapp);
        SDL_QueryTexture(menu_gauche->Tchronoapp, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_gauche->Tchronoapp, NULL, &menu_gauche->Rchrono);

       }




    //affichage du boutton QUITTER
    menu_gauche->Scase2 = SDL_LoadBMP("./image/quitter.bmp");
    if (menu_gauche->Scase2 == NULL)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image du boutton quitter.",NULL);
    }
    else
    {
        menu_gauche->Tcase2 = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Scase2);
        SDL_RenderCopy(ecran->renderer1,menu_gauche->Tcase2,NULL,&menu_gauche->Rcase2);
    }

    if(menu_haut->statueCAM == 0) //camera deconnecter
    {
        SDL_SetRenderDrawColor(ecran->renderer1,255,201,14,0); //orange
        SDL_RenderFillRect(ecran->renderer1, &menu_haut->RstatueCAM);
        menu_haut->SstatueCAM = TTF_RenderText_Blended(ecran->police, " Camera OFF ",ecran->couleurNoire);
        menu_haut->TstatueCAM = SDL_CreateTextureFromSurface(ecran->renderer1, menu_haut->SstatueCAM);
        SDL_RenderFillRect(ecran->renderer1, &menu_haut->RstatueCAM );
        SDL_QueryTexture(menu_haut->TstatueCAM, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_haut->TstatueCAM, NULL, &menu_haut->RstatueCAM );
        SDL_DestroyTexture(menu_haut->TstatueCAM);
        SDL_FreeSurface(menu_haut->SstatueCAM);
    }
    else if (menu_haut->statueCAM == 1) //Camera connecter
    {



        camera->SimageFondCam = SDL_LoadBMP("./image/6wd.bmp");
        if (camera->SimageFondCam == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image 6wd.bmp.",NULL);
        }
        else
        {
            SDL_SetRenderDrawColor(ecran->renderer1,63,241,58,0); //vert
            SDL_RenderFillRect(ecran->renderer1, &menu_haut->RstatueCAM);
            menu_haut->SstatueCAM = TTF_RenderText_Blended(ecran->police, "Camera ON",ecran->couleurNoire);
            menu_haut->TstatueCAM = SDL_CreateTextureFromSurface(ecran->renderer1, menu_haut->SstatueCAM);
            SDL_RenderFillRect(ecran->renderer1, &menu_haut->RstatueCAM );
            SDL_QueryTexture(menu_haut->TstatueCAM, NULL, NULL, &w, &h);
            SDL_RenderCopy(ecran->renderer1, menu_haut->TstatueCAM, NULL, &menu_haut->RstatueCAM );
            camera->TimageFondCam = SDL_CreateTextureFromSurface(ecran->renderer1,camera->SimageFondCam); //SDL TEXTURE
            SDL_RenderCopy(ecran->renderer1, camera->TimageFondCam , NULL, &camera->Rcamera );

            SDL_RenderCopy(ecran->renderer1,menu_gauche->Tcase1 ,NULL,&camera->Rchronocam);
           //Affichage chrono
            menu_gauche->Schrono = TTF_RenderText_Blended(ecran->police, xchronocam ,ecran->couleurRouge);
            menu_gauche->Tchrono = SDL_CreateTextureFromSurface(ecran->renderer1, menu_gauche->Schrono);
            SDL_QueryTexture(menu_gauche->Tchrono, NULL, NULL, &w, &h);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Tchrono, NULL, &camera->Rchronocambis);

        }
        SDL_DestroyTexture(menu_gauche->Tchrono);
        SDL_FreeSurface(menu_gauche->Schrono);
        SDL_DestroyTexture(menu_haut->TstatueCAM);
        SDL_FreeSurface(menu_haut->SstatueCAM);
        SDL_DestroyTexture(camera->TimageFondCam);
        SDL_FreeSurface(camera->SimageFondCam);
    }

    if (menu_droit->lumiere == 1)
    {
        SDL_SetRenderDrawColor(ecran->renderer1,255,255,0,0);
        menu_droit->SVlumiere = TTF_RenderText_Blended(ecran->police, " Lumiere ON ",ecran->couleurNoire);
        menu_droit->TVlumiere = SDL_CreateTextureFromSurface(ecran->renderer1, menu_droit->SVlumiere);
        SDL_RenderFillRect(ecran->renderer1, &menu_droit->RVlumiere);
        SDL_QueryTexture(menu_droit->TVlumiere, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_droit->TVlumiere, NULL, &menu_droit->RVlumiere);
    }
    else if(menu_droit->lumiere == 0)
    {
        SDL_SetRenderDrawColor(ecran->renderer1,255,201,14,0);
        menu_droit->SVlumiere = TTF_RenderText_Blended(ecran->police, " Lumiere OFF ",ecran->couleurNoire);
        menu_droit->TVlumiere = SDL_CreateTextureFromSurface(ecran->renderer1, menu_droit->SVlumiere);
        SDL_RenderFillRect(ecran->renderer1, &menu_droit->RVlumiere);
        SDL_QueryTexture(menu_droit->TVlumiere, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_droit->TVlumiere, NULL, &menu_droit->RVlumiere);
    }

    //Detection de deconnexion joystique
    if (SDL_NumJoysticks() < 1)
    {
        //int w = 5 , h = 5;
        SDL_SetRenderDrawColor(ecran->renderer1,255,201,14,0);
        SDL_RenderFillRect(ecran->renderer1, &menu_haut->RVjoystick);
        menu_haut->SVjoystick = TTF_RenderText_Blended(ecran->police, "Joystick deconnecter",ecran->couleurNoire);
        menu_haut->TVjoystick = SDL_CreateTextureFromSurface(ecran->renderer1, menu_haut->SVjoystick);
        SDL_QueryTexture(menu_haut->TVjoystick, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_haut->TVjoystick, NULL, &menu_haut->RVjoystick);
        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"Erreur","Erreur: Le joystique viens de se deconnecter, veuillez le reconnecter",NULL);
        SDL_JoystickClose(input->joystick);

        SDL_DestroyTexture(menu_haut->TVjoystick);
        SDL_FreeSurface(menu_haut->SVjoystick);
    }
    else
    {
        SDL_SetRenderDrawColor(ecran->renderer1,63,241,58,0);
        SDL_RenderFillRect(ecran->renderer1, &menu_haut->RVjoystick);
        menu_haut->SVjoystick = TTF_RenderText_Blended(ecran->police, "Joystick connecter",ecran->couleurNoire);
        menu_haut->TVjoystick = SDL_CreateTextureFromSurface(ecran->renderer1, menu_haut->SVjoystick);
        SDL_QueryTexture(menu_haut->TVjoystick, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_haut->TVjoystick, NULL, &menu_haut->RVjoystick);
        input->joystick = SDL_JoystickOpen(0);
        SDL_JoystickEventState(SDL_ENABLE);

        SDL_DestroyTexture(menu_haut->TVjoystick);
        SDL_FreeSurface(menu_haut->SVjoystick);
    }
    if (input->mode_pilotage == 1)
    {
        //JGX
        sprintf(input->JGXX, "X %d",input->JGX);
        //SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->RJoy12);
        menu_bas->SJoy12 = TTF_RenderText_Solid(ecran->police,input->JGXX,ecran->couleurNoire);
        menu_bas->TJoy12 = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->SJoy12);
        SDL_QueryTexture(menu_bas->TJoy12, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->TJoy12, NULL, &menu_bas->RJoy12);

        //JGY JGYY
        sprintf(input->JGYY, "Y %d",input->JGY);
        //SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->RJoy13);
        menu_bas->SJoy13 = TTF_RenderText_Solid(ecran->police,input->JGYY,ecran->couleurNoire);
        menu_bas->TJoy13 = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->SJoy13);
        SDL_QueryTexture(menu_bas->TJoy13, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->TJoy13, NULL, &menu_bas->RJoy13);

        //JDX JDXX
        sprintf(input->JDXX, "X %d",input->JDX);
        //SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->RJoy22);
        menu_bas->SJoy22 = TTF_RenderText_Solid(ecran->police,input->JDXX,ecran->couleurNoire);
        menu_bas->TJoy22 = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->SJoy22);
        SDL_QueryTexture(menu_bas->TJoy22, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->TJoy22, NULL, &menu_bas->RJoy22);

        //JDY JDYY
        sprintf(input->JDYY, "Y %d",input->JDY);
        //SDL_SetRenderDrawColor(ecran->renderer1,255,255,255,255); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->RJoy23);
        menu_bas->SJoy23 = TTF_RenderText_Solid(ecran->police,input->JDYY,ecran->couleurNoire);
        menu_bas->TJoy23 = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->SJoy23);
        SDL_QueryTexture(menu_bas->TJoy23, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->TJoy23, NULL, &menu_bas->RJoy23);

        //Affichage puissance moteur gauche et droit
        sprintf(input->PRoueGx, "%d",input->PRoueG);
        // SDL_SetRenderDrawColor(ecran->renderer1,0,0,0,0); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->Rproueg);
        menu_bas->Sproueg = TTF_RenderText_Solid(ecran->police,input->PRoueGx,ecran->couleurNoire);
        menu_bas->Tproueg = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->Sproueg);
        SDL_QueryTexture(menu_bas->Tproueg, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->Tproueg, NULL, &menu_bas->Rproueg);

        sprintf(input->PRoueDx, "%d",input->PRoueD);
        // SDL_SetRenderDrawColor(ecran->renderer,0,0,0,0); //BLANC

        //SDL_RenderFillRect(ecran->renderer1, &menu_bas->Rproued);
        menu_bas->Sproued = TTF_RenderText_Solid(ecran->police,input->PRoueDx,ecran->couleurNoire);
        menu_bas->Tproued = SDL_CreateTextureFromSurface(ecran->renderer1, menu_bas->Sproued);
        SDL_QueryTexture(menu_bas->Tproued, NULL, NULL, &w, &h);
        SDL_RenderCopy(ecran->renderer1, menu_bas->Tproued, NULL, &menu_bas->Rproued);


        //BOUTTON Y
        if(input->BOUTTON_Y == 1)
        {
            menu_bas->SbouttonY = SDL_LoadBMP("./image/BouttonY.bmp");
            if (menu_bas->SbouttonY == NULL)
            {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image du boutton A.",NULL);
            }
            else
            {
                menu_bas->TbouttonY = SDL_CreateTextureFromSurface(ecran->renderer1,menu_bas->SbouttonY);
                SDL_RenderCopy(ecran->renderer1,menu_bas->TbouttonY,NULL,&menu_bas->RbouttonY);
            }

            SDL_DestroyTexture(menu_bas->TbouttonY);
            SDL_FreeSurface(menu_bas->SbouttonY);
        }

        if(input->BOUTTON_X == 1)
        {
            menu_bas->SbouttonX = SDL_LoadBMP("./image/BouttonX.bmp");
            if (menu_bas->SbouttonX == NULL)
            {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image du boutton A.",NULL);
            }
            else
            {
                menu_bas->TbouttonX = SDL_CreateTextureFromSurface(ecran->renderer1,menu_bas->SbouttonX);
                SDL_RenderCopy(ecran->renderer1,menu_bas->TbouttonX,NULL,&menu_bas->RbouttonX);
            }
            SDL_DestroyTexture(menu_bas->TbouttonX);
            SDL_FreeSurface(menu_bas->SbouttonX);
        }

        if(input->BOUTTON_A == 1)
        {
            menu_bas->SbouttonA = SDL_LoadBMP("./image/BouttonA.bmp");
            if ( menu_bas->SbouttonA == NULL)
            {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image du boutton A.",NULL);
            }
            else
            {
                menu_bas->TbouttonA = SDL_CreateTextureFromSurface(ecran->renderer1,menu_bas->SbouttonA);
                SDL_RenderCopy(ecran->renderer1,menu_bas->TbouttonA,NULL,&menu_bas->RbouttonA);
            }

            SDL_DestroyTexture(menu_bas->TbouttonA);
            SDL_FreeSurface(menu_bas->SbouttonA);
        }
        if(input->BOUTTON_B == 1)
        {
            menu_bas->SbouttonB = SDL_LoadBMP("./image/BouttonB.bmp");
            if (menu_bas->SbouttonB == NULL)
            {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image du boutton A.",NULL);
            }
            else
            {
                menu_bas->TbouttonB = SDL_CreateTextureFromSurface(ecran->renderer1,menu_bas->SbouttonB);
                SDL_RenderCopy(ecran->renderer1,menu_bas->TbouttonB,NULL,&menu_bas->RbouttonB);
            }
            SDL_DestroyTexture(menu_bas->TbouttonB);
            SDL_FreeSurface(menu_bas->SbouttonB);
        }

        //Destruction texture
        SDL_DestroyTexture(menu_bas->TJoy23);
        SDL_DestroyTexture(menu_bas->TJoy22);
        SDL_DestroyTexture(menu_bas->TJoy13);
        //boutton
        SDL_DestroyTexture(menu_bas->TJoy12);

        SDL_DestroyTexture(menu_bas->Tproueg);
        SDL_DestroyTexture(menu_bas->Tproued);

        //Liberation des surfaces
        SDL_FreeSurface(menu_bas->SJoy23);
        SDL_FreeSurface(menu_bas->SJoy13);
        SDL_FreeSurface(menu_bas->SJoy12);
        SDL_FreeSurface(menu_bas->SJoy22);
        SDL_FreeSurface(menu_bas->Sproued);
        SDL_FreeSurface(menu_bas->Sproueg);
        //boutton

    }

    if(menu_gauche->wifi == 0)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi0.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi0.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 1)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi1.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 2)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi2.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 3)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi3.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 4)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi4.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 5)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi5.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 6)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi6.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 7)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi7.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }
    else if(menu_gauche->wifi == 8)
    {
        menu_gauche->Swifi = SDL_LoadBMP("./image/wifi8.bmp");
        if ( menu_gauche->Swifi == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image wifi1.",NULL);
        }
        else
        {
            menu_gauche->Twifi = SDL_CreateTextureFromSurface(ecran->renderer1,menu_gauche->Swifi);
            SDL_RenderCopy(ecran->renderer1, menu_gauche->Twifi, NULL, &menu_gauche->Rcase3);
        }
        SDL_DestroyTexture(menu_gauche->Twifi);
        SDL_FreeSurface(menu_gauche->Swifi);
    }

    if (input->mode_pilotage == 1)
    {
        ecran->Szozor = SDL_LoadBMP("./image/zozor.bmp");
        if (ecran->Szozor == NULL)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Erreur","Erreur: Impossible de charger l'image fond1.",NULL);
        }
        else
        {
            //Affichage image de fond
            ecran->Tzozor = SDL_CreateTextureFromSurface(ecran->renderer1,ecran->Szozor);
            SDL_RenderCopy(ecran->renderer1,ecran->Tzozor ,NULL,&ecran->zozor);
        }

    SDL_DestroyTexture(ecran->Tzozor);
    SDL_FreeSurface(ecran->Szozor);
    }

    SDL_RenderPresent(ecran->renderer1);

    SDL_DestroyTexture(menu_gauche->Tcase2);
    SDL_FreeSurface(menu_gauche->Scase2);

    SDL_DestroyTexture(menu_droit->TVlumiere);
    SDL_FreeSurface(menu_droit->SVlumiere);

    //Fonction temps
    SDL_DestroyTexture(menu_gauche->Tcase1);
    SDL_FreeSurface(menu_gauche->Scase1);
    SDL_DestroyTexture(menu_gauche->Ttime);
    SDL_FreeSurface(menu_gauche->Stime);
    SDL_DestroyTexture(menu_gauche->Tchronoapp);
    SDL_FreeSurface(menu_gauche->Schronoapp);



    SDL_DestroyTexture(ecran->TimageFond_1);
    SDL_FreeSurface(ecran->SimageFond_1);

}

void camera_camera(camera *camera, menu_haut *menu_haut)
{
    // if(ping \\Rasperry ok)
    // &&
    if (menu_haut->statueCAM == 1)
    {
        //Activer la camera


    }
}
