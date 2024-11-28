# EasyCPlusPlus

# 安装
1 确保安装了推荐插件cmaketools

2 确保安装了vs 2022,确保Visual Studio 2022中安装了"使用C++的桌面开发"工作负载, 确保有英文语言包

3 安装vcpkg
git clone https://github.com/Microsoft/vcpkg.git
确保vcpkg在 C:\app
.\bootstrap-vcpkg.bat
.\vcpkg integrate install

4 使用
在CMakeTool上,配置里面可以切debug和release
在项目大纲上对具体的app右键设置为启动调试目标可以切换运行
