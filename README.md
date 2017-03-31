# This is my readme file, by Huy Nguyen
Raspberry Pi acoustic sensor project

This project will turn a raspberry Pi 3 into an acoustic sensor.


1. Configuration
----------------
1.1 Hardward configuration

A raspberry Pi 3 is recommended. If a older version of Pi is used, corresponding configuration might be changed.

The Pi is mounted with a USB sound card, and plugged in a microphone.

It is recommended to have Ethernet connection for your Pi.

1.2 Software configuration

The USB sound card has to be set as default audio device. To do so, you need to modify files with following contents.
- Type "lsusb" in console and check USD.
- Use command: "sudo nano /etc/asound.conf" and type:
	pcm.!default {
		type plug
		slave {
			pcm "hw:1,0"
		}
	}
	ctl.!default {
	type hw
	card 1
	}
- Use command nano .asoundrc and put the same content.
- Finally, Run alsamixer and check USB sound card as the default audio device.
If you are using Raspian Jessie, you have to roll-back alsa-utils to an early vesion.


2. Acoustic Sensor
------------------
2.1 Introduction
Have you ever heard about the acoustic electrical divice? 
An acoustic sensor is the electric device which can measure te sound level accurately. This project is about using Raspberry Pi 3 as a 
sound sensor after setting. Moreover it actually works as a recording device.

2.2 Operation
Firstly inserting USB sound card and also headphone in. The Raspberry Pi 3 inputs the sound from microphone and displays sound level to the screen.
Using UTF-8 as compromise character encoding system - Character 2590th as the appearance of the sound level graph.
The graph changes due to the sound level, the louder the sound the higher the peak.

3. Bug dealing
---------------
There will be a bug whi make the program doesn't stop. In order stop, we need to add contents into C files.


4. Warning
----------------
To stop the application, remember to use "ctrl C". There will be a problem if stopping the audio with "ctrl Z".
"Ctrl Z" is not to stop the audio record, the recording function would keep running and cause problem.
To fix the problem: type "ps" command and check if the audio still run.
Next, use "fg" command to stop the current job.

 

