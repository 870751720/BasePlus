# 安装vcpkg
如果没有安装vcpkg, 可以去 https://github.com/microsoft/vcpkg 下载
vcpkg\bootstrap-vcpkg.bat 执行
vcpkg\vcpkg integrate install 关联到vs,管理员权限执行

# 查看 boost-property-tree 的所有可用版本
vcpkg search boost-property-tree

# 添加指定版本的 boost-property-tree
vcpkg add port boost-property-tree

# 翻墙cmd网速还慢
cmd执行, 单次生效
set http_proxy=http://127.0.0.1:7890
set https_proxy=http://127.0.0.1:7890