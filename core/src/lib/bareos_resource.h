/*
   BAREOS® - Backup Archiving REcovery Open Sourced

   Copyright (C) 2000-2010 Free Software Foundation Europe e.V.
   Copyright (C) 2011-2012 Planets Communications B.V.
   Copyright (C) 2013-2018 Bareos GmbH & Co. KG

   This program is Free Software; you can redistribute it and/or
   modify it under the terms of version three of the GNU Affero General Public
   License as published by the Free Software Foundation and included
   in the file LICENSE.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/

#ifndef BAREOS_LIB_BAREOS_RESOURCE_H_
#define BAREOS_LIB_BAREOS_RESOURCE_H_

#include "lib/common_resource_header.h"

class PoolMem;
class ConfigurationParser;

/*
 * Base Class for all Resource Classes
 */
class BareosResource {
 public:
  CommonResourceHeader hdr;

  /* Methods */
  inline char* name() const { return this->hdr.name; }
  bool PrintConfig(PoolMem& buf,
                   const ConfigurationParser& my_config,
                   bool hide_sensitive_data = false,
                   bool verbose = false);
  /*
   * validate can be defined by inherited classes,
   * when special rules for this resource type must be checked.
   */
  // virtual inline bool validate() { return true; };
};

#endif /* BAREOS_LIB_BAREOS_RESOURCE_H_ */
