#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Turtle {
private:
    sf::RenderWindow& window;
    sf::Vector2f position;
    float angle; // 角度，0表示向右
    bool penDown;
    sf::Color penColor;
    float penWidth;
    std::vector<sf::Vertex> lines;
    
public:
    // 构造函数
    Turtle(sf::RenderWindow& win, float startX, float startY) 
        : window(win), position(startX, startY), angle(0), penDown(true), 
          penColor(sf::Color::Green), penWidth(2.0f) {}
    
    Turtle(sf::RenderWindow& win) 
        : Turtle(win, win.getSize().x/2.0f, win.getSize().y/2.0f) {}
    
    // 移动命令
    void forward(float distance) {
        sf::Vector2f newPos = position;
        float rad = angle * M_PI / 180.0f;  // 修复：提前计算弧度
        newPos.x += distance * std::cos(rad);
        newPos.y += distance * std::sin(rad);
        
        if (penDown) {
            lines.emplace_back(position, penColor);
            lines.emplace_back(newPos, penColor);
        }
        
        position = newPos;
    }
    
    void backward(float distance) {
        forward(-distance);
    }
    
    // 转向命令
    void right(float degrees) {
        angle += degrees;
    }
    
    void left(float degrees) {
        angle -= degrees;
    }
    
    // 笔控制
    void penup() {
        penDown = false;
    }
    
    void pendown() {
        penDown = true;
    }
    
    // 颜色设置
    void color(const sf::Color& col) {
        penColor = col;
    }
    
    void color(unsigned char r, unsigned char g, unsigned char b) {
        penColor = sf::Color(r, g, b);
    }
    
    // 位置控制 - 修复：goto改为go_to
    void go_to(float x, float y) {
        if (penDown) {
            lines.emplace_back(position, penColor);
            lines.emplace_back(sf::Vector2f(x, y), penColor);
        }
        position = sf::Vector2f(x, y);
    }
    
    void setposition(float x, float y) {
        position = sf::Vector2f(x, y);
    }
    
    // 获取位置 - 修复：与成员变量名冲突
    std::pair<float, float> get_position() const {
        return {position.x, position.y};
    }
    
    // 绘制
    void draw() {
        if (!lines.empty()) {
            window.draw(&lines[0], lines.size(), sf::Lines);
        }
        
        // 绘制乌龟图标（简单三角形）
        sf::ConvexShape turtle(3);
        turtle.setPoint(0, sf::Vector2f(10, 0));
        turtle.setPoint(1, sf::Vector2f(-5, -5));
        turtle.setPoint(2, sf::Vector2f(-5, 5));
        turtle.setFillColor(sf::Color::Red);
        turtle.setPosition(position);
        turtle.setRotation(angle);
        window.draw(turtle);
    }
    
    // 清屏
    void clear() {
        lines.clear();
        position = sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f);
        angle = 0;
    }
    
    // 设置笔宽
    void width(float w) {
        penWidth = w;
    }
    
    // 获取当前角度
    float heading() const {
        return angle;
    }
    
    // 设置角度
    void set_heading(float new_angle) {
        angle = new_angle;
    }
};

#endif // TURTLE_H