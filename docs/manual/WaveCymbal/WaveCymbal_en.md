---
lang: en
...

# WaveCymbal
![](img/wavecymbal.png)

WaveCymbal is an attempt to make a cymbal synthesizer with banded wave-guide model. The result is more like dragging bunch of empty cans or thin metal plate on asphalt rather than cymbal.

- [Download WaveCymbal 0.1.9 - VST® 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LatticeReverb0.1.0/WaveCymbal0.1.9.zip) <img
  src="img/VST_Compatible_Logo_Steinberg_negative.svg"
  alt="VST compatible logo."
  width="60px"
  style="display: inline-block; vertical-align: middle;">
- [Download Presets (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LinuxGUIFix/WaveCymbalPresets.zip)

The package includes following builds:

- Windows 64bit
- Linux 64bit
- macOS 64bit

macOS build isn't tested because I don't have Mac. If you found a bug, please file a issue to [GitHub repository](https://github.com/ryukau/VSTPlugins) or send email to `ryukau@gmail.com`.

Linux build is built on Ubuntu 18.0.4 and tested on Bitwig 3.1.2 and Reaper 6.03. Bitwig 3.1.2 seems to have a bug that occasionally blackouts GUI.

## Installation
### Plugin
Place `*.vst3` directory to:

- `/Program Files/Common Files/VST3/` for Windows.
- `$HOME/.vst3/` for Linux.
- `/Users/$USERNAME/Library/Audio/Plug-ins/VST3/` for macOS.

DAW may provides additional VST3 directory. For more information, please refer to the manual of the DAW.

### Presets
Extract preset zip, then place preset directory to the OS specific path:

- Windows : `/Users/$USERNAME/Documents/VST3 Presets/Uhhyou`
- Linux : `$HOME/.vst3/presets/Uhhyou`
- macOS : `/Users/$USERNAME/Library/Audio/Presets/Uhhyou`

Preset directory name must be the same as the plugin. Make `Uhhyou` directory if it does not exist.

### Windows Specific
If DAW doesn't recognize the plugin, try installing C++ redistributable (`vc_redist.x64.exe`). Installer can be found in the link below.

- [The latest supported Visual C++ downloads](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

### Linux Specific
On Ubuntu 18.0.4, those packages are required.

```bash
sudo apt install libxcb-cursor0  libxkbcommon-x11-0
```

If DAW doesn't recognize the plugin, take a look at `Package Requirements` section of the link below and make sure all the VST3 related package is installed.

- [VST 3 Interfaces: Setup Linux for building VST 3 Plug-ins](https://steinbergmedia.github.io/vst3_doc/vstinterfaces/linuxSetup.html)

REAPER on Linux may not recognize the plugin. A workaround is to delete a file `~/.config/REAPER/reaper-vstplugins64.ini` and restart REAPER.

## Controls
Knob and slider can do:

- Ctrl + Left Click: Reset value.
- Shift + Left Drag: Fine adjustment.

Right clicking on controllable object popups a context menu provided by DAW.

## Caution
Parameters that turns red when pointing can drastically change output gain. Changing those parameters with Shift + Left Drag is recommended. To prevent sudden clipping, always insert limiter after WaveCymbal.

## Block Diagram
If the image is small, use <kbd>Ctrl</kbd> + <kbd>Mouse Wheel</kbd> or "View Image" on right click menu to scale.

Diagram only shows overview. It's not exact implementation.

![](img/wavecymbal.svg)

## Parameters
### Gain
Output gain.

### Excitation
Short delays that turns impulse to tone.

Feedback

:   Feedback of excitor delays.

Time

:   Delay time of excitor delays. Beware that when the value of this parameter is high, output will be loud.

### Objects
nCymbal

:   Number of cymbal-ish objects.

nString

:   Number of Karplus-Strong string per cymbal object.

### Wave
Damping

:   Damping of 1D wave simulation. Beware that when the value of this parameter is high, output will be loud.

PulsePosition

:   Position where oscillator input causes wave.

PulseWidth

:   Width of wave caused by oscillator input.

### Collision
When turns on, it sounds like a rubbing on surface of thin light metal plate. When `nCymbal` is 1, this doesn't change output sound.

Distance

:   Distance between cymbals. Collision will more likely to occur when turning this knob to left.

### Random
Seed

:   Random seed. Output will be the same for each note while checking `Retrigger`.

Amount

:   Amount of random number effects to delay time and band-pass cutoff. Beware that when the value of this parameter is low, output may be loud.

### String
MinHz

:   Lower bound of Karplus-Strong string frequency.

MaxHz

:   Upper bound of Karplus-Strong string frequency.

Decay

:   Decay of Karplus-Strong string. Decay time will be longer when turning this knob to left.

Q

:   Band-pass filter Q.

### Oscillator
Retrigger

:   When checking, each note on resets random seed.

OscType

:   Oscillator type.

    - `Off` : Stop making noise for each note on. This option will be used when using WaveCymbal as FX.
    - `Impulse` : Outputs impulse for each note on. Simulates hit of cymbal with stick.
    - `Sustain` : Outputs impulse train with pitch of note. Simulates drawing of bow on surface of cymbal.
    - `Velvet Noise` : Outputs velvet noise of a density respect to pitch of note. Simulates less uniform drawing than `Sustain`.
    - `Brown Noise` : Outputs brown noise of a brightness respect to pitch of note. Kind of like dragging cymbal on asphalt.

Bandpass Cutoff Distribution

:   - `Log` : Sound becomes relatively natural.
    - `Linear` : Leans sound to higher frequency.

### Smoothness
Transition time from previous value to current value in seconds. `Gain`, `Excitation.Time`, `Random.Amount`, `Bandpass.MinCutoff`, `Bandpass.MaxCutoff` will be affected. Slide effect of `OscType.Sustain` can be tuned by `Smoothness`.

## Change Log
- 0.1.9
  - Reverted parameter smoother to the old one which works with variable size audio buffer.
- 0.1.8
  - Fixed a bug that cause crash when drawing string.
- 0.1.7
  - Changed display method for pop-up which shows up by clicking plugin title.
- 0.1.6
  - Fixed to stop sounds when deactivated.
  - Fixed a bug that was causing noise on PreSonus Studio One 4.6.1.
- 0.1.5
  - Enabled GUI for Linux build.
  - Fixed broken presets.
- 0.1.4
  - Fixed wobbling knob bug.
- 0.1.3
  - Added support for synchronization between multiple GUI instances.
  - Fixed a bug that opening splash screen causes crash.
  - Fixed a bug that crash plugin when reloading.
  - Fixed GUI to follow host automation.
- 0.1.2
  - Fixed note on/off event to be triggered at exact timing.
- 0.1.1
  - Fixed smoothing algorithm to prevent blow up.
- 0.1.0
  - Initial release.

### Old Versions
- [WaveCymbal 0.1.8 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/DrawStringFix/WaveCymbal0.1.8.zip)
- [WaveCymbal 0.1.6 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EsPhaser0.1.0/WaveCymbal0.1.6.zip)
- [WaveCymbal 0.1.5 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/LinuxGUIFix/WaveCymbal0.1.5.zip)
- [WaveCymbal 0.1.4 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/EnvelopedSine0.1.0/WaveCymbal0.1.4.zip)
- [WaveCymbal 0.1.3 - VST 3 (github.com)](https://github.com/ryukau/VSTPlugins/releases/download/IterativeSinCluster0.1.0/WaveCymbal0.1.3.zip)

## License
WaveCymbal is licensed under GPLv3. Complete licenses are linked below.

- [https://github.com/ryukau/VSTPlugins/tree/master/License](https://github.com/ryukau/VSTPlugins/tree/master/License)

If the link above doesn't work, please send email to `ryukau@gmail.com`.

### About VST
VST is a trademark of Steinberg Media Technologies GmbH, registered in Europe and other countries.
