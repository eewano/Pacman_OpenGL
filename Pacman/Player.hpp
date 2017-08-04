#ifndef Player_hpp
#define Player_hpp

#include "Define.hpp"
#include "Sprite.hpp"

static constexpr Vec2f PLAYER_SIZE = { 0.2f, 0.2f };

class Player : public Sprite<DEFAULT_VERTS_COUNT>
{
public:
    enum class Type
    {
        RIGHT01 = 0,
        RIGHT02,
        LEFT01,
        LEFT02,
        UP01,
        UP02,
        DOWN01,
        DOWN02
    };
    
public:
    Player();
    Player(const Vec2f& aSize, const Vec2f& aPos);
    
    ~Player();
    
    void Update(Type aType);
    void RefreshUv(Type aType);
    void MoveHorizontal(float value);
    void MoveVertical(float value);
    
public:
    int uvMaxHorizontal = 2;
    int uvMaxVertical = 4;
    Type mStatus;
};

#endif /* Player_hpp */
