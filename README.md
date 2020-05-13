# Picture oscillator

## About
Picture is an oscillator module that draws pictures on an XY-mode oscilloscope using [lissa delay](https://github.com/boochow/lissa).

Multiple pictures can be included in a single module. You can select one with the Shift-shape knob.

The shape knob squashes the picture. It affects the sound in a way similar to PWM.

Edit `figure.h` to show your own picture on an oscilloscope. It's easy!

Picture works on any logue-sdk compatible hardware.

## Drawing pictures

It is known that the pair of synchronized two waveforms can draw a picture on an XY-mode oscilloscope screen. However, the logue-sdk oscillator is single-channel and is not able to generate two waveforms at once. 

I use Lissa delay, a 90 degrees delay, to generate two signals from a single signal.

![top-page](https://raw.githubusercontent.com/boochow/picture/images/fig1.png)

The main idea of Picture OSC is to place the X signal and the Y signal in a different phase of a single waveform. 
The Y signal is placed at the first quarter of waveform. The X signal is placed at the fourth quarter.
Then Lissa delay aligns them to the same phase by delaying the signal for a quarter of the wavelength.

![top-page](https://raw.githubusercontent.com/boochow/picture/images/fig2.png)

The first quarter of the Y signal is copied to the X signal of the second quarter. 
The Y signal of the second quarter (which is also the X signal of the third quarter) could be -X of the first quarter to draw the same picture of the first quarter with 90 degrees rotation.

![top-page](https://raw.githubusercontent.com/boochow/picture/images/fig3.png)

The result would be four same pictures rotated by 90 degrees.

## Synchronizing the tone pitch and the delay time

Althogh playing music with the sound of Picture OSC is possible, there is an issue for drawing pictures while playing music.

To draw a stable figure, the delay time must always be a quarter of the wavelength precisely. However, there is no way for the delay module to get the current pitch value of the oscillator module.

To solve this, I used a MIDI signal processor plugin software on PC, which converts MIDI note number to MIDI control change for delay time (CC#30).
The MIDI filter I used is midiNotesToCC in [Piz MIDI Plugins](https://www.kvraudio.com/forum/viewtopic.php?t=300566).
![top-page](https://raw.githubusercontent.com/boochow/picture/images/fig4.png)

