import whisper
import sounddevice as sd
import numpy as np
import tempfile
import scipy.io.wavfile

model = whisper.load_model("medium")  # Oder "base", "small", "large", je nach Geschwindigkeit

def record_and_transcribe(duration=5, fs=44100):
    print("🎙️ Aufnahme startet... Bitte sprich.")

    # Aufnahme mit float32, besser für Whisper
    audio = sd.rec(int(duration * fs), samplerate=fs, channels=1, dtype='float32')
    sd.wait()

    # Normieren, falls zu leise
    audio = audio / np.max(np.abs(audio))

    with tempfile.NamedTemporaryFile(delete=False, suffix=".wav") as f:
        scipy.io.wavfile.write(f.name, fs, (audio * 32767).astype('int16'))  # In int16 konvertieren

        try:
            result = model.transcribe(f.name)
            return result["text"]
        except Exception as e:
            print("❌ Fehler bei der Transkription:", e)
            return ""  # Leerer String bei Fehler

if __name__ == "__main__":
    text = record_and_transcribe()
    
    if text.strip() == "":
        print("🤖 Ich konnte nichts verstehen.")
    else:
        print("💬 Verstanden:", text)
        with open("command.txt", "w", encoding="utf-8") as f:
            f.write(text.strip())
