#pragma once
#include "ECS.hpp"

class PositionComponent : public Component
{
    private:
        int xpos = 0;
        int ypos  = 0;
    
    public:
        int x()
        {
            return xpos;
        }
        int y()
        {
            return ypos;
        }

        void init() override
        {
            xpos = 0;
            ypos = 0;
        }

        void update() ovveride
        {
            xpos++;
            ypos++;
        }

        void setPos(int x.int y)
        {
            xpos = x;
            ypos = y;
        }
};