#include <iostream>     // Für Ein und Ausgabe cout , cin
#include <string>       // Für std::string
#include <cstdlib>      // Für system()  Programme starten, PowerShell verwenden
#include <vector>       // Für Vektoren (aktuell nicht aktiv genutzt)
#include <chrono>       // Für Zeitfunktionen (Systemzeit)
#include <ctime>        // Für Umwandlung in Zeitformat
#include <sstream>      // Optional: für späteres Stringstreaming (nicht genutzt)
#include <iomanip>      // Optional: für Formatierung (nicht genutzt)


// 🧠 Globale Variablen
std::string user_eingabe, dai_antwort, micIn;     // User Eingabe , Dai Antwort , Mikro Eingabe
std::vector<std::string> dai_sprech;              // Noch leer kann für Gesprächslogik genutzt werden

std::vector<std::string> begruessung = {

 	"Hallo Sir, ich bin DAI Ihre digitale Assistenz.",
    "DAI meldet sich zum Dienst.",
    "System hochgefahren. Bereit, Sir.",
    "Alle Systeme laufen. Auf Ihre Befehle wartend.",
    "Schön, Sie wiederzusehen, Commander."
};

// Funktion für Sprachausgabe über PowerShell (Microsoft SAPI)
void dai_sprachausgabe(const std::string& text, const std::string& stimme = "Microsoft Zira Desktop") {
    // Baue PowerShell-Befehl zusammen Nutzt SAPI zur Sprachausgabe
    std::string befehl = "powershell -Command \""
        "Add-Type -AssemblyName System.Speech; "                     // Lade Sprachmodul
        "$s = New-Object System.Speech.Synthesis.SpeechSynthesizer; " // Erstelle Sprachobjekt
        "$s.SelectVoice('" + stimme + "'); "                         // Wähle Stimme
        "$s.Volume = 100; "                                          // Lautstärke auf 100 %
        "$s.Rate = 0; "                                              // Neutrale Geschwindigkeit
        "$s.Speak('" + text + "');\"";                               // Sag den Text
    system(befehl.c_str());                                          // Führe den Befehl aus
}


// Funktion für aktuelle Uhrzeit als String zurückzugeben
std::string getUhrzeitAlsString() {
    auto now = std::chrono::system_clock::now();         // Aktuelle Zeit
    std::time_t jetzt = std::chrono::system_clock::to_time_t(now); // In time_t konvertieren
    std::tm* local_tm = std::localtime(&jetzt);          // In lokale Zeit umwandeln

    char buffer[6];                                      // HH:MM → 5 Zeichen + \0
    std::strftime(buffer, sizeof(buffer), "%H:%M", local_tm); // Formatieren

    return std::string(buffer);                          // Als std::string zurückgeben
}


// Hauptprogramm
int main() {
    std::string time;

	srand(std::time(NULL));  // Zufallszahl initialisieren
	int index = rand() % begruessung.size();
	std::cout << begruessung[index] << std::endl;
	dai_sprachausgabe(begruessung[index]);

    // DAI Begrüßung
    std::cout << "***************************\n\n";
    std::cout << "Hallo Sir, Ich bin DAI\n";
    std::cout << "\n***************************\n";

    // Hauptloop bis "beenden" eingegeben wird
    while (true) {
        std::cout << "\nIch: ";
        getline(std::cin, user_eingabe);   // Eingabe lesen

        // Uhrzeit-Abfrage
        if (user_eingabe == "wie viel uhr haben wir") {
            std::string zeit = getUhrzeitAlsString();    // Uhrzeit holen
            dai_antwort = "Die Zeit ist relativ… aber aktuell ist es " + zeit + " Uhr, Sir."; // Antwort formulieren

            std::cout << "DAI: " << dai_antwort << std::endl;
            dai_sprachausgabe(dai_antwort);              // DAI spricht
        }

        // Opera starten
        else if (user_eingabe == "oeffne opera") {
            dai_antwort = "Opera wird fuer sie geoeffnet";
            std::cout << "DAI: Opera wird geoeffnet..." << std::endl;
            dai_sprachausgabe(dai_antwort);
            system("start opera");                       // Opera öffnen
        }

        // Chrome starten
        else if (user_eingabe == "oeffne chrome") {
            dai_antwort = "Chrome wird fuer sie geoeffnet";
            std::cout << "DAI: Oeffne Chrome..." << std::endl;
            dai_sprachausgabe(dai_antwort);
            system("start chrome");
        }

        // Programm beenden
        else if (user_eingabe == "beenden") {
            dai_antwort = "Auf Wiedersehen, Sir!";
            std::cout << "DAI: " << dai_antwort << std::endl;
            dai_sprachausgabe(dai_antwort);
            break;                                       // while-Schleife verlassen
        }
		else if (user_eingabe == "oeffne datei"){
			dai_antwort = "Navigiere durch deine Datenwelt";
			std::cout << "DAI: " << dai_antwort << std::endl;
			dai_sprachausgabe(dai_antwort);
			system("start explorer");

		}
		else if (user_eingabe == "oeffne cmd") {
    		dai_antwort = "Öffne die Kommandozentrale.";
    		std::cout << "DAI: " << dai_antwort << std::endl;
    		dai_sprachausgabe(dai_antwort);
    		system("start cmd");
		}
		else if (user_eingabe == "oeffne rechner") {
		    dai_antwort = "Der Rechner wird gestartet.";
    		std::cout << "DAI: " << dai_antwort << std::endl;
    		dai_sprachausgabe(dai_antwort);
    		system("start calc");
		}
        // Unbekannter Befehl
        else {
            std::cout << "DAI: Befehl nicht erkannt. Versuchen Sie: oeffne chrome, beenden, etc." << std::endl;
        }
    }

    return 0; // Rückgabewert für das Betriebssystem (0 = alles ok)
}
