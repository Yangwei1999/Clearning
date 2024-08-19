
git add .

git commit -m "auto commit"

echo "正在推送更改到远程仓库gitee..."
git push -u gitee main

echo "正在推送更改到远程仓库github..."
git push -u github main

echo "推送已完成“