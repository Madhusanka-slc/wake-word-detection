# Wake Word Detection 🔊

An end-to-end deep learning pipeline for custom wake word detection, powered by TensorFlow and ElevenLabs TTS.

## Features

✅ Generate activate and negative samples using ElevenLabs TTS  
✅ Mix with background noise for realistic training data  
✅ Automatic creation of training and dev datasets  
✅ Train a GRU-based deep learning model  
✅ Evaluate and visualize model predictions

## Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/Madhusanka-slc/wake-word-detection.git
cd wake-word-detection
```

### 2. Create Virtual Environment

```bash
# Create environment
python -m venv wakeword-env

# Activate (Windows)
wakeword-env\Scripts\activate

# Activate (macOS/Linux)
source wakeword-env/bin/activate
```

### 3. Install Dependencies

```bash
pip install -r requirements.txt
```

**Requires:** Python 3.8+

### 4. Setup API Key

Copy the example environment file:

```bash
cp .env.example .env
```

Add your ElevenLabs API key in `.env`:

```env
ELEVENLABS_API_KEY=your_api_key_here
```

Get your key from [ElevenLabs Profile Settings](https://elevenlabs.io/)

### 5. Add Background Audio

Place your 10-second background clips in:

```
data/raw/backgrounds/
```

**Examples:** ambient noise, music, office chatter  
**Formats:** `.wav`, `.mp3`, `.m4a`  
**Minimum:** 2-5 clips required

## Usage

Run the notebooks in order:

```bash
jupyter notebook
```

1. **1_data_downloading.ipynb** - Download activate and negative audio samples
2. **2_data_creation.ipynb** - Generate training and dev datasets
3. **3_training.ipynb** - Train the GRU-based model
4. **4_test_model.ipynb** - Test and evaluate model

## Project Structure

```
wake-word-detection/
├── scripts/
│   ├── 1_data_downloading.ipynb
│   ├── 2_data_creation.ipynb
│   ├── 3_training.ipynb
│   └── 4_test_model.ipynb
├── data/
│   ├── raw/
│   │   └── backgrounds/        # ⚠️ Add your audio here
│   └── processed/              # Generated datasets
├── models/                     # Saved models
├── audio/sample/               # Test samples
├── td_utils.py                 # Helper utilities
├── requirements.txt
└── .env                        # ⚠️ Add your API key here
```

## Model Architecture

The model uses:
- **Conv1D layers** - Temporal feature extraction
- **Bidirectional GRU layers** - Sequential context understanding
- **Dense + Sigmoid** - Frame-level wake word prediction

## Requirements

- Python 3.8+
- TensorFlow
- ElevenLabs API Key
- Jupyter Notebook
- Background audio clips (10 seconds each)

## License

MIT License

Made with ❤️ by [Madhusanka](https://github.com/Madhusanka-slc)