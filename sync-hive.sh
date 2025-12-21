#!/bin/bash

set -e  # 遇到错误立即停止

cd ~/Hive

echo "🔄 [$HOSTNAME] Syncing Hive project..."
# 显示设备标识
echo "Device: $HOSTNAME ($(uname -s))"
echo "Date: $(date)"

# 显示变更
echo "Changed files:"
git status --short

# 添加所有更改
git add .

# 如果有更改就提交
if ! git diff --cached --quiet; then
    git commit -m "自动同步 $(date '+%Y-%m-%d %H:%M:%S')"
    echo "Commited"
else
    echo "No changes need to commit"
fi

# 拉取最新代码
echo "Pulling"
git pull --rebase origin main

# 推送更改
echo "Pushing"
git push origin main

echo "Update successfully!"
