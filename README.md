# Realtime Color Sensor controlled by a proximity sensor using Particle Photon

The Realtime Color Sensor controlled by a proximity sensor is second version of the realtime color sensor using particle photon. It senses the color of the object that you want the RGB value of and displays it on an OLED display connected to the photon except in this version, the color sensor is only activated when an object is brought closer to the proximity sensor. This whole circuit is now enclosed in an enclosre to make it work similar to a camera but to get the rgb values of the color it senses.

## Getting Started

These instructions will help you get the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

Things you will need to get this to work:

1. Particle Photon
2. OLED Display
3. Flora Color Sensor
4. ColorSensor.ino file
5. InputVisualization.html file for displaying the input visualization.
6. Illustrator file included with this project for laser cutting.
7. stl files included for 3D Printing.

### Circuit Diagram



### Installing

1. Connect the OLED Display and the flora color sensor as shown in the circuit diagram.
2. Contain the Circuit in the enclosure (Enclosure made after laser cutting and 3D Printing). 
3. Flash the code from the saishColorSensor.ino to the photon either using the particle cloud IDE or locally.
4. Power up the photon and wait for it to connect to the internet.
5. Once it is connected to the internet, the rgb values will be displayed on the oled display.
6. For the input visualization open the saishColorSensorInputVisualization.html file on your web browser and notice the change in color of the bouncing ball.
7. That's all!


## Running the tests

Once the photon is powered up, open the terminal and type in "particle serial monitor" without the quotes.
 - If you are getting the values in the form (eg: 77, 79, 90), your color sensor input is working fine.
 - If you are gettig the values in the range 100 - 3000, the proximity sensor is working.
 - If you are getting "data: 77, 79, 90", your subscription to the cloud is working fine.
 - If you are getting the output on the OLED display in the form - "rgb(77, 79, 9)", then everything is working fine.

### Break down into end to end tests

The above tests are used to make sure that the input and output are working fine in collaboration.

## Deployment

No additional requirements are necessary except that you should flash the code to the photon and then open the "InputVisualization.html" file to view the visualization - the color of the bouncing ball changes.

## Built With

* Particle Photon Maker Kit - [https://store.particle.io/]
* Visualization is done using d3.js - [https://d3js.org/]
* Bouncing beach ball visualization got from "datavizclub.tumble.com" = [http://datavizclub.tumblr.com/post/119132679558/make-a-bouncing-beach-ball-with-d3]
* Lulzbot Taz 4 3D Printer
* Laser Cutter

## Images

![mage] (https://github.com/saishmenon/color-sensor-controlled-by-a-proximity-sensor/Images and Working Video/Image-Back.jpg)

## Authors

* **datavizclub.tumble.com** - *Initial visualization work* - datavizclub.tumble.com
* 3D Printing Model - http://www.thingiverse.com/thing:380166
* Saish Menon - RIT


## License

Open Licence

## Acknowledgments

* Thanks to datavizclub.tumble.com - beach ball visualization
