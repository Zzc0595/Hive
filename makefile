# 编译器设置
CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = myapp

# 目录设置
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# 源文件
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# 创建目录
$(shell mkdir -p $(BUILDDIR) $(BINDIR))

# 默认目标
all: $(BINDIR)/$(TARGET)

# 链接
$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# 编译
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# 运行
run: all
	./$(BINDIR)/$(TARGET)

.PHONY: all clean run