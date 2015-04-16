#Games Programming - Lecture 08 - Audio

###Examples

- An example, state of the art, research (2010)
  - Precomputed Wave Simulation for Real-time Sound Propagation of Dynamic Sources in Complex Scenes
  - https://www.youtube.com/watch?v=MQt1jtDBNK4

- Another example, state of the art, game (2010)
  - Red Dead Redemption - Launch Trailer
  - https://www.youtube.com/watch?v=3gBctl1h_2o

###History

- http://www.gamessound.com/


# Audio

###Types Audio we're interested in

- Player perspective
  - Any audio at all,...
  - Music tracks
  - Ambient sound
  - Character Sound Effects
  - Character Speech
  - Other player audio (voice chat)

###Details

- Music tracks
  - long tracks (minutes)
  - usually pre-mixed
  - usually stereo (2-channel), sometimes multi-channel (e.g. 5.1)
  - usually monophonic (one track at a time)
  - latency to start unimportant

- Ambient sound
  - long tracks (minutes, hours) or medium tracks (seconds)
  - perhaps a long pre-mixed track
  - OR multiple short tracks mixed, ordered, played dynamically
  - Could be localized
  - usually stereo (2-channel), sometimes multi-channel (e.g. 5.1)
  - frequently polyphonic (multiple tracks at a time)
  - latency to start unimportant

- Character Sound Effects
  - usually short tracks (milliseconds -> a few seconds)
  - usually mono
  - polyphonic
  - usually polyphonic
  - mixed dynamically
  - often localized
  - latency to start **very** important
    - bullets, explosions, grunts
    - sound effect triggers occur unpredictably

- Character Speech
  - usually medium tracks (single, few words utterances could be considered sound effects)
  - usually mono
  - usually monophonic (one track at a time)
  - mixed dynamically
  - often localized
  - latency to start somewhat important
  - synchrony of playback **very** important
    - for lip-sync

- Other player audio (voice chat)
  - streaming
  - can lose the stream, suffer from delays
  - usually mono
  - can be localized
  - latency fairly important
  - synchrony to lip-sync very rare


###Dimensions to consider with Audio

- Sample rate (e.g. 44,100Hz)
- Sample depth (e.g. 8-bit int, 16bit)
- Channels
  - 1 = Mono
  - 2 = Stereo
  - 2.1 = ??
  - 4.1 = ??
  - 5.1 = ??
  - 7.1 = ??
  - ???
- Spatialisation
- Effects
- Pre-recorded or dynamically generated
- Data source location
  - local system
  - streaming
- Privacy (voice chat)


#What is Sound?

###What is Sound?

- Sound is a vibration
- Sound propagates through a medium such as air or water
- Sound is a typically an mechanical wave of pressure (or displacement)



###Perception of Sound

- Are bodies sense the pressure waves, and pass this on to the brain which processes it
  - mainly sensed through our ears
  - also through bones around the ear
  - also through our whole body, stomach, etc
- Humans can hear sound frequencies from around:
  - 20Hz to 20,000Hz (20 kHz)
  - The upper limit decreases with age and/or damage

###Amplitude (Sound pressure)

- The difference between average local pressure and the pressure in the sound wave
- usually the square of this difference (i.e., a square of the deviation from the equilibrium pressure) is usually averaged over time and/or space, and a square root of this average provides a root mean square (RMS) value.

###Attenuation

- energy loss as sound propagates
- Stokes law of sound attenuation
  - a formula for the attenuation of sound in a Newtonian fluid, such as water or air
    - due to the fluid's viscosity
  - amplitude of a plane wave decreases exponentially with distance traveled, at a rate given by

