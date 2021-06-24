//
// Created by yanni on 20/05/2021.
//

#include <node.h>
#include <iostream>
#include <utility>
#include "../include/Transpiler.h"
#include "../include/Parser.h"

namespace CPPAddOn {

    using node::AddEnvironmentCleanupHook;
    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Global;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    Global<Function> Transpiler::constructor;

    Transpiler::Transpiler(std::string dataCode) : dataCode(std::move(dataCode)) {}

    Transpiler::~Transpiler() noexcept = default;

    void Transpiler::Init(Isolate *isolate) {
        auto tpl = FunctionTemplate::New(isolate, New);
        tpl->SetClassName(String::NewFromUtf8(isolate, "Transpiler"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        NODE_SET_PROTOTYPE_METHOD(tpl, "transpile", Parse);

        auto currentContext = isolate->GetCurrentContext();
        constructor.Reset(isolate, tpl->GetFunction(currentContext).ToLocalChecked());

        AddEnvironmentCleanupHook(isolate, [](void *) {
            constructor.Reset();
        }, nullptr);

    }

    void Transpiler::New(const v8::FunctionCallbackInfo<v8::Value> &args) {

        auto *isolate = args.GetIsolate();
        auto currentContext = isolate->GetCurrentContext();

        if (args.IsConstructCall()) {
            auto dataCode = args[0]->IsUndefined() ? "" : std::string(*v8::String::Utf8Value(isolate, args[0]));
            auto * transpiler = new Transpiler(dataCode);
            transpiler->Wrap(args.This());
            args.GetReturnValue().Set(args.This());
        } else {
            const int argc = 1;
            Local<Value> argv[argc] = {args[0]};
            auto cons = Local<Function>::New(isolate, constructor);
            auto instance = cons->NewInstance(currentContext, argc, argv).ToLocalChecked();
            args.GetReturnValue().Set(instance);
        }
    }

    void Transpiler::NewInstance(const FunctionCallbackInfo<Value> &args) {
        auto *isolate = args.GetIsolate();

        const unsigned argc = 1;
        Local<Value> argv[argc] = {args[0]};
        auto cons = Local<Function>::New(isolate, constructor);
        auto context = isolate->GetCurrentContext();
        auto instance = cons->NewInstance(context, argc, argv).ToLocalChecked();

        args.GetReturnValue().Set(instance);
    }

    void Transpiler::Parse(const v8::FunctionCallbackInfo<v8::Value> &args) {
        auto * isolate = args.GetIsolate();

        //MAIN GOES HERE

        auto * transpiler = ObjectWrap::Unwrap<Transpiler>(args.Holder());



        auto* parser = new Parser(transpiler->dataCode);

        try {
            parser->parse();
            args.GetReturnValue().Set(String::NewFromUtf8(isolate, Parser::JAVASCRIPT_CODE.c_str()));
        } catch (std::exception &e) {
            std::cerr << "Build failed !" << std::endl;
            args.GetReturnValue().Set(String::NewFromUtf8(isolate, e.what()));
        }

        Parser::JAVASCRIPT_CODE = "";

        delete parser;
        delete transpiler;
    }

}