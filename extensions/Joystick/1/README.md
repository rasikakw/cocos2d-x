# Cocos2D-X Joystick


## Introduction

This is based on the [code here](http://discuss.cocos2d-x.org/t/control-sphere-object-with-simple-joystick-in-box2d/491). The code has been re—formatted and updated to run on Cocos2D-X v3.x. It has also been simplified with the removal of the Box2D code.


## Download

Clone or download these files from the [project root](https://github.com/rasikakw/cocos2d-x).


## Installation

Create a new Cocos2D-X project so that the files here can be added to it. To create a new Cocos2D-X project perform the steps below:

1. Download and install the latest SDK from the [Cocos2D-X download page](http://www.cocos2d-x.org/download). This was created using Cocos2D-X v3.15. 

2. Create a new Cocos2D-X project by running the `cocos` console command. Refer to the Cocos2D-X documentation for more information on this. View the [Installation](http://www.cocos2d-x.org/docs/static-pages/installation.html) and [Cocos command-line tool](http://www.cocos2d-x.org/docs/editors_and_tools/cocosCLTool/) help sections.

3. Replace all the files inside your project’s ‘Classes’ folder with the ‘Classes’ files from here. Add / import the newly added file to your IDE project.

4. Add all the files in the ‘Resources’ folder into your project’s ‘Resources’ folder and add / import them to your IDE project.

5. Build and run.


## Known Issues

The following issues are currently known:

1. The joystick sprites appear at the bottom left of the screen but the actual joystick is functional at the top—left of the screen. So to make the player sprite move, click—hold and move the cursor at the top—left side of the screen. Experiment to find the exact location.

2. The joystick movement is vertically inverted to suit flight simulator type games, but not other games.

If you can provide solutions for the issues above, please [post them here] (). Thank you.


## Alternatives

1. [JoystickCocos2D-X](https://github.com/prsolucoes/JoystickCocos2D-X)


## Version History

### Version 1.00 

Released on the 15th of May 2017.