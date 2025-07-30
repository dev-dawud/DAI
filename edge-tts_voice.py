import edge_tts
import asyncio
import os

text = "Hallo Sir, ich bin DAI. Bereit für neue Befehle."
voice = "de-DE-FlorianMultilingualNeural"

async def speak():
    communicate = edge_tts.Communicate(text, voice)
    await communicate.save("dai_edge_voice.mp3")

asyncio.run(speak())
os.system("start dai_edge_voice.mp3")
