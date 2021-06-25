//
// Created by yanni on 20/05/2021.
//

#include <node.h>
#include <iostream>
#include <nan.h>
#include "../include/Transpiler.h"
#include "../include/Parser.h"


using namespace v8;
using namespace Nan;

Transpiler::Transpiler(std::string dataCode) : m_dataCode(std::move(dataCode)) {}

void Transpiler::Init(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Transpiler").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "getHandle", GetHandle);
    Nan::SetPrototypeMethod(tpl, "transpile", Transpile);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(target, Nan::New("Transpiler").ToLocalChecked(),
             Nan::GetFunction(tpl).ToLocalChecked());
}

void Transpiler::New(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    auto *isolate = info.GetIsolate();

    if (info.IsConstructCall()) {
        auto value = info[0]->IsUndefined() ? "" : std::string(*v8::String::Utf8Value(isolate, info[0]));
        auto *obj = new Transpiler(value);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } else {
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = {info[0]};
        v8::Local<v8::Function> cons = Nan::New(constructor());
        info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
    }
}

void Transpiler::GetHandle(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    auto *obj = Nan::ObjectWrap::Unwrap<Transpiler>(info.Holder());
    info.GetReturnValue().Set(obj->handle());
}

void Transpiler::Transpile(const Nan::FunctionCallbackInfo<v8::Value> &info) {
    auto *isolate = info.GetIsolate();

    auto *transpiler = Nan::ObjectWrap::Unwrap<Transpiler>(info.Holder());

    auto *parser = new Parser(transpiler->m_dataCode);

    try {
        parser->parse();
        info.GetReturnValue().Set(String::NewFromUtf8(isolate, Parser::JAVASCRIPT_CODE.c_str()));
    } catch (std::exception &e) {
        std::cerr << "Build failed !" << std::endl;
        info.GetReturnValue().Set(String::NewFromUtf8(isolate, e.what()));
    }

    Parser::JAVASCRIPT_CODE = "";

    delete parser;
    delete transpiler;
}

Transpiler::~Transpiler() noexcept = default;

inline Nan::Persistent<v8::Function> &Transpiler::constructor() {
    static Nan::Persistent<v8::Function> my_constructor;
    return my_constructor;
}
