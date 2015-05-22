#include "fonts.hpp"

#include <iostream>

#include "utils.hpp"

std::unique_ptr<Fonts> Fonts::s_instance;

void Fonts::init(const std::string& directory_path)
{
  // Initialize only once
  if(s_instance)
    return;

  s_instance.reset( new Fonts(directory_path) );
}

Fonts::Fonts(const std::string& directory_path)
  : m_directory_path{ ensureDirEnd(directory_path) }
{}

void Fonts::load(const std::string& name)
{
  m_resources[name].loadFromFile( m_directory_path + name );
}

const sf::Font* Fonts::get(const std::string& name)
{
  if(!s_instance)
  {
    std::cerr << "Trying to use an uninitailized Fonts manager!" << std::endl;
    return nullptr;
  }

  // Try to find already loaded resource
  auto found = s_instance->m_resources.find(name);
  if( found != s_instance->m_resources.end() )
    return &(found->second);

  // Resource isn't in memory, let's load it
  s_instance->load(name);
  return &s_instance->m_resources[name];
}
