#pragma once
class MCell
{
    friend class Maze;
    MCell();
    bool m_down = false;
    bool m_right = false;
public:
    bool right() const;
    bool down() const;
};
