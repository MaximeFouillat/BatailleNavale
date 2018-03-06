int boucle = 0;
//variables
int mode = 0;     // mode dans le programme

//variables Joueur 1
int led_J1[30];// tableau de constantes des LED J1
int sensor_J1[30]; //tableau de constantes des sensors J1
int pave_num_J1[16];
int cases_disponibles[30];

//variables Joueur 2
int led_J2[30] ;// tableau de constantes des LED J2
int sensor_J2[30] ; //tableau de constantes des sensors J2



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
  allumer_radar_principal_J1("b"); // allume radar principal J1 en bleu
  allumer_radar_secret_J1("g");  // allume radar principal J1 en gris
  allumer_radar_principal_J2("bleu");
  allumer_radar_secret_J2("gris");
  set_all_cases_disponibles_J1("true");//met toutes les cases disponibles J1 à true 
  set_all_cases_disponibles_J2("true");//met toutes les cases disponibles J2 à true
}
void allumer_radar_principal_J1(char couleur){
  Serial.println("radar principal J1 en bleu");
}
void allumer_radar_secret_J1(char couleur){
  Serial.println("radar principal J1 en gris");
}
void allumer_radar_principal_J2(char couleur){
  Serial.println("radar principal J2 en bleu");
}
void allumer_radar_secret_J2(char couleur){
  Serial.println("radar principal J2 en gris");
}
void set_all_cases_disponibles_J1(bool disponible){
  Serial.println("toutes les cases disponibles pour J1");
}
void set_all_cases_disponibles_J2(bool disponible){
  Serial.println("toutes les cases disponibles pour J2");
}
////////////////////////////////////////////////////////////////////////////

// Positionnement des bateaux //////////////////////////////////////////////
void positionner_bateaux(){
  joueur_1_place_bateau_1();
  joueur_2_place_bateau_1();
  joueur_1_place_bateau_2();
  joueur_2_place_bateau_2();
  joueur_1_place_bateau_3();
  joueur_2_place_bateau_3();
}


void joueur_1_place_bateau_1(){
    Serial.println("bateau 1 joueur 1 ok");
}
void joueur_2_place_bateau_1(){
    Serial.println("bateau 1 joueur 2 ok");
}
void  joueur_1_place_bateau_2(){
    Serial.println("bateau 2 joueur 1 ok");
}
void joueur_2_place_bateau_2(){
    Serial.println("bateau 2 joueur 2 ok");
}
void joueur_1_place_bateau_3(){
    Serial.println("bateau 3 joueur 1 ok");
}
void joueur_2_place_bateau_3(){
    Serial.println("bateau 3 joueur 2 ok");
}

////////////////////////////////////////////////////////////////////////////


// phase de jeu ////////////////////////////////////////////////////////////
void jouer() {
  joueur_1_tirer();
}
void joueur_1_tirer(){
  Serial.println("joueur 1 tire");
  int rapport_degats = get_rapport_degats();
    if(rapport_degats == 0){//raté
      Serial.println("raté !!");
      joueur_2_tirer();
    }
    if(rapport_degats == 1){//touché
      Serial.println("touché !!");
    }
    if(rapport_degats == 2){//coulé
      Serial.println("coulé !!");
    }
  }
void joueur_2_tirer(){
  Serial.println("joueur 2 tire");
  int rapport_degats = get_rapport_degats();
    if(rapport_degats == 0){//raté
      Serial.println("raté !!");
      joueur_1_tirer();
      mode = 3;
    }
    if(rapport_degats == 1){//touché
      Serial.println("touché !!");
    }
    if(rapport_degats == 2){//coulé
      Serial.println("coulé !!");
    }
  }
//rapport des dégats suite à un tir
int get_rapport_degats(){
  boucle = boucle + 1;
  int rapport_degats;
  if (boucle == 5){
    mode = 3;
    rapport_degats = 2;
    return rapport_degats;
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


