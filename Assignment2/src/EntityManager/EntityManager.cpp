#include "EntityManager.hpp"
#include <algorithm>
#include <memory>
#include <iostream>

EntityManager::EntityManager() {}

std::shared_ptr<Entity> EntityManager::addEntity(const EntityTag::Tag & tag)
{
   auto e = std::shared_ptr<Entity>(new Entity(tag));
   this->m_toAdd.push_back(e);
   return e;
}

bool IsDead(const std::shared_ptr<Entity> e)
{
   return !e->isActive();
}

void EntityManager::update()
{
   for (auto e : this->m_toAdd)
   {
      this->m_entities.push_back(e);
      this->m_entityTagMap[e->tag()].push_back(e);
   }

   this->m_toAdd.clear();


   auto newEnd = std::remove_if(this->m_entities.begin(), this->m_entities.end(), IsDead);
   this->m_entities.erase(newEnd, this->m_entities.end());
   for (auto & [_, vec] : this->m_entityTagMap)
   {
      auto newTagVecEnd = std::remove_if(vec.begin(), vec.end(), IsDead);
      vec.erase(newTagVecEnd, vec.end());
   }
}

const EntityVector & EntityManager::getEntities()
{
   return this->m_entities;
}

const EntityVector & EntityManager::getEntities(const EntityTag::Tag & tag)
{
   return this->m_entityTagMap[tag];
}
