CMake v3.25~v3.29
Ubuntu v20.0~v24.0
gcc11~13


dependencies:
Apache Arrow
Apache Pistache
Restclient-cpp
nlnohamn json
nlnohamn json fifomap
tbb
spdlog

compile:
cd Accordion_cpp/
mkdir build
cd build
cmake ..
make

cp Accordion ../accordion/
cp ../accordion/ ~/
cd ~/accordion/
bash run.sh