![http://upload.wikimedia.org/math/c/d/d/cdd1edea09006959325d6bbcae414f07.png](http://upload.wikimedia.org/math/c/d/d/cdd1edea09006959325d6bbcae414f07.png)


```
===

2 x dynamicViscosityCoefficient x soundFrequency(squared)

     /

3 x fluidDensity x speedOfSoundInTheMedium(cubed)
```


###Speed of sound

- Sound propagates relatively slowly (compared to the speed of light)
- At similar speeds to some in-game characters, and objects
- approx. 344m/s in air, 768 mph
- faster in other materials (4.3 times in water, 15 times in iron)

###Echo and Reverberation

- Sound that reflects of a surfaces and arrives at the listener some time after the direct sound
- human ear can only distinguish an echo from the original sound if the delay is more than 1/15 of a second (50-100ms)
  -delays less than these are perceived as reverberation
- Reverberation (Reverb) is created when a sound is reflected causing a large number of reflections to build up and then decay as the sound is absorbed by the surfaces of objects in the space – which could include furniture and people, and air  
  - gives us an impression of the physical space
    - it's size
    - it's surface properties (absorption coefficient)
  - simulated using Convolution Reverb

###Doppler effect

- For an observer moving relative to a sound source
  - a change in frequency of a wave is perceived
  - total Doppler effect results from:
    - motion of the source
    - motion of the observer
    - motion of the medium

![http://upload.wikimedia.org/wikipedia/commons/thumb/9/90/Dopplerfrequenz.gif/250px-Dopplerfrequenz.gif](http://upload.wikimedia.org/wikipedia/commons/thumb/9/90/Dopplerfrequenz.gif/250px-Dopplerfrequenz.gif)

--<cite>http://en.wikipedia.org/wiki/Doppler_effect#/media/File:Dopplerfrequenz.gif</cite>

###Doppler effect 2

--<cite>http://en.wikipedia.org/wiki/Doppler_effect</cite>

####Stationary

- Stationary sound source produces sound waves at a constant frequency f, and the wave-fronts propagate symmetrically away from the source at a constant speed c. The distance between wave-fronts is the wavelength. All observers will hear the same frequency, which will be equal to the actual frequency of the source where f = f0 .

![http://upload.wikimedia.org/wikipedia/commons/e/e3/Dopplereffectstationary.gif](http://upload.wikimedia.org/wikipedia/commons/e/e3/Dopplereffectstationary.gif)

####Mach 0.7

The same sound source is radiating sound waves at a constant frequency in the same medium. However, now the sound source is moving with a speed υs = 0.7 c (Mach 0.7). Since the source is moving, the centre of each new wavefront is now slightly displaced to the right. As a result, the wave-fronts begin to bunch up on the right side (in front of) and spread further apart on the left side (behind) of the source. An observer in front of the source will hear a higher frequency

f = c + 0/c - 0.7c f0 = 3.33 f0

and an observer behind the source will hear a lower frequency

f = c - 0/c + 0.7c f0 = 0.59 f0 .

![http://upload.wikimedia.org/wikipedia/commons/c/c9/Dopplereffectsourcemovingrightatmach0.7.gif](http://upload.wikimedia.org/wikipedia/commons/c/c9/Dopplereffectsourcemovingrightatmach0.7.gif)

####Mach 1.0

Now the source is moving at the speed of sound in the medium (υs = c, or Mach 1). The wave fronts in front of the source are now all bunched up at the same point. As a result, an observer in front of the source will detect nothing until the source arrives where

f = c + 0/c - c f0 = ∞

and an observer behind the source will hear a lower frequency

f = c - 0/c + c f0 = 0.5 f0 .

![http://upload.wikimedia.org/wikipedia/commons/d/d1/Dopplereffectsourcemovingrightatmach1.0.gif](http://upload.wikimedia.org/wikipedia/commons/d/d1/Dopplereffectsourcemovingrightatmach1.0.gif)

####Mach 1.4

The sound source has now broken through the sound speed barrier, and is traveling at 1.4 c (Mach 1.4). Since the source is moving faster than the sound waves it creates, it actually leads the advancing wavefront. The sound source will pass by a stationary observer before the observer hears the sound. As a result, an observer in front of the source will detect

f = c + 0/c - 1.4c f0 = -2.5 f0

and an observer behind the source will hear a lower frequency

f = c - 0/c + 1.4c f0 = 0.42 f0

![http://upload.wikimedia.org/wikipedia/commons/e/e4/Dopplereffectsourcemovingrightatmach1.4.gif](http://upload.wikimedia.org/wikipedia/commons/e/e4/Dopplereffectsourcemovingrightatmach1.4.gif)

###Head-related transfer function!!

- Characterizes how an ear receives a sound from a point in space


###These are **some** of things an audio library helps you with

- i.e. let's not do this ourselves

#Recording, Representation, and Reproduction

###Recording

- We're not going to focus on this much
- Real-world audio/sound is **ANALOGUE**
- We need to convert it to a **DIGITAL** representation
  - this is **sampling**
  - converting a signal (for example, a function of continuous time and/or space) into a numeric sequence (a function of discrete time and/or space



###Representation

-  Nyquist Theorem and Aliasing

- ```Intuitively we expect that when one reduces a continuous function to a discrete sequence (called samples) and interpolates back to a continuous function, the fidelity of the result depends on the density (or sample-rate) of the original samples```
<cite>http://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem</cite>

- the highest reproducible frequency of a digital system will be less than one-half the sampling rate. From the opposite point of view, the sampling rate must be greater than twice the highest frequency we wish to reproduce
<cite>http://www.indiana.edu/~emusic/etext/digital_audio/chapter5_nyquist.shtml</cite>

- 44,100 standard
- often 96kHz for high quality
- usually sampled at 16-bits per sample,
- usually represented using 32-bit floating point
  - to allow effects
- output
  - For digital audio, if an HDMI device has audio, it is required to implement the baseline format: stereo (uncompressed) PCM. Other formats are optional, with HDMI allowing up to 8 channels of uncompressed audio at sample sizes of 16-bit, 20-bit and 24-bit, with sample rates of 32 kHz, 44.1 kHz, 48 kHz, 88.2 kHz, 96 kHz, 176.4 kHz and 192 kHz.
  - <cite>http://en.wikipedia.org/wiki/HDMI#Audio.2Fvideo</cite>

###Reproduction

- Speakers
- Headphones
- ...

#Challenges

- ...

#Libraries

- FMod
- WWise
- OpenAL
- HTML5 Audio
- SDL, SDL_mixer
- libsndfile
- BASS
- Audiere
- IrrKlang
- cAudio
- gorilla-audio
- SFML
- FFmpeg
- GStreamer
- Mumble (open source, low-latency, high quality voice chat )
- TeamSpeak (voice chat)
- Ventrilo (voice chat)
- do it yourself!!

#Links

- http://www.gameaudio101.com/articles.php
- http://www.gameaudio101.com/Game-Audio-Programming.php
- http://www.aiwisdom.com/audio_all.html
- https://wiki.libsdl.org/Books
- https://www.packtpub.com/game-development
