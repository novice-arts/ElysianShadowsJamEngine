
//API
#ifndef GIMBAL_ALREADY_INCLUDED
#define GIMBAL_ALREADY_INCLUDED
    #include <gimbal/gimbal_meta.h>
    #include <gimbal/gimbal_strings.h>
    #include <gimbal/gimbal_core.h>
#endif 
#include <src/utils/macros/gimbal_properties_extensions.h>

#include <src/platform/gl.h>
#include <src/utils/macros/gl_helpers.h>

#include "rect2d.h"

GBL_PROPERTIES_GET(Rect2D, RECT2D_PROPERTIES)
GBL_PROPERTIES_SET(Rect2D, RECT2D_PROPERTIES)


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

GBL_RESULT Rect2D_update_(Rect2D* pSelf){return GBL_RESULT_SUCCESS;}

//this is assumed to be used in a draw block
GBL_RESULT Rect2D_draw_(Rect2D* pSelf) {
	
	float x = pSelf->x;
	float y = pSelf->y;
	float w = pSelf->w;
	float h = pSelf->h;
	glQuad(x, y, w, h, 0.95f);
	
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