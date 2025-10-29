#ifndef ENGINE_RECT2D_H
#define ENGINE_RECT2D_H

#ifndef GIMBAL_ALREADY_INCLUDED
#define GIMBAL_ALREADY_INCLUDED
    #include <gimbal/gimbal_meta.h>
    #include <gimbal/gimbal_strings.h>
    #include <gimbal/gimbal_core.h>
#endif 

#define RECT2D_TYPE				(GBL_TYPEID(Rect2D))
#define RECT2D(self)			(GBL_CAST(Rect2D, self))
#define RECT2D_CLASS(klass)		(GBL_CLASS_CAST(Rect2D, klass))
#define RECT2D_GET_CLASS(self)	(GBL_CLASSOF(Rect2D, self))

#define GBL_SELF_TYPE Rect2D
GBL_FORWARD_DECLARE_STRUCT(Rect2D);

GBL_CLASS_DERIVE(Rect2D, GblObject)
	GBL_RESULT (*pFnUpdate)(GBL_SELF);
	GBL_RESULT (*pFnDraw)(GBL_SELF);
GBL_CLASS_END


GBL_DECLS_BEGIN

GBL_INSTANCE_DERIVE(Rect2D, GblObject)
	float x, y, w, h;
GBL_INSTANCE_END

#define RECT2D_PROPERTIES \
	(x, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),\
	(y, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),\
	(w, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),\
	(h, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE)

GBL_PROPERTIES(Rect2D, RECT2D_PROPERTIES)


GBL_RESULT Rect2DClass_init_(GblClass *pClass, const void *pData);
GblType Rect2D_type(void);

GBL_RESULT Rect2D_init_(GblInstance *pInstance);
GBL_RESULT Rect2D_update_(GBL_SELF);
GBL_RESULT Rect2D_draw_(GBL_SELF);

/*format: name, value, name, value, ... */
#define Rect2D_create(name, ...)	GBL_NEW(Rect2D, name, __VA_ARGS__)
#define Rect2D_create_empty(...)	GBL_NEW(Rect2D)

GBL_DECLS_END
#undef GBL_SELF_TYPE

#endif //ENGINE_RECT2D_H