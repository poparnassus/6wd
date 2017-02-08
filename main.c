#include "prototype.h"
#include "reseau.h"

int main(int argc, char** argv)
{
    system("start /MIN .\\scan_reseau.bat");

    //Chrono Application
    chronoapp = time (NULL);
    tm_chronoapp = localtime (&chronoapp);
    //declaration des structures
    ecran ecran;
    Input input;
    menu_bas menu_bas;
    menu_gauche menu_gauche;
    menu_droit menu_droit;
    menu_haut menu_haut;
    camera camera;

    /*
    //Strcuture Reseau
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;

    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0 );
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);
    bind(sock,(SOCKADDR *) &sin, sizeof(sin));
    listen(sock, 0);
    */

    //Initialisation des structures
    init_structure( &ecran, &input, &menu_bas, &menu_gauche, &menu_droit, &menu_haut, &camera);
    //Init SDL2 et SDL_TTF
    initialisation("Programme Wild Thumper: Station de pilotage",&input, &ecran);

     while (!input.quitter)
    {
        updateEvent( &input, &ecran, &menu_gauche);

        pilotage(&input,&ecran, &menu_droit, &menu_haut, &menu_gauche, &menu_bas); //Definition des variables, et mise a jour position image.

        chargement_image(&input, &ecran, &menu_droit, &menu_haut, &menu_gauche, &menu_bas, &camera);


        if (menu_haut.statueCAM == 1)
        {
            camera_camera(&camera, &menu_haut);
        }

        send_data_pilotage (&input);


        //print_data(&input, &menu_droit, &menu_gauche);
       SDL_Delay(1);
    }
    /*
    closesocket(csock);
    closesocket(sock);
    WSACleanup();
    */
    cleanup(&input, &ecran, &menu_bas, &menu_gauche, &menu_droit, &menu_haut, &camera);
    //system("del .\\resultat_Scan_reseau.txt");
    return 0;
}
