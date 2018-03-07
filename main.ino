//variables
int boucle = 0;
int mode = 0;     // mode dans le programme

//variables Joueur 1
int led_J1[30]; // tableau de constantes des LED J1
int sensor_J1[30]; //tableau de constantes des sensors J1
int pave_num_J1[16];
int cases_disponibles_J1[30];

//variables Joueur 2
int led_J2[30]; // tableau de constantes des LED J2
int sensor_J2[30];  //tableau de constantes des sensors J2
int pave_num_J2[16];
int cases_disponibles_J2[30];



void setup() {
        // initialisation des nombres aléatoires
        Serial.begin(9600);
}

void loop() {
        //les actions sont réalisées en fonction du mode en cours
        switch (mode) { //on regarde le mode
        case 0: //mode de démarrage
                Serial.println("mode 0..initialisation de la plateforme");
                start(); // appel de la fonction de démarrage
                mode = 1; // on peut passer au mode suivant
                Serial.print("passe au mode : ");
                Serial.println(mode);
                Serial.println("");

                break;
        case 1: //Positionnement des bateaux
                Serial.println("mode 1..Positionnement des bateaux");
                //augmenteSequence(); //appel de la fonction pour allonger la séquence
                positionner_bateaux();
                mode = 2; // on peut passer au mode suivant
                Serial.print("passe au mode : ");
                Serial.println(mode);
                Serial.println("");
                break;
        case 2: // mode jeu
                Serial.println("mode 2..au tour de joueur 1");
                jouer(); // on joue
                mode = 3; // on peut passer au mode suivant
                Serial.print("passe au mode : ");
                Serial.println(mode);
                Serial.println("");
                break;
        case 3: // mode fin de partie
                Serial.println("mode 3..fin du jeu");
                delay(10000);
                boucle = 0;
                mode =0;
                break;
        }
}

//-----------------------fonctions--------------------

// Initialisation du jeu //////////////////////////////////////////////////
void start() {
        allumer_radar(0, 1, "bleu"); // allume radar principal J1 en bleu
        allumer_radar(1, 1, "gris"); // allume radar secret J1 en gris
        allumer_radar(0, 2, "bleu");
        allumer_radar(1, 2, "gris");
        set_all_cases(1, true); //met toutes les cases disponibles J1 à true
        set_all_cases(2, true); //met toutes les cases disponibles J2 à true
}
void allumer_radar(int radar_type, int joueur_num, char* couleur){
        // radar_type : 0 pour principal, 1 pour secret
        char line[128];
        sprintf(line, "Radar %d du J%d en %s", radar_type, joueur_num, couleur);
        Serial.println(line);
}
void set_all_cases(int joueur_num, bool state){
        // state : 0 pour utilisées, 1 pour disponibles
        char line[128];
        sprintf(line, "Toutes les cases à l'état %d pour le J%d", state, joueur_num);
        Serial.println(line);
}

////////////////////////////////////////////////////////////////////////////

// Positionnement des bateaux //////////////////////////////////////////////
void positionner_bateaux(){
        placement_bateau(1,1);
        placement_bateau(2,1);
        placement_bateau(1,2);
        placement_bateau(2,2);
        placement_bateau(1,3);
        placement_bateau(2,3);
}

void placement_bateau(int joueur_num, int bateau_num){
        char line[128];
        sprintf(line, "Bateau %d du J%d placé", bateau_num, joueur_num);
        Serial.println(line);

}

////////////////////////////////////////////////////////////////////////////


// phase de jeu ////////////////////////////////////////////////////////////
void jouer() {
        joueur_1_tirer();
}
void joueur_1_tirer(){
        Serial.println("joueur 1 tire");
        int rapport_degats = get_rapport_degats();
        if(rapport_degats == 0) { //raté
                Serial.println("raté !!");
                joueur_2_tirer();
        }
        if(rapport_degats == 1) { //touché
                Serial.println("touché !!");
        }
        if(rapport_degats == 2) { //coulé
                Serial.println("coulé !!");
        }
}
void joueur_2_tirer(){
        Serial.println("joueur 2 tire");
        int rapport_degats = get_rapport_degats();
        if(rapport_degats == 0) { //raté
                Serial.println("raté !!");
                joueur_1_tirer();
                mode = 3;
        }
        if(rapport_degats == 1) { //touché
                Serial.println("touché !!");
        }
        if(rapport_degats == 2) { //coulé
                Serial.println("coulé !!");
        }
}
//rapport des dégats suite à un tir
int get_rapport_degats(){
        boucle = boucle + 1;
        int rapport_degats;
        if (boucle == 5) {
                mode = 3;
                rapport_degats = 2;
        }
        //si tir dans l'eau, return r
        //si c'est touché, return t
        //si c'est coulé, return
        else{
                rapport_degats = 0;
        }
        return rapport_degats;

}
////////////////////////////////////////////////////////////////////////////
