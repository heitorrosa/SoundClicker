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

# Building the Application from Source
Clone the repository and compile with any C compiler supporting Windows API:

```bash
gcc -o soundclicker.exe src/main.c -lwinmm
```

Or use Visual Studio 2022 with the Windows SDK for optimal performance.

#
This application serves as a proof of concept for advanced audio integration in automation tools, demonstrating how sophisticated sound management can enhance gaming experiences.

## License

Licensed using GPL 3.0 and is a part of the Cauto Minecraft Autoclicker project.
