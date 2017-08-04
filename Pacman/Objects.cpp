#include "Objects.hpp"

Objects::Objects()
{
}

Objects::Objects(const Vec2f& aSize, const Vec2f& aPos)
{
    vertex[0] = geometry[0] = {-aSize.x / 2, +aSize.y / 2};
    vertex[1] = geometry[1] = {+aSize.x / 2, +aSize.y / 2};
    vertex[2] = geometry[2] = {+aSize.x / 2, -aSize.y / 2};
    vertex[3] = geometry[3] = {-aSize.x / 2, -aSize.y / 2};
    
    mStatus = Type::BLANK;
    RefreshUv(mStatus);
    pos = aPos;
    size = aSize;
}

Objects::~Objects()
{
}

void Objects::Update(Type aType)
{
    mStatus = aType;
    RefreshUv(mStatus);
}

void Objects::RefreshUv(Type aType)
{
    uv[0] = {(0.0f + (int)aType) / 3.0f, 1.0f};
    uv[1] = {(1.0f + (int)aType) / 3.0f, 1.0f};
    uv[2] = {(1.0f + (int)aType) / 3.0f, 0.0f};
    uv[3] = {(0.0f + (int)aType) / 3.0f, 0.0f};
}
