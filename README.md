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

**1. Get Accordion source code from Git Hub.**
```
git clone https://github.com/Blueratzxk/Accordion_cpp
cd Accordion_cpp/
```

**2. Install all the dependencies.**

   
* The source file `fifo_map.hpp` needs to be copied to `json/include/nlohmann/`.
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


**3. Build Accordion and copy the Accordion execution file to `Accordion_cpp/accordion/`.**
```
cd Accordion_cpp/
mkdir build
cd build
cmake ..
make -j6
cp Accordion ../accordion/
```


**4. Build Accordion tools and copy them to `Accordion_cpp/accordion/`.**
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


**5. Move `Accordion_cpp/accordion/` to the home directory and check if the Accordion is able to run.**
```
cp -r Accordion_cpp/accordion/ ~/
cd ~/accordion/
bash run.sh
```


# Running Accordion stand-alone

```
cd accordion/
```
**1. Configure the Accordion.**
* Modify the `httpconfig.config` file.
Change all IP addresses in the file to the host IP address. Here is an example.

```
{
    "coordinator":{
        "Restful_Web_Server_IP":"192.168.226.137",
        "Restful_Web_Server_Port":"9080",
        "Arrow_RPC_Server_IP":"192.168.226.137",
        "Arrow_RPC_Server_Port":"9081"
    },
    "local":{
        "Restful_Web_Server_IP":"192.168.226.137",
        "Restful_Web_Server_Port":"9080",
        "Arrow_RPC_Server_IP":"192.168.226.137",
        "Arrow_RPC_Server_Port":"9081"
    },
    "nic":"ens33",
    "HttpServerAddress":"192.168.226.137:9080"
}
```
* Add workers.
```
echo "192.168.226.137" > sbin/slaves
```
* Config the workers' user and password
```
echo -e "root\nroot" >  userpasswd
```

**2. Import TPC-H dataSet.**

* Get dbgen tools from [TPC-H](https://www.tpc.org/tpch/).
* Generate TPC-H tables and copy them to `accordion/dataSet/`. Below is an example.
```
$cd dataSet
$ls
customer.tbl  makeDFS.sh       PartitionsMaker.sh  scpFile.sh
DFSMaker      nation.tbl       partsupp.tbl        supplier.tbl
DFSMaker.sh   orders.tbl       part.tbl            tablePartitions.txt
lineitem.tbl  partitionsMaker  region.tbl

```
* Modify the `tablePartitions.txt`. The first column is the table name, the second column is the number of storage nodes, and the third column is the number of table slices contained in each storage node. Below is an example. Since we are running Accordion on a single machine, there is only 1 storage node. This configuration slices the ORDERS table and LINEITEM table horizontally into 4 partitions.
```
nation,1,1
supplier,1,1
region,1,1
part,1,1
partsupp,1,1
customer,1,1
orders,1,4
lineitem,1,4
```
* Generate the `DataFileDicts`. This file contains information about the storage configuration, schema, etc. for each table.
```
bash PartitionsMaker.sh
```

* Overwrite the DataFileDict file in the accordion directory.
```
cp DataFileDicts.out ../DataFileDicts
```

* Generate partitions for each table.
```
$bash DFSMaker.sh
$ls
customer.tbl       lineitem.tbl_1  orders.tbl_0        partsupp.tbl
DataFileDicts.out  lineitem.tbl_2  orders.tbl_1        part.tbl
DFSMaker           lineitem.tbl_3  orders.tbl_2        region.tbl
DFSMaker.sh        makeDFS.sh      orders.tbl_3        scpFile.sh
lineitem.tbl       nation.tbl      partitionsMaker     supplier.tbl
lineitem.tbl_0     orders.tbl      PartitionsMaker.sh  tablePartitions.txt
```
* Move these partitions to `accordion/data/`
```
bash makeDFS.sh
```

**3. Run TPC-H Queries.**
* Run Accordion.
```
cd ..
bash run.sh
```
* The WEB UI of Accordion can be accessed through IP:9082 (for example, 192.168.226.137:9082). Here is an example.
 
![image](https://raw.githubusercontent.com/Blueratzxk/Accordion_cpp/master/imgs/UI1.png)

* Enter "run Q1S" in the left input box to run TPC-H Q1. There are 12 TPC-H queries in Accordion (Q1 ~ Q12).

![image](https://raw.githubusercontent.com/Blueratzxk/Accordion_cpp/master/imgs/UI2.png)

* Click the `Control` button to enter the query control panel, you can adjust the query stage parallelism and task parallelism.

![image](https://raw.githubusercontent.com/Blueratzxk/Accordion_cpp/master/imgs/UI3.png)

* Click the `Complete` button to get the results of the query execution. 

![image](https://raw.githubusercontent.com/Blueratzxk/Accordion_cpp/master/imgs/UI4.png)  
