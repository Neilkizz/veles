/*! @file unit_registry.cc
 *  @brief Implements Veles::UnitFactory class.
 *  @author markhor
 *  @version 1.0
 *
 *  @section Notes
 *  This code partially conforms to <a href="http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml">Google C++ Style Guide</a>.
 *
 *  @section Copyright
 *  Copyright 2013 Samsung R&D Institute Russia
 */

#include "src/unit_registry.h"
#include <cstdio>
#include <string>

namespace Veles {

UnitFactory::UnitFactory() {
}

UnitFactory::~UnitFactory() {
}

const UnitFactory& UnitFactory::Instance() {
  return InstanceRW();
}

UnitFactory& UnitFactory::InstanceRW() {
  static UnitFactory instance;
  return instance;
}

UnitFactory::UnitConstructor UnitFactory::operator[](
    const std::string& name) const {
  auto f = map_.find(name);
  if (f != map_.end()) {
    return f->second;
  }
  return nullptr;
}

void UnitFactory::PrintRegisteredUnits() const {
  for (auto tit : map_) {
    std::printf("%s\n", tit.first.c_str());
  }
}

}  // namespace Veles
