



To create build and src projects for eclipse:
mkdir HeatSim_build
cd HeatSim_build
cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE ../HeatSim

