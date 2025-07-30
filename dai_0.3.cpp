#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <thread>
#include <algorithm> // für std::transform

// === Pfade (nur hier musst du was ändern, falls sich etwas verschiebt) ===
const std::string basePath = "D:/David/DAI/DAI/";
const std::string python = "C:/Users/David/AppData/Local/Programs/Python/Python311/python.exe";

// === Globale Variablen ===
std::string user_eingabe, dai_antwort;
std::vector<std::string> dai_sprech;

std::vector<std::string> begruessung = {
    "Hallo Sir, ich bin DAI Ihre digitale Assistenz.",
    "DAI meldet sich zum Dienst.",
    "System hochgefahren. Bereit, Sir.",
    "Alle Systeme laufen. Auf Ihre Befehle wartend.",
    "Schön, Sie wiederzusehen, Commander."
};

// === Uhrzeit als String zurückgeben ===
std::string getUhrzeitAlsString() {
    auto now = std::chrono::system_clock::now();
    std::time_t jetzt = std::chrono::system_clock::to_time_t(now);
    std::tm* local_tm = std::localtime(&jetzt);
    char buffer[6];
    std::strftime(buffer, sizeof(buffer), "%H:%M", local_tm);
    return std::string(buffer);
}

// === Text-to-Speech über Python ===
void speakWithFlorian(const std::string& text) {
    std::string script = basePath + "tts_florian.py";
    std::string command = python + " \"" + script + "\" \"" + text + "\"";
    system(command.c_str());
}

// === Sprachaufnahme + Whisper-Auswertung ===
bool getSpeechInput(std::string& input) {
    std::string speech_script = basePath + "speech_to_text.py";
    std::string command = python + " \"" + speech_script + "\"";
    system(command.c_str());

    std::ifstream commandFile("command.txt");
    if (commandFile) {
        std::getline(commandFile, input);
        commandFile.close();
        return true;
    } else {
        std::cerr << "Fehler: konnte Sprachkommando nicht lesen." << std::endl;
        return false;
    }
}

// === Hauptprogramm ===
int main(int argc, char* argv[]) {
    if (argc == 1) {
        system(("start \"\" \"" + basePath + "dai_0.3.exe\" --no-restart").c_str());
        return 0;
    }

    srand(std::time(NULL));
    int index = rand() % begruessung.size();
    std::cout << begruessung[index] << std::endl;
    speakWithFlorian(begruessung[index]);

    std::cout << "***************************\n\n";
    std::cout << "Hallo Sir, Ich bin DAI\n";
    std::cout << "\n***************************\n";

    while (true) {
        std::cout << "\n🎙️  Sprechen Sie jetzt (DAI hört zu...)\n";

        if (!getSpeechInput(user_eingabe)) {
            continue;
        }

        // Eingabe in Kleinbuchstaben umwandeln
        std::transform(user_eingabe.begin(), user_eingabe.end(), user_eingabe.begin(), ::tolower);
        std::cout << "Ich (per Sprache): " << user_eingabe << std::endl;

        // === Befehle analysieren ===
        if (user_eingabe.find("uhr") != std::string::npos) {
            std::string zeit = getUhrzeitAlsString();
            dai_antwort = "Die Zeit ist relativ… aber aktuell ist es " + zeit + " Uhr, Sir.";
        } 
        else if (user_eingabe.find("chrome") != std::string::npos) {
            dai_antwort = "Chrome wird fuer Sie geoeffnet.";
            system("start chrome");
        } 
        else if (user_eingabe.find("opera") != std::string::npos) {
            dai_antwort = "Opera wird fuer Sie geoeffnet.";
            system("start opera");
        } 
        else if (user_eingabe.find("datei") != std::string::npos || user_eingabe.find("explorer") != std::string::npos) {
            dai_antwort = "Navigiere durch Ihre Datenwelt.";
            system("start explorer");
        } 
        else if (user_eingabe.find("cmd") != std::string::npos || user_eingabe.find("konsole") != std::string::npos) {
            dai_antwort = "Öffne die Kommandozentrale.";
            system("start cmd");
        } 
        else if (user_eingabe.find("rechner") != std::string::npos) {
            dai_antwort = "Der Rechner wird gestartet.";
            system("start calc");
        } 
        else if (user_eingabe.find("beenden") != std::string::npos || 
                 user_eingabe.find("tschüss") != std::string::npos || 
                 user_eingabe.find("tschuss") != std::string::npos || 
                 user_eingabe.find("exit") != std::string::npos || 
                 user_eingabe.find("verlassen") != std::string::npos) {

            dai_antwort = "Auf Wiedersehen, Sir!";
            std::cout << "DAI: " << dai_antwort << std::endl;
            speakWithFlorian(dai_antwort);
            break;
        } 
        else {
            dai_antwort = "Befehl nicht erkannt. Versuchen Sie es erneut.";
        }

        // Antwort sprechen (außer beim Beenden, das wurde schon oben gemacht)
        if (user_eingabe.find("beenden") == std::string::npos &&
            user_eingabe.find("tschüss") == std::string::npos &&
            user_eingabe.find("tschuss") == std::string::npos &&
            user_eingabe.find("exit") == std::string::npos &&
            user_eingabe.find("verlassen") == std::string::npos) {
                
            std::cout << "DAI: " << dai_antwort << std::endl;
            speakWithFlorian(dai_antwort);
        }
    }

    return 0;
}
