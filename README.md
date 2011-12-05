# Introduction

This is a test project, more details to come if it works.


# Build notes

To create build and src projects for eclipse:  
    mkdir HeatSim_build  
    cd HeatSim_build  
    cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE ../HeatSim  

For Windows 7, the cmake command is:
    cmake -G"Eclipse CDT4 - NMake Makefiles" -D CMAKE_BUILD_TYPE=Debug -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE ..\HeatSim  
