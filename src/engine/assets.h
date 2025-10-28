#ifndef ENGINE_ASSETS_H_
#define ENGINE_ASSETS_H_

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#define INCBIN_PREFIX app_data_


#define ASSET_PATH(file) GBL_STRINGIFY(project/assets/file)

#define app_asset_embed_text(name, path) INCTXT(name, path)
#define app_asset_embed(name, path) INCBIN(name, path)
#define app_asset_data(name) GBL_GLUE(app_data_, GBL_GLUE(name, _data))
#define app_asset_end_ptr(name) GBL_GLUE(app_data_, GBL_GLUE(name, end))
#define app_asset_size(name) GBL_GLUE(app_data_, GBL_GLUE(name, size))

#include <deps/incbin.h>

#endif //ENGINE_ASSETS_H_