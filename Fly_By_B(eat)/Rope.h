#pragma once
#include <vector>
#include <cmath>

struct Vec2 {
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float _x, float _y) : x(_x), y(_y) {}

    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    void operator+=(const Vec2& o) { x += o.x; y += o.y; }
    void operator-=(const Vec2& o) { x -= o.x; y -= o.y; }

    float Length() const { return std::sqrt(x * x + y * y); }
    Vec2 Normalized() const {
        float len = Length();
        if (len == 0) return Vec2(0, 0);
        return Vec2(x / len, y / len);
    }
};


struct RopePoint {
    Vec2 position;
    Vec2 oldPosition;
    bool pinned; // if true, this point is fixed in space

    RopePoint(const Vec2& pos) : position(pos), oldPosition(pos), pinned(false) {}
};

class Rope {
public:
    Rope(const Vec2& start, const Vec2& end, int segments);

    void Update(float dt, const Vec2& gravity);
    void Draw(); // implement in your rendering system

    std::vector<RopePoint>& GetPoints() { return points; }

private:
    std::vector<RopePoint> points;
    float segmentLength;

    void ApplyConstraints();
};
