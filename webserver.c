#include "quickjs.h"
#include "cutils.h"

static JSValue greet(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    return JS_NewString(ctx, "QuickJS Webserver :: Greetings!");
}

static const JSCFunctionListEntry js_webserver_funcs[] = {
    JS_CFUNC_DEF("greet", 0, greet),
};

static int js_webserver_init(JSContext *ctx, JSModuleDef *m)
{
    return JS_SetModuleExportList(ctx, m, js_webserver_funcs, countof(js_webserver_funcs));
}

JSModuleDef *js_init_module_webserver(JSContext *ctx, const char *module_name)
{
    JSModuleDef *m;
    m = JS_NewCModule(ctx, module_name, js_webserver_init);
    
    if (!m)
        return NULL;
    
    JS_AddModuleExportList(ctx, m, js_webserver_funcs, countof(js_webserver_funcs));
    return m;
}
