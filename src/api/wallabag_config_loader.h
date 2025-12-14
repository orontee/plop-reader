#ifndef API_WALLABAG_CONFIG_LOADER_H_
#define API_WALLABAG_CONFIG_LOADER_H_

#include "inkview.h"
#include "json-c/json.h"

#include "../defines.h"
#include "../exceptions.h"
#include "../log.h"
#include "wallabag_config.h"

#include "../translate.h"

class WallabagConfigLoader {
public:
  auto load() -> WallabagConfig;

private:
  const char *CONFIG_FILE = PLOP_BASE_DIRECTORY "/config.json";

  auto readConfigFile(const char *path) -> char *;
};

#endif /* API_WALLABAG_CONFIG_LOADER_H_ */
