#include "prototype.h"

//Evenement Clavier-Joystick
void updateEvent( Input *input, ecran *ecran, menu_gauche *menu_gauche)
{
    static SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                {
                    input->quitter = 1;
                }

            }
            if (e.type == SDL_WINDOWEVENT)
            {
                if (e.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    input->quitter = 1;
                }
            }
            //Si un bouton de la souris est pressee
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    input->sourisBG = 1;
                }
                else if (e.button.button == SDL_BUTTON_RIGHT)
                {
                    input->sourisBD = 1;
                }

            }
            //Si un bouton de la souris est relache
            else if(e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    input->sourisBG = 0;

                }
                else if (e.button.button == SDL_BUTTON_RIGHT)
                {
                    input->sourisBD = 0;
                }

            }
            if(e.type == SDL_MOUSEMOTION)
            {
                input->sourisRelX= e.motion.xrel;
                input->sourisRelY= e.motion.yrel;
                input->sourisX = e.motion.x;
                input->sourisY = e.motion.y;
                /**/
            }

            if (e.type == SDL_JOYAXISMOTION)  //ICI on gere les axes du joystique donc JGX, JGY, JDX, JDY
            {
                //Si le chapeau Gauche a détecté un mouvement
                if (e.jaxis.which == 0)
                {
                //Si le mouvement a eu lieu sur l'axe des X
                    if (e.jaxis.axis == 0)
                    {
                        //Si l'axe des X est neutre ou à l'intérieur de la "dead zone", je recupere J0X
                        if ((e.jaxis.value > input->DEADZONE_N) && (e.jaxis.value < input->DEADZONE_P))
                        {
                            input->JGX = 0;
                            input->JGX_Mx = (100 * input->JGX) / input->JGX_Max;

                        }
                        else
                        {
                            if (e.jaxis.value < input->DEADZONE_N)
                            {
                                input->JGX = e.jaxis.value - input->DEADZONE_N;
                                input->JGX_Mx = (100 * input->JGX) / input->JGX_Max;

                            }
                            else if (e.jaxis.value > input->DEADZONE_P)
                            {
                                input->JGX = e.jaxis.value - input->DEADZONE_P ;
                                input->JGX_Mx = (100 * input->JGX) / input->JGX_Max;

                            }
                        }
                    }
                    //Si le mouvement a eu lieu sur l'axe des Y, je recupere J0Y
                    else if (e.jaxis.axis == 1)
                    {
                        //Si l'axe des Y est neutre ou à l'intérieur de la "dead zone"
                        if ((e.jaxis.value > input->DEADZONE_N) && (e.jaxis.value < input->DEADZONE_P))
                        {
                            input->JGY = 0;
                            input->JGY_Mx = (100 * input->JGY) / input->JGY_Max;

                        }
                        else
                        {
                            if (e.jaxis.value < input->DEADZONE_N)
                            {
                                input->JGY = -(e.jaxis.value - input->DEADZONE_N);
                                input->JGY_Mx = (100 * input->JGY) / input->JGY_Max;

                            }
                            else if (e.jaxis.value > input->DEADZONE_P)
                            {
                                input->JGY = -(e.jaxis.value - input->DEADZONE_P);
                                input->JGY_Mx = (100 * input->JGY) / input->JGY_Max;

                            }
                        }
                    }
                    //Si le mouvement a eu lieu sur l'axe des X
                    if (e.jaxis.axis == 2)
                    {
                        //Si l'axe des X est neutre ou à l'intérieur de la "dead zone", je recupere J0X
                        if ((e.jaxis.value > input->DEADZONE_N) && (e.jaxis.value < input->DEADZONE_P))
                        {
                            input->JDX = 0;
                            input->JDX_Mx = (100 * input->JDX) / input->JDX_Max;

                        }
                        else
                        {
                            if (e.jaxis.value < input->DEADZONE_N)
                            {
                                input->JDX = e.jaxis.value - input->DEADZONE_N;
                                input->JDX_Mx = (100 * input->JDX) / input->JDX_Max;

                            }
                            else if (e.jaxis.value > input->DEADZONE_P)
                            {
                                input->JDX = e.jaxis.value - input->DEADZONE_P;
                                input->JDX_Mx = (100 * input->JDX) / input->JDX_Max;

                            }
                        }
                    }
                    //Si le mouvement a eu lieu sur l'axe des Y, je recupere J0Y
                    else if (e.jaxis.axis == 3)
                    {
                        //Si l'axe des Y est neutre ou à l'intérieur de la "dead zone"
                        if ((e.jaxis.value > input->DEADZONE_N) && (e.jaxis.value < input->DEADZONE_P))
                        {
                            input->JDY = 0;
                            input->JDY_Mx = (100 * input->JDY) / input->JDY_Max;

                        }
                        else
                        {
                            if (e.jaxis.value < input->DEADZONE_N)
                            {
                                input->JDY = -(e.jaxis.value - input->DEADZONE_N);
                                input->JDY_Mx = (100 * input->JDY) / input->JDY_Max;

                            }
                            else if (e.jaxis.value > input->DEADZONE_P)
                            {
                                input->JDY = -(e.jaxis.value - input->DEADZONE_P);
                                input->JDY_Mx = (100 * input->JDY) / input->JDY_Max;

                            }
                        }
                    }
                }
            }

            if (e.type == SDL_JOYBUTTONDOWN) //ICI on gere les bouttons BOUTTON APPUYER
            {
                if (e.jbutton.button == 10)
                {
                    input->BOUTTON_A = 1;
                }
                else if (e.jbutton.button == 11)
                {
                    input->BOUTTON_B = 1;
                }
                else if (e.jbutton.button == 12)
                {
                    input->BOUTTON_X = 1;
                }
                else if (e.jbutton.button == 13)
                {
                    input->BOUTTON_Y = 1;
                }
                else if (e.jbutton.button == 8)
                {
                    input->BOUTTON_LB = 1;
                    input->mode_pilotage =1;
                }
                else if (e.jbutton.button == 9)
                {
                    input->BOUTTON_RB =1 ;
                }
                else if ( e.jbutton.button == 4)
                {
                    input->BOUTTON_START=1;
                }
                else if (e.jbutton.button == 5)
                {
                    input->BOUTTON_BACK = 1;
                }
            }
            else if (e.type == SDL_JOYBUTTONUP)
            {
                 if (e.jbutton.button == 10)
                {
                    input->BOUTTON_A = 0;
                }
                else if (e.jbutton.button == 11)
                {
                    input->BOUTTON_B = 0;
                }
                else if (e.jbutton.button == 12)
                {
                    input->BOUTTON_X = 0;
                }
                else if (e.jbutton.button == 13)
                {
                    input->BOUTTON_Y = 0;
                }
                else if (e.jbutton.button == 8)
                {
                    input->BOUTTON_LB = 0;
                }
                else if (e.jbutton.button == 9)
                {
                    input->BOUTTON_RB =0;
                }
                else if ( e.jbutton.button == 4)
                {
                    input->BOUTTON_START=0;
                }
                else if (e.jbutton.button == 5)
                {
                    input->BOUTTON_BACK = 0;
                }
            }
        }
}

