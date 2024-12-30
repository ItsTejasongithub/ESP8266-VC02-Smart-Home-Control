Setup Guide for ESP8266 VC02 Smart Home Control
This guide will walk you through the setup process for the ESP8266 microcontroller integrated with the AI Thinker VC02 module to control devices such as fans and lights using serial commands and physical switches.

Components Needed
ESP8266 (e.g., NodeMCU or Wemos D1 Mini)
AI Thinker VC02 Wi-Fi module
Relay Module (for controlling fan and light)
Push Button Switches (for manual control)
Jumper wires
Breadboard
Power Supply (5V for ESP8266 and Relay)
Resistors (if needed)
Wiring Diagram

Connections:
ESP8266 D4 → Relay IN (Fan control)
ESP8266 D0 → Relay IN (Light control)
ESP8266 D1 → Push Button (Fan switch)
ESP8266 D2 → Push Button (Light switch)
AI Thinker VC02 TX → ESP8266 RX
AI Thinker VC02 RX → ESP8266 TX
5V Power Supply → ESP8266, Relay Module
GND → Common ground for ESP8266, Relay, and VC02
Software Setup
1. Install Arduino IDE
If you don't have the Arduino IDE installed, download it from the official Arduino website.

2. Install ESP8266 Board in Arduino IDE
To program the ESP8266, you need to install the board support in the Arduino IDE:

Open Arduino IDE and go to File > Preferences.
In the Additional Boards Manager URLs field, add the following URL:
bash
Copy code
http://arduino.esp8266.com/stable/package_esp8266com_index.json
Go to Tools > Board > Boards Manager.
Search for ESP8266 and click Install.
3. Install Libraries
You will need the ESP8266WiFi library for communication. You can install it from the Library Manager in the Arduino IDE:

Go to Sketch > Include Library > Manage Libraries.
Search for ESP8266WiFi and click Install.
4. Upload the Code
Open the main.ino file from the project repository in Arduino IDE.
Select the appropriate board and port:
Tools > Board > ESP8266 Boards (e.g., NodeMCU 1.0).
Tools > Port > Select your ESP8266 COM port.
Click the Upload button to upload the code to the ESP8266.
5. Serial Monitor
Open the Serial Monitor in Arduino IDE (set to 9600 baud).
You will see the system awaiting serial commands.
Command List
The following commands can be sent through the Serial Monitor to control the fan and light:

41251: Turn the fan ON.
41524: Turn the fan OFF.
41797: Turn the light ON.
42343: Turn the light OFF.
42070: Activate manual switch control.
42616: Deactivate manual switch control.
Manual Control (Physical Switches)
Fan Control: Press the push button connected to D1 to turn the fan ON or OFF.
Light Control: Press the push button connected to D2 to turn the light ON or OFF.
Troubleshooting
No Response from Relay: Make sure the Relay Module is connected to the correct pin and powered properly.
Wi-Fi Connection Issues: Ensure the VC02 module is correctly configured and connected to Wi-Fi via serial communication.
Serial Communication Failures: Check the wiring between ESP8266 and VC02. Ensure TX and RX are correctly connected.
License
This project is licensed under the MIT License. See the LICENSE file for more details.
