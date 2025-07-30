# DAI  David's Artificial Intelligence (v0.3)

**DAI** (gesprochen wie Day) ist ein persönlicher, lokal laufender KI-Assistent in C++.  
Inspiriert von **J.A.R.V.I.S.** aus *Iron Man* ist DAI dein digitaler Butler  reagiert auf Spracheingaben, antwortet mit Sprachausgabe und führt echte Windows-Befehle aus.

---

##  Features nach Version

###  v0.1  Foundation
- Textbasiertes Terminal-Interface (`std::cin`)
- Erste einfache Befehlserkennung:
  - `wie viel uhr haben wir`
  - `oeffne chrome`
  - `beenden`
- Nur Textausgabe über `std::cout`

---

###  v0.2  Sprach-Ausgabe & mehr Befehle
-  **Sprachausgabe** über PowerShell + `System.Speech.Synthesis` (Microsoft SAPI)
-  Zufällige Begrüßungen beim Start (`"DAI meldet sich zum Dienst"`, etc.)
-  Aktuelle Uhrzeit mit natürlicher Formulierung (`"Es ist 17:42 Uhr, Sir."`)
-  Erweiterte Befehlserkennung:
  - `oeffne chrome`
  - `oeffne opera`
  - `oeffne explorer`
  - `oeffne rechner`
  - `oeffne cmd`
  - `wie viel uhr haben wir`
  - `beenden`
- Sprachliche Rückmeldung zu jeder Aktion
- Modularer Code  vorbereitet für Spracheingabe

---

###  v0.3  Spracheingabe integriert
-  **Spracheingabe** via [Whisper](https://github.com/openai/whisper)
-  Kommunikation zwischen Python (Sprache) & C++ (Logik)
-  Voice-Steuerung aller bisherigen Befehle
-  Mehrere Verabschiedungen werden erkannt (`tschüss`, `exit`, `verlassen`, ...)
-  Logging über `command.txt`

---

##  Roadmap (Zukunft)

###  v0.4  GUI & Kontextverständnis
-  Eigene GUI (z.B. Qt oder WinAPI)
-  Kommando-Ketten (z.B. öffne chrome und spiele Musik)
-  Kontextspeicher / einfache KI-Logik
-  Konfigurierbare Stimme, Sprache, Geschwindigkeit

###  v0.5  Vision & Kamera
-  OpenCV-Integration für Objekterkennung
-  Gesichtserkennung & Begrüßung
-  Kamera-Input als neuer Kanal
-  QR, Farbe, Text erkennen

###  v1.0  DAI 24/7
-  System-Tray-App oder Hintergrunddienst
-  Always-on  reagiert auf Sprachaktivierung
-  Nur autorisierte Nutzer (lokale Sicherheit)
-  100% Offline-fähig  keine Cloud nötig

---

##  Voraussetzungen

- Windows 10 oder 11
- [Python](https://www.python.org/) + Whisper (`pip install git+https://github.com/openai/whisper.git`)
- Git
- C++ Compiler (z.B. MSVC mit CMake)
- PowerShell aktiviert

---

##  Schnellstart

```bash
git clone https://github.com/dev-dawud/DAI.git
cd DAI
