

#ifndef ENGINE_INPUT_H_
#define ENGINE_INPUT_H_

#define INPUT_TYPE           (GBL_TYPEID(Input))
#define INPUT_CLASS(klass)   (GBL_CLASS_CAST(Input, klass))


#define GBL_SELF_TYPE InputClass

typedef struct InputButton{    
    bool pressed : 1;
    bool released : 1;
    bool held : 1;
    uint8_t tap_count: 5;
}InputButton;

typedef struct InputDpad{
    InputButton directions[8];
}InputDpadButton;

GBL_STATIC_ASSERT(sizeof(char) == sizeof(bool) && sizeof(bool) == sizeof(InputButton));

GBL_DECLS_BEGIN

GBL_CLASS_BASE(Input)
    int test;
GBL_CLASS_END

GBL_EXPORT bool Input_pressed(GBL_CSELF){return false;}


GBL_DECLS_END

#undef GBL_SELF_TYPE


#endif //ENGINE_INPUT_H_