# 安装vcpkg
vs installer 的单个组件的 有vcpkg包管理器
管理员模式下 cd C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg
执行 vcpkg integrate install
# 从零开始一个新工程
1 创建一个空白解决方案
2 添加一个新建项目 控制台应用 即可
3 项目新建 Include Source文件夹
4 属性页的vcpkg的 Use Vcpkg Manifest 设置为 是
5 在项目文件夹执行 "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" new --application
6 后续添加新依赖就比如 "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\vcpkg\vcpkg.exe" add port boost-property-tree
7 可以在项目右键添加 新建 EditorConfig