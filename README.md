# 🎰 Excuse Generator — ESP32 + LCD 16×2 + Joystick

Un générateur d'excuses aléatoires piloté par joystick, affiché sur un écran LCD 16×2.

---

## 📦 Matériel nécessaire

- ESP32 DevKit V1 (30 pins)
- LCD 16×2 (sans I2C)
- Joystick Elegoo (module analogique avec bouton)
- 1 résistance (470Ω à 2kΩ) pour le contraste LCD
- Câbles Dupont

---

## 🗂️ Structure du projet

```
excuse-generator/
├── README.md
├── BRANCHEMENT.md
└── excuse_generator.ino
```

---

## ⚙️ Installation

### 1. Arduino IDE

- Installer [Arduino IDE](https://www.arduino.cc/en/software)
- Ajouter le support ESP32 : `Fichier > Préférences > URLs supplémentaires` :
  ```
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```
- Puis : `Outils > Type de carte > Gestionnaire de cartes` → chercher **esp32** → Installer

### 2. Bibliothèque LCD

- `Croquis > Inclure une bibliothèque > LiquidCrystal` (incluse par défaut dans Arduino IDE)

### 3. Upload

- Brancher l'ESP32 en USB
- Sélectionner : `Outils > Carte > ESP32 Dev Module`
- Sélectionner le bon port COM
- Cliquer sur **Téléverser**

---

## 🕹️ Utilisation

| Action | Résultat |
|---|---|
| Joystick ⬆️ Haut | Excuse catégorie **Réveil / Sommeil** |
| Joystick ⬇️ Bas | Excuse catégorie **Transport** |
| Joystick ⬅️ Gauche | Excuse catégorie **Objets perdus** |
| Joystick ➡️ Droite | Excuse catégorie **Famille / Urgence** |
| Bouton (appui) | **Nouvelle excuse aléatoire** dans la même direction |
| Retour au centre | Prêt pour une nouvelle direction |

---

## 📋 Catégories d'excuses

### ⬆️ Réveil / Sommeil
- Reveil en panne
- Alarm pas sonnee
- Trop fatigue hier
- Nuit difficile
- Dodo prolonge :/

### ⬇️ Transport
- Embouteillages!
- Bus en retard...
- Accident sur A8
- Travaux sur route
- Trafic dense...

### ⬅️ Objets perdus
- Clefs perdues!!
- Portable oublie
- Sac introuvable
- Chaussure perdue
- Manteau oublie!

### ➡️ Famille / Urgence
- Enfant malade...
- Medecin urgent
- Urgence familiale
- Appel important
- Famille d'abord

---

## ⚠️ Points importants

- **GPIO 12** est un strapping pin sur l'ESP32 — ne pas l'utiliser pour le LCD
- **V0 du LCD** doit avoir une résistance vers GND (pas un fil direct) pour le contraste
- Les excuses sont limitées à **32 caractères** (2 lignes × 16 caractères)

---

## 🔧 Dépannage

| Problème | Solution |
|---|---|
| Blocs noirs, pas de texte | Ajuster la résistance sur V0 |
| Texte bizarre / aléatoire | Vérifier l'ordre des fils D4–D7 |
| Rien ne s'affiche | Vérifier 5V sur VDD et rétroéclairage |
| Joystick ne répond pas | Vérifier les seuils `SEUIL_*` avec le moniteur série |
| ESP32 ne boote pas | Vérifier que GPIO 12 n'est pas utilisé ou essayer de débrancher puis rebrancher le câble usb C|

---

## 👤 Auteur

Projet réalisé avec ESP32 + Arduino IDE.
