# Introduction

This is an outreach project for the NSF grant:
“Materials World Network: Complex Structured ‘Electron-Poor’ framwork Semiconductors with Potential for Thermoelectric Application.” NSF-MPS-DMR.

The goal of this project is to simulate thermal transport and thermoelectric properties of materials. Currently Co-PI Prof. John Shumway and graduate student Daryn Benson are working on this computatinal project, to be joined by undergraduate Paul Campitelli in Summer 2012. We welcome inquiries from interested students, especially once the project is in a more practical, applied phase.

In its current state, the code calculates phonon spectra for empirical potentials, such as the Stillinger-Weber model for Si and Ge.


## Technical Details
This project is utilizing Test Driven Development (TDD) in C++ with Eclipse and gtest on multiple platforms. 

# Build notes

To create build and src projects for eclipse:  
    mkdir HeatSim_build  
    cd HeatSim_build  
    cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE ../HeatSim  

For Windows 7, the cmake command is:
    cmake -G"Eclipse CDT4 - NMake Makefiles" -D CMAKE_BUILD_TYPE=Debug -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE ..\HeatSim  
