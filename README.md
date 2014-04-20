# BoostPolygonNewbie #
==================

Boost的Polygon库功能很强大，不过文档比较简陋，因此提供几个简洁的用例

希望能包含一下功能：

1）使用STL与Polygon中Rect、Polygon的交互，即数据的转换

2）多边形的求与、并操作、判断接壤

3）多边形划分（该功能在芯片设计中具有很大作用，比如将boundary进行矩形划分提取OBS）

## 初始化 ##
本工程建立在[boost_1_55_0](http://http://www.boost.org/users/download/)版本，用户需要自行下载Boost库，并在工程中设置包含目录。

同时，boost的polygon在git上位置为：[https://github.com/boostorg/boost](https://github.com/boostorg/boost)
