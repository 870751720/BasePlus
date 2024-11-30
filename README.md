# EasyCPlusPlus

# 安装

1 确保安装了推荐插件cmaketools

2 
确保安装了vs 2022,确保Visual Studio 2022中安装了"使用C++的桌面开发"工作负载, 确保有英文语言包
修改系统区域设置:
打开控制面板 -> 时钟和区域-> 区域
切换到"管理"标签
点击"更改系统区域设置"
勾选"使用 Unicode UTF-8 提供全球语言支持"
重启系统

3 安装vcpkg
git clone git@github.com:microsoft/vcpkg.git

vkpkg\bootstrap-vcpkg.bat
vkpkg\vcpkg integrate install
最后调用tools/initEnv.bat 输入vcpkg的目录名(exe的上一层)

4 安装依赖库
对着Requirements.txt的库安装就好

5 使用
在CMakeTool上,配置里面可以切debug和release
在项目大纲上对具体的app右键设置为启动调试目标可以切换运行
