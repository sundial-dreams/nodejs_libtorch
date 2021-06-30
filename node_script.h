#ifndef NODE_ADDON_LIBTORCH_NODE_SCRIPT_H
#define NODE_ADDON_LIBTORCH_NODE_SCRIPT_H

#include <napi.h>
#include "torch_script.h"
using namespace std;

Napi::Array ModuleForward(const Napi::CallbackInfo& callbackInfo);

#endif //NODE_ADDON_LIBTORCH_NODE_SCRIPT_H
