#include "extensions/exception/plugin.h"
#include "exceptional.h"

#include <string>
#include <string_view>
#include <vector>


#ifdef NULL_PLUGIN

namespace proxy_wasm {
namespace null_plugin {
namespace scaffold {

PROXY_WASM_NULL_PLUGIN_REGISTRY

#endif

static RegisterContextFactory register_Scaffold(
    CONTEXT_FACTORY(PluginContext), ROOT_FACTORY(PluginRootContext));

bool PluginRootContext::onConfigure(size_t) { 
    LOG_WARN("CONFIGURE");
    return true; 
}

FilterHeadersStatus PluginContext::onRequestHeaders(uint32_t, bool) {
    const std::string path = getRequestHeader(":path")->toString();
    LOG_INFO(std::string{"REQUEST PATH: "} + path);
    if (path == "/exception") {
        executeException();
    } else {
        LOG_INFO("NOTHING TO DO");
    }
    return FilterHeadersStatus::Continue;
}


#ifdef NULL_PLUGIN

}  // scaffold
}  // namespace null_plugin
}  // namespace proxy_wasm

#endif

