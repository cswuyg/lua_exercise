cjson.so 
功能：json解析库
来源：https://www.kyne.com.au/~mark/software/lua-cjson.php
版本：lua-cjson-2.1.0
引入方法：源码目录下修改makefile文件的PREFIX，指定为lua安装目录，执行make，得到cjson.so

core.so & md5.so 
功能：md5计算库
来源：https://github.com/keplerproject/md5/tree/v1.2
版本：md5-1.2
引入方法：源码目录下修改config，指定lua的安装目录；执行make && make install得到core.so以及md5.lua，并修改md5.lua，以支持我们自定义的嵌入




