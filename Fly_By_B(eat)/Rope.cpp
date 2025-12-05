#include "Rope.h"
#include <iostream>



Rope::Rope(const Vec2& start, const Vec2& end, int segments) {
    points.clear();
    for (int i = 0; i <= segments; ++i) {
        float t = float(i) / segments;
        Vec2 pos = start * (1 - t) + end * t;
        points.push_back(RopePoint(pos));
    }
    points.front().pinned = true; // anchor first point
    segmentLength = (end - start).Length() / segments;
}

void Rope::Update(float dt, const Vec2& gravity) {
    // Verlet integration
    for (auto& p : points) {
        if (p.pinned) continue;

        Vec2 velocity = p.position - p.oldPosition;
        p.oldPosition = p.position;
        p.position += velocity;
        p.position += gravity * dt * dt;
    }

    // Apply constraints multiple times for stability
    for (int i = 0; i < 5; ++i) ApplyConstraints();
}

void Rope::ApplyConstraints() {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        RopePoint& p1 = points[i];
        RopePoint& p2 = points[i + 1];

        Vec2 delta = p2.position - p1.position;
        float dist = delta.Length();
        float diff = (dist - segmentLength) / dist;

        if (!p1.pinned) p1.position += delta * 0.5f * diff;
        if (!p2.pinned) p2.position -= delta * 0.5f * diff;
    }
}

void Rope::Draw() {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        Vec2& p1 = points[i].position;
        Vec2& p2 = points[i + 1].position;
        // Replace with your rendering:
        std::cout << "Draw line: (" << p1.x << "," << p1.y << ") -> (" << p2.x << "," << p2.y << ")\n";
    }
}
