CMake v3.25 ~ v3.29
Ubuntu v20.0 ~ v24.0
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


##Dependencies

Accordion has the following third party dependencies

* [@apache arrow](https://github.com/apache/arrow)

* [@pistache](https://github.com/pistacheio/pistache)

* [@restclient-cpp](https://github.com/mrtazz/restclient-cpp)

* [@nlnohamn json](https://github.com/nlohmann/json)

* [@nlnohamn json fifomap](https://github.com/nlohmann/fifo_map)

* [@tbb](https://github.com/oneapi-src/oneTBB)

* [@spdlog](https://github.com/gabime/spdlog)


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
