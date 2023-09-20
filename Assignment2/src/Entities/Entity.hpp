#pragma once
#include <cstddef>
#include <memory>
#include "Tag.hpp"
#include "../Components/Components.hpp"

class Entity
{
   private:
      static size_t m_gid;
      const size_t m_id = 0;
      const EntityTag::Tag m_tag = EntityTag::Default;
      bool m_active = true;

      Entity(EntityTag::Tag tag);
   public:
      std::shared_ptr<CTransform> cTransform;
      std::shared_ptr<CShape> cShape;
      std::shared_ptr<CCollision> cCollision;
      std::shared_ptr<CInput> cInput;
      std::shared_ptr<CScore> cScore;
      std::shared_ptr<CLifespan> cLifespan;
      std::shared_ptr<CCrosshair> cCrosshair;

      const size_t id() const;
      const EntityTag::Tag & tag() const;
      bool isActive() const;
      void destroy();

      friend class EntityManager;
};
