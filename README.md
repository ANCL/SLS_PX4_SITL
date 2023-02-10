# Quasi-static state feedback  output tracking for a slung load system : PX4 SITL validation


This repo contains the simulation code for Quasi-static state feedback output tracking for a slung load system : PX4 SITL validation. 

The code simulates a slung load system with a multirotor UAV running the [PX4 autopilot firmware](https://px4.io/). **SITL** (*Software in the loop*) is combined with the [Gazebo](https://github.com/gazebosim/gazebo-classic) simulator. The reason for using SITL simulation is to test controller performance using actual PX4 firmware. This ensures the controller is implementable on-board physical autopilots (e.g. Pixhawk 1, etc.) and that simulation results are closer to what are observed in flight testing. 

## Important Folders and Files

1. Folder containing the module which implements the quasi-static controller: [RosControl](./ancl_sls/RosControl/)

2. For installing and running PX4-Gazebo simulator, please refer to: [PX4 Gazebo Plugin Suite for MAVLink SITL and HITL](https://github.com/PX4/PX4-SITL_gazebo)

3. SLS Model SDF File: [iris_pendulum](./ancl_sls/iris_pendulum/)

## Docker Image
A docker image is provided [DockerHub](https://hub.docker.com/repository/docker/zifeifei/quasijint). The PX4 code and gazebo simulation code is at 
```/src/PX4-Autopilot``` and ```/src/PX4-Autopilot/Tools/sitl_gazebo/``` respectively.

## Usage

### Running the SITL/Gazebo Simulation

1. In order to compile the PX4 code for SITL and and start jMAVSim:

```make px4_sitl_default gazebo no_sim=1```

When the build is successful, JMAVSim and the PXH shel are launched. In the terminal you should see

```
______  __   __    ___ 
| ___ \ \ \ / /   /   |
| |_/ /  \ V /   / /| |
|  __/   /   \  / /_| |
| |     / /^\ \ \___  |
\_|     \/   \/     |_/

px4 starting
...
INFO [tone_alarm] home_set
INFO [tone_alarm] neutral
pxh>

```
2. Start ROS, PX4, and Gazebo:

```
cd ancl_sls
./mavros_script.sh
```

3. Using QgroundControl to take off.

4. Enagle quasi-static controller:

```
rosrun offb_control get_states_node
rosrun offb_control offb_control_node 
```

## Debug/Customize Controller

If you run into any problems using the code, please open an [issue](https://help.github.com/en/github/managing-your-work-on-github/creating-an-issue), or you can email one of us:

* Zifei Jiang <zifei3@ualberta.ca>
* Alan F.Lynch <alan.lynch@ualberta.ca>

## Citing

## Acknowledgement
Thanks to the [PX4 team](https://px4.io/) and [PX4 Gazebo Plugin](https://github.com/PX4/PX4-SITL_gazebo) for their open-source autopilot on which this code is based. 
# SLS_PX4_SITL
