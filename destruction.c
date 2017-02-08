#include "prototype.h"
/*
Destruction de toute les surfaces et les textures !!
*/

void cleanup(Input *input, ecran *ecran, menu_bas *menu_bas, menu_gauche *menu_gauche, menu_droit *menu_droit, menu_haut *menu_haut, camera *camera)
{
    //Structure ecran
    {
    SDL_DestroyTexture(ecran->TimageFond_1); //Image de fond
    SDL_FreeSurface(ecran->SimageFond_1); // Image de fond

    SDL_DestroyTexture(camera->TimageFondCam);
    SDL_FreeSurface(camera->SimageFondCam);
    }

    //Structure menu_bas
    {
    SDL_DestroyTexture(menu_bas->TbouttonA);
    SDL_FreeSurface(menu_bas->SbouttonA);

    SDL_DestroyTexture(menu_bas->TbouttonB);
    SDL_FreeSurface(menu_bas->SbouttonB);

    SDL_DestroyTexture(menu_bas->TbouttonY);
    SDL_FreeSurface(menu_bas->SbouttonY);

    SDL_DestroyTexture(menu_bas->TbouttonX);
    SDL_FreeSurface(menu_bas->SbouttonX);

    SDL_DestroyTexture(menu_bas->TJoy1);
    SDL_FreeSurface(menu_bas->SJoy1);

    SDL_DestroyTexture(menu_bas->TJoy11);
    SDL_FreeSurface(menu_bas->SJoy11);

    SDL_DestroyTexture(menu_bas->TJoy12);
    SDL_FreeSurface(menu_bas->SJoy12);

    SDL_DestroyTexture(menu_bas->TJoy13);
    SDL_FreeSurface(menu_bas->SJoy13);

    SDL_DestroyTexture(menu_bas->TJoy2);
    SDL_FreeSurface(menu_bas->SJoy2);

    SDL_DestroyTexture(menu_bas->TJoy21);
    SDL_FreeSurface(menu_bas->SJoy21);

    SDL_DestroyTexture(menu_bas->TJoy22);
    SDL_FreeSurface(menu_bas->SJoy22);

    SDL_DestroyTexture(menu_bas->TJoy23);
    SDL_FreeSurface(menu_bas->SJoy23);
    }


    //Menu_gauche
    {
    SDL_DestroyTexture(menu_gauche->Tcase1);
    SDL_FreeSurface(menu_gauche->Scase1);
    SDL_DestroyTexture(menu_gauche->Tcase2);
    SDL_FreeSurface(menu_gauche->Scase2);
    SDL_DestroyTexture(menu_gauche->Tcase3);
    SDL_FreeSurface(menu_gauche->Scase3);
    SDL_DestroyTexture(menu_gauche->Tcase4);
    SDL_FreeSurface(menu_gauche->Scase4);
    SDL_DestroyTexture(menu_gauche->Tcase5);
    SDL_FreeSurface(menu_gauche->Scase5);
    SDL_DestroyTexture(menu_gauche->Tcase6);
    SDL_FreeSurface(menu_gauche->Scase6);

    SDL_DestroyTexture(menu_gauche->Twifi);
    SDL_FreeSurface(menu_gauche->Swifi);
    }

    //Menu_droit
    {
    SDL_DestroyTexture(menu_droit->TVlumiere);
    SDL_FreeSurface(menu_droit->SVlumiere);
    }

    //Menu_haut
    {
    SDL_DestroyTexture(menu_haut->TVjoystick);
    SDL_FreeSurface(menu_haut->SVjoystick);

    SDL_DestroyTexture(menu_haut->TstatueCAM);
    SDL_FreeSurface(menu_haut->SstatueCAM);
    }

    SDL_DestroyRenderer(ecran->renderer1);
    SDL_DestroyWindow(ecran->screen1);

    TTF_CloseFont(ecran->police);
    SDL_JoystickClose(input->joystick);
    TTF_Quit();
    SDL_Quit();
}
