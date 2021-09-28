[![Ubuntu Build](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/ubuntu_build.yml/badge.svg)](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/ubuntu_build.yml)
[![Windows Build](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/windows_build.yml/badge.svg)](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/windows_build.yml)
[![Style Check](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/style_check.yml/badge.svg)](https://github.com/learn-orolia/skydel-plug-ins/actions/workflows/style_check.yml)

## Welcome to the Public Skydel Plug-ins Github Repository!

With plug-ins, users can develop features and integrate them to the Skydel user interface and the real-time simulation engine. In Skydel's context, a plug-in is a dynamic library (*.so* on Ubuntu and *.dll* on Windows).

This repository contains the Skydel Plug-ins Software Development Kit (SDK) and multiple plug-in examples.

### Getting Started

Skydel-sdx plug-ins you cmake for project configuration, if you need to install it, you can refer to the official [website](https://cmake.org/install/).  You will need at least cmake 3.17  

Skydel plug-ins depends on two external project which you will need to install:    
+ Blaze 3.7
+ Qt 5.12
  
First we will briefly guide you on how to install those dependencies.  

Install blaze 3.7 from official repository
```sh
git clone https://github.com/parsa/blaze
cd blaze && mkdir build && cd build
cmake -DBLAZE_BLAS_MODE=ON .. && sudo make install
```
Note: By default we use blas and lapack library for Blaze.

Install Qt 5.12 as describe in [documentation](https://skydel.gitbook.io/skydel-plug-ins-documentation/)

Now that you have your environment setup you will be able to install the sdk as follow.  

First get source code
```sh
git clone https://github.com/learn-orolia/skydel-plug-ins
```

Then you can install the plugin sdk.  

Note that by default we also build the examples and install them in Skydel dedicated default folder: HOME/Documents/Skydel-SDX/Plug-ins 

```sh
cd skydel-plug-ins && mkdir build && cd build
cmake .. && make install
```

If you don't want to build examples plug-ins use the dedicated flag before installation as follow:  
```sh
cmake -DBUILD_SKYDELPLUGIN_EXAMPLES=FALSE .. && make install
```

If you want to use skydel plugin in your own Plugin you just have to install it as described above and add the following lines in your CMakeLists
```sh
find_package(SkydelPlugin)
target_link_libraries(MyPlugin PUBLIC Skydel::SkydelPlugin
```

See [documentation](https://skydel.gitbook.io/skydel-plug-ins-documentation/) to have more details on how to get started.

## Contributing

Would you like your plug-in to be part of the Skydel Plug-ins repository? You found an improvement on an existing plug-in example? We suggest forking our repository and when you're all set, open a pull request!

## Reporting Issues

Having a good idea to improve the SDK or there is something bothering you? Open an issue [here](https://github.com/learn-orolia/skydel-plug-ins/issues/new/choose), the Skydel team will address you concerns!

## Featured Plug-ins

Would you like your plug-in to be featured in this repository? Add your project to the list bellow and send us a pull request!

- [IMU Plug-in](https://github.com/learn-orolia/skydel-plug-ins/tree/master/source/example/imu_plugin): Simulates an inertial measurement unit with real-time position data from Skydel.
