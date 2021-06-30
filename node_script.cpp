#include "node_script.h"


Napi::Array ModuleForward(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Array result = Napi::Array::New(env);
    Napi::String pathname = info[0].ToString();
    Napi::Array input = info[1].As<Napi::Array>();

    vector<float> in;
    for (size_t i = 0; i < input.Length(); i++)
        in.push_back(input.Get(i).ToNumber());
    vector<float> r = module_forward(pathname.Utf8Value().c_str(), in);

    for (size_t i = 0; i < r.size(); i++)
        result.Set(i, Napi::Number::New(env, r[i]));
    return result;
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("moduleForward", Napi::Function::New(env, ModuleForward));
    return exports;
}

NODE_API_MODULE(torch_script, Init)