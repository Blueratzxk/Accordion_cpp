# Accordion

The first IQRE (Intra-Query Runtime Elasticity) SQL query engine (prototype version).

# Prerequisites

* Linux Ubuntu version v20.04, v22.04, v24.04.

* Make sure you have installed CMake version 3.25 (or newer) on your system. 

* GCC version 11 (or newer).



# Dependencies

Accordion has the following third party dependencies

* [@apache arrow](https://github.com/apache/arrow) : Data format exchanging between operators and tasks.

* [@pistache](https://github.com/pistacheio/pistache) : Restful HTTP server.

* [@restclient-cpp](https://github.com/mrtazz/restclient-cpp) : Restful HTTP client.

* [@nlnohamn json](https://github.com/nlohmann/json) : Json library.

* [@nlnohamn json fifomap](https://github.com/nlohmann/fifo_map) : Json library.

* [@tbb](https://github.com/oneapi-src/oneTBB) : TBB library.

* [@spdlog](https://github.com/gabime/spdlog) : Log library.



# Building from source

1. Get Accordion source code from Git Hub.
```
git clone https://github.com/Blueratzxk/Accordion_cpp
cd Accordion_cpp/
```

2. Install all the dependencies.

   
* The source file `fifo_map.hpp` is needed to copy to `json/include/nlohmann/`.
* After installing all the dependent libraries, it is needed to modify the `Accordion_cpp/CMakeLists.txt` to allow CMake to find all the header files and dynamic link libraries (according to the locations of installed dependencies). Here is an example.
```
include_directories(
        "/home/zxk/dependency/json/include/"
        "/usr/local/include/"
        "/home/zxk/dependency/oneapi-tbb-2021.9.0/include"
)

target_link_libraries(
        Accordion
        pistache
        /usr/local/lib64/libpistache.so
        /usr/local/lib/librestclient-cpp.so
        curl
        arrow
        arrow_acero
        arrow_flight
        gandiva
        libtbb
)
```


3. Build Accordion and copy the Accordion execution file to `Accordion_cpp/accordion/`.
```
cd Accordion_cpp/
mkdir build
cd build
cmake ..
make -j6
cp Accordion ../accordion/
```


4. Build Accordion tools and copy them to `Accordion_cpp/accordion/`.
```
cd accordion_tools/DFSMaker
mkdir build && cd build
cmake .. && make -j6
cp DFSMaker ../../../accordion/dataSet/

cd accordion_tools/partitionsMaker
mkdir build && cd build
cmake .. && make -j6
cp partitionsMaker ../../../accordion/dataSet/

cd accordion_tools/httpConfigIpUpdater
mkdir build && cd build
cmake .. && make -j6
cp httpConfigIpUpdater ../../../accordion/sbin/
```


5. Move `Accordion_cpp/accordion/` to the home directory and check if the Accordion is able to run.
```
cp -r Accordion_cpp/accordion/ ~/
cd ~/accordion/
bash run.sh
```


# Running Accordion stand-alone





