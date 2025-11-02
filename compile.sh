#!/bin/bash
# 这是Turtle项目的编译脚本

echo "🐢 编译Turtle图形程序..."
echo "编译命令: g++ -std=c++11 $@ -lsfml-graphics -lsfml-window -lsfml-system"

# 编译
g++ -std=c++11 -o turtle_demo "$@" -lsfml-graphics -lsfml-window -lsfml-system

# 检查是否编译成功
if [ $? -eq 0 ]; then
    echo "✅ 编译成功！"
    echo "🚀 运行程序..."
    echo "----------------------------------------"
    ./turtle_demo
else
    echo "❌ 编译失败！请检查错误信息。"
fi
