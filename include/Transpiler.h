//
// Created by yanni on 20/05/2021.
//

#ifndef HELLO_TRANSPILER_H
#define HELLO_TRANSPILER_H

#include <node.h>
#include <node_object_wrap.h>
#include <map>
#include <fstream>

namespace CPPAddOn {

    class Transpiler : public node::ObjectWrap {
        public:
            static void Init(v8::Isolate *isolate);
            static void NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args);

        private:
            explicit Transpiler(std::string dataCode);

            ~Transpiler() noexcept;

            static void New(const v8::FunctionCallbackInfo<v8::Value> &args);

            static void Parse(const v8::FunctionCallbackInfo<v8::Value> &args);

            static v8::Global<v8::Function> constructor;

            std::string dataCode;
    };

}

#endif //HELLO_TRANSPILER_H
