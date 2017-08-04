#include "Player.hpp"

Player::Player()
{
}

Player::Player(const Vec2f& aSize, const Vec2f& aPos)
{
    vertex[0] = geometry[0] = {-aSize.x / 2, +aSize.y / 2};
    vertex[1] = geometry[1] = {+aSize.x / 2, +aSize.y / 2};
    vertex[2] = geometry[2] = {+aSize.x / 2, -aSize.y / 2};
    vertex[3] = geometry[3] = {-aSize.x / 2, -aSize.y / 2};
    
//    uv[0] = {0.0f, 1.0f};
//    uv[1] = {1.0f, 1.0f};
//    uv[2] = {1.0f, 0.0f};
//    uv[3] = {0.0f, 0.0f};
    
    mStatus = Type::RIGHT01;
    RefreshUv(mStatus);
    pos = aPos;
    size = aSize;
    
    for(size_t i = 0; i < 4; i++)
    {
        geometry[i].x = pos.x + vertex[i].x;
        geometry[i].y = pos.y + vertex[i].y;
    }
}

Player::~Player()
{
}

void Player::Update(Type aType)
{
    mStatus = aType;
    RefreshUv(mStatus);
}

void Player::RefreshUv(Type aType)
{
    float y = (int)aType / uvMaxHorizontal; //行
    int x = (int)aType % (int)uvMaxHorizontal; //列
    
    //static_castを使用
    float uv_X01 = x / (float)uvMaxHorizontal; //x01 0
    float uv_X02 = (x + 1) / (float)uvMaxHorizontal; //x02 1
    
    
    float uv_Y01 = 1 - y / uvMaxVertical;
    float uv_Y02 = 1 - ((y + 1) / uvMaxVertical);
    
    
    uv[0] = { uv_X01, uv_Y01 };
    uv[1] = { uv_X02, uv_Y01 };
    uv[2] = { uv_X02, uv_Y02 };
    uv[3] = { uv_X01, uv_Y02 };
    
//    uv[0] = { (0.0f + (int)aType) / uvMaxHorizontal, (1.0f + (int)aType) / uvMaxVertical };
//    uv[1] = { (1.0f + (int)aType) / uvMaxHorizontal, (1.0f + (int)aType) / uvMaxVertical };
//    uv[2] = { (1.0f + (int)aType) / uvMaxHorizontal, (0.0f + (int)aType) / uvMaxVertical };
//    uv[3] = { (0.0f + (int)aType) / uvMaxHorizontal, (0.0f + (int)aType) / uvMaxVertical };
}

void Player::MoveHorizontal(float value)
{
    pos.x += value;
}

void Player::MoveVertical(float value)
{
    pos.y += value;
}
