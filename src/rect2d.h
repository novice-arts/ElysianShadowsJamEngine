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
	GBL_RESULT (*pFnDraw)(GBL_SELF, SDL_Renderer*);
GBL_CLASS_END


GBL_DECLS_BEGIN

GBL_INSTANCE_DERIVE(Rect2D, GblObject)
	float x, y, w, h;
GBL_INSTANCE_END




GBL_PROPERTIES(Rect2D,
	(x, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(y, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(w, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE),
	(h, GBL_GENERIC, (READ, WRITE), GBL_FLOAT_TYPE)
)

static GBL_RESULT Rect2D_GblObject_setProperty_(GblObject *pObject, const GblProperty *pProp, GblVariant *pValue){
	Rect2D *pSelf = RECT2D(pObject);
	switch(pProp->id){
		case Rect2D_Property_Id_x:{
			GblVariant_valueCopy(pValue, &pSelf->x);
		}break;
		case Rect2D_Property_Id_y:{
			GblVariant_valueCopy(pValue, &pSelf->y);
		}break;
		case Rect2D_Property_Id_w:{
			GblVariant_valueCopy(pValue, &pSelf->w);
		}break;
		case Rect2D_Property_Id_h:{
			GblVariant_valueCopy(pValue, &pSelf->h);
		}break;
	}
	return GBL_RESULT_SUCCESS;
}


static GBL_RESULT Rect2D_GblObject_property_(const GblObject *pObject, const GblProperty *pProp, GblVariant *pValue){
	Rect2D *pSelf = RECT2D(pObject);
	switch(pProp->id){
		case Rect2D_Property_Id_x:{
			GblVariant_setFloat(pValue, pSelf->x);
		}break;
		case Rect2D_Property_Id_y:{
			GblVariant_setFloat(pValue, pSelf->y);
		}break;
		case Rect2D_Property_Id_w:{
			GblVariant_setFloat(pValue, pSelf->w);
		}break;
		case Rect2D_Property_Id_h:{
			GblVariant_setFloat(pValue, pSelf->h);
		}break;
	}
	return GBL_RESULT_SUCCESS;
}
//API

static GBL_RESULT Rect2DClass_init_(GblClass *pClass, const void *pData);
GblType Rect2D_type(void);

static GBL_RESULT Rect2D_init_(GblInstance *pInstance);
static GBL_RESULT Rect2D_update_(GBL_SELF);
static GBL_RESULT Rect2D_draw_(Rect2D* pSelf, SDL_Renderer* renderer);

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

GBL_RESULT Rect2D_draw_(GBL_SELF, SDL_Renderer* renderer) {
    SDL_RenderFillRect(renderer, &(SDL_FRect) { pSelf->x, pSelf->y, pSelf->w, pSelf->h });
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