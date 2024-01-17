#pragma once

#include <memory>
#include <vector>

#include <SDL.h>

#include "Math.hpp"
#include "Rect.hpp"
#include "RenderWindow.hpp"
#include "Texture.hpp"

namespace kn
{

/**
 * @brief An entity to be inherited from.
 */
class Entity
{
  public:
    /**
     * @brief Create a entity.
     *
     * @param texture The texture of the entity.
     */
    explicit Entity(std::shared_ptr<Texture> texture);
    ~Entity() = default;

    /**
     * @brief Get the entity's texture pointer.
     *
     * @return The entity's texture pointer.
     */
    std::shared_ptr<Texture> getTexture() const;

    Rect crop;
    Rect rect;
    math::Vec2 position;
    math::Vec2 direction;
    math::Vec2 velocity;

  protected:
    RenderWindow& window = RenderWindow::get();
    std::shared_ptr<Texture> texture;

    bool onGround = false;
    bool onCeiling = false;

    /**
     * @brief Move the entity while checking for collisions.
     *
     * @param deltaTime The time since the last frame.
     * @param others The other entities to check for collisions with.
     */
    template <typename T>
    void moveAndCollide(double deltaTime, const std::vector<std::shared_ptr<T>>& others)
    {
        onGround = false;
        onCeiling = false;

        position += (velocity * deltaTime);
        rect.x = position.x - rect.w / 2.0f;

        for (const auto& entity : others)
        {
            if (entity.get() != this)
            {
                if (rect.collideRect(entity->rect))
                {
                    if (velocity.x > 0)
                    {
                        rect.setRight(entity->rect.getLeft());
                    }
                    else if (velocity.x < 0)
                    {
                        rect.setLeft(entity->rect.getRight());
                    }

                    velocity.x = 0;
                    position = rect.getCenter();
                }
            }
        }

        position.y += (velocity.y * deltaTime);
        rect.y = position.y - rect.h / 2.0f;

        for (const auto& entity : others)
        {
            if (entity.get() != this)
            {
                if (rect.collideRect(entity->rect))
                {
                    if (velocity.y > 0)
                    {
                        rect.setBottom(entity->rect.getTop());
                        onGround = true;
                    }
                    else if (velocity.y < 0)
                    {
                        rect.setTop(entity->rect.getBottom());
                        onCeiling = true;
                    }

                    velocity.y = 0;
                    position = rect.getCenter();
                }
            }
        }
    }
};

} // namespace kn
