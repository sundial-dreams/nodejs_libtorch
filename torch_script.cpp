#include "torch/script.h"
#include "torch_script.h"

vector<float> module_forward(const char *pathname, const vector<float> &input) {
    try {
     torch::jit::Module module =  torch::jit::load(pathname);
        vector<torch::jit::IValue> in_batch;
        at::Tensor in = torch::tensor(input);
        in_batch.emplace_back(torch::reshape(in, {1, int64_t(input.size())}));
        at::Tensor output = module.forward(in_batch).toTensor();

        auto float_out = output.data_ptr<float>();
        return vector<float>(float_out, float_out + output.size(1));

    } catch (const c10::Error &e) {
        cerr << e.msg() << endl;
    }

    return vector<float>();

}