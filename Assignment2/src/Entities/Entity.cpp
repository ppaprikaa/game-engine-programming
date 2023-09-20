#include "Entity.hpp"
#include "Tag.hpp"
#include <iostream>
#include <cstddef>

size_t Entity::m_gid = 1;

Entity::Entity(EntityTag::Tag tag)
   : m_tag(tag), m_id(this->m_gid++)
{}

const size_t Entity::id() const
{
   return m_id;
}

bool Entity::isActive() const
{
   return this->m_active;
}

const EntityTag::Tag & Entity::tag() const
{
   return this->m_tag;
}

void Entity::destroy()
{
   this->m_active = false;
}
