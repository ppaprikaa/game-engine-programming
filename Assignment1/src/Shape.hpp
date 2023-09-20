#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

class AShape 
{
   private:
      std::shared_ptr<sf::Shape> m_shape;
      std::shared_ptr<sf::Text> m_text;
      float m_xSpeed = 1.0f;
      float m_ySpeed = 1.0f;
   public:  
      AShape(
               std::shared_ptr<sf::Shape> sf_shape, 
               std::shared_ptr<sf::Text> sf_text,
               float xSpeed, 
               float ySpeed
            )
         :  m_shape(sf_shape),
            m_text(sf_text),
            m_xSpeed(xSpeed),
            m_ySpeed(ySpeed)
      {
      }

      void Move()
      {
         this->m_shape->setPosition(
               this->m_shape->getPosition().x + this->m_xSpeed,
               this->m_shape->getPosition().y + this->m_ySpeed
               );
         this->m_text->setPosition(
               (this->m_shape->getPosition().x + (this->m_shape->getLocalBounds().getSize().x - this->m_text->getLocalBounds().getSize().x) / 2.0f),
               (this->m_shape->getPosition().y + (this->m_shape->getLocalBounds().getSize().y - this->m_text->getLocalBounds().getSize().y) / 2.0f)
               );
      }

      void ReverseXSpeed()
      {
         this->m_xSpeed *= -1;
      }

      void ReverseYSpeed()
      {
         this->m_ySpeed *= -1;
      }

      bool CollidesX(float a, float b) const 
      {
         if ((this->m_shape->getPosition().x <= a) || (this->m_shape->getPosition().x >= b - this->m_shape->getLocalBounds().getSize().x))
            return true;
         return false;
      }

      bool CollidesY(float a, float b) const
      {
         if((this->m_shape->getPosition().y <= a) || (this->m_shape->getPosition().y >= b - this->m_shape->getLocalBounds().getSize().y))
            return true;
         return false;
      }

      std::shared_ptr<sf::Shape> GetSfShape() const
      {
         return this->m_shape;
      }

      std::shared_ptr<sf::Text> GetSfText() const
      {
         return m_text;
      }

      const std::string to_string() const {
         return this->m_text->getString();
      }
};
