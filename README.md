# SoundClicker

A tool made for autoclickers to fake click sounds in games like Minecraft, Roblox and etc.

## Features

- **Randomized Audio**: Multiple WAV file support with random selection for natural variation
- **Zero-Latency Playback**: Real-time audio response with optimized memory management
- **Seamless Integration**: Designed specifically for autoclicker compatibility
- **Undetectable Operation**: Natural sound patterns that mimic genuine user interaction
- **Resource Efficient**: Minimal CPU and memory footprint for background operation

## Requirements

- Windows 7 or higher
- WAV audio files (16-bit/44.1kHz recommended for best performance)
- Visual C++ Redistributable (linked above)

# Building the Application
Clone the repository and compile with any C compiler supporting Windows API:

```bash
gcc -o soundclicker.exe src/main.c -lwinmm
```

Or use Visual Studio 2022 with the Windows SDK for optimal performance.

## Pro Tips

- Mix different click sounds to avoid repetitive patterns
- Adjust system volume to match your typical clicking audio levels
- Test with various sound sets to find what works best for your use case

## Technical Implementation

- **Windows API Integration**: Native file dialogs and mouse input detection
- **Multimedia API**: Hardware-accelerated audio playback via winmm.lib
- **Smart Memory Management**: Efficient loading and caching of audio data
- **Real-time Processing**: Sub-millisecond response time for authentic feedback
- **Multi-file Architecture**: Scalable sound management system


## License

Part of the Cauto project ecosystem. Open source and free to modify and distribute.