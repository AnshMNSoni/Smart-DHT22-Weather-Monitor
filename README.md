# Smart-DHT22-Weather-Monitor

### Components Used:
- `DHT22 Sensor`
- `LCD(16x2) Display`
- `Arduino UNO R3`
- `BreadBoard`
- `pushButton`
- `1KΩ Resistors` and `Jumper Wires`

### Circuit Diagram:

![image](https://github.com/user-attachments/assets/6ab0ce51-b2e7-4998-924f-5e0e1c615dfe)


### Wiring Diagram:

#### 👉 DHT22 Sensor:
VCC -> 5V <br/>
GND -> GND <br/>
Data -> Pin 2 (Digital Pin) <br/>

#### 👉 LCD Display:
VCC -> 5V <br/>
GND -> GND <br/>
SDA -> A4 (on most Arduino boards like Uno) <br/>
SCL -> A5 (on most Arduino boards like Uno) <br/>

#### 👉 Push Buttons:
Red Button -> Pin 7 (for mode toggle) <br/>
Blue Button -> Pin 5 (for showing readings) <br/>

### How to Use:
1️⃣ Upload the Code: Open the code in the Arduino IDE and upload it to your Arduino. <br/>

2️⃣ Power the Arduino: Connect the Arduino to your power source (e.g., USB or external power supply). <br/>

3️⃣ Interact with Buttons: <br/>
- Press the Red Button to toggle between Mode 1 and Mode 2.
- Press the Blue Button to display the temperature and humidity readings.
- View the Output: The LCD will display the readings for 1 second and then return to the main menu.

### Notes:
1️⃣ Ensure your wiring is correct to avoid any issues with sensor readings. <br/>

2️⃣ The DHT22 sensor might take a few seconds to stabilize and give accurate readings. <br/>

3️⃣ You can adjust the delay times in the code to change how long the readings are displayed. <br/>

### License:
This project is open-source and licensed under the `MIT License`.

### Contributions are always Welcome!
