#include "Math.h"
#include<math.h>

void Math::normalizeVector(sf::Vector2f &direction){
            float m;
            m=std::sqrt((direction.x*direction.x)+(direction.y*direction.y));
            direction/=m;
        }