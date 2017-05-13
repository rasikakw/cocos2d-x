# Cocos Joystick v1.00, 15 May 2017


## Introduction

This is based on the code [found here](http://discuss.cocos2d-x.org/t/control-sphere-object-with-simple-joystick-in-box2d/491). The code has been re-formatted and changed to run on Cocos2D-X v3.xx. It has also been simplified by removing the Box2D code.


## Installation

A new Cocos2D-X project will need to be created so these files can be added to the project. To create a new Cocos2D-X project perform the steps below:

1. Download and install the latest Cocos2D-X SDK from [download page](http://www.cocos2d-x.org/download). This was created using Cocos2D-X v3.15. 

2. Create a new Cocos2D-X project by running the `cocos` console command.

3. Replace all the files inside the 'Classes' with the 'Classes' files from here. Add / import the newly added file to your IDE project.

4. Add all the files in the 'Resources' folder into your project's 'Resources' folder and add / import them to your project.

5. Build and run.


## Known Issues

1. The joystick sprites appear at the bottom left of the screen but the actual joystick is functional at the top-left of the screen. So to make the player sprite move, click-hold and move the cursor at the top-left side of the screen. Experiment to find the exact location.

2. The joystick movement is vertically inverted to suit flight simulator type games, but not other games.

If you can provide solutions for the issues above, please [post them here] ().