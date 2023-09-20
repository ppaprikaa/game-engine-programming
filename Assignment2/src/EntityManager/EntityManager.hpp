#pragma once
#include "../Entities/Entity.hpp"
#include <cstddef>
#include <map>
#include <memory>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> EntityVector;
typedef std::map<EntityTag::Tag, EntityVector> EntityTagMap;
class EntityManager
{
   private:
      EntityVector m_entities;
      EntityVector m_toAdd;
      EntityTagMap m_entityTagMap;
      size_t m_totalEntities = 0;
   public:
      EntityManager();
      void update();
      std::shared_ptr<Entity> addEntity(const EntityTag::Tag & tag);
      const EntityVector & getEntities();
      const EntityVector & getEntities(const EntityTag::Tag & tag);
};
