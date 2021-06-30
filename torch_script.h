#ifndef NODE_ADDON_LIBTORCH_TORCH_SCRIPT_H
#define NODE_ADDON_LIBTORCH_TORCH_SCRIPT_H

#include <vector>
#include <iostream>

using namespace std;

vector<float> module_forward(const char* pathname, const vector<float>& in);

#endif //NODE_ADDON_LIBTORCH_TORCH_SCRIPT_H
