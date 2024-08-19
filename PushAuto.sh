#!/bin/bash

# 读取位置参数
param1=$1

# 打印读取的参数
echo "提交信息为: $param1"

git add .

git commit -m "$param1"

echo "正在推送更改到远程仓库gitee..."
git push -u gitee main

echo "正在推送更改到远程仓库github..."
git push -u github main

echo "推送已完成：$param1"