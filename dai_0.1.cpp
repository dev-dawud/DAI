#include <iostream>     // Für Ein und Ausgabe cout , cin
#include <string>       // Für die Verwendung von std::string
#include <cstdlib>      // Für system()  Programme starten, PowerShell verwenden


std::string user_eingabe;		// User Eingabe

int main() {
    // Begrüßung beim Start des Programms
    std::cout << "***************************\n\n";
    std::cout << "Hallo Sir, Ich bin DAI\n";  
    std::cout << "\n***************************\n";

    // Hauptloop bis "beenden" eingegeben wird
    while (true) {
        std::cout << "\nIch: ";               // Eingabeaufforderung
        getline(std::cin, user_eingabe);      // Liest eine ganze Zeile vom Benutzer

        // Uhrzeit abfragen
        if (user_eingabe == "wie viel uhr haben wir") {
            std::cout << "DAI: Wir haben ";
            system("time /T");                // Führt den Windows-Befehl "time /T" aus 
            std::cout << ", Sir!" << std::endl;
        }

        // Opera starten
        else if (user_eingabe == "oeffne opera") {
            std::cout << "DAI: Oeffne Opera..." << std::endl;
            system("start opera");            // Startet Opera 
        }

        // Chrome starten
        else if (user_eingabe == "oeffne chrome") {
            std::cout << "DAI: Oeffne Chrome..." << std::endl;
            system("start chrome");           // Startet Chrome
        }

        // Programm beenden
        else if (user_eingabe == "beenden") {
            std::cout << "DAI: Auf Wiedersehen, Sir!" << std::endl;
            break;                            // Beendet die while-Schleife -> Programmende
        }

        //  Unbekannter Befehl
        else {
            std::cout << "DAI: Befehl nicht erkannt. Versuchen Sie: oeffne chrome, beenden, etc." << std::endl;
        }
    }

    return 0;  // Rückgabewert für das Betriebssystem (0 = alles ok)
}
