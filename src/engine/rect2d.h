#ifndef ENGINE_RECT2D_H
#define ENGINE_RECT2D_H


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

GBL_PROPERTIES_GETSET(Rect2D,
	(x, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(y, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(w, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(h, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE)
)

//API

static GBL_RESULT Rect2DClass_init_(GblClass *pClass, const void *pData);
GblType Rect2D_type(void);

static GBL_RESULT Rect2D_init_(GblInstance *pInstance);
static GBL_RESULT Rect2D_update_(GBL_SELF);
static GBL_RESULT Rect2D_draw_(Rect2D* pSelf);

//Implementation
GblType Rect2D_type(void) {
	static GblType type = GBL_INVALID_TYPE;
	static GblTypeInfo tInfo = {
			.classSize = sizeof(Rect2DClass),
			.pFnClassInit = Rect2DClass_init_,
			.instanceSize = sizeof(Rect2D),
			.pFnInstanceInit = Rect2D_init_
	};
	if(type == GBL_INVALID_TYPE){
		type = GblType_register(GblQuark_internStatic("Rect2D"), GBL_OBJECT_TYPE, &tInfo, GBL_TYPE_FLAG_TYPEINFO_STATIC);
	}
	return type;
}

GBL_RESULT Rect2D_init_(GblInstance *pInstance){
	Rect2D* rect_instance = RECT2D(pInstance);
	rect_instance->x = 160.0f;
	rect_instance->y = 120;
	rect_instance->w = 320;
	rect_instance->h = 240;
	return GBL_RESULT_SUCCESS;
}

GBL_RESULT Rect2D_update_(GBL_SELF){return GBL_RESULT_SUCCESS;}

GBL_RESULT Rect2D_draw_(GBL_SELF) {
	
	float x = pSelf->x;
	float y = pSelf->y;
	float w = pSelf->w;
	float h = pSelf->h;
	GL_DRAW(GL_QUADS){
		glColor3f(0.8f, 0.1f, 0.15f);
		glQuad(x, y, w, h, 0.95f);
		
		x += 0.2f;
		glColor3f(0.1f, 0.8f, 0.15f);
		glQuad(x, y, w, h, 0.95f);
	}
	
    return GBL_RESULT_SUCCESS;
}


GBL_RESULT Rect2DClass_init_(GblClass *pClass, const void *pData){
	GBL_UNUSED(pData);
	
	if(!GblType_classRefCount(GBL_CLASS_TYPEOF(pClass))) GBL_PROPERTIES_REGISTER(Rect2D);


	GBL_PROPERTIES_HOOK_CLASS(Rect2D);

	Rect2DClass* klass = RECT2D_CLASS(pClass);
	klass->pFnUpdate = Rect2D_update_;
	klass->pFnDraw = Rect2D_draw_;
	
	return GBL_RESULT_SUCCESS;
}
/*format: name, value, name, value, ... */
#define Rect2D_create(name, ...)	GBL_NEW(Rect2D, name, __VA_ARGS__)
#define Rect2D_create_empty(...)	GBL_NEW(Rect2D)

GBL_DECLS_END
#undef GBL_SELF_TYPE

#endif //ENGINE_RECT2D_H