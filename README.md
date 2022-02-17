# buggy teleoperation with joystic  
See how it works:  
    
Motion:  
[https://www.youtube.com/watch?v=3fb8u-CaNpo](https://www.youtube.com/watch?v=3fb8u-CaNpo)  

Wheel smooth control:  
[https://www.youtube.com/watch?v=xl25I120_WY](https://www.youtube.com/watch?v=xl25I120_WY)  

The buggy is controlled with Logitech F710 Wireless Gamepad with axis.  
Differential steering is used.   
Raspbery pi 3 B+  has 2 PWMs so voltage for each wheel can be set independently.  
See [catkin_ws](./catkin_ws) for the codes.  
It is C++/ROS coding.  
There are 2 nodes:  
1) joy - it broadcast joystick's messages  
2) main_node it listen to joy and control wheels   

#### How I made it:
URL used to install ROS melodic:  
https://wiki.ros.org/ROSberryPi/Installing%20ROS%20Melodic%20on%20the%20Raspberry%20Pi  
  
See joystick_drivers:  
http://wiki.ros.org/joystick_drivers  
  
Install dependencies:  
sudo apt-get install libspnav-dev libbluetooth-dev libcwiid-dev  
  
Create catkin workspace:  
mkdir -p catkin_ws/src  
cd catkin_ws/  
catkin_make  
  
create package:  
cd src  
catkin_create_pkg ros_joystic_teleoperation std_msgs roscpp joy  
  
from https://github.com/ros-drivers/joystick_drivers  
put joy package to catkin_ws/src  
  
in catkin_ws/src:  
git clone https://github.com/ros/roslint.git  
(roslint is used inside joy node so roslint is necessary)  
  
cd catkin_ws/  
catkin_make  
  
to check that joystick works:  
sudo jstest /dev/input/js0  
  
sudo chmod a+rw /dev/input/js0  
  
command to run ROS:  
source /opt/ros/melodic/setup.bash  
  
command to run core:  
roscore  
  
in new window from catkin_ws:  
source devel/setup.bash  
rosrun joy joy_node  
  
to test ros node in new window:  
rostopic list  
rostopic echo /joy  
  
install wiringpi  
sudo apt-get install wiringpi  
(I don't remember how I instaled it exactly, but this line:  
```#include <wiringPi.h>```  
in cpp codes should goes without errors)  
wiringpi tutorial:  
https://roboticsbackend.com/use-and-compile-wiringpi-with-ros-on-raspberry-pi/  
https://answers.ros.org/question/221046/can-i-use-wiringpi-on-ros-indigo/  
  
add main_node:  
write main_node.cpp in catkin_ws/src/ros_joystic_teleoperation/src  
Here is the [main_node.cpp](catkin_ws/src/ros_joystic_teleoperation/src/main_node.cpp)    
  
in catkin_ws/src/ros_joystic_teleoperation/CMakeLists.txt
append to the end:  
FIND_LIBRARY(WIRINGPI_LIBRARY wiringPi /usr/lib)  
add_executable(main_node src/main_node.cpp)  
target_link_libraries(main_node ${catkin_LIBRARIES} ${WIRINGPI_LIBRARY})  
  
in catkin_ws:  
catkin_make  
  
to run main_node as root (to fix wiringpi issues):  
https://answers.ros.org/question/165246/launch-node-with-root-permissions/  
in catkin_ws/devel/lib/ros_joystic_teleoperation :  
sudo chown root:root main_node  
sudo chmod a+rx main_node  
sudo chmod u+s main_node  
  
run joy_node if neccesarry  
  
run main_node:  
in catkin_ws:  
source devel/setup.bash  
rosrun ros_joystic_teleoperation main_node  

