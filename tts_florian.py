import sys
import asyncio
import edge_tts
from pydub import AudioSegment
import simpleaudio as sa  # <--- NEU
import os

async def tts(text, voice="de-DE-FlorianMultilingualNeural"):
    communicate = edge_tts.Communicate(text, voice)
    await communicate.save("output.mp3")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        text = sys.argv[1]
        asyncio.run(tts(text))

        # mp3 -> wav konvertieren
        mp3_audio = AudioSegment.from_mp3("output.mp3")
        wav_audio = mp3_audio.set_channels(2).set_frame_rate(44100)
        wav_audio.export("output.wav", format="wav")

        # 🎧 Wiedergabe mit simpleaudio
        wave_obj = sa.WaveObject.from_wave_file("output.wav")
        play_obj = wave_obj.play()
        play_obj.wait_done()  # Warten bis abgespielt

        # Aufräumen
        os.remove("output.mp3")
        os.remove("output.wav")
    else:
        print("⚠ Kein Text übergeben.")
