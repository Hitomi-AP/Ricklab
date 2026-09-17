#include <LiquidCrystal.h>

LiquidCrystal lcd(25, 26, 27, 14, 19, 13);

#define JOY_X 34
#define JOY_Y 35
#define JOY_SW 32

#define SEUIL_HAUT 3000
#define SEUIL_BAS 1000
#define SEUIL_DROIT 3000
#define SEUIL_GAUCHE 1000

const char *excuses_haut[] = {
    "Reveil en panne",
    "Alarm pas sonnee",
    "Trop fatigue hier",
    "Nuit difficile",
    "Dodo prolonge :/"};

const char *excuses_bas[] = {
    "Embouteillages!",
    "Bus en retard...",
    "Accident sur A8",
    "Travaux sur route",
    "Trafic dense..."};

const char *excuses_gauche[] = {
    "Clefs perdues!!",
    "Portable oublie",
    "Sac introuvable",
    "Chaussure perdue",
    "Manteau oublie!"};

const char *excuses_droite[] = {
    "Enfant malade...",
    "Medecin urgent",
    "Urgence familiale",
    "Appel important",
    "Famille d'abord"};

String derniereDirection = "";

void afficherExcuse(const char *excuse)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    String texte = String(excuse);
    if (texte.length() <= 16)
    {
        lcd.print(texte);
    }
    else
    {
        lcd.print(texte.substring(0, 16));
        lcd.setCursor(0, 1);
        lcd.print(texte.substring(16, 32));
    }
}

const char *excuseAleatoire(const char *liste[], int taille)
{
    return liste[random(taille)];
}

void setup()
{
    pinMode(JOY_SW, INPUT_PULLUP);
    randomSeed(analogRead(0)); // Graine aléatoire via pin flottante
    delay(500);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Excuse Generator");
    lcd.setCursor(0, 1);
    lcd.print("Bougez joystick!");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pret !");
}

void loop()
{
    int x = analogRead(JOY_X);
    int y = analogRead(JOY_Y);
    bool btn = digitalRead(JOY_SW) == LOW;

    // Bouton : nouvelle excuse aléatoire dans la même direction
    if (btn && derniereDirection != "")
    {
        if (derniereDirection == "haut")
            afficherExcuse(excuseAleatoire(excuses_haut, 5));
        if (derniereDirection == "bas")
            afficherExcuse(excuseAleatoire(excuses_bas, 5));
        if (derniereDirection == "gauche")
            afficherExcuse(excuseAleatoire(excuses_gauche, 5));
        if (derniereDirection == "droite")
            afficherExcuse(excuseAleatoire(excuses_droite, 5));
        delay(400);
        return;
    }

    String direction = "";

    if (y > SEUIL_HAUT)
        direction = "haut";
    else if (y < SEUIL_BAS)
        direction = "bas";
    else if (x < SEUIL_GAUCHE)
        direction = "gauche";
    else if (x > SEUIL_DROIT)
        direction = "droite";

    // Nouvelle direction → excuse aléatoire
    if (direction != "" && direction != derniereDirection)
    {
        derniereDirection = direction;
        if (direction == "haut")
            afficherExcuse(excuseAleatoire(excuses_haut, 5));
        if (direction == "bas")
            afficherExcuse(excuseAleatoire(excuses_bas, 5));
        if (direction == "gauche")
            afficherExcuse(excuseAleatoire(excuses_gauche, 5));
        if (direction == "droite")
            afficherExcuse(excuseAleatoire(excuses_droite, 5));
    }

    if (direction == "")
    {
        derniereDirection = "";
    }

    delay(150);
}