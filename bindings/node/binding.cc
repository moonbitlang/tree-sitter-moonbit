#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_moonbit();
extern "C" TSLanguage *tree_sitter_moonbit_interface();
extern "C" TSLanguage *tree_sitter_moonbit_package();

// "tree-sitter", "language" hashed with BLAKE2
const napi_type_tag LANGUAGE_TYPE_TAG = {
    0x8AF2E5212AD58ABF, 0xD5006CAD83ABBA16
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    auto moonbit = Napi::External<TSLanguage>::New(env, tree_sitter_moonbit());
    moonbit.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["language"] = moonbit;

    auto moonbit_interface = Napi::External<TSLanguage>::New(env, tree_sitter_moonbit_interface());
    moonbit_interface.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["moonbit_interface"] = moonbit_interface;

    auto moonbit_package = Napi::External<TSLanguage>::New(env, tree_sitter_moonbit_package());
    moonbit_package.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["moonbit_package"] = moonbit_package;

    return exports;
}

NODE_API_MODULE(tree_sitter_moonbit_binding, Init)
