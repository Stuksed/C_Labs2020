#pragma once
enum Direction
{
    None = 0,
    Down = 1 << 0,
    Right = 1 << 1,
    RightDown = Down | Right
};
