/*
 *  Copyright 2015, DFKI GmbH Robotics Innovation Center
 *
 *  This file is part of the MARS simulation framework.
 *
 *  MARS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  MARS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with MARS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CONFIG_VECTOR_HPP
#define CONFIG_VECTOR_HPP

#ifdef _PRINT_HEADER_
  #warning "ConfigVector.hpp"
#endif

#include <string>
#include <vector>

#include "ConfigItem.hpp"

namespace configmaps {

  class ConfigVector : public ConfigBase,
                       public std::vector<ConfigItem> {
  public:

    ConfigVector(std::string s) : ConfigBase(s) {}
    ConfigVector() {}

    size_t append(const ConfigItem &item) {
      this->push_back(item);
      this->back().setParentName(parentName);
      return this->size() - 1;
    }

    ConfigVector& operator<<(const ConfigItem &item) {
      this->push_back(item);
      this->back().setParentName(parentName);
      return *this;
    }

    ConfigVector& operator+=(const ConfigItem &item) {
      this->push_back(item);
      this->back().setParentName(parentName);
      return *this;
    }    
  }; // end of class ConfigVectorTemplate

} // end of namespace configmaps

#endif // CONFIG_VECTOR_H