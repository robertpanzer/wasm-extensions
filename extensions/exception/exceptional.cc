#include "exceptional.h"

#include <stdexcept>

#ifndef NULL_PLUGIN

#include "proxy_wasm_intrinsics.h"

#else

#include "include/proxy-wasm/null_plugin.h"

#endif

const std::string error_message {"Some exception"};

void g() {
    throw std::runtime_error(error_message);
}

void f() {
    g();
}

void executeException() {

    LOG_INFO("EXECUTE EXCEPTION");

    try {
        f();
        LOG_INFO("NO EXCEPTION THROWN????");
    } catch (std::runtime_error e) {
        LOG_INFO(std::string{"GOT A RUNTIME ERROR: "} + e.what());
    } catch (...) {
        LOG_INFO("OH YEAH, GOT AN EXCEPTION");
    }
}