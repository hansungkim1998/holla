# Holla
## Description
Holla is an interactive screaming battle. Yell as loud as you can to shoot a beam of light from your mouth and defeat your opponent! Let off all your stress by screaming like never before.

Inspired by the [duel between Lord Voldemort and Harry from *Harry Potter*](https://www.youtube.com/watch?v=ImQAFLaRpfQ), Holla is a battle to scream louder than your opponent.

This project was done with Chae Eun Park for the Horizons Hackathon by HackGT in February 2020 at the Georgia Institute of Technology.

## Requirements
### Devices
1. Computer (macOS or Windows)
2. Arduino Mega (or Arduino Uno)

### Installations
1. Install [Arduino IDE](https://www.arduino.cc/en/main/software) and required packages.
   - Install [Adafruit_DotStar](https://github.com/adafruit/Adafruit_DotStar).

## Building the Holla
### Materials
- [Adafruit DotStar Digital LED Strip](https://www.adafruit.com/product/2238?length=2)
- [ELEGOO Big Sound Sensor](https://www.amazon.com/ELEGOO-Upgraded-Tutorial-Compatible-MEGA2560/dp/B01MG49ZQ5/ref=sr_1_3?crid=2UP2H4601WJWQ&keywords=37+sensor+kit&qid=1572128556&sprefix=37+sens,aps,164&sr=8-3) x2
- [12"x24" 1/8" Clear Acrylic Sheet](https://www.amazon.com/Source-Thick-Inches-Acrylic-Plexiglass/dp/B01FEF0VQI/ref=pd_sbs_229_t_1/144-1796961-3528918?_encoding=UTF8&pd_rd_i=B004DYW31I&pd_rd_r=23722ac3-ba96-430e-a6e7-02854eb94f7d&pd_rd_w=Cj4qd&pd_rd_wg=jLJDG&pf_rd_p=5cfcfe89-300f-47d2-b1ad-a4e27203a02a&pf_rd_r=2B4SK5NH2PXG9KRQPDEN&refRID=2B4SK5NH2PXG9KRQPDEN&th=1) x3
- [12"x24" 1/4" MDF Board](https://www.homedepot.com/p/Medium-Density-Fiberboard-Common-1-4-in-x-2-ft-x-4-ft-Actual-0-216-in-x-23-75-in-x-47-75-in-1508104/202089069) x1
- [8ft 2"x4" Wood Stud](https://www.homedepot.com/p/2-in-x-4-in-x-96-in-Premium-Kiln-Dried-Whitewood-Stud-161640/202091220) x1
- Electrical wires
- Tape

### Tools
- Lasercutter(Laser engraver)
- Woodworking Tools
  - Bandsaw
  - Miter saw
- Electronics Equipment
  - Soldering iron
  - Wiring kit (wires, wire strippers, electrical tape, solder, etc.)
- Basic Tools
  - Hot glue gun and hot glue sticks

### Construction Instructions
1. Cut the 2x4 wood stud
   - Cut the stud to be 8ft long and at least a 1"x2" rectangle with a flat top and bottom
2. Cut the LED strip
   - Cut the LED strip to include 58 (or other desired number of) LEDs
   - Solder the 4 wires to the end of the LED strip
3. Attach LED strip to wood stud
   - Center the LED strip with the center of the wood stud
   - Attach the LED strip along the center of the wider side with hot glue
   
      <img src="IMG_0502.png" height="250"> <img src="IMG_0500.png" height="250">
4. Laser cut using [holla_lasercut.ai](holla_lasercut.ai)
   - Use pages 1 and 2 to cut the appropriate number of acrylic circles
   - Use page 3 to cut twice the number of MDF supports than acrylic circles
   - Use page 4 to cut two sound chambers
5. Glue lasercut components together
   - Hot glue 1 MDF support on each side of each acrylic circle
   
      <img src="IMG_0506.png" height="250">
   
   - Glue 4 acrylic trapezoids together to create a sound chamber, repeat for the second one
6. Assemble all components
   - Attach one acrylic-MDF assembly above each LED such that the acrylic circle is directly above the LED
   - Attach the two sound chambers on either side of the wood stud
   - Attach one big sound sensor inside of each sound chamber
   
      <img src="IMG_0515.png" height="250"> <img src="IMG_0518.png" height="250">
7. Wiring
   - Wire all necessary components
   - Group and hide all wires to the side of the wood stud
   - Gather all wires to the center of the setup so that they can be connected to the Arduino

## Running the Game
1. Connect all wires according to the diagram below.
   - If changing the pins, change them accordingly in lines 4-8 of [Holla.ino](Holla/Holla.ino).
   
2. Connect to Arduino and upload code.
   - Upload [Holla.ino](Holla/Holla.ino) to the Arduino.
   - Keep the Ardunio connect to the computer or connect the Arduino to a power supply.

## Playing the Game
### Rules
- The game is played by 2 players.
- Both players scream as loud as they can into the sound chambers until one fills all the LEDs with their color.
- Screaming louder pushes a player's beam further towards the other side.
- When the two beams meet, they push against each other and the movement is determined by the difference in the screaming volumes.
