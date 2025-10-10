---

# Wake Word Detection 🔊

An **end-to-end deep learning pipeline** for **custom wake word detection**, powered by **TensorFlow** and **ElevenLabs TTS**.

This project covers the full workflow — from **audio generation and preprocessing** to **GRU-based model training and evaluation**.

---

## ⚙️ Features

✅ Generate *activate* and *negative* samples using **ElevenLabs TTS**
✅ Mix with *background noise* for realistic audio data
✅ Automatic creation of *training* and *dev* datasets
✅ Train a **GRU (Gated Recurrent Unit)** based deep learning model
✅ Evaluate, test, and visualize model predictions

---

## 🚀 Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/Madhusanka-slc/wake-word-detection.git
cd wake-word-detection
```

---

## 🐍 Environment Setup

### Create and Activate Virtual Environment

```bash
# Create environment
python -m venv wakeword-env

# Activate (Windows)
wakeword-env\Scripts\activate
# or (macOS/Linux)
source wakeword-env/bin/activate
```

### Install Dependencies

```bash
pip install -r requirements.txt
```

✅ Requires **Python 3.8+**

---

## 🔑 Setup API Key

Copy the example `.env` file:

```bash
cp .env.example .env
```

Add your **ElevenLabs API key**:

```env
ELEVENLABS_API_KEY=your_api_key_here
```

👉 Get your key from [ElevenLabs → Profile Settings](https://elevenlabs.io/)

---

## 🎧 Add Background Audio

Place your 10-second background clips here:

```
data/raw/backgrounds/
```

Examples: ambient noise, music, office chatter, etc.
Formats: `.wav`, `.mp3`, `.m4a`

> You need at least **2–5 clips** for the system to work properly.

---

## 🧠 Full Pipeline (Run in Order)

Open Jupyter and execute the following notebooks:

1. **1_data_downloading.ipynb** → Download or create *activate* and *negative* audio samples
2. **2_data_creation.ipynb** → Generate labeled *training* and *dev* datasets
3. **3_training.ipynb** → Build and train the **GRU-based wake word detection model**
4. **4_test_model.ipynb** → Test and visualize model performance

```bash
jupyter notebook
```

---

## 🧩 Utility Script

**`td_utils.py`** – Helper functions for:

* Audio preprocessing and normalization
* Spectrogram generation
* Label creation for training sequences
* Visualization and analysis utilities

---

## 🧠 Model Architecture

The wake word detection model is built using:

* **Conv1D layers** – for low-level temporal feature extraction
* **Bidirectional GRU layers** – for sequential context understanding
* **Dense + Sigmoid output** – for frame-level wake word prediction

---

## 📂 Project Structure

```
wake-word-detection/
├── scripts/                    
│   ├── 1_data_downloading.ipynb
│   ├── 2_data_creation.ipynb
│   ├── 3_training.ipynb
│   └── 4_test_model.ipynb
├── data/
│   ├── raw/
│   │   └── backgrounds/        
│   └── processed/              
├── models/                     # Saved GRU models
├── audio/sample/               # Test samples
├── td_utils.py                 # Helper utilities
├── requirements.txt
└── .env                        # API key file
```

---

## 🧰 Requirements

* Python 3.8+
* TensorFlow
* ElevenLabs API Key
* Jupyter Notebook
* Background audio (10s clips)

---

## 📜 License

MIT License

Made with ❤️ by [**Madhusanka**](https://github.com/Madhusanka-slc)

---