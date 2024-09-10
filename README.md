# Accordion

The first IQRE(Intra-Query Runtime Elasticity) SQL query engine (prototype version).

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

After installing all the dependent libraries, it is needed to modify the `Accordion_cpp/CMakeLists.txt` to allow CMake to find all the header files and dynamic link libraries (according to the locations of installed dependencies). Here is an example.
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


5. Move `Accordion_cpp/accordion/` to the home directory and check the Accordion is able to run.
```
cp -r Accordion_cpp/accordion/ ~/
cd ~/accordion/
bash run.sh
```









##MaHua是什么?
一个在线编辑markdown文档的编辑器

##MaHua有哪些功能？

* 方便的`导入导出`功能
    *  直接把一个markdown的文本文件拖放到当前这个页面就可以了
    *  导出为一个html格式的文件，样式一点也不会丢失
* 编辑和预览`同步滚动`，所见即所得（右上角设置）
* `VIM快捷键`支持，方便vim党们快速的操作 （右上角设置）
* 强大的`自定义CSS`功能，方便定制自己的展示
* 有数量也有质量的`主题`,编辑器和预览区域
* 完美兼容`Github`的markdown语法
* 预览区域`代码高亮`
* 所有选项自动记忆

##有问题反馈
在使用中有任何问题，欢迎反馈给我，可以用以下联系方式跟我交流

* 邮件(dev.hubo#gmail.com, 把#换成@)
* 微信:jserme
* weibo: [@草依山](http://weibo.com/ihubo)
* twitter: [@ihubo](http://twitter.com/ihubo)

##捐助开发者
在兴趣的驱动下,写一个`免费`的东西，有欣喜，也还有汗水，希望你喜欢我的作品，同时也能支持一下。
##感激
感谢以下的项目,排名不分先后

* [ace](http://ace.ajax.org/)
* [jquery](http://jquery.com)

##关于作者

```javascript
var ihubo = {
  nickName  : "草依山",
  site : "http://jser.me"
}
```
