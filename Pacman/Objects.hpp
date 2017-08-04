#ifndef Objects_hpp
#define Objects_hpp

#include "Define.hpp"
#include "Sprite.hpp"

static constexpr Vec2f OBJECTS_SIZE = { 0.2f, 0.2f };

class Objects : public Sprite<DEFAULT_VERTS_COUNT>
{
public:
    enum class Type
    {
        BLANK = 0,
        EGG,
        WALL
    };
public:
    Objects();
    Objects(const Vec2f& aSize, const Vec2f& aPos);
    
    ~Objects();
    
    void Update(Type aType);
    void RefreshUv(Type aType);
    
public:
    Type mStatus;
};

#endif /* Objects_hpp */
