#ifndef API_WALLABAG_ENTITIES_FACTORY_H_
#define API_WALLABAG_ENTITIES_FACTORY_H_

#include "json-c/json.h"
#include <cstdio>
#include <cstring>

#include "../entities/entry.h"

class WallabagEntitiesFactory {
public:
  auto createEntryFromJson(json_object *item) -> Entry;
  auto mergeLocalAndRemoteEntries(Entry &local, Entry &remote) -> Entry;

private:
  time_t datetimeStringToTimeT(const char *str);
};

#endif /* API_WALLABAG_ENTITIES_FACTORY_H_ */
