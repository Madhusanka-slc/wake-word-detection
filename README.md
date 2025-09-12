# Wake Word Detection Dataset Preprocessing

This project contains a complete preprocessing pipeline for creating a wake word dataset using ElevenLabs TTS API.  
It downloads "activate" and negative samples, converts audio to WAV, renames files, and preprocesses background audio.

## Features
- Generate **activate samples** (wake word) with multiple voices.
- Generate **negative samples** (random phrases) with multiple voices.
- Convert MP3/M4A to WAV, mono, 44.1 kHz.
- Rename audio files for consistent dataset (`pos-1.wav`, `neg-1.wav`, `bg-1.wav`).
- Preprocess background audio to fixed duration (10 seconds).
- Fully modular, secure, and portfolio-ready.

## Setup

1. Clone the repo:

```bash
git clone https://github.com/Madhusanka-slc/wake-word-detection.git
cd wake-word-detection
