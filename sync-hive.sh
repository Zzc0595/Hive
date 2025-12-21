#!/bin/bash
# Hive 项目同步脚本

set -e  # 遇到错误立即停止

cd ~/Hive

echo "🔄 [$HOSTNAME] 正在同步 Hive 项目..."
# 显示设备标识
echo "设备: $HOSTNAME ($(uname -s))"
echo "时间: $(date)"

# 显示变更
echo "📋 变更文件："
git status --short

# 添加所有更改
git add .

# 如果有更改就提交
if ! git diff --cached --quiet; then
    git commit -m "自动同步 $(date '+%Y-%m-%d %H:%M:%S')"
    echo "✅ 已提交更改"
else
    echo "⏭️  没有需要提交的更改"
fi

# 拉取最新代码
echo "⬇️  拉取远程更新..."
git pull --rebase origin main

# 推送更改
echo "⬆️  推送更改..."
git push origin main

echo "🎉 同步完成！"
