//
// Created by yanni on 20/05/2021.
//

#ifndef HELLO_TRANSPILER_H
#define HELLO_TRANSPILER_H

#include <node.h>
#include <node_api.h>
#include <nan.h>
#include <node_object_wrap.h>
#include <map>
#include <fstream>


class Transpiler : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init);

private:
    std::string m_dataCode;

    explicit Transpiler(std::string dataCode);

    ~Transpiler() noexcept;

    static NAN_METHOD(New);

    static NAN_METHOD(GetHandle);

    static NAN_METHOD(Transpile);

    static inline Nan::Persistent<v8::Function> &constructor();


};

NODE_MODULE(objectwrapper, Transpiler::Init)

#endif //HELLO_TRANSPILER_H
