import sys
import random
import pyaudio
import wave
import serial

CHUNK = 1024

WAVES = [('griffindor.wav', 3),
         ('hufflepuff.wav', 3),
         ('ravenclaw.wav', 3),
         ('slitheryn.wav', 2)]

def fala (r):
    print(sys.argv[1])
    try:
        ser = serial.Serial(sys.argv[1], 9600)
    except:
        print ("Nao foi possivel se comunicar a porta serial passada como parametro")
        exit ()
    ser.write(chr(WAVES[r][1]))
    wf = wave.open(WAVES[r][0], 'rb')
    p = pyaudio.PyAudio()
    stream = p.open(format=p.get_format_from_width(wf.getsampwidth()),
                channels=wf.getnchannels(),
                rate=wf.getframerate(),
                output=True)
    data = wf.readframes(CHUNK)
    while data != '':
        stream.write(data)
        data = wf.readframes(CHUNK)
    stream.stop_stream()
    stream.close()
    p.terminate()
    
def onKeyPress ():
    text.insert ()

for i in range(10000):
    garbage = sys.stdin.readline ()
    r = random.random ()
    r = (int) (r * 4)
    fala (r)

