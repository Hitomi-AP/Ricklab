# 🔌 Branchements — Excuse Generator

ESP32 DevKit V1 (30 pins) + LCD 16×2 + Joystick Elegoo

---

## 🖥️ LCD 16×2 → ESP32

| Pin LCD | Nom | Branché sur | Note |
|---|---|---|---|
| 1 — VSS | GND | GND | |
| 2 — VDD | Alimentation | 5V | |
| 3 — V0 | Contraste | Résistance → GND | 470Ω à 2kΩ ⚠️ |
| 4 — RS | Commande | D25 | GPIO 25 |
| 5 — RW | Lecture/écriture | GND | |
| 6 — E | Enable | D26 | GPIO 26 |
| 7 — D0 | Données | Non branché | |
| 8 — D1 | Données | Non branché | |
| 9 — D2 | Données | Non branché | |
| 10 — D3 | Données | Non branché | |
| 11 — D4 | Données | D27 | GPIO 27 |
| 12 — D5 | Données | D14 | GPIO 14 |
| 13 — D6 | Données | D19 | GPIO 19 ✅ (pas D12 !) |
| 14 — D7 | Données | D13 | GPIO 13 |
| 15 — A | Rétroéclairage + | 5V | |
| 16 — K | Rétroéclairage − | GND | |

> ⚠️ **Ne jamais brancher V0 directement sur GND** — utiliser une résistance pour régler le contraste.

> 🚨 **Ne jamais utiliser GPIO 12 (D12)** pour le LCD — strapping pin, cause des problèmes au démarrage.

---

## 🕹️ Joystick Elegoo → ESP32

| Joystick | Branché sur | Note |
|---|---|---|
| GND | GND | |
| VCC | 3.3V | ⚠️ Pas 5V ! |
| VRx | D34 | GPIO 34 |
| VRy | D35 | GPIO 35 |
| SW | D32 | GPIO 32 |

> ⚠️ **VCC joystick sur 3.3V obligatoire** — les sorties VRx/VRy vont directement dans l'ESP32, qui ne tolère pas le 5V.

---

## 📊 Schéma résumé

```
              ESP32 DevKit V1
           ┌─────────────────┐
           │                 │
LCD RS ────┤ D25   (GPIO 25) │
LCD E  ────┤ D26   (GPIO 26) │
LCD D4 ────┤ D27   (GPIO 27) │
LCD D5 ────┤ D14   (GPIO 14) │
LCD D6 ────┤ D19   (GPIO 19) │  ← pas D12 !
LCD D7 ────┤ D13   (GPIO 13) │
           │                 │
JOY VRx ───┤ D34   (GPIO 34) │
JOY VRy ───┤ D35   (GPIO 35) │
JOY SW  ───┤ D32   (GPIO 32) │
           │                 │
JOY VCC ───┤ 3.3V            │
LCD VDD ───┤ 5V              │
LCD A   ───┤ 5V              │
           │                 │
LCD V0  ───┤ [résistance] ───┤ GND
LCD VSS ───┤ GND             │
LCD RW  ───┤ GND             │
LCD K   ───┤ GND             │
JOY GND ───┤ GND             │
           └─────────────────┘
```

---

## 💻 Code correspondant

```cpp
#include <LiquidCrystal.h>

//                 RS   E   D4   D5   D6   D7
LiquidCrystal lcd(25,  26,  27,  14,  19,  13);

#define JOY_X   34
#define JOY_Y   35
#define JOY_SW  32
```

---

## ✅ Checklist avant démarrage

- [ ] V0 branché via résistance (pas fil direct sur GND)
- [ ] D6 du LCD sur D19 (pas D12 pin car déjà attribuer par esp32 )
- [ ] RW du LCD sur GND
- [ ] D0 à D3 du LCD non branchés (mode 4 bits)
- [ ] 5V sur VDD et broche A du LCD
