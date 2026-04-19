# 🌈 ESP32 RGB LED Controller (Potentiometer Edition)

> Mini project simpel tapi aesthetic: kontrol warna RGB LED pakai **ESP32 + Potentiometer**  
> Dari vibe hangat 🔥 sampai dingin ❄️ cuma dengan satu putaran knob.

---

## ✨ Preview

- 🎛️ Putar potentiometer → warna berubah realtime  
- 🔥 Kiri = warm (merah/kuning)  
- ❄️ Kanan = cool (biru/cyan)  
- 🎨 Transisi halus (no disco norak)

---

## 🧠 Konsep

Project ini menggunakan:
- **ESP32 PWM (LEDC)** → kontrol intensitas RGB
- **ADC (Analog Read)** → baca nilai potentiometer
- **Color Mapping** → ubah nilai analog jadi spektrum warna

👉 Jadi bukan sekadar ON/OFF, tapi kontrol warna dinamis.

---

## 🧩 Komponen

| Komponen | Jumlah |
|---------|-------|
| ESP32 | 1 |
| RGB LED (Common Cathode) | 1 |
| Resistor 220Ω | 3 |
| Potentiometer (810k / 10k recommended) | 1 |
| Breadboard + Jumper | secukupnya |

---

## ⚠️ Catatan Penting
- RGB LED **WAJIB pakai resistor**
- Potentiometer ideal: **10kΩ** (810k bisa, tapi agak noisy)
- ESP32 pakai **3.3V**, bukan 5V

---

## 🔌 Wiring

### RGB LED → ESP32

| Warna | GPIO | Resistor |
|------|------|---------|
| Red  | 25   | 220Ω |
| Green| 26   | 220Ω |
| Blue | 27   | 220Ω |
| GND  | GND  | - |

---

### Potentiometer

| Pin Pot | Koneksi |
|--------|--------|
| Kiri   | GND |
| Kanan  | 3.3V |
| Tengah | GPIO 34 |


