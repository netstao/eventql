/**
 * Copyright (c) 2016 zScale Technology GmbH <legal@zscale.io>
 * Authors:
 *   - Paul Asmuth <paul@zscale.io>
 *   - Laura Schlimmer <laura@zscale.io>
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License ("the license") as
 * published by the Free Software Foundation, either version 3 of the License,
 * or any later version.
 *
 * In accordance with Section 7(e) of the license, the licensing of the Program
 * under the license does not imply a trademark license. Therefore any rights,
 * title and interest in our trademarks remain entirely with us.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You can be released from the requirements of the license by purchasing a
 * commercial license. Buying such a license is mandatory as soon as you develop
 * commercial activities involving this program without disclosing the source
 * code of your own applications
 */
#include <eventql/config/process_config.h>
#include <inih/ini.h>

namespace eventql {

ProcessConfig::ProcessConfig(
      Vector<Pair<String, String>> properties) :
      properties_(properties) {}

Option<String> ProcessConfig::getProperty(const String& key) const {
  for (auto p : properties_) {
    if (p.first == key) {
      return Some(p.second);
    }
  }

  return None<String>();
}

Status ProcessConfigBuilder::loadFile(const String& file) {
  return Status(eParseError);
}

void ProcessConfigBuilder::setProperty(const String& key, const String& value) {
  Pair<String, String> p;
  p.first = key;
  p.second = value;
  properties_.emplace_back(p);
}

void ProcessConfigBuilder::setProperty(
    const String& section,
    const String& key,
    const String& value) {
  setProperty(StringUtil::format("$0.$1", section, key), value);
}

ProcessConfig ProcessConfigBuilder::getConfig() {
  return ProcessConfig(properties_);
}


} // namespace eventql




